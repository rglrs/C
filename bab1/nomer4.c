#include <stdio.h>

int main()
{
    int choice;

    printf("Pilihan hari yang anda inginkan\n");
    printf("1. Senin\n");
    printf("2. Selasa\n");
    printf("3. Rabu\n");
    printf("4. Kamis\n");
    printf("5. Jumat\n");
    printf("6. Sabtu\n");
    printf("7. Minggu\n");
    printf("Masukkan pilihan anda : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Pilihan Anda = Senin\n");
        printf("Selesai");
        break;
    case 2:
        printf("Pilihan Anda = Selasa\n");
        printf("Selesai");
        break;
    case 3:
        printf("Pilihan Anda = Rabu\n");
        printf("Selesai");
        break;
    case 4:
        printf("Pilihan Anda = Kamis\n");
        printf("Selesai");
        break;
    case 5:
        printf("Pilihan Anda = Jumat\n");
        printf("Selesai");
        break;
    case 6:
        printf("Pilihan Anda = Sabtu\n");
        printf("Selesai");
        break;
    case 7:
        printf("Pilihan Anda = Minggu\n");
        printf("Selesai");
        break;
    }

    return 0;
}