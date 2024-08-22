#include <stdio.h>

// Prototype fungsi
int cariBilanganTerbesar(int bil1, int bil2);

int main() {
    int angka1, angka2;

    // Meminta pengguna memasukkan dua bilangan
    printf("Masukkan dua bilangan: ");
    scanf("%d %d", &angka1, &angka2);

    // Memanggil fungsi untuk menentukan bilangan terbesar
    int terbesar = cariBilanganTerbesar(angka1, angka2);

    // Menampilkan bilangan terbesar
    printf("Bilangan terbesar adalah: %d\n", terbesar);

    return 0;
}

// Implementasi fungsi untuk mencari bilangan terbesar
int cariBilanganTerbesar(int bil1, int bil2) {
    if (bil1 > bil2) {
        return bil1;
    } else {
        return bil2;
    }
}
