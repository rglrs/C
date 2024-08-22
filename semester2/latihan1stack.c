#include <stdio.h>
#define MAX 100
typedef char Itemtype;
typedef struct
{
    Itemtype Item[MAX];
    int count;
} stack;

void init(stack *s)
{
    s->count = 0;
}

Itemtype isEmpty(stack *s)
{
    return (s->count == 0);
}

Itemtype isFull(stack *s)
{
    return (s->count == MAX);
}

void push(stack *s, Itemtype x)
{
    if (isFull(s))
        printf("Stack is full\n");
    else
    {
        s->Item[s->count] = x;
        s->count++;
    }
}

Itemtype pop(stack *s)
{
    Itemtype character = 'A';
    if (isEmpty(s))
        printf("Stack is empty\n");
    else
    {
        s->count--;
        character = s->Item[s->count];
        return character;
    }
}



int main()
{
    stack data;
    printf("Masukan input: ");
    init(&data);
    char input;
    while ((input = getchar()) != '\n')
    {
        if(input == '*'){
            printf("%c", pop(&data));
        } else {
            push(&data, input);
        }
    }
}