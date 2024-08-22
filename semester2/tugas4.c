#include <stdio.h>
#define N 10

float tambah(int A[],int B[], float x){
    float hasil =0.0;
    int i;
    for(i=0;i<N;i++)
    hasil += (A[i]+B[i])* (float)pow(x,i);
    return hasil;
}

float kurang(int A[],int B[], float x){
    float hasil =0.0;
    int i;
    for(i=0;i<N;i++)
    hasil += (A[i]-B[i])* (float)pow(x,i);
    return hasil;
}

float kali(int A[],int B[], float x){
    float hasil = 0.0;
    int i;
    for(i=0;i<N;i++)
    hasil += (A[i]*B[i])* (float)pow(x,i);
    return hasil;
}

float turunan(int A[], float x){
    float hasil = 0.0;
    int i;
    for (i = 1; i < N; i++)
    {
        hasil += (A[i]) * i * (float)pow(x, i - 1);
    }
    return hasil;
}

main(){
    int P1[N] = {15,0,0,1,0,5,0,8,6,0};
    int P2[N] = {10,0,2,2,3,0,0,4,0,3};
    int P3[N] = {5,0,1,0,0,0,0,0,0,0,0};
    float x,hasil;
    printf("Masukkan nilai x=");
    scanf("%f",&x);
    hasil = tambah(P1,P2,x);
    printf("Hasil penjumlahan P1 + P2 = %5.2f\n",hasil);
    hasil = kurang(P1,P2,x);
    printf("Hasil pengurangan P1 - P2 = %5.2f\n",hasil);
    hasil = kali(P1,P3,x);
    printf("Hasil perkalian P1 * P3 = %5.2f\n",hasil);
    hasil = turunan(P2,x);
    printf("Hasil turunan P2' = %5.2f\n",hasil);
}