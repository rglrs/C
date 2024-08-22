#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void Insertion(int A[N]){
    int i, j, key;
    i = 1;
    while (i<N)
    {
        key = A[i];
        j = i - 1;
        while (j <= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
        i++;
        
    }
    
}

void Selection(int A[]){
    int i, j, min, temp;
    i = 0;
    while (i < N - 2)
    {
        j = i + 1;
        min = j;
        while (j < N)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
            j++;
            
        }
        temp = A[i];
        A[i] = A[j];
        A[min] = temp;
        i++;
        
    }
    
}

int main(){
    int data[N], i, pilih, data_acak[N];
    char lagi = 'y';
    for (int i = 0; i < N; i++)
    {
        srand(time(NULL) * (i + 1));
        data[i] = rand() % 100 + 1;
        printf("%d ", data[i]);
    }
    while (lagi == 'y')
    {
        printf("1. Insertion\n");
        printf("2. Selection\n");
        printf("Pilihan: ");
        fflush(stdin);
        scanf("%d", &pilih);

        switch (pilih)
        {
        case 1:
        Insertion(data_acak); 
            break;
        case 2:
        Selection(data_acak);
            break;
        default:
            break;
        }
        printf("Data setelah urut: ");
        for (int i = 0; i < N; i++)
        {
            printf("%d ", data_acak[i]);
        }

        printf("Lagi? ");
        fflush(stdin);
        scanf("%c", lagi);
    }
    
    
}