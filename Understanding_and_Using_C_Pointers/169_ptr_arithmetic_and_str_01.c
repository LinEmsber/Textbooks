/* pointer arithmetic and structures */

// If the address of ptr start at 100.
// The ptr becomes 110, which is the address of the two bytes found
// between the two fields.



//		 ____ ____ ____ ____
//	 	|    |    |    |    |
//	name 100|____|____|____|____|
//		|    |    |    |    |
//	     104|____|____|____|____|
//		|    |    | XX | XX |
//	     108|____|____|_XX_|_XX_|
//		|    |    |    |    |
//	age  112|____|____|____|____|
//
//	xx
//	xx: not used address



typedef struct _employee{
	char name[10];
	int age;
} Employee;

Employee employee;

//Initialize employee
char *ptr = employee.name;
ptr = ptr + sizeof(employee.name);
