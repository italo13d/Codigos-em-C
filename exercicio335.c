#include <stdio.h>
#include <math.h>

int main ()
{
    int Xm, Ym, Xr, Yr;
    scanf("%d %d %d %d", &Xm, &Ym, &Xr, &Yr);
    int dist = abs(Xr - Xm) + abs(Yr - Ym);
    printf("%d\n", dist);

}