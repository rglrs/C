#include<stdio.h>
#include<stdlib.h>
typedef struct simpul Node;
struct simpul {
    int data;
    Node *next;
};
Node *baru, *head = NULL;
void alokasi_simpul(int x)
{
    baru = (Node *) malloc (sizeof(Node));
    if(baru==NULL) { printf("alokasi gagal\n"); exit(1); }
    else{
        baru->data = x;
        baru->next = NULL;
    }
}
void cetak()
{
    Node *p = head;
    while(p!=NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
void sisip_awal()
{
    baru->next = head;
    head = baru;
}
void sisip_akhir()
{
    Node *akhir = head;
    while(akhir->next != NULL)
        akhir = akhir->next;
    akhir->next = baru;
}
void sisip_sebelum (int x)
{
    Node *sebelum = head;
    while(sebelum->next->data!=x)
        sebelum = sebelum->next;
    baru->next = sebelum->next;
    sebelum->next = baru;
}
void sisip_setelah (int x)
{
    Node *setelah = head;
    while(setelah->data!=x)
        setelah = setelah->next;
    baru->next = setelah->next;
    setelah->next = baru;
}
main()
{
    int dt, pilih, x;
    char jawab='y';
    alokasi_simpul(10);
    head = baru;
    cetak();
    while(jawab=='y'){
        printf("1.Sisip awal\n");
        printf("2.Sisip akhir\n");
        printf("3.Sisip sebelum simpul tertentu\n");
        printf("4.Sisip setelah simpul tertentu\n");
        printf("Pilihan: ");fflush(stdin);scanf("%d",&pilih);
        switch(pilih){
        case 1: printf("Masukkan data: ");scanf("%d",&dt);alokasi_simpul(dt);
                sisip_awal();
                break;
        case 2: printf("Masukkan data: ");scanf("%d",&dt);alokasi_simpul(dt);
                sisip_akhir();
                break;
        case 3: printf("Masukkan data: ");scanf("%d",&dt);alokasi_simpul(dt);
                printf("Sisip sebelum simpul: ");scanf("%d",&x);
                sisip_sebelum(x);
                break;
        case 4: printf("Masukkan data: ");scanf("%d",&dt);alokasi_simpul(dt);
                printf("Sisip setelah simpul: ");scanf("%d",&x);
                sisip_setelah(x);
                break;
        }
        cetak();
        printf("Lagi? ");fflush(stdin);scanf("%c",&jawab);
    }
}
