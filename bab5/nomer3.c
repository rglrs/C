#include <stdio.h>

#define ORDO 2 // Konstanta untuk ordo matriks

int main() {
    int A[ORDO][ORDO], B[ORDO][ORDO], C[ORDO][ORDO];

    // Meminta pengguna memasukkan elemen-elemen matriks A
    printf("Masukkan elemen matriks A[%d][%d]:\n", ORDO, ORDO);
    for (int i = 0; i < ORDO; i++) {
        for (int j = 0; j < ORDO; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    // Meminta pengguna memasukkan elemen-elemen matriks B
    printf("Masukkan elemen matriks B[%d][%d]:\n", ORDO, ORDO);
    for (int i = 0; i < ORDO; i++) {
        for (int j = 0; j < ORDO; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    // Menjumlahkan matriks A dan B, hasil disimpan dalam matriks C
    for (int i = 0; i < ORDO; i++) {
        for (int j = 0; j < ORDO; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    // Menampilkan isi matriks A
    printf("Matriks A[%d][%d]:\n", ORDO, ORDO);
    for (int i = 0; i < ORDO; i++) {
        for (int j = 0; j < ORDO; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    // Menampilkan isi matriks B
    printf("Matriks B[%d][%d]:\n", ORDO, ORDO);
    for (int i = 0; i < ORDO; i++) {
        for (int j = 0; j < ORDO; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    // Menampilkan hasil penjumlahan dalam matriks C
    printf("Matriks C[%d][%d] (Hasil Penjumlahan A + B):\n", ORDO, ORDO);
    for (int i = 0; i < ORDO; i++) {
        for (int j = 0; j < ORDO; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
