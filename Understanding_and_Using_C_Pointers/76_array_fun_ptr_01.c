/* 76 array of function pointers */

#include <stdio.h>

int add (int n1, int n2)
{
	return n1 + n2;
}

int sub(int n1, int n2)
{
	return n1 - n2;
}


typedef int (*fun_ptr_operation) (int, int);
fun_ptr_operation operations[128] = {NULL};

// declare this array without ising a typedef as shown below:
// int (*operation[128]) (int, int) = {NULL};


void init_operation_arr()
{
	operations['+'] = add;
	operations['-'] = sub;
}


// using the operation character as an index
int evaluate_arr( char op_char, int n1, int n2)
{
	fun_ptr_operation op;
	op = operations[ op_char ];
	return op(n1, n2);
}

int main()
{
	init_operation_arr();

	printf("%d\n", evaluate_arr('+', 25, 10) );
	printf("%d\n", evaluate_arr('-', 25, 10) );

	return 0;
}
