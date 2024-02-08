#include <stdio.h>

int main()
{
    float a = 20.8, *p, b = 15.7, *q;
    p = &a; q = &b;
    printf("a = %f;b = %f;\n",a, b);
    printf("p = &a = %ld; q = &b = %ld;\n", p, q);
    printf("&p = %ld; &q = %ld;\n", &p, &q);
    printf("a = %f; *p = %f;\n", a, *p);
    printf("b = %f; *q = %f;\n", b, *q);
    *q = *p + 2;
    printf("a = %f; *p = %f;\n", a, *p);
    printf("b = %f; *q = %f;\n", b, *q);
    p = q;
    printf("a = %f; *p = %f;\n", a,*p);
    printf("b = %f; *q = %f\n", b, *q);

    return 0;
}