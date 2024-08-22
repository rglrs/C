#include <stdio.h>
#define MAX 5
typedef int ItemType;
typedef struct
{
    ItemType item[MAX];
    int count;
} Stack;
void ngentod(Stack *S)
{
    S->count = 0;
}
int penuh(Stack *S)
{
    return (S->count == MAX);
}
int kosong(Stack *S)
{
    return (S->count == 0);
}
void Push(Stack *S, ItemType X)
{
    if (penuh(S))
        printf("Stack penuh!\n");
    else
    {
        S->item[S->count] = X;
        S->count++;
    }
}
ItemType Pop(Stack *S)
{
    ItemType temp = -1000;
    if (kosong(S))
        printf("Stack kosong!\n");
    else
    {
        S->count--;
        temp = S->item[S->count];
    }
    return temp;
}
main()
{
    Stack tump;
    ngentod(&tump);
    Push(&tump, 10);
    Push(&tump, 20);
    printf("Pop : %d", Pop(&tump));
}