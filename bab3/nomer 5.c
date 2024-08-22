#include <stdio.h>

// Prototipe fungsi konversi
float konversi(float suhu, char asal, char tuj);

int main() {
    float suhu;
    char asal, tuj;

    // Meminta input dari pengguna
    printf("Masukkan suhu: ");
    scanf("%f", &suhu);

    printf("Satuan asal (C/F/R): ");
    scanf(" %c", &asal);

    printf("Satuan tujuan (C/F/R): ");
    scanf(" %c", &tuj);

    // Memanggil fungsi konversi dan menampilkan hasilnya
    float hasil = konversi(suhu, asal, tuj);
    printf("Hasil konversi: %.2f %c -> %.2f %c\n", suhu, asal, hasil, tuj);

    return 0;
}

// Implementasi fungsi konversi
float konversi(float suhu, char asal, char tuj) {
    if (asal == 'C' && tuj == 'F') {
        return (suhu * 9 / 5) + 32; // Celsius ke Fahrenheit
    } else if (asal == 'C' && tuj == 'R') {
        return suhu * 4 / 5; // Celsius ke Reamur
    } else if (asal == 'F' && tuj == 'C') {
        return (suhu - 32) * 5 / 9; // Fahrenheit ke Celsius
    } else if (asal == 'F' && tuj == 'R') {
        return (suhu - 32) * 4 / 9; // Fahrenheit ke Reamur
    } else if (asal == 'R' && tuj == 'C') {
        return suhu * 5 / 4; // Reamur ke Celsius
    } else if (asal == 'R' && tuj == 'F') {
        return (suhu * 9 / 4) + 32; // Reamur ke Fahrenheit
    } else {
        printf("Konversi tidak valid.\n");
        return 0;
    }
}
