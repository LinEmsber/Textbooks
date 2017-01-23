/* 75 passing function pointers */

int add (int n1, int n2)
{
	return n1 + n2;
}

int sub(int n1, int n2)
{
	return n1 - n2;
}

typedef int (*f_ptr_operation) (int, int);

int compute(f_ptr_operation, int n1, int n2)
{
	return operation(n1, n2);
}


int main()
{
	printf("%d\n", computer(add, 5, 6));
	printf("%d\n", computer(sub, 5, 6));
}
