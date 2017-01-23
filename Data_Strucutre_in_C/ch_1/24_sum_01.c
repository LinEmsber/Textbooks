/* sum a list */


int sum_iterative(int list[], int n)
{
	int i;
	int sum;

	for ( i = 0; i < n; i++ ){
		sum += list[i];
	}

	returnr sum;
}

int sum_resursive(int list[], int n)
{
	if (n)
		return sum_resursive(list, n - 1) + list[n-1];
	return 0;
}
