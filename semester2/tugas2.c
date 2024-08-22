#include <stdio.h>

// Fungsi untuk menampilkan matriks
void tampilmatrix(int matrix[][10], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Fungsi untuk menambahkan dua matriks
void tambah(int m1[][10], int m2[][10], int result[][10], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

// Fungsi untuk mengurangkan dua matriks
void kurang(int m1[][10], int m2[][10], int result[][10], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = m1[i][j] - m2[i][j];
        }
    }
}

// Fungsi untuk mengalikan dua matriks
void kali(int m1[][10], int m2[][10], int result[][10], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

int main() {
    int n;
    printf("Masukkan ordo matriks: ");
    scanf("%d", &n);

    int matrix1[10][10], matrix2[10][10], result[10][10];

    printf("Masukkan elemen matriks pertama:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Masukkan elemen matriks kedua:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("Matriks pertama:\n");
    tampilmatrix(matrix1, n, n);

    printf("Matriks kedua:\n");
    tampilmatrix(matrix2, n, n);

    // Penjumlahan matriks
    tambah(matrix1, matrix2, result, n, n);
    printf("Penjumlahan matriks:\n");
    tampilmatrix(result, n, n);

    // Pengurangan matriks
    kurang(matrix1, matrix2, result, n, n);
    printf("Pengurangan matriks:\n");
    tampilmatrix(result, n, n);

    // Perkalian matriks
    kali(matrix1, matrix2, result, n, n, n);
    printf("Perkalian matriks:\n");
    tampilmatrix(result, n, n);

    return 0;
}
