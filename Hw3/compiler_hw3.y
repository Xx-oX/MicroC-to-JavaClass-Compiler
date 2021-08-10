/*	Definition section */
%{
    #include "common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;

    #define codegen(...) \
        do { \
            for (int i = 0; i < INDENT; i++) { \
                fprintf(fout, "\t"); \
            } \
            fprintf(fout, __VA_ARGS__); \
        } while (0)

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;
    
    /* Other global variables */
    FILE *fout = NULL;
    bool HAS_ERROR = false;
    int INDENT = 0;
    
    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    /* variables */
    symbol_table_t *symbolTable;
    int scope = 0;
    int addr = 0;
    int cmplabel = 0;
    int looplabels[10] = {0};
    int loopflag = 0; // 0: while 1:if-else

    /* Symbol table function - you can add new function if needed. */
    static symbol_table_t *create_symbol(int s);
    static symbol_table_t *find_symbol_table(int s);
    static void insert_symbol(char *name, char *type, char *element, int lineno);
    static node_t *lookup_symbol(char *name);
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
%type <s_val> Type TypeName LId
%type <s_val> unary_op cmp_op add_op mul_op assign_op IncDec
%type <s_val> Expression UnaryExpr PrimaryExpr Operand Literal IndexExpr LIndexExpr ConversionExpr
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
    : Expression OR Expr7 { 
        error_check($1, $3, "OR"); 
        codegen("ior\n");
        $$ = "bool";
    }
    | Expr7 { $$ = $1; }
;

Expr7
    : Expr7 AND Expr6 { 
        error_check($1, $3, "AND");  
        codegen("iand\n");
        $$ = "bool";
    }
    | Expr6 { $$ = $1; }
;

Expr6
    : Expr6 cmp_op Expr5 { 
        error_check($1, $3, $2);
        if(strcmp($1, "int") == 0)
        {
            codegen("isub\n");
        }
        else if(strcmp($1, "float") == 0)
        {
            codegen("fcmpl\n");
        }
        if(strcmp($2, "gtr") == 0)
        {
            codegen("ifgt L_cmp_%d\n", ++cmplabel);
            codegen("iconst_0\n");
            codegen("goto L_cmp_%d\nL_cmp_%d:\n", cmplabel+1, cmplabel);
            codegen("iconst_1\nL_cmp_%d:\n", ++cmplabel);
        }
        else if(strcmp($2, "lss") == 0)
        {
            codegen("iflt L_cmp_%d\n", ++cmplabel);
            codegen("iconst_0\n");
            codegen("goto L_cmp_%d\nL_cmp_%d:\n", cmplabel+1, cmplabel);
            codegen("iconst_1\nL_cmp_%d:\n", ++cmplabel);
        }
        else if(strcmp($2, "geq") == 0)
        {
            codegen("ifge L_cmp_%d\n", ++cmplabel);
            codegen("iconst_0\n");
            codegen("goto L_cmp_%d\nL_cmp_%d:\n", cmplabel+1, cmplabel);
            codegen("iconst_1\nL_cmp_%d:\n", ++cmplabel);
        }
        else if(strcmp($2, "leq") == 0)
        {
            codegen("ifle L_cmp_%d\n", ++cmplabel);
            codegen("iconst_0\n");
            codegen("goto L_cmp_%d\nL_cmp_%d:\n", cmplabel+1, cmplabel);
            codegen("iconst_1\nL_cmp_%d:\n", ++cmplabel);
        }
        else if(strcmp($2, "eql") == 0)
        {
            codegen("ifeq L_cmp_%d\n", ++cmplabel);
            codegen("iconst_0\n");
            codegen("goto L_cmp_%d\nL_cmp_%d:\n", cmplabel+1, cmplabel);
            codegen("iconst_1\nL_cmp_%d:\n", ++cmplabel);
        }
        else if(strcmp($2, "neq") == 0)
        {
            codegen("ifne L_cmp_%d\n", ++cmplabel);
            codegen("iconst_0\n");
            codegen("goto L_cmp_%d\nL_cmp_%d:\n", cmplabel+1, cmplabel);
            codegen("iconst_1\nL_cmp_%d:\n", ++cmplabel);
        }
        $$ = "bool"; 
    }
    | Expr5 { $$ = $1; }
;

Expr5
    : Expr5 add_op Expr4 { 
        error_check($1, $3, $2); 
        $$ = $3;
        if(strcmp($1, "int") == 0)
        {
            codegen("i%s\n", $2);
        }
        else
        {
            codegen("f%s\n", $2);
        }
    }
    | Expr4 { $$ = $1; }
;

Expr4
    : Expr4 mul_op UnaryExpr { 
        error_check($1, $3, $2); 

        if(strcmp($3, "int") == 0 )
        {
            codegen("i%s\n", $2);
        }
        else
        {
            codegen("f%s\n", $2);
        }
    }
    | UnaryExpr { $$ = $1; }
;

UnaryExpr
    : PrimaryExpr {
        $$ = $1; 
    }
    | unary_op UnaryExpr {  
        if(strcmp($1, "neg") == 0)
        {
            if(strcmp($2, "int") == 0) 
            {
                codegen("ineg\n");
            }
            else if(strcmp($2, "float") == 0)
            { 
                codegen("fneg\n");
            }
        }
        else if(strcmp($1, "not") == 0)
        {
            codegen("iconst_1\n");/* load true for xor */
            codegen("ixor\n");
        }
        $$ = $2;
    }
;

PrimaryExpr
    : Operand { $$ = $1; }
    | IndexExpr { $$ = $1; }
    | ConversionExpr { $$ = $1; }
;

Operand
    : Literal { $$ = $1; }
    | IDENT {
        node_t *n = lookup_symbol($1); 
        if(n)
        {
            if(strcmp(n->type, "int") == 0)
            {
                codegen("iload %d\n", n->address);
            }
            else if(strcmp(n->type, "float") == 0)
            {
                codegen("fload %d\n", n->address);
            }
            else if(strcmp(n->type, "string") == 0)
            {
                codegen("aload %d\n", n->address);
            }
            else if(strcmp(n->type, "bool") == 0)
            {
                codegen("iload %d\n", n->address);
            }
            $$ = n->type;
        }
    }
    | LPAREN Expression RPAREN { $$ = $2; }
;

Literal
    : INT_LIT {
        codegen("ldc %d\n", $<i_val>$);
        $$ = "int"; 
    }
    | FLOAT_LIT { 
        codegen("ldc %f\n", $<f_val>$);
        $$ = "float";
    }
    | STRING_LIT { 
        codegen("ldc \"%s\"\n", $<s_val>$);
        $$ = "string";
    }
    | TRUE { 
        codegen("iconst_1\n");
        $$ = "bool";
    }
    | FALSE { 
        codegen("iconst_0\n");
        $$ = "bool";
    }
;

LId
    : IDENT {
        node_t *n = lookup_symbol($1);
        if(n)
        {   
            if(strcmp(n->type, "array") == 0)
            {
                codegen("aload %d\n", n->address);
                $$ = n->element;
            }      
            else
            {
                if(strcmp(n->type, "int") == 0)
                {
                    codegen("iload %d\n", n->address);
                }
                else if(strcmp(n->type, "float") == 0)
                {
                    codegen("fload %d\n", n->address);
                }
                else if(strcmp(n->type, "string") == 0)
                {
                    codegen("aload %d\n", n->address);
                }
                else if(strcmp(n->type, "bool") == 0)
                {
                    codegen("iload %d\n", n->address);
                }
                $$ = $1;
            }
        }
    }
;

IndexExpr
    : LId LBRACK Expression RBRACK {
        if(strcmp($1, "int") == 0)
        {
            codegen("iaload\n");
        }
        else if(strcmp($1, "float") == 0)
        {
            codegen("faload\n");
        }
        $$ = $1; 
    }
;

LIndexExpr
    : LId LBRACK Operand RBRACK {
        $$ = $1; 
    }
;


ConversionExpr
    : LPAREN Type RPAREN Expression { 
        // printf("%c to %c\n", get_short_type($4), get_short_type($2));
        if(strcmp($2, $4) == 0)
        {
            printf("nofunc\n");
        }
        else if(strcmp($2, "int") == 0)
        {
            codegen("f2i\n");
        }
        if(strcmp($2, "float") == 0)
        {
            codegen("i2f\n");
        }
        
        $$ = $2; 
    }
;

cmp_op
    : EQL { $$ = "eql"; }
    | NEQ { $$ = "neq"; }
    | LSS { $$ = "lss"; }
    | LEQ { $$ = "leq"; }
    | GTR { $$ = "gtr"; }
    | GEQ { $$ = "geq"; }
;

add_op
    : ADD { $$ = "add"; }
    | SUB { $$ = "sub"; }
;

mul_op
    : MUL { $$ = "mul"; }
    | QUO { $$ = "div"; }
    | REM { $$ = "rem"; }
;

unary_op
    : ADD { $$ = "pos"; }
    | SUB { $$ = "neg"; }
    | NOT { $$ = "not"; }
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
    : Type IDENT SEMICOLON { 
        insert_symbol($2, $1, "-", yylineno);
        node_t *n = lookup_symbol($2);
        if(n)
        {
            if(strcmp(n->type, "int") == 0)
            {
                codegen("ldc 0\n");
                codegen("istore %d\n", n->address);
            }
            else if(strcmp(n->type, "float") == 0)
            {
                codegen("ldc 0.0\n");
                codegen("fstore %d\n", n->address);
            }
            else if(strcmp(n->type, "string") == 0)
            {
                codegen("ldc \"\"\n");
                codegen("astore %d\n", n->address);
            }
            else if(strcmp(n->type, "bool") == 0)
            {
                codegen("ldc 1\n");
                codegen("istore %d\n", n->address);
            }
        }
    }
    | Type IDENT ASSIGN Expression SEMICOLON { 
        insert_symbol($2, $1, "-", yylineno);
        node_t *n = lookup_symbol($2);
        if(n)
        {
            if(strcmp(n->type, "int") == 0)
            {
                codegen("istore %d\n", n->address);
            }
            else if(strcmp(n->type, "float") == 0)
            {
                codegen("fstore %d\n", n->address);
            }
            else if(strcmp(n->type, "string") == 0)
            {
                codegen("astore %d\n", n->address);
            }
            else if(strcmp(n->type, "bool") == 0)
            {
                codegen("istore %d\n", n->address);
            }
        }
    }
    | Type IDENT LBRACK Expression RBRACK SEMICOLON { 
        insert_symbol($2, "array", $1, yylineno); 
        node_t *n = lookup_symbol($2);
        if(n)
        {
            if(strcmp(n->element, "int") == 0)
            {
                codegen("newarray int\n");
                codegen("astore %d\n", n->address);
            }
            else if(strcmp(n->element, "float") == 0)
            {
                codegen("newarray float\n");
                codegen("astore %d\n", n->address);
            }
        }
    }
;

AssignmentStmt
    : AssignmentExpr SEMICOLON
;

AssignmentExpr
    : Literal assign_op Expression { 
        printf("error:%d: cannot assign to %s\n", yylineno, $1); 
        HAS_ERROR = true;
    }
    | IDENT ASSIGN Expression {
        node_t *n = lookup_symbol($1);
        if(n)
        {
            if(strcmp(n->type, "int") == 0)
            {
                codegen("istore %d\n", n->address);
            }
            else if(strcmp(n->type, "float") == 0)
            {
                codegen("fstore %d\n", n->address);
            }
            else if(strcmp(n->type, "string") == 0)
            {
                codegen("astore %d\n", n->address);
            }
            else if(strcmp(n->type, "bool") == 0)
            {
                codegen("istore %d\n", n->address);
            }
        }
        
    }
    | LId assign_op Expression {
        node_t *n = lookup_symbol($1);
        if(n)
        {
            if(strcmp(n->type, "int") == 0)
            {
                codegen("i%s\n", $2);
            }
            else if(strcmp(n->type, "float") == 0)
            {
                codegen("f%s\n", $2);
            }

            if(strcmp(n->type, "int") == 0)
            {
                codegen("istore %d\n", n->address);
            }
            else if(strcmp(n->type, "float") == 0)
            {
                codegen("fstore %d\n", n->address);
            }
            else if(strcmp(n->type, "string") == 0)
            {
                codegen("astore %d\n", n->address);
            }
            else if(strcmp(n->type, "bool") == 0)
            {
                codegen("istore %d\n", n->address);
            }
        }
    }
    | LIndexExpr assign_op Expression {
        if(strcmp($1, "int") == 0)
        {
            codegen("iastore\n");
        }
        else if(strcmp($1, "float") == 0)
        {
            codegen("fastore\n");
        }
    }
    | ConversionExpr assign_op Expression {
    }
    /* | Expression assign_op Expression {
        printf("Nani\n");
    } */
;

assign_op
    : ASSIGN { $$ = "assign"; }
    | ADD_ASSIGN { $$ = "add"; }
    | SUB_ASSIGN { $$ = "sub"; }
    | MUL_ASSIGN { $$ = "mul"; }
    | QUO_ASSIGN { $$ = "div"; }
    | REM_ASSIGN { $$ = "rem"; }
;

IncDecStmt
    : IncDecExpr SEMICOLON
;

IncDecExpr
    : IDENT INC { 
        node_t *n = lookup_symbol($1);
        if(n)
        {
            if(strcmp(n->type, "int") == 0)
            {
                codegen("iload %d\n", n->address);
                codegen("ldc 1\n"); 
                codegen("iadd\n"); 
                codegen("istore %d\n", n->address); 
            }
            else
            {
                codegen("fload %d\n", n->address);
                codegen("ldc 1.0\n"); 
                codegen("fadd\n"); 
                codegen("fstore %d\n", n->address); 
            }
        }
    }
    | IDENT DEC {
        node_t *n = lookup_symbol($1);
        if(n)
        {
            if(strcmp(n->type, "int") == 0)
            {
                codegen("iload %d\n", n->address);
                codegen("ldc 1\n"); 
                codegen("isub\n"); 
                codegen("istore %d\n", n->address); 
            }
            else
            {
                codegen("fload %d\n", n->address);
                codegen("ldc 1.0\n"); 
                codegen("fsub\n"); 
                codegen("fstore %d\n", n->address); 
            }
        }
    } 
    | Expression INC {  
        if(strcmp($1, "int") == 0)
        {
            codegen("ldc 1\n"); 
            codegen("iadd\n"); 
        }
        else
        {
            codegen("ldc 1.0\n"); 
            codegen("fadd\n"); 
        }
    }
    | Expression DEC { 
        if(strcmp($1, "int") == 0)
        {
            codegen("ldc 1\n"); 
            codegen("isub\n"); 
        }
        else
        {
            codegen("ldc 1.0\n"); 
            codegen("fsub\n"); 
        }
    }   
;

Block
    : Lbrace StatementList Rbrace
;

Lbrace
    : LBRACE { scope++; }
;

Rbrace
    : RBRACE { dump_symbol(); scope--; }
;

StatementList
    : Statement
;

If
    : IF{
        ++looplabels[scope];
        loopflag = 1;
    }
;

IfStmt
    : If LPAREN Condition Rparen Block {
        codegen("L_if_false%d:\n", looplabels[scope] + 10*scope);
    }
    | If LPAREN Condition Rparen Block Else IfStmt {
        codegen("L_if_exit:\n");
    }
    | If LPAREN Condition Rparen Block Else Block {
        codegen("L_if_exit:\n");
    }
;

Condition
    : Expression { error_check($1, $1, "condition"); }
;

Else
    : ELSE {
        codegen("goto L_if_exit\n");
        codegen("L_if_false%d:\n", looplabels[scope] + 10*scope);
    }
;

Rparen
    : RPAREN {
        symbol_table_t *s = find_symbol_table(scope);
        if(!s)
        {
            create_symbol(scope);
        }
        if(loopflag == 0)
        {
            codegen("ifeq L_for_exit%d\n", looplabels[scope] + 10*scope);
        }
        else
        {
            codegen("ifeq L_if_false%d\n", looplabels[scope] + 10*scope);
        }
    }
;

While
    : WHILE 
    {
        codegen("L_for_begin%d:\n", ++looplabels[scope] + 10*scope);
        loopflag = 0;
    }
;

WhileStmt
    : While LPAREN Condition Rparen Block {
        codegen("goto L_for_begin%d\n", looplabels[scope] + 10*scope);
        codegen("L_for_exit%d:\n", looplabels[scope] + 10*scope);
    }
;

For
    : FOR {
        // codegen("L_for_begin%d:\n", ++looplabels[scope] + 10*scope);
        // loopflag = 0;
    }
; 

LSemicolon
    : SEMICOLON {
        codegen("L_for_begin%d:\n", ++looplabels[scope] + 10*scope);
        loopflag = 0;
    }
;

RSemicolon
    : SEMICOLON {
        symbol_table_t *s = find_symbol_table(scope);
        if(!s)
        {
            create_symbol(scope);
        }
        codegen("ifeq L_for_exit%d\n", looplabels[scope] + 10*scope);
    }
;

IncDec
    : INC { $$ = "add"; }
    | DEC { $$ = "sub"; }
;

ForStmt
    : For LPAREN InitStmt LSemicolon Condition RSemicolon IDENT IncDec RPAREN Block {
        node_t *n = lookup_symbol($7);
        if(n)
        {
            if(strcmp(n->type, "int") == 0)
            {
                codegen("iload %d\n", n->address);
                codegen("ldc 1\n"); 
                codegen("i%s\n", $8); 
                codegen("istore %d\n", n->address); 
            }
            else
            {
                codegen("fload %d\n", n->address);
                codegen("ldc 1.0\n"); 
                codegen("f%s\n", $8); 
                codegen("fstore %d\n", n->address); 
            }
        }

        codegen("goto L_for_begin%d\n", looplabels[scope] + 10*scope);
        codegen("L_for_exit%d:\n", looplabels[scope] + 10*scope);
    }
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
    : PRINT LPAREN Expression RPAREN SEMICOLON {        
        char t = get_short_type($3);
        if(t == 'S')
        {
            codegen("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            codegen("swap\n");
            codegen("invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
        }
        else if(t == 'B')
        {
            codegen("ifne L_cmp_%d\n", ++cmplabel);
            codegen("ldc \"false\"\n");
            codegen("goto L_cmp_%d\nL_cmp_%d:\n", cmplabel+1, cmplabel);
            codegen("ldc \"true\"\nL_cmp_%d:\n", ++cmplabel);
            codegen("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            codegen("swap\n");
            codegen("invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
        }
        else
        {
            codegen("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            codegen("swap\n");
            codegen("invokevirtual java/io/PrintStream/print(%c)V\n", t);
        }
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

    /* Codegen output init */
    char *bytecode_filename = "hw3.j";
    fout = fopen(bytecode_filename, "w");
    codegen(".source hw3.j\n");
    codegen(".class public Main\n");
    codegen(".super java/lang/Object\n");
    codegen(".method public static main([Ljava/lang/String;)V\n");
    codegen(".limit stack 100\n");
    codegen(".limit locals 100\n");
    INDENT++;

    /* symbol table init */
    symbolTable = malloc(sizeof(symbol_table_t));
    symbolTable->scope = 0;
    symbolTable->index = 0;
    symbolTable->head = malloc(sizeof(node_t));
    symbolTable->next = NULL;

    yyparse();

    /* symbol table end */
    dump_symbol();

	printf("Total lines: %d\n", yylineno);

    /* Codegen end */
    codegen("return\n");
    INDENT--;
    codegen(".end method\n");
    fclose(fout);
    fclose(yyin);

    if (HAS_ERROR) {
        remove(bytecode_filename);
    }
    return 0;
}

/* symbol table function */
static symbol_table_t *create_symbol(int s)
{
    symbol_table_t *new_s, *curr = symbolTable;
    new_s = malloc(sizeof(symbol_table_t));
    new_s->scope = s;
    new_s->index = 0;
    new_s->head = malloc(sizeof(node_t));
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
        node_t *n = st->head->next;
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
            HAS_ERROR = true;
            return;
        }
    }

    //printf("> Insert {%s} into symbol table (scope level: %d)\n", name, scope);

    node_t *new_n = malloc(sizeof(node_t));
    new_n->index = st->index++;
    new_n->address = addr++;
    new_n->lineno = lineno;
    new_n->name = strdup(name);
    new_n->type = strdup(type);
    new_n->element = strdup(element);
    new_n->next = NULL;

    node_t *curr = st->head;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_n;

}

static node_t *lookup_symbol(char *name)
{
    int s = scope;
    do{
        symbol_table_t *st = find_symbol_table(s);
        if(!st)
        {
            continue;
        }

        node_t *curr = st->head->next;
        while(curr != NULL)
        {
            if(strcmp(name, curr->name) == 0)
            {
                //printf("IDENT (name=%s, address=%d)\n", curr->name, curr->address);
                return curr;
            }
            curr = curr->next;
        }
    } while(--s >= 0);

    printf("error:%d: undefined: %s\n", yylineno, name);
    HAS_ERROR = true;

    return NULL;
}

static void dump_symbol()
{
    symbol_table_t *st = find_symbol_table(scope);
    /* int s;
    if(st == NULL)
    {
        s = scope;
    }
    else 
    {
        s = st->scope;
    }
    printf("> Dump symbol table (scope level: %d)\n", s);
    printf("%-10s%-10s%-10s%-10s%-10s%s\n", "Index", "Name", "Type", "Address", "Lineno", "Element type"); */
    
    if(st == NULL)
    {
        return;
    }

    node_t *curr = st->head->next/*, *tmp*/;
    while(curr != NULL)
    {
        //printf("%-10d%-10s%-10s%-10d%-10d%s\n", curr->index, curr->name, curr->type, curr->address, curr->lineno, curr->element);
        //tmp = curr;
        curr = curr->next;
        //free(tmp);
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
    if(strcmp(type, "int") == 0 || strcmp(type, "intL") == 0) return 'I';
    if(strcmp(type, "float") == 0 || strcmp(type, "floatL") == 0) return 'F';
    if(strcmp(type, "string") == 0 || strcmp(type, "stringL") == 0) return 'S';
    if(strcmp(type, "bool") == 0 || strcmp(type, "boolL") == 0) return 'B';
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
            HAS_ERROR = true;
        }
        return;
    }

    if(strcmp(op, "REM") == 0)
    {
        if(strcmp(a, "int") != 0 || strcmp(b, "int") != 0)
        {
            printf("error:%d: invalid operation: (operator REM not defined on float)\n", yylineno);
            HAS_ERROR = true;
        }
        return;
    }

    if(strcmp(op, "AND") == 0 || strcmp(op, "OR") == 0 )
    {
        if(strcmp(a, "bool") != 0)
        {
            printf("error:%d: invalid operation: (operator %s not defined on %s)\n", yylineno, op, a);
            HAS_ERROR = true;
        }

        if(strcmp(b, "bool") != 0)
        {
            printf("error:%d: invalid operation: (operator %s not defined on %s)\n", yylineno, op, b);
            HAS_ERROR = true;
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
        HAS_ERROR = true;
    }
}