/* Ackermann function */

#include <stdio.h>


int Ackermann( int m, int n )
{
	if ( m == 0 )
		return n + 1;
	else if ( m > 0 && n == 0 )
		return Ackermann(m - 1, 1);
	else if ( m > 0 && n > 0)
		return Ackermann( m - 1, Ackermann(m, n - 1) );
}


int main()
{
        int m, n;
        for (m = 0; m <= 4; m++)
                for (n = 0; n < 6 - m; n++)
                        printf("A(%d, %d) = %d\n", m, n, Ackermann(m, n));

        return 0;
}
