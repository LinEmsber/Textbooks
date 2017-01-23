/* evaluate a polynomial at the specific value of x */

#include <math.h>

double poly_eval(polynomial terms[], float x, int n)
{
        int i;
        float answer = 0;

        for(i = 0; i < n; i++)
                answer = answer + terms[i].coef * pow(x, terms[i].expon);

        return answer;
}
