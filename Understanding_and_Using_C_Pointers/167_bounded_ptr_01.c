/* Bounded pointers */

// C does not provide any direct support for address checking, but we can
// do it by ourself.


#define SIZE 32

int main()
{

	char name[SIZE];
	char *p = name;

	if(p >= name && p < name+SIZE){
		// valid pointer, correct condition
	}else{
		// invalid pointer, error condition
	}


}
