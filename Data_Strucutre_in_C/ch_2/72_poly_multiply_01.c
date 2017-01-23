/* multiply two polynomial
 *
 * @a: the poly a
 * @b: the poly b
 * @c: the poly save ploy a multiply ploy b
 * @na: the number of poly a term
 * @nb: the number of poly b term
 * @nc: the number of poly c term
 */
void pmult(polynomial a [] , polynomial b [], polynomial c [], int na, int nb, int *nc)
{
        int i, j;
        *nc = 0;

        for (i = 0; i < na; i++)
                for (j = 0; j < nb; j++) {
                        c[*nc].coef = a[i].coef * b[j].coef;
                        c[(*nc)++].expon = a[i].expon + b[j].expon;
                }
        }
}
