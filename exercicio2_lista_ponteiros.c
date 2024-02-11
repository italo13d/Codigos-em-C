#include <stdio.h>

int main ()
{
    double *p, *q, *r, A[5] = {1.2,6.5,73.34,18, 0.1};
    p = A; q = p+1; r = p+2;


    printf("p = %ld; &A[0] = %ld;\n", p, &A[0]);

    printf("q = %ld; &A[1] = %ld;\n", q, &A[1]);

    printf("r = %ld; &A[2] = %ld;\n", r, &A[2]);

    printf("A[0] = %lf; &A[1] = %lf; &A[2] = %lf \n", A[0], A[1], A[2]);

    printf("*p = %lf; *q = %lf; *r = %lf\n", *p, *q, *r);

    printf("q-p = %ld; r-p = %ld;\n", q-p, r-p);  

    double **s; r++; q=q+2; s=&q;

    printf("*A[3] =  %lf; &A[4] = %lf; *r = %lf \n", **s, *(r+1));   
    
    return 0;
}