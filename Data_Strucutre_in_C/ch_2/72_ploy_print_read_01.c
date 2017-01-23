/* Functions of print and read polynomial */

/* print the polynomial
 *
 * @terms: the polynomial terms array
 * @n: the number of terms want to print
 */
void poly_print(polynomial terms [], int n)
{
	int i;
	for (i = 0;i < n-1; i++)
		printf("%5.2fx^%d +", terms[i].coef, terms[i].expon);

	printf("%5.2fx^%d\n", terms[n-1].coef, terms[n-1].expon);
}

/* read the polynomial
 *
 * @terms: the polynomial terms array
 * @n: for saving the number of terms you want to input the polynomial array
 */
void poly_read(polynomial terms [], int *n)
{
	int i
        int expon;
	float coef;
	printf ("Enter the number of terms in your polynomial: ");
	scanf("%d", n);

	while (*n >= MAX_TERMS) {
		printf("Too many terms in the polynomial\n");
		printf("Number of terms: ");
		scanf("%d", n);
	}

	for (i= 0; i < *n; i++) {
		printf("Coefficient: ");
		scanf("%f", &coef);
		printf("Exponent: ");
		scanf("%d", &expon);
		terms[i].coef = coef;
		terms[i].expon = expon;
	}
}
