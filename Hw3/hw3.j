.source hw3.j
.class public Main
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
.limit stack 100
.limit locals 100
	ldc 0
	istore 0
	ldc 0
	istore 0
	L_for_begin1:
	iload 0
	ldc 10
	isub
	iflt L_cmp_1
	iconst_0
	goto L_cmp_2
L_cmp_1:
	iconst_1
L_cmp_2:
	ifeq L_for_exit1
	iload 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	iload 0
	ldc 1
	iadd
	istore 0
	goto L_for_begin1
	L_for_exit1:
	ldc "\n"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	ldc 1
	istore 0
	L_for_begin2:
	iload 0
	ldc 0
	isub
	ifgt L_cmp_3
	iconst_0
	goto L_cmp_4
L_cmp_3:
	iconst_1
L_cmp_4:
	ifeq L_for_exit2
	iload 0
	ldc 1
	isub
	istore 0
	ldc 3
	newarray int
	astore 1
	aload 1
	ldc 0
	ldc 1
	ldc 21
	iadd
	iastore
	aload 1
	ldc 1
	aload 1
	ldc 0
	iaload
	ldc 1
	isub
	iastore
	aload 1
	ldc 2
	aload 1
	ldc 1
	iaload
	ldc 3
	idiv
	iastore
	aload 1
	ldc 2
	iaload
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	ldc "\n"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	ldc 3
	ldc 4
	ldc 5
	ldc 8
	ineg
	iadd
	imul
	isub
	ldc 10
	ldc 7
	idiv
	isub
	ldc 4
	ineg
	ldc 3
	irem
	isub
	ifgt L_cmp_5
	iconst_0
	goto L_cmp_6
L_cmp_5:
	iconst_1
L_cmp_6:
	iconst_1
	iconst_1
	ixor
	iconst_0
	iconst_1
	ixor
	iconst_1
	ixor
	iand
	ior
	ifne L_cmp_7
	ldc "false"
	goto L_cmp_8
L_cmp_7:
	ldc "true"
L_cmp_8:
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	ldc "\n"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	ldc 3
	newarray float
	astore 2
	aload 2
	ldc 0
	ldc 1.100000
	ldc 2.100000
	fadd
	fastore
	aload 2
	ldc 0
	faload
	f2i
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	ldc "\n"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	goto L_for_begin2
	L_for_exit2:
	ldc 0
	istore 3
	iload 3
	ldc 10
	iadd
	istore 3
	L_for_begin3:
	iload 3
	ldc 0
	isub
	ifgt L_cmp_9
	iconst_0
	goto L_cmp_10
L_cmp_9:
	iconst_1
L_cmp_10:
	ifeq L_for_exit3
	iload 3
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	ldc "\t"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	iload 3
	ldc 1
	isub
	istore 3
	iload 3
	ldc 0
	isub
	ifne L_cmp_11
	iconst_0
	goto L_cmp_12
L_cmp_11:
	iconst_1
L_cmp_12:
	ifeq L_if_false11
	ldc 3.140000
	fstore 4
	fload 4
	f2i
	iload 3
	iadd
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	goto L_if_exit
	L_if_false11:
	ldc 6.600000
	fstore 5
	ldc "If x == "
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	ldc 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	fload 5
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(F)V
	L_if_exit:
	ldc 1
	istore 6
	L_for_begin12:
	iload 6
	ldc 3
	isub
	ifle L_cmp_13
	iconst_0
	goto L_cmp_14
L_cmp_13:
	iconst_1
L_cmp_14:
	ifeq L_for_exit12
	ldc "\t"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	iload 3
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	ldc "*"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	iload 6
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	ldc "="
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	iload 3
	iload 6
	imul
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	ldc "\t"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	iload 6
	ldc 1
	iadd
	istore 6
	goto L_for_begin12
	L_for_exit12:
	ldc "\n"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	goto L_for_begin3
	L_for_exit3:
	return
.end method
