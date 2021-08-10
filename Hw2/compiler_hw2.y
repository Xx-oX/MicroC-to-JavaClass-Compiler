/*	Definition section */
%{
    #include "common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    /* Symbol table structure */

    struct node{
        int index;
        int address;
        int lineno;
        char *name;
        char *type;
        char *element;
        struct node *next;
    };

    typedef struct ST {
        int scope;
        int index;
        struct node *head;
        struct ST *next;
    } symbol_table_t;

    /* variables */
    symbol_table_t *symbolTable;

    int scope = 0;
    int addr = 0;

    /* Symbol table function - you can add new function if needed. */
    static symbol_table_t *create_symbol(int s);
    static symbol_table_t *find_symbol_table(int s);
    static void insert_symbol(char *name, char *type, char *element, int lineno);
    static struct node *lookup_symbol(char *name);
    static void dump_symbol();
    static char get_short_type(char *type);
    static void error_check(char *a, char *b, char *op);
%}

%error-verbose

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    float f_val;
    char *s_val;
}

/* Token without return */
%token ADD SUB MUL QUO REM INC DEC
%token GTR LSS GEQ LEQ EQL NEQ
%token ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN QUO_ASSIGN REM_ASSIGN
%token AND OR NOT
%token LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE
%token SEMICOLON COMMA QUOTA
%token PRINT 
%token RETURN IF ELSE FOR WHILE 
%token INT FLOAT BOOL STRING
%token TRUE FALSE CONTINUE BREAK VOID


/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <f_val> FLOAT_LIT
%token <s_val> STRING_LIT BOOL_LIT IDENT

/* Nonterminal with return, which need to sepcify type */
%type <s_val> Type TypeName
%type <s_val> Expression UnaryExpr PrimaryExpr Operand Literal IndexExpr ConversionExpr
%type <s_val> unary_op cmp_op add_op mul_op assign_op
%type <s_val> Expr4 Expr5 Expr6 Expr7

/* associativity & precedence */
%right ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN QUO_ASSIGN REM_ASSIGN
%left ADD SUB MUL QUO REM INC DEC

/* Yacc will start at this nonterminal */
%start Program

/* Grammar section */
%%

Program
    : StatementList
;

Type
    : TypeName { $$ = $1; }
;

TypeName
    : INT { $$ = "int"; }
    | FLOAT { $$ = "float"; }
    | STRING { $$ = "string"; }
    | BOOL { $$ = "bool"; }
;

Expression
    : Expression OR Expr7 { error_check($1, $3, "OR"); printf("OR\n"); $$ = $3; }
    | Expr7 { $$ = $1; }
    // | Expression binary_op Expression { printf("%s\n", $2); }
;

Expr7
    : Expr7 AND Expr6 { error_check($1, $3, "AND"); printf("AND\n"); $$ = $3; }
    | Expr6 { $$ = $1; }
;

Expr6
    : Expr6 cmp_op Expr5 { error_check($1, $3, $2); printf("%s\n", $2); $$ = "bool"; }
    | Expr5 { $$ = $1; }
;

Expr5
    : Expr5 add_op Expr4 { error_check($1, $3, $2); printf("%s\n", $2); $$ = $3; }
    | Expr4 { $$ = $1; }
;

Expr4
    : Expr4 mul_op UnaryExpr { error_check($1, $3, $2); printf("%s\n", $2); $$ = $3; }
    | UnaryExpr { $$ = $1; }
;

UnaryExpr
    : PrimaryExpr { $$ = $1; }
    | unary_op UnaryExpr { printf("%s\n", $1); $$ = $2; }
;

// binary_op
//     : OR { $$ = "OR"; }
//     | AND { $$ = "AND"; }
//     | cmp_op { $$ = $1; }
//     | add_op { $$ = $1; }
//     | mul_op { $$ = $1; }
// ;

cmp_op
    : EQL { $$ = "EQL"; }
    | NEQ { $$ = "NEQ"; }
    | LSS { $$ = "LSS"; }
    | LEQ { $$ = "LEQ"; }
    | GTR { $$ = "GTR"; }
    | GEQ { $$ = "GEQ"; }
;

add_op
    : ADD { $$ = "ADD"; }
    | SUB { $$ = "SUB"; }
;

mul_op
    : MUL { $$ = "MUL"; }
    | QUO { $$ = "QUO"; }
    | REM { $$ = "REM"; }
;

unary_op
    : ADD { $$ = "POS"; }
    | SUB { $$ = "NEG"; }
    | NOT { $$ = "NOT"; }
;

PrimaryExpr
    : Operand { $$ = $1; }
    | IndexExpr { $$ = $1; }
    | ConversionExpr { $$ = $1; }
