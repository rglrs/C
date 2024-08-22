#include <stdio.h>

// Definisi struktur untuk bilangan kompleks
typedef struct {
    float real; // Bagian real
    float imag; // Bagian imajiner
} Complex;

// Fungsi untuk menampilkan bilangan kompleks
void tampilcomplex(Complex num) {
    printf("%.2f + %.2fi\n", num.real, num.imag);
}

// Fungsi untuk menjumlahkan dua bilangan kompleks
Complex tambah(Complex A, Complex B) {
    Complex hasil;
    hasil.real = A.real + B.real;
    hasil.imag = A.imag + B.imag;
    return hasil;
}

// Fungsi untuk mengurangkan dua bilangan kompleks
Complex kurang(Complex A, Complex B) {
    Complex hasil;
    hasil.real = A.real - B.real;
    hasil.imag = A.imag - B.imag;
    return hasil;
}

// Fungsi untuk mengalikan dua bilangan kompleks
Complex kali(Complex A, Complex B) {
    Complex hasil;
    hasil.real = A.real * B.real - A.imag * B.imag;
    hasil.imag = A.real * B.imag + A.imag * B.real;
    return hasil;
}

// Fungsi untuk membagi dua bilangan kompleks
Complex bagi(Complex A, Complex B) {
    Complex hasil;
    float penyebut = B.real * B.real + B.imag * B.imag;
    hasil.real = (A.real * B.real + A.imag * B.imag) / penyebut;
    hasil.imag = (A.imag * B.real - A.real * B.imag) / penyebut;
    return hasil;
}

int main() {
    Complex A, B, hasil;

    // Input bilangan kompleks pertama
    printf("Masukkan bagian real bilangan kompleks pertama: ");
    scanf("%f", &A.real);
    printf("Masukkan bagian imajiner bilangan kompleks pertama: ");
    scanf("%f", &A.imag);

    // Input bilangan kompleks kedua
    printf("Masukkan bagian real bilangan kompleks kedua: ");
    scanf("%f", &B.real);
    printf("Masukkan bagian imajiner bilangan kompleks kedua: ");
    scanf("%f", &B.imag);

    // Penjumlahan
    hasil = tambah(A, B);
    printf("Penjumlahan: ");
    tampilcomplex(hasil);

    // Pengurangan
    hasil = kurang(A, B);
    printf("Pengurangan: ");
    tampilcomplex(hasil);

    // Perkalian
    hasil = kali(A, B);
    printf("Perkalian: ");
    tampilcomplex(hasil);

    // Pembagian
    hasil = bagi(A, B);
    printf("Pembagian: ");
    tampilcomplex(hasil);

    return 0;
}
