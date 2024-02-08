#include <stdio.h>

#define MAX_PROGRAMS 1000

int main() 
{
    int installed_versions[MAX_PROGRAMS] = {0};
    int available_versions[MAX_PROGRAMS] = {0};
    int C, N, Pc, Vc, Pn, Vn;

    scanf("%d %d", &C, &N);

    for(int i = 0; i< C; i++)
    {
        scanf("%d %d", &Pc, &Vc);
        installed_versions[Pc] = Vc;

    }

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &Pn, &Vn);
        if (Vn > available_versions[Pn])
        {
            available_versions[Pn] = Vn;
        }
    }
    for (int i = 0; i < MAX_PROGRAMS; i++)
    {
        if (available_versions[i] > installed_versions[i])
        {
            printf("%d %d\n", i, available_versions[i]);
        }

    return 0;
    }
}