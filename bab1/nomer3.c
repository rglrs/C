#include <stdio.h>

int main() {
    int choice;
    float input,result,tinggi;

    printf("Menu:\n");
    printf("1. Menghitung volume kubus\n");
    printf("2. Menghitung luas lingkaran\n");
    printf("3. Menghitung volume silinder\n");
    printf("Pilihan Anda: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
                printf("Masukkan panjang sisi kubus: ");
                scanf("%f", &input);
                result = input * input * input; // Volume kubus
                printf("Volume kubus: %.2f\n", result);
            break;
        case 2:
                printf("Masukkan panjang jari-jari lingkaran: ");
                scanf("%f", &input);
                result = 3.14 * input * input; // Luas lingkaran
                printf("Luas lingkaran: %.2f\n", result);
            break;
        case 3:
                printf("Masukkan panjang jari-jari lingkaran: ");
                scanf("%f", &input);
                printf("Masukkan tinggi silinder: ");
                scanf("%f", &tinggi);
                result = 3.14 * input * input * tinggi; // Volume silinder
                printf("Volume silinder: %.2f\n", result);
            break;
        default:
            printf("Pilihan tidak valid. Silakan pilih 1, 2, atau 3.\n");
            break;
    }

    return 0;
}