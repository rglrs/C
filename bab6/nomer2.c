#include <stdio.h>
#include <string.h>

// Fungsi untuk menghitung panjang string
int pjgstr(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int main() {
    char inputString[100];  // Anda dapat menyesuaikan panjang string maksimum
    printf("Masukkan sebuah string: ");
    fgets(inputString, sizeof(inputString), stdin);

    // Menghilangkan karakter newline ('\n') jika ditemukan
    size_t inputLength = strlen(inputString);
    if (inputLength > 0 && inputString[inputLength - 1] == '\n') {
        inputString[inputLength - 1] = '\0';
    }

    int panjang = pjgstr(inputString);
    printf("Panjang string adalah: %d karakter\n", panjang);

    return 0;
}
