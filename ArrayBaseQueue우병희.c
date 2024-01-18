/*
결과 예시 (Q_SIZE 값이 5일때)

Input some data in Queue!
.......
What is first element of Queue? => 1

What is second element of Queue? => 2

What is number of elements? => 3

What is last element of Queue? => 4

Queue is empty...!

*/
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define Q_SIZE 5
typedef struct _arrayQueue
{
    int arr[Q_SIZE];
    int front;
    int rare;

} Queue;

void QueueInit(Queue *q);
void Enqueue(Queue *q, int data);
void Dequeue(Queue *q);
int IsEmpty(Queue *q);
int IsFull(Queue *q);
int QueueSize(Queue *q);
int QueuePeek(Queue *q);

int main(void)
{
    // Queue q // 이렇게 하면 함수 파라미터로 항상 & 넣어야 됨
    Queue *q = (Queue *)malloc(sizeof(Queue));

    QueueInit(q);

    printf("Input some data in Queue!\n");
    printf(".......\n");

    for (int i = 0; i < Q_SIZE - 1; i++) // 한자리를 안쓰니까 -1
    {
        Enqueue(q, i + 1);
    }

    printf("What is first element of Queue? => ");
    printf("%d\n\n", QueuePeek(q));

    Dequeue(q); // 1을 하나 뺏음 처음꺼 그래서 size가 3

    printf("What is second element of Queue? => ");
    printf("%d\n\n", QueuePeek(q));
    printf("What is number of elements? => ");
    printf("%d\n\n", QueueSize(q));
    Dequeue(q);
    Dequeue(q);
    printf("What is last element of Queue? => ");
    printf("%d\n\n", QueuePeek(q));
    Dequeue(q);

    if (IsEmpty(q))
        printf("Queue is empty...!\n");
    else
        printf("Queue is not empty...!\n");

    for (int i = 0; i < 2; i++)
    {
        Enqueue(q, i + 1);
    }
    printf("What is first element of Queue? => ");
    printf("%d\n\n", QueuePeek(q));

    Dequeue(q);

    printf("What is second element of Queue? => ");
    printf("%d\n\n", QueuePeek(q));
    printf("What is number of elements? => ");
    printf("%d\n\n", QueueSize(q));

    return 0;
}

void QueueInit(Queue *q)
{
    q->front = 0;
    q->rare = 0;
    // 선형 배열로 시작시 끝과 시작점이 만나 있는 형태 이므로 모두 0;
}

int IsEmpty(Queue *q)
{
    return q->rare == q->front;
    // rare와 front의 인덱스가 같다면 비어있는 것
}

// full or empty 판별시 front와 rare 그 전과 반대로 이동 후에 삭제(삽입) 하는 것으로 판별 가능

int IsFull(Queue *q)
{
    return ((q->rare + 1) % Q_SIZE) == q->front % Q_SIZE;
    // 원형으로 보았을 때 rare가 갈 수 있는 max는 Q_SIZE -1;
}

void Enqueue(Queue *q, int data)
{
    if (IsFull(q))
    {
        printf("queue is full\n");
        return;
    }

    // 인덱스 0에는 값이 원래 안들어간다
    q->rare = (q->rare + 1) % Q_SIZE;
    // ++ 하면 rare값이 두번일어나므로 값을 rare에 저장
    // 이동하는 것을 나타 냄
    q->arr[q->rare] = data;
    // 넣고

    // 다시 선형으로 돌면서 돌아가도록 해야 한다.
}

void Dequeue(Queue *q)
{
    if (IsEmpty(q))
    {
        printf("queue is empty\n");
        return;
    }

    q->front = (q->front + 1) % Q_SIZE;
    q->arr[q->front] = -1;

    // 삭제 후 이동하는 front 코드
}

int QueueSize(Queue *q)
{

    return (abs(q->rare - q->front) + Q_SIZE) % Q_SIZE;
    // q -> rare의 인덱스 - q -> front의 인덱스
    // rare의 인덱스가 front보다 작을때도 고려
}

int QueuePeek(Queue *q)
{
    if (IsEmpty(q))
    {
        printf("queue is empty\n");
        return -1;
    }
    return q->arr[(q->front + 1) % Q_SIZE];
    // 인덱스를 나머지 갑으로 설정하면 값이 증가해도 꾸준한 값이 나옴

    // front를 비우고 rear를 채우는 형식이라 그럼
    // 그래서 인덱스 0에는 값을 안넣음

    // 현재 저장된 요소들의 반환
    // q의 맨 앞요소를 반환해야 하므로(인덱스 0을 제외한)
    // front는 이동했으니 제일 맨 앞에 있는 값이 front에 해당하는 값이다.
}