;

Operand
    : Literal { $$ = $1; }
    | IDENT {
        struct node *n = lookup_symbol($1); 
        if(n)
        {
            $$ = n->type;
        }
        else
        {
            $$ = "undefined";
        }
    }
    | LPAREN Expression RPAREN { $$ = $2; }
;

Literal
    : INT_LIT { printf("INT_LIT %d\n", $<i_val>$); $$ = "int"; }
    | FLOAT_LIT { printf("FLOAT_LIT %f\n", $<f_val>$); $$ = "float"; }
    | STRING_LIT { printf("STRING_LIT %s\n", $<s_val>$); $$ = "string"; }
    | TRUE { printf("TRUE\n"); $$ = "bool"; }
    | FALSE { printf("FALSE\n"); $$ = "bool"; }
;

IndexExpr
    : PrimaryExpr LBRACK Expression RBRACK { $$ = $1; }
;

ConversionExpr
    : LPAREN Type RPAREN Expression { printf("%c to %c\n", get_short_type($4), get_short_type($2)); $$ = $2; }
;

Statement
    : Statement Statement
    | ExpressionStmt
    | DeclarationStmt
    | AssignmentStmt
    | IncDecStmt
    | Block
    | IfStmt
    | WhileStmt
    | ForStmt
    | PrintStmt
;

ExpressionStmt
    : Expression SEMICOLON
;

DeclarationStmt
    : Type IDENT SEMICOLON { insert_symbol($2, $1, "-", yylineno); }
    | Type IDENT ASSIGN Expression SEMICOLON { insert_symbol($2, $1, "-", yylineno); }
    | Type IDENT LBRACK Expression RBRACK SEMICOLON { insert_symbol($2, "array", $1, yylineno); }
;

AssignmentStmt
    : AssignmentExpr SEMICOLON
;

AssignmentExpr
    : Literal assign_op Expression { printf("error:%d: cannot assign to %s\n", yylineno, $1); printf("%s\n", $2); }
    | Expression assign_op Expression { error_check($1, $3, $2); printf("%s\n", $2); }
;

assign_op
    : ASSIGN { $$ = "ASSIGN"; }
    | ADD_ASSIGN { $$ = "ADD_ASSIGN"; }
    | SUB_ASSIGN { $$ = "SUB_ASSIGN"; }
    | MUL_ASSIGN { $$ = "MUL_ASSIGN"; }
    | QUO_ASSIGN { $$ = "QUO_ASSIGN"; }
    | REM_ASSIGN { $$ = "REM_ASSIGN"; }
;

IncDecStmt
    : IncDecExpr SEMICOLON
;

IncDecExpr
    : Expression INC { printf("INC\n"); }
    | Expression DEC { printf("DEC\n"); }
;

Block
    : Lbrace StatementList Rbrace
;

Lbrace
    : LBRACE { scope++;}
;

Rbrace
    : RBRACE { dump_symbol(); scope--; }
;

StatementList
    : Statement
;

IfStmt
    : IF Condition Block
    | IF Condition Block ELSE IfStmt
    | IF Condition Block ELSE Block
;

Condition
    : Expression { error_check($1, $1, "condition"); }
;

WhileStmt
    : WHILE LPAREN Condition RPAREN Block
;

ForStmt
    : FOR LPAREN ForClause RPAREN Block
;

ForClause
    : InitStmt SEMICOLON Condition SEMICOLON PostStmt
;

InitStmt
    : SimpleExpr
;

PostStmt
    : SimpleExpr
;

SimpleExpr
    : AssignmentExpr
    | Expression
    | IncDecExpr
;

PrintStmt
    : PRINT LPAREN IDENT RPAREN SEMICOLON {
        struct node *n = lookup_symbol($3);
        if(n)
        {
            printf("PRINT %s\n", n->type);
        }
    }
    | PRINT LPAREN IDENT LBRACK INT_LIT RBRACK RPAREN SEMICOLON {
        struct node *n = lookup_symbol($3);
        printf("INT_LIT %d\n", $5);
        if(n)
        {
            printf("PRINT %s\n", n->element);
        }
    }
    | PRINT LPAREN Expression RPAREN SEMICOLON {
        printf("PRINT %s\n", $3);
    }
;

%%

/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    symbolTable = malloc(sizeof(symbol_table_t));
    symbolTable->scope = 0;
    symbolTable->index = 0;
    symbolTable->head = malloc(sizeof(struct node));
    symbolTable->next = NULL;

    yyparse();
    dump_symbol();

	printf("Total lines: %d\n", yylineno);
    fclose(yyin);
    return 0;
}

