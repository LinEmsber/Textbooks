/* Misusing the sizeof operator */


	int i;
	int buffer[20];
	int *buffer_ptr = buffer;


	// The sizeof(buffer) expression returns 80, since the size of the buffer
	// in bytes is 80(20 multiplied by 4 byte elements.)


	// wrong.

	for(i = 0; i < sizeof(buffer); i++){
		*(buffer_ptr) = 0;
	}


	// correct.

	int buffer_size = sizeof(buffer) / sizeof(int);
	for(i = 0; i < buffer_size; i++){
		*(buffer_ptr) = 0;
	}
