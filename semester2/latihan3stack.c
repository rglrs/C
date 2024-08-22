#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct Stack
{
    int top;
    unsigned kapasitas;
    char* array;
};

struct Stack* createStack(unsigned kapasitas)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack -> kapasitas = kapasitas;
    stack -> top = -1;
    stack -> array = (char*)malloc(stack->kapasitas*sizeof(char));
    return stack;
};

int Kosong(struct Stack* stack){
    return stack -> top == -1;
}

int Penuh(struct Stack* stack){
    return stack -> top == stack -> kapasitas - 1;
}

void push(struct Stack* stack,char item){
    if(Penuh(stack))
    return;
    stack -> array[++stack -> top] = item;
}

char pop(struct Stack* stack){
    if(Kosong(stack))
    return '\0';
    return stack -> array[stack -> top--];
}

void balikKata(char* balik){
    int panjang = strlen(balik);
    struct Stack* stack = createStack(panjang);
    for (int i = 0; i < panjang; i++)
    push(stack, balik[i]);
    for (int i = 0; i < panjang; i++)
    balik[i] = pop(stack);
}

int main(){
    char balik[MAX];
    printf("Masukkan kalimat: ");
    fgets(balik,MAX,stdin);
    balik[strcspn(balik, "\n")] = '\0';
    balikKata(balik);
    printf("Kalimat setelah dibalik: %s\n", balik);
    return 0;
}