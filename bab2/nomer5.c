#include <stdio.h>

int main()
{
    int a,n;

    printf("Masukkan nilai n: ");
    scanf("%d", &n);

    for (int a = 1; a <= n*2; a++)
    {
        if (a % 2 != 0)
        {
            printf("%d", a);
        }
        
    }

    printf("\n");

    return 0;
}