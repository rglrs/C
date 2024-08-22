#include <stdio.h>

void reverseArray(char arr[], int length) {
    int start = 0;
    int end = length - 1;
    char temp;

    while (start < end) {
        // Tukar elemen pada posisi start dengan posisi end
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // Pindahkan pointer start ke kanan dan pointer end ke kiri
        start++;
        end--;
    }
}

int main() {
    char arr[] = {'p', 'e', 'n', 's', 'i', 't'};
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("Array sebelum dibalik: ");
    for (int i = 0; i < length; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");

    // Memanggil fungsi untuk membalikkan array
    reverseArray(arr, length);

    printf("Array setelah dibalik: ");
    for (int i = 0; i < length; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");

    return 0;
}
