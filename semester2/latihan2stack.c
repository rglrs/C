#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Stack {
    int items[MAX];
    int top;
};

void initialize(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack penuh, push gagal.\n");
        return;
    }
    stack->items[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack kosong, pop gagal.\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

void decimalToBinary(int num) {
    struct Stack stack;
    initialize(&stack);

    while (num > 0) {
        push(&stack, num % 2);
        num /= 2;
    }

    printf("Biner: ");
    while (!isEmpty(&stack)) {
        printf("%d", pop(&stack));
    }
    printf("\n");
}

void decimalToOctal(int num) {
    struct Stack stack;
    initialize(&stack);

    while (num > 0) {
        push(&stack, num % 8);
        num /= 8;
    }

    printf("Oktal: ");
    while (!isEmpty(&stack)) {
        printf("%d", pop(&stack));
    }
    printf("\n");
}

void decimalToHexadecimal(int num) {
    struct Stack stack;
    initialize(&stack);

    while (num > 0) {
        push(&stack, num % 16);
        num /= 16;
    }

    printf("Heksadesimal: ");
    while (!isEmpty(&stack)) {
        int rem = pop(&stack);
        if (rem < 10) {
            printf("%d", rem);
        } else {
            printf("%c", rem - 10 + 'A');
        }
    }
    printf("\n");
}

int main() {
    int num;

    printf("Masukkan bilangan desimal: ");
    scanf("%d", &num);

    decimalToBinary(num);
    decimalToOctal(num);
    decimalToHexadecimal(num);

    return 0;
}
