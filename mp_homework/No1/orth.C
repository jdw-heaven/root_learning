#include<stdio.h>
#include<math.h>

const int N = 3;

int orth(void)
{
    //make the vectors as columns in A
    double A[N*N] = {1,-0.2,0.1,0.1,1,0.1,0.2,0.05,1};
    double I[N*N] = {0,};
    double up = 0;
    double down = 0;
    double mod = 0;
    //Schmidt orthogonalisation
    for(int i=1; i<N; i++)
    {
        for(int j=0; j<i; j++)
        {
            up = 0;
            down = 0;
            for(int k=0; k<N; k++)
            {
                up += A[k*N+i]*A[k*N+j];
                down += A[k*N+j]*A[k*N+j];
            }
            for(int l=0; l<N; l++)
            {
                A[l*N+i] = A[l*N+i]-up*A[l*N+j]/down;
            }
        }
    }

    //normalize
    for(int i=0; i<N; i++)
    {
        mod = 0;
        for(int j=0; j<N; j++)
        {
            mod += A[j*N+i]*A[j*N+i];
        }
        mod = sqrt(mod);
        for(int k=0; k<N; k++)
        {
            A[k*N+i] = A[k*N+i]/mod;
        }
    }

    //output
    printf("the orthogonal noemalization of given vectors is:(as columns)\n");
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            printf("%3.4lf  ", A[i*N+j]);
        }
        printf("\n");
    }

    //check:
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            for(int k=0; k<N; k++)
            {
                I[i*N+k] += A[j*N+i]*A[j*N+k];
            }
        }
    }

    printf("check:(the output should be unit)\n");
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            printf("%3.4lf  ", I[i*N+j]);
        }
        printf("\n");
    }

    return 0;
}