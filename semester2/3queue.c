#include <stdio.h>
#define MAX 10
typedef int Itemtype;
typedef struct
{
    Itemtype item[MAX];
    int count;
    int front;
    int rear;
} Queue;

void Inisialisasi_q(Queue *q)
{
    q->count = 0;
    q->front = 0;
    q->rear = 0;
}

int Penuh_q(Queue *q)
{
    return (q->count == MAX);
}

int Kosong_q(Queue *q)
{
    return (q->count == 0);
}

void Enqueue_q(Queue *q, Itemtype x)
{
    if (Penuh_q(q))
        printf("Queue Penuh, Data tidak dapat disimpan\n");
    else
    {
        q->item[q->rear] = x;
        q->rear = (q->rear + 1) % MAX;
        q->count++;
    }
}

Itemtype Dequeue_q(Queue *q)
{
    Itemtype temp;
    if (Kosong_q(q))
    {
        printf("Queue Kosong, tidak dapat mengambil data\n");
        return ' ';
    }
    else
    {
        temp = q->item[q->front];
        q->front = (q->front + 1) % MAX;
        q->count--;
        return (temp);
    }
}

typedef struct
{
    char data[MAX];
    int count;
} Stack;
void Inisialisasi_s(Stack *s)
{
    s->count = 0;
}
int Kosong_s(Stack *s)
{
    return (s->count == 0);
}
int Penuh_s(Stack *s)
{
    return (s->count == MAX);
}
void Push(Stack *s, char c)
{
    if (!Penuh_s(s))
    {
        s->data[s->count] = c;
        s->count++;
    }
    else
    {
        printf("Stack penuh");
    }
}
char Pop(Stack *s)
{
    if (!Kosong_s(s))
    {
        s->count--;
        return s->data[s->count];
    }
    else
    {
        printf("Stack kosong");
    }
}

void cetak_parkir(Queue q)
{
    int i = q.front;
    printf("Urutan parkir: ");
    while (i != q.rear)
    {
        printf("%d", q.item[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    Queue ant;
    Stack tum;
    int no_parkir = 1, no_keluar, pilih;
    char lagi = 'y';
    Inisialisasi_q(&ant);
    Inisialisasi_s(&tum);
    while (lagi == 'y')
    {
        printf("PROGRAM PARKIR\n");
        printf("1. Masuk\n");
        printf("2. Keluar\n");
        printf("Pilih: ");
        fflush(stdin);
        scanf("%d", &pilih);
        switch (pilih)
        {
        case 1:
            printf("Nomer parkir yang masuk: %d\n", no_parkir);
            Enqueue_q(&ant, no_parkir);
            no_parkir++;
            break;
        case 2:
            printf("Nomer parkir yang keluar: ");
            scanf("%d", &no_keluar);
            if (ant.item[ant.front] == no_keluar)
            {
                printf("Parkir yang keluar: %d\n", Dequeue_q(&ant));
            }
            else
            {
                while (ant.item[ant.front] != no_keluar)
                {
                    Push(&tum, Dequeue_q(&ant));
                }
                no_keluar = Dequeue_q(&ant);
                while (!Kosong_s(&tum))
                {
                    ant.count++;
                    ant.item[(ant.front - 1) % MAX] = Pop(&tum);
                    ant.front = (ant.front - 1) % MAX;
                }
            }
            break;
        }
        cetak_parkir(ant);
        printf("Lagi? ");
        fflush(stdin);
        scanf("%c", &lagi);
    }
}