/* symbol table function */
static symbol_table_t *create_symbol(int s)
{
    symbol_table_t *new_s, *curr = symbolTable;
    new_s = malloc(sizeof(symbol_table_t));
    new_s->scope = s;
    new_s->index = 0;
    new_s->head = malloc(sizeof(struct node));
    new_s->next = NULL;

    while(curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = new_s;
    return new_s;
}

static symbol_table_t *find_symbol_table(int s)
{
    symbol_table_t *curr = symbolTable;
    while(curr != NULL)
    {
        if(curr->scope == s)
        {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

static void insert_symbol(char *name, char *type, char *element, int lineno)
{
    symbol_table_t *st = find_symbol_table(scope);
    if(!st)
    {
        st = create_symbol(scope);
    }
    else
    {
        struct node *n = st->head->next;
        int found = 0;
        while(n != NULL)
        {
            if(strcmp(name, n->name) == 0)
            {
                found = 1;
                break;
            }
            n = n->next;
        }

        if(found == 1)
        {
            printf("error:%d: %s redeclared in this block. previous declaration at line %d\n", lineno, name, n->lineno);
            return;
        }
    }

    printf("> Insert {%s} into symbol table (scope level: %d)\n", name, scope);

    struct node *new_n = malloc(sizeof(struct node));
    new_n->index = st->index++;
    new_n->address = addr++;
    new_n->lineno = lineno;
    new_n->name = strdup(name);
    new_n->type = strdup(type);
    new_n->element = strdup(element);
    new_n->next = NULL;

    struct node *curr = st->head;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_n;

}

static struct node *lookup_symbol(char *name)
{
    int s = scope;
    do{
        symbol_table_t *st = find_symbol_table(s);
        if(!st)
        {
            continue;
        }

        struct node *curr = st->head->next;
        while(curr != NULL)
        {
            if(strcmp(name, curr->name) == 0)
            {
                printf("IDENT (name=%s, address=%d)\n", curr->name, curr->address);
                return curr;
            }
            curr = curr->next;
        }
    } while(--s >= 0);

    printf("error:%d: undefined: %s\n", yylineno, name);

    return NULL;
}

static void dump_symbol()
{
    symbol_table_t *st = find_symbol_table(scope);
    int s;
    if(st == NULL)
    {
        s = scope;
    }
    else 
    {
        s = st->scope;
    }
    printf("> Dump symbol table (scope level: %d)\n", s);
    printf("%-10s%-10s%-10s%-10s%-10s%s\n", "Index", "Name", "Type", "Address", "Lineno", "Element type");
    
    if(st == NULL)
    {
        return;
    }

    struct node *curr = st->head->next, *tmp;
    while(curr != NULL)
    {
        printf("%-10d%-10s%-10s%-10d%-10d%s\n", curr->index, curr->name, curr->type, curr->address, curr->lineno, curr->element);
        tmp = curr;
        curr = curr->next;
        free(tmp);
    }
    st->head->next = NULL;
    free(st);
    // if(scope > 0){
    //     symbol_table_t *prev = find_symbol_table(scope-1);
    //     prev->next = NULL;
    // }    
}

static char get_short_type(char *type)
{
    if(strcmp(type, "int") == 0) return 'I';
    if(strcmp(type, "float") == 0) return 'F';
    if(strcmp(type, "string") == 0) return 'S';
    if(strcmp(type, "bool") == 0) return 'B';
    return 'N'; //not a type
}

static void error_check(char *a, char *b, char *op)
{

    if(strcmp(a, "undefined") == 0 || strcmp(b, "undefined") == 0)
    {
        return;
    }

    if(strcmp(op, "condition") == 0)
    {
        if(strcmp(a, "bool") != 0)
        {
            printf("error:%d: non-bool (type %s) used as for condition\n", yylineno+1, a);
        }
        return;
    }

    if(strcmp(op, "REM") == 0)
    {
        if(strcmp(a, "int") != 0 || strcmp(b, "int") != 0)
        {
            printf("error:%d: invalid operation: (operator REM not defined on float)\n", yylineno);
        }
        return;
    }

    if(strcmp(op, "AND") == 0 || strcmp(op, "OR") == 0 )
    {
        if(strcmp(a, "bool") != 0)
        {
            printf("error:%d: invalid operation: (operator %s not defined on %s)\n", yylineno, op, a);
        }

        if(strcmp(b, "bool") != 0)
        {
            printf("error:%d: invalid operation: (operator %s not defined on %s)\n", yylineno, op, b);
        }
        return;
    }

    if(strcmp(a, b) != 0)
    {
        if(strcmp(a, "array") == 0 || strcmp(b, "array") == 0)
        {
            return;
        }
        printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n", yylineno, op, a, b);
    }
}
