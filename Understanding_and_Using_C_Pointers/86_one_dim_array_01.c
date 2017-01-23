/* Using malloc to create a one-dim array */


int main()
{
	int i;
	int *pv = (int *) malloc(5 * sizeof(int));

	for (i=0; i<5; i++){

		// method 1
		pv[i] = i + 1;

		// method 2
		*(pv + i) = i + 1;

	}

	return 0;
}
