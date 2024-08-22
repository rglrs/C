#include <stdio.h>
#include <stdlib.h>

main()
{
    char letter;
    int sum, valid_flag;
    printf("Input huruf :");
    scanf("%c", &letter);

    switch (letter)
    {
    case 'X':
        sum = 0;
        break;
    case 'Z':
        valid_flag = 1;
        break;
    case 'A':
        sum = 1;
        break;
    default:
        printf("Unknown letter -->%c\n", letter);
    }
}