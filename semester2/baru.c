#include <stdio.h>
#include <stdlib.h>

typedef struct simpul DNode;
struct simpul{
    int data;
    DNode *next;
    DNode *prev;
};
DNode *head=NULL, *tail=NULL, *baru;

void alokasi_DNode(int x) {
    baru=(DNode *)malloc(sizeof(DNode));
    if (baru==NULL) {
        printf("Alokasi Gagal\n");
        exit(1);
    } else {
        baru->data=x;
        baru->next = baru->prev = NULL;
    }
}

void cetak_headtail() {
    DNode *p=head;
    while(p!=NULL) {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void cetak_tailhead() {
    DNode *p=tail;
    while(p!=NULL) {
        printf("%d ",p->data);
        p=p->prev;
    }
    printf("\n");
}

void Sisip_awal() {
    baru->next = head;
    head->prev = baru;
    head = baru;
}

main() {
    int dt, pilih, cur;
    char lagi='y';

    alokasi_DNode(10);
    head=tail=baru;
    cetak_headtail();
    cetak_tailhead();

    while(lagi=='y') {
        printf("1. Sisip Awal\n");
        printf("Pilihan ");
        scanf("%d", &pilih);

        switch(pilih) {
            case 1: 
            printf("Masukkan data: ");
            scanf("%d", &dt);
            alokasi_DNode(dt);
            Sisip_awal();
            break;
        }
        cetak_headtail();
        cetak_tailhead();

        printf("Lagi? ");
        fflush(stdin);
        scanf("%c", &lagi);
    }
}