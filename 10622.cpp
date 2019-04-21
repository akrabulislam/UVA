#include <bits/stdc++.h>
using namespace std;

long long powerUp (int i, int p)
{
    long long sum = i;
    for ( int k = 2; k <= p; k++ ) {
        sum *= i;
    }

    return sum;
}
int main ()
{
    double n;

    while ( scanf ("%lf", &n) && n ) {

        bool printed = false;
        int length;

        if ( n < 0 ) {
            length = sqrt (n * -1);
            for ( int i = -2; i >= -length; i-- ) {
                long long ans = i;
                int p = 2;
                while ( ans > n ) {
                    ans = powerUp (i, p);
                    p++;
                }
                if ( ans == n ) {
                    printf ("%d\n", p - 1);
                    printed = true;
                    break;
                }
            }

            if ( !printed )
                printf ("1\n");
        }
        else {
            length = sqrt (n);
            for ( int i = 2; i <= length; i++ ) {
                long long ans = i;
                int p = 2;
                while ( ans < n ) {
                    ans = powerUp (i, p);
                    p++;
                }
                if ( ans == n ) {
                    printf ("%d\n", p - 1);
                    printed = true;
                    break;
                }
            }

            if ( !printed ) printf ("1\n");
        }

        //printf ("%d\n", power);

    }

    return 0;
}
