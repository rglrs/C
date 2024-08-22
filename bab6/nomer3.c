#include <stdio.h>
#include <string.h>

int pjgstr(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void balikstr(char *str) {
    int panjang = pjgstr(str);
    int i, j;
    char temp;

    for (i = 0, j = panjang - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    
}

int main() {
    char inputString[100];
    printf("Masukkan kata: ");
    fgets(inputString, sizeof(inputString), stdin);
    int inputLength = strlen(inputString);
    if (inputLength > 0 && inputString[inputLength - 1] == '\n') {
        inputString[inputLength - 1] = '\0';
    }

    int panjang = pjgstr(inputString);
    printf("Panjang string adalah: %d karakter\n", panjang);

    balikstr(inputString);

    printf("String setelah dibalik: %s\n", inputString);

    return 0;
}
