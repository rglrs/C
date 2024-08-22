#include <stdio.h>
#include <string.h>
#define MAX 100
typedef char ItemType;
typedef struct
{
    ItemType item[MAX];
    int count;
} Stack;
void Inisialisasi(Stack *s)
{
    s->count = 0;
}
int Penuh(Stack *s)
{
    return (s->count == MAX);
}
int Kosong(Stack *s)
{
    return (s->count == 0);
}
void Push(Stack *s, ItemType x)
{
    if (Penuh(s))
        printf("Stack Penuh\n");
    else
    {
        s->item[s->count] = x;
        s->count++;
    }
}
ItemType Pop(Stack *s)
{
    ItemType temp = '\0';
    if (Kosong(s))
    {
        printf("Stack Kosong\n");
    }
    else
    {
        s->count--;
        temp = s->item[s->count];
    }
    return temp;
}

main()
{
    Stack tump;
    Inisialisasi(&tump);
    char kalimat[MAX];
    char hasil[MAX];
    printf("Masukkan Kalimat: ");
    gets(kalimat);
    int i;
    for (i = 0; i < strlen(kalimat); i++)
    {
        Push(&tump, kalimat[i]);
    }
    i = 0;
    while (!Kosong(&tump))
    {
        hasil[i] = Pop(&tump);
        i++;
    }
    hasil[i] = '\0';
    // strcmt
    printf("Hasil pembalikan = %s\n", hasil);
    if (strcmp(kalimat, hasil) == 0)
        printf("Palindrom\n");
    else
        printf("Bukan Polindrom\n");
}