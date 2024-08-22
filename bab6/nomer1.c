#include <stdio.h>

int main() {
    char str[100];
    printf("Masukkan sebuah string: ");
    fgets(str, sizeof(str), stdin);
    printf("Anda memasukkan: %s\n", str);
    return 0;
}
