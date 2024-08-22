#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Mhs Node;
struct Mhs{
    unsigned long int Nrp;
    char Nama[50];
    float Nilai;
    Node *next;
};
Node *head=NULL, *baru;
void alokasi_simpul(unsigned long int nrp, char *nama, float nilai)
{
    baru = (Node *) malloc(sizeof(Node));
    if(baru==NULL) { printf("Alokasi gagal\n");exit(1);}
    else{
        baru->Nrp = nrp;
        strcpy(baru->Nama, nama);
        baru->Nilai = nilai;
        baru->next = NULL;
    }
}

void hitung_rata(){
    Node* P = head;
    int jumlah = 0;
    int total = 0;
    while(P != NULL){
        total += P->Nilai;
        jumlah++;
        P = P->next;
    }
    float rata_rata = (float)total/jumlah;
    printf("Nilai rata rata: %1.f\n", rata_rata);
}

void cetak()
{
    Node *p = head;
    int i = 1;
    while(p!=NULL){\
        printf("No. %d\n", i);
        printf("Nrp : %lu\n", p->Nrp);
        printf("Nama : %s\n", p->Nama);
        printf("Nilai : %.1f\n", p->Nilai);
        p = p->next;
        i++;
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
    Node *tail=head;
    while(tail->next != NULL)
        tail = tail->next;
    tail->next = baru;
}
void sisip_sebelum(int x)
{
    Node *before = head;
    while(before->next->Nrp != x)
        before = before->next;
    baru->next = before->next;
    before->next = baru;
}
void sisip_setelah(int x)
{
    Node *after = head;
    while(after->Nrp != x)
        after = after->next;
    baru->next = after->next;
    after->next = baru;
}
void free_node(Node *p)
{
    free(p);
    p = NULL;
}
void hapus_awal()
{
    Node *hapus = head;
    head = hapus->next;
    free_node(hapus);
}
void hapus_akhir()
{
    Node *hapus=head, *before;
    while(hapus->next!=NULL){
        before = hapus;
        hapus = hapus->next;
    }
    before->next = NULL;
    free_node(hapus);
}
void hapus_tengah(int x)
{
    Node *hapus=head, *before;
    while(hapus->Nrp != x){
        before = hapus;
        hapus = hapus->next;
    }
    before->next = hapus->next;
    free_node(hapus);
}
void sisip_urut(int x){
    Node *cur;
    if(head==NULL) head=baru;
    else if(baru->Nrp < head->Nrp) sisip_awal();
    else {
        cur = head;
        while (cur != NULL && cur->Nrp < baru->Nrp)
            cur = cur->next;
        if(cur == NULL) sisip_akhir();
        else if(cur->Nrp == baru->Nrp) printf("Simpul Duplikat");
        else sisip_sebelum(cur->Nrp);
    }
}

void hapus(int x){
    Node *cur = head;
    if(head==NULL) printf("List Kosong");
    else if(head->Nrp == x) hapus_awal(),printf("Hapus Awal\n");
    else {
        while(cur != NULL && cur->Nrp != x){
            cur = cur->next;
            if(cur->Nrp == x) {
                hapus_tengah(x),printf("Hapus Tengah\n");
                break;
            } else {
                hapus_akhir(),printf("Hapus Akhir\n");
                break;
            }
        }
    }
}


int main()
{
    unsigned long int nrp, dt_tengah; 
    int pilih;
    char lagi='y', nama[50];
    float nilai;
    cetak();
    while(lagi=='y'){
        printf("1.Sisip urut\n");
        printf("2.hapus\n");
        printf("Pilihan: ");fflush(stdin);scanf("%d",&pilih);
        switch(pilih){
            case 1: 
                printf("Masukan Nrp : "); scanf("%lu",&nrp);
                printf("Masukan Nama : "); 
                while(getchar() != '\n');
                gets(nama);
                printf("Masukan Nilai : "); scanf("%f",&nilai);
                alokasi_simpul(nrp, nama,  nilai);
                sisip_urut(nrp);
                break;
            case 2: 
                printf("Masukan Nrp : "); scanf("%lu",&nrp);
                hapus(nrp);
                break;
        }
        cetak();
        printf("Lagi?(y/n) ");fflush(stdin);scanf("%c",&lagi);
        if(lagi != 'y') {
            hitung_rata();
        }
    }
}