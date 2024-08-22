#include <stdio.h>
#include <stdlib.h>

typedef struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
} Term;

void melbuAwal(Term** poly, int coef, int exp) {
    Term* newNode = (Term*)malloc(sizeof(Term));
    newNode->coefficient = coef;
    newNode->exponent = exp;
    newNode->next = *poly;
    *poly = newNode;
}

void melbuTengah(Term* prev, int coef, int exp) {
    if (prev == NULL) {
        printf("Data sebelum e kosong! Gaiso ngelebokno ng tengah su!\n");
        return;
    }
    Term* newNode = (Term*)malloc(sizeof(Term));
    newNode->coefficient = coef;
    newNode->exponent = exp;
    newNode->next = prev->next;
    prev->next = newNode;
}

void melbuAkhir(Term** poly, int coef) {
    Term* newNode = (Term*)malloc(sizeof(Term));
    newNode->coefficient = coef;
    newNode->exponent = 0;
    newNode->next = NULL;
    if (*poly == NULL) {
        *poly = newNode;
        return;
    }
    Term* temp = *poly;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void hapusAwal(Term** poly) {
    if (*poly == NULL) {
        printf("Poli ne lo kosong! Gaiso hapus lol!\n");
        return;
    }
    Term* temp = *poly;
    *poly = (*poly)->next;
    free(temp);
}

void hapusTengah(Term* prev) {
    if (prev == NULL || prev->next == NULL) {
        printf("Gaiso hapus ndek tengah! Nilai sebelum e gaono!\n");
        return;
    }
    Term* temp = prev->next;
    prev->next = temp->next;
    free(temp);
}

void hapusAkhir(Term** poly) {
    if (*poly == NULL) {
        printf("Poli ne kosong su! Gaiso dihapus teko akhir!\n");
        return;
    }
    Term* temp = *poly;
    Term* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev != NULL) {
        prev->next = NULL;
    } else {
        *poly = NULL;
    }
    free(temp);
}

void printPolynomial(Term* poly) {
    if (poly == NULL) {
        printf("Poli ne kosong ndeng!\n");
        return;
    }
    while (poly != NULL) {
        printf("%dx^%d ", poly->coefficient, poly->exponent);
        poly = poly->next;
        if (poly != NULL) {
            printf("+ ");
        }
    }
    printf("\n");
}

int main() {
    Term* polynomial = NULL;
    int choice, coef, exp;
    
    do {
        printf("\n1. Lebokno awal\n2. Lebokno tengah\n3. Lebokno akhir\n");
        printf("4. hapus awal\n5. Hapus tengah\n6. Hapus akhir\n");
        printf("7. Cetak Poli\n0. Metu\n");
        printf("Milih o: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Lebokno koefisien karo eksponen: ");
                scanf("%d %d", &coef, &exp);
                melbuAwal(&polynomial, coef, exp);
                break;
            case 2:
                printf("Lebokno eksponen sebelum e, koefisien, karo eksponen: ");
                scanf("%d %d %d", &exp, &coef, &exp);
                Term* temp = polynomial;
                while (temp != NULL && temp->exponent != exp) {
                    temp = temp->next;
                }
                melbuTengah(temp, coef, exp);
                break;
            case 3:
                printf("Lebokno koefisien: ");
                scanf("%d", &coef);
                melbuAkhir(&polynomial, coef);
                break;
            case 4:
                hapusAwal(&polynomial);
                break;
            case 5:
                printf("Lebokno eksponen sebelum e: ");
                scanf("%d", &exp);
                temp = polynomial;
                while (temp != NULL && temp->exponent != exp) {
                    temp = temp->next;
                }
                hapusTengah(temp);
                break;
            case 6:
                hapusAkhir(&polynomial);
                break;
            case 7:
                printf("Polynomial: ");
                printPolynomial(polynomial);
                break;
            case 0:
                printf("Keluar...\n");
                break;
            default:
                printf("Pilihan salah,milih o sg bener su!\n");
        }
    } while (choice != 0);

    return 0;
}
