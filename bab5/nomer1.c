#include <stdio.h>

int main() {
    int n; // Jumlah elemen dalam array
    printf("Masukkan jumlah elemen dalam array: ");
    scanf("%d", &n);

    // Deklarasi array dengan jumlah elemen n
    int arr[n];

    // Mengisi array dengan data
    printf("Masukkan %d elemen integer:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemen ke-%d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Menampilkan isi array menggunakan for()
    printf("Isi array:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemen ke-%d: %d\n", i + 1, arr[i]);
    }

    return 0;
}
