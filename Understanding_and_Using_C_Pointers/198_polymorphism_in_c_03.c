/* Polymorphism in C */

// Using C to do a implementation of object-oriented language such as C++.

#include <stdio.h>
#include <stdlib.h>

// function pointer
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


// =====shape=====
typedef struct _shape
{
	virtual_functions functions;

	// base variables
	int x;
	int y;
}shape;

void shape_display()
{
	printf("shape\n");
}

void shape_set_x(shape *s, int x)
{
	s -> x = x;
}

void shape_set_y(shape *s, int y)
{
	s -> y = y;
}

int shape_get_x(shape *s)
{
	return s -> x;
}

int shape_get_y(shape *s)
{
	return s -> y;
}

shape *get_shape_object()
{
	shape *s = (shape *) malloc (sizeof(shape));

	s -> functions.set_x = (f_ptr_set) shape_set_x;
	s -> functions.set_y = (f_ptr_set) shape_set_y;
	s -> functions.get_x = (f_ptr_get) shape_get_x;
	s -> functions.get_y = (f_ptr_get) shape_get_y;
	s -> functions.display = shape_display;

	s -> x = 100;
	s -> y = 100;

	return s;
}
// =====shape=====

// =====rectangle=====
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

	r -> base.functions.set_x = (f_ptr_set) rectangle_set_x;
	r -> base.functions.set_y = (f_ptr_set) rectangle_set_y;
	r -> base.functions.get_x = (f_ptr_get) rectangle_get_x;
	r -> base.functions.get_y = (f_ptr_get) rectangle_get_y;
	r -> base.functions.display = rectangle_display;

	r -> base.x = 100;
	r -> base.y = 100;

	r -> width = 500;
	r -> height = 300;

	return r;
}
// =====rectangle=====


int main()
{

	int i ;
	shape *s[3];

	s[0] = get_shape_object();
	s[0] -> functions.set_x(s[0], 35);
	s[1] = (shape *) get_rectangle_object();
	s[1] -> functions.set_x(s[1], 45);
	s[2] = (shape *) get_rectangle_object();
	s[2] -> functions.set_x(s[2], 55);

	for (i=0; i<3; i++){
		s[i] -> functions.display();
		printf("%d\n", s[i] -> functions.get_x(s[i]) );
	}

	return 0;
}
