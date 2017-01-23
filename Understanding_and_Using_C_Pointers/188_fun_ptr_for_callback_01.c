/* Using function pointers to support callbacks */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>

struct factorial_data
{
	int number;
	int result;
	void (*callback) (struct factorial_data *);
};


void *factorial (void *argvs)
{

	// function prototype
	void (*callback)(struct factorial_data *);

	int i;
	int sum = 1;
	struct factorial_data *f_data = (struct factorial_data *) argvs;

	int number = f_data -> number;
	callback = f_data -> callback;

	for ( i = 1; i <= number; i++){
		sum *= i;
	}

	f_data -> result = sum;
	callback(f_data);

	pthread_exit(NULL);
}


void start_thread(struct factorial_data *data)
{
	int thread;
	pthread_t tid;

	thread = pthread_create(&tid, NULL, &factorial, (void *)data);
}

void callback_function(struct factorial_data *data)
{
	printf("Factorial: %d\n", data -> result);
}


int main()
{

	struct factorial_data *data = (struct factorial_data *) malloc ( sizeof(struct factorial_data) );
	if(!data){
		perror("malloc");
	}

	data->number = 5;
	data->callback = callback_function;

	start_thread(data);

	sleep(1);

	return 0;
}
