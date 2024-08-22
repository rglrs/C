#include <stdio.h>
#include <stdlib.h>

typedef struct simpul DNode;
struct simpul
{
    int data;
    DNode *next;
    DNode *prev;
};

DNode *head = NULL, *tail = NULL, *baru;
void alokasi_DNode(int x)
{
    baru = (DNode *)malloc(sizeof(DNode));
    if (baru == NULL)
    {
        printf("Alokasi gagal\n");
        exit(1);
    }
    else
    {
        baru->data = x;
        baru->next = baru->prev = NULL;
    }
}

void cetak_headtail()
{
    DNode *p = head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void cetak_tailhead()
{
    DNode *p = tail;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->prev;
    }
    printf("\n");
}

void Sisip_awal()
{
    baru->next = head;
    if (head != NULL)
        head->prev = baru;
    head = baru;
    if (tail == NULL)
        tail = baru;
}

void Sisip_akhir()
{
    baru->prev = tail;
    if (tail != NULL)
        tail->next = baru;
    tail = baru;
    if (head == NULL)
        head = baru;
}

void Sisip_sebelum(int x)
{
    DNode *before = head;
    while (before->data != x)
        before = before->next;
    baru->prev = before->prev;
    baru->next = before;
    if (before->prev != NULL)
        before->prev->next = baru;
    before->prev = baru;
}

void Sisip_setelah(int x)
{
    DNode *after = head;
    while (after->data != x)
        after = after->next;
    baru->prev = after;
    baru->next = after->next;
    if (after->next != NULL)
        after->next->prev = baru;
    after->next = baru;
}

void free_DNode(DNode *p)
{
    free(p);
    p = NULL;
}

void hapus_awal()
{
    if (head != NULL)
    {
        DNode *hapus = head;
        head = hapus->next;
        if (head != NULL)
            head->prev = NULL;
        if (hapus == tail)
            tail = NULL;
        free_DNode(hapus);
    }
}

void hapus_akhir()
{
    if (tail != NULL)
    {
        DNode *hapus = tail;
        tail = hapus->prev;
        if (tail != NULL)
            tail->next = NULL;
        if (hapus == head)
            head = NULL;
        free_DNode(hapus);
    }
}

void hapus_tengah(int x)
{
    DNode *hapus = head;
    while (hapus != NULL && hapus->data != x)
        hapus = hapus->next;
    if (hapus != NULL)
    {
        if (hapus == head)
            hapus_awal();
        else if (hapus == tail)
            hapus_akhir();
        else
        {
            hapus->prev->next = hapus->next;
            hapus->next->prev = hapus->prev;
            free_DNode(hapus);
        }
    }
    else
        printf("Simpul tidak ada\n");
}

void sisip_urut(int x)
{
    DNode *cur;
    alokasi_DNode(x);

    if (head == NULL || x < head->data)
        Sisip_awal();
    else if (x > tail->data)
        Sisip_akhir();
    else
    {
        cur = head;
        while (cur != NULL && cur->data < x)
            cur = cur->next;
        if (cur->data == x)
            printf("Simpul Duplikat\n");
        else
            Sisip_sebelum(cur->data);
    }
}

void hapus(int x)
{
    if (head == NULL)
        printf("Tidak ada simpul\n");
    else if (head->data == x)
        hapus_awal();
    else if (tail->data == x)
        hapus_akhir();
    else
        hapus_tengah(x);
}

int main()
{
    int pilih;
    char lagi = 'y';

    cetak_headtail();
    cetak_tailhead();

    while (lagi == 'y')
    {
        int dt;

        printf("1. Sisip Urut\n");
        printf("2. Hapus\n");
        printf("Pilihan: ");
        scanf("%d", &pilih);
        switch (pilih)
        {
        case 1:
            printf("Masukkan data: ");
            scanf("%d", &dt);
            sisip_urut(dt);
            break;
        case 2:
            printf("Masukkan data yang akan dihapus: ");
            scanf("%d", &dt);
            hapus(dt);
            break;
        default:
            printf("Pilihan tidak valid\n");
            break;
        }

        cetak_headtail();
        cetak_tailhead();
        printf("Lagi? (y/n): ");
        fflush(stdin);
        lagi = getchar();
    }
    if (lagi != 'y')
    {
        printf("Program Telah Berhenti\n");
    }
    return 0;
}