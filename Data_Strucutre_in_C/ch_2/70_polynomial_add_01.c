/* Function to add two polynomial */

#define COMPARE(x, y)   ( ( (x) < (y) ) ? -1 : ( (x) == (y) ? 0 : 1 ) )

// size of terms array
#define MAX_TERMS 100

// structure
typedef struct _polynomial polynomial;
struct _polynomial
{
        float coef;
        int expon;
};

polynomial terms[MAX_TERMS];
// The index of the next free location in the array is given by avail.
int avail = 0;

/* add a new term to the polynomial */
void attach(float coefficient, int exponent)
{
        if (avail >= MAX_TERMS){
                fprintf(stderr, "Too many terms in the polynomial\n");
                exit(EXIT_FAILURE);
        }
        term[avail].coef = coefficient;
        terms[avail++].expon = exponent;
}


void poly_add(int start_a, int finish_a, int start_b, int finish_b, int *start_c, int *finish_c)
{
        float coefficient;
        *start_c = avail;

        while (start_a <= finish_a && start_b <= finish_b){

                switch (COMPARE(terms[start_a].expon, terms[start_b].expon)){

                        // a expon < b expon
                        case -1:
                                attach(terms[start_b].coef, terms[start_b].expon);
                                start_b++;
                                break;

                        // equal expon
                        case 0:
                                coefficient = terms[start_a].coef + terms[start_b].coef;
                                if(coefficient)
                                        attach(coefficient, terms[start_a].expon);

                                start_a++;
                                start_b++;
                                break;

                        // a expon > b expon
                        case 1:
                                attach(terms[start_a].coef, terms[start_a].expon);
                                start_a++;
                                break;
                }
        }

        // add in remaining terms of A(x)
        for (; start_a <= finish_a; start_a++){
                attach(terms[start_a].coef, terms[start_a].expon);
        }

        // add in remaining terms of B(x)
        for (; start_b <= finish_b; start_b++){
                attach(terms[start_b].coef, terms[start_b].expon);
        }

        *finish_c = avail -1;
}
