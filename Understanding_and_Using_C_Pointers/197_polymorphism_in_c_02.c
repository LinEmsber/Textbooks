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
	int x;
	int y;
}shape;

typedef struct _rectangle
{
	shape base;
	int width;
	int height;
}rectangle;


void rectangle_display()
{
	printf("rectangle\n");
}

void rectangle_set_x(rectangle *r, int x)
{
	r -> base.x = x;
}

void rectangle_set_y(rectangle *r, int y)
{
	r -> base.y = y;
}

int rectangle_get_x(rectangle *r)
{
	return r -> base.x;
}

int rectangle_get_y(rectangle *r)
{
	return r -> base.y;
}

rectangle *get_rectangle_object()
{
	rectangle *r = (rectangle *) malloc (sizeof(rectangle));

	r -> base.functions.set_x = (f_ptr_set)rectangle_set_x;
	r -> base.functions.set_y = (f_ptr_set)rectangle_set_y;
	r -> base.functions.get_x = (f_ptr_get)rectangle_get_x;
	r -> base.functions.get_y = (f_ptr_get)rectangle_get_y;
	r -> base.functions.display = rectangle_display;

	r -> base.x = 100;
	r -> base.y = 100;

	r -> width = 500;
	r -> height = 300;

	return r;
}


int main()
{

	rectangle *r_ptr = get_rectangle_object();
	r_ptr -> base.functions.set_x(r_ptr, 35);
	r_ptr -> base.functions.display();

	printf("%d\n", r_ptr -> base.functions.get_x(r_ptr));

	return 0;
}
