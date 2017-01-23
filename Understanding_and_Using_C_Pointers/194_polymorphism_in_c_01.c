/* Polymorphism in C */

// Using C to do a implementation of object-oriented language such as C++.

#include <stdio.h>
#include <stdlib.h>

typedef void (*f_ptr_set) (void *, int );
typedef int (*f_ptr_get) (void *);
typedef void (*f_ptr_display) ();

typedef struct _functions
{
	f_ptr_set set_x;
	f_ptr_set set_y;
	f_ptr_get get_x;
	f_ptr_get get_y;
	f_ptr_display display;
}virtual_functions;




typedef struct _shape
{
	virtual_functions functions;

	// base variables
	int _x;
	int _y;
}shape;


void shape_display()
{
	printf("shape\n");
}

void shape_set_x(shape *s, int x)
{
	s -> _x = x;
}

void shape_set_y(shape *s, int y)
{
	s -> _y = y;
}

int shape_get_x(shape *s)
{
	return s -> _x;
}

int shape_get_y(shape *s)
{
	return s -> _y;
}

shape * get_shape_object()
{
	shape *s = (shape *) malloc (sizeof(shape));

	s -> functions.set_x = (f_ptr_set) shape_set_x;
	s -> functions.set_y = (f_ptr_set) shape_set_y;
	s -> functions.get_x = (f_ptr_get) shape_get_x;
	s -> functions.get_y = (f_ptr_get) shape_get_y;
	s -> functions.display = (f_ptr_display) shape_display;

	s -> _x = 100;
	s -> _y = 100;

	return s;
}


int main()
{

	shape *s_ptr = get_shape_object();
	s_ptr -> functions.set_x(s_ptr, 35);
	s_ptr -> functions.display();

	printf("%d\n", s_ptr -> functions.get_x(s_ptr));

	free(s_ptr);

	return 0;
}
