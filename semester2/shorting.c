#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

void Insertion(int A[]) // tanpa N gpp
{
    int i, j, key;
    i = 1;
    while (i < N)
    {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
        i++;
    }
}

void Selection(int A[])
{
    int i, j, min, temp;
    i = 0;
    while (i < N - 2)
    {
        min = i;
        j = i + 1;
        // min = j;
        while (j < N)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
            j++;
        }
        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
        i++;
    }
}

void Bubble(int A[])
{
    int i, j, temp;
    i = 1;
    while (i < N)
    {
        j = N - 1;
        while (j >= i)
        {
            if (A[j - 1] > A[j])
            {
                temp = A[j - 1];
                A[j - 1] = A[j];
                A[j] = temp;
            }
            j--;
        }
        i++;
    }
}

void BubbleFlag(int A[])
{
    int i, j, temp, did_swap = 1;
    i = 1;
    while (did_swap && i < N)
    {
        j = N - 1;
        did_swap = 0;
        while (j >= i)
        {
            if (A[j - 1] > A[j])
            {
                temp = A[j - 1];
                A[j - 1] = A[j];
                A[j] = temp;
                did_swap = 1;
            }
            j--;
        }
        i++;
    }
}

void Shell(int A[])
{
    int i, jarak, temp, did_swap;
    jarak = N;
    while (jarak > 1)
    {
        jarak /= 2;
        did_swap = 1;
        if (did_swap)
        {
            did_swap = 0;
            i = 0;
            while (i < N - jarak)
            {
                if (A[i] > A[i + jarak])
                {
                    temp = A[i];
                    A[i] = A[i + jarak];
                    A[i + jarak] = temp;
                    did_swap = 1;
                }
                i++;
            }
        }
    }
}

int Partition(int p, int r, int A[])
{
    int i, j, pivot, temp;
    pivot = A[p];
    // pivot = A[(p + r) / 2];
    i = p;
    j = r;
    while (i <= j)
    {
        while (A[i] < pivot)
            i++;
        while (A[j] > pivot)
            j--;
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++;
            j--;
        }
        else
        {
            return j;
        }
    }
    return j;
}

int Quick(int p, int r, int A[])
{
    int q;
    if (p < r)
    {
        q = Partition(p, r, A);
        Quick(p, q, A);
        Quick(q + 1, r, A);
    }
}
void Merge(int l, int med, int r, int A[])
{
    int l1, l2, r1, r2, k, temp[N];
    l1 = l;
    r1 = med;
    l2 = med + 1;
    r2 = r;
    k = l;
    while (l1 <= r1 && l2 <= r2)
    {
        if (A[l1] < A[l2])
        {
            temp[k] = A[l1];
            l1++;
        }
        else
        {
            temp[k] = A[l2];
        }
        k++;
    }
    while (l1 <= r1)
    {
        temp[k] = A[l1];
        l1++;
        k++;
    }
    while (l2 <= r2)
    {
        temp[k] = A[l2];
        l2++;
        k++;
    }
    k = l1;
    while (k <= r2)
    {
        A[k] = temp[k];
        k++;
    }
}

void MergeShort(int l, int mid, int r, int A[])
{
    if (l<r)
    {
        
    }
    
}

int main()
{
    int data[N], i, pilih, data_acak[N];
    char lagi = 'y';
    for (int i = 0; i < N; i++)
    {
        srand(time(NULL) * (i + 1));
        data[i] = rand() % 100 + 1;
        printf("%d ", data[i]);
    }
    printf("\n");
    while (lagi == 'y')
    {
        for (int i = 0; i < N; i++)
        {
            data_acak[i] = data[i];
        }

        printf("\n");
        printf("1. Insertion\n");
        printf("2. Selection\n");
        printf("3. Bubble\n");
        printf("4. Bubble Flag\n");
        printf("5. Shell\n");
        printf("6. Quick\n");
        printf("7. Merge\n");
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
        case 3:
            Bubble(data_acak);
            break;
        case 4:
            BubbleFlag(data_acak);
            break;
        case 5:
            Shell(data_acak);
            break;
        case 6:
            Quick(0, N - 1, data_acak);
            break;
        case 7:
            MergeShort(0, N - 1, data_acak);
            break;
        default:
            printf("Kontol\n");
            break;
        }
        printf("Data setelah urut: ");
        for (int i = 0; i < N; i++)
        {
            printf("%d ", data_acak[i]);
        }
        printf("\n");
        printf("Lagi? ");
        fflush(stdin);
        scanf("%c", &lagi);
    }
}