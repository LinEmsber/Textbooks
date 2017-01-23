/* Sharing pointers between threads */


#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <pthread.h>

#define NUM_THREADS 4

// =====typedef=====
typedef struct _vector_info vector_info_t;
struct _vector_info{
	double *vector_a;
	double *vector_b;
	double sum;
	int length;
};

typedef struct _product product_t;
struct _product{
	vector_info_t *info;
	int begin_index;
};


// =====global variable mutex=====
pthread_mutex_t mutex;

// =====function=====
void dot_product(void *prod)
{
	int i;

	product_t *p = (product_t *)prod;
	vector_info_t *v = p -> info;
	int begin_index = p -> begin_index;
	int end_index = begin_index + v -> length;
	double total = 0;

	for (i = 0; i < end_index; i++){
		total += ( v->vector_a[i] * v->vector_b[i] );
	}

	pthread_mutex_lock(&mutex);
	v -> sum += total;
	pthread_mutex_unlock(&mutex);


	// pthread_exit is called from the thread itself to terminate its
	// execution (and return a result) early.
	pthread_exit( (void *) 0);
}




int main()
{
	int i;
	int return_number;

	// vector info
	vector_info_t v;
	double vector_a[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0,
				9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0};
	double vector_b[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0,
				9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0};
	double sum;

	v.vector_a = vector_a;
	v.vector_b = vector_b;
	v.length = 4;


	// threads id
	pthread_t threads[NUM_THREADS];

	// return status for pthread_join
	void *status;

	// thread attr
	pthread_attr_t attr;

	pthread_mutex_init(&mutex, NULL);
	pthread_attr_init(&attr);

	// Threads that are created using attr will be created in a joinable state.
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);


	for (i = 0; i < NUM_THREADS; i++){

		//memory allocated
		product_t *p = (product_t *) malloc( sizeof(product_t) );

		// each thread calculate 4 elements of vector_a and vector_b.
		p -> begin_index = i*4;

		// each dot_product_t struct include the entire vector info
		p -> info = &v;

		// int pthread_create(pthread_t *restrict thread, const pthread_attr_t *restrict attr,
		// 				void *(*start_routine)(void*), void *restrict arg);
		// If successful, the pthread_create() function shall return zero.
		return_number = pthread_create( &threads[i], &attr, dot_product, (void *) p);

		if (return_number){
			perror("pthread_create");
		}
	}

	// When a thread attributes object is no longer required, it should be destroyed using
	// the pthread_attr_destroy() function.
	//
	// Destroying a thread attributes object has no effect on threads that were created
	// using that object.
	pthread_attr_destroy(&attr);


	// pthread_join is called from another thread (usually the thread that created it) to wait for
	// a thread to terminate and obtain its return value. It can be called before or after the thread
	// you're waiting for calls pthread_exit.
	//
	// If before, it will wait for the exit to occur.
	//
	// If after, it simply obtains the return value and releases the pthread_t resources.
	for ( i = 0; i < NUM_THREADS; i++){
		pthread_join(threads[i], &status);
	}

	pthread_mutex_destroy(&mutex);

	printf("dot product sum: %lf\n", v.sum);

	return 0;
}
