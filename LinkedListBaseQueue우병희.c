#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

//기존 queue와 다른것 선형으로 돌아가는 거이 다름
// 그렇기에 기존 값들에 q_size더하고 q_size를 %한 게 없지만 형태는 비슷

typedef struct _node
{
    int data;
    struct _node *next;

} Node;

typedef struct _LinkedList
{
    Node *head;
    Node *tail;
    int NumOfData;

} List;

void QueueInit(List *list);
void Enqueue(List *list, int data);
int Dequeue(List *list);
int IsEmpty(List *list);

int Count(List *list);
void LinearSearch(List *list);

int main()
{
    List list;
    QueueInit(&list);
    printf("Insert...\n");
    Enqueue(&list, 1);
    Enqueue(&list, 10);
    Enqueue(&list, 15);
    Enqueue(&list, 18);
    Enqueue(&list, 22);
    Enqueue(&list, 30);
    printf("Inside: \n");
    LinearSearch(&list);

    printf("....\n");
    printf("Elements : ");

    while (!IsEmpty(&list))
    {

        printf("%d ", Dequeue(&list));
    }

    return 0;
}
void QueueInit(List *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->NumOfData = 0;
}
int IsEmpty(List *list)
{

    if(list->head==NULL){
        return TRUE;
    }else{
        return FALSE;
    }
}

void Enqueue(List *list, int data)
{
 //큐는 새로운 큐 옆에  데이터 추가하는 형태(rear가) 이동하고 넣는거
 
 //링크드 리스트에서 뒤로 노드 데이터 추가하는 것과 비슷
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

// 비어 있으면 head,tail 모두 동일하게 newNode가 된다. 
    if (IsEmpty(list))
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        //링크드 리스트에서 뒤로 노드 데이터 추가하는 것과 비슷
        list->tail->next = newNode;
        list->tail = newNode;
    }

    list->NumOfData++;
}
void LinearSearch(List *list)
{
    
    Node *temp=list->head;
    while (temp!=NULL){

        printf("%d\n",temp->data);
        temp=temp->next;


    }
}

int Dequeue(List *list)
{

//큐에서 front가 제거하는것과 비슷 앞으로 가면서 제거 하는 것과 비슷
//앞에서 뒤로 가는 것(링크드 리스트에서 제거시에 앞에 노드 에서 부터 제거)
    if (IsEmpty(list))
    {
        printf("Queue is empty!\n");
        return -1;
    }
    Node *delNode;
    delNode = list->head;

    int retData = delNode->data; //제거하기 위한 값들 저장 중임

    list->head = list->head->next;
    free(delNode);
    list->NumOfData--;
    delNode=NULL;

    if (list->head == NULL)
    {
        list->tail = NULL;
    }

    return retData;
}

int Count(List *list)
{
    return list->NumOfData;
}