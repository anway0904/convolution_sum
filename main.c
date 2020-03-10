/* ANWAY SHIRGAONKAR
SY INSTRUMENTATION AND CONTROL
B 77 */

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, k, L, M, i, j;
    int sum = 0, index_h, index_x;
    int zeroth_index_x, zeroth_index_h;

    printf("Enter length of impulse response signal h(n): ");
    scanf("%d", &M);

    printf("\nEnter length of input signal x(n): ");
    scanf("%d", &L);

    n = L+M-1; //Total length of output signal.
    int y[n]; //Output Signal.
    int x[L], h[M]; //x is the arbitrary input signal, while h is the impulse response signal.

    //accepting values of discrete time signals from the user.
    printf("\nEnter input signal array x(n): ");
    for(i=0 ; i<L ; i++)
    {
        scanf("%d", &x[i]);
    }
    printf("\nEnter index of the zeroth position element of x(n): ");
    scanf("%d", &zeroth_index_x);

    printf("\nEnter impulse response signal array h(n): ");
    for(i=0 ; i<M ; i++)
    {
        scanf("%d", &h[i]);
    }
    printf("\nEnter index of the zeroth position element of h(n): ");
    scanf("%d", &zeroth_index_h);

    //The Convolution Sum of signals.
    for(i=0 ; i<n ; i++)
    {
        for(j=0-zeroth_index_x ; j<(L-zeroth_index_x) ; j++) //j will vary for entire length of x[n].
        {
            index_h = zeroth_index_h + (i - j); // index_h is the actual index of array
            index_x = zeroth_index_x + j; // index_x is the actual index of array
            if(M > index_h && 0<=index_h)
            {
                sum += x[index_x]*h[index_h];
            }
        }
        y[i] = sum;
        sum  = 0;
    }
    printf("\nThe output signal is y(n) = ");
    for(k=0 ; k<n ; k++)
    {
        printf("%d ", y[k]);
    }
    return 0;
}
