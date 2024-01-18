#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

//선입후선출 방식으로 앞에서 부터 점점 쌓이다가(top이 하나씩 증가)
// 뒤에서 부터 뺀다.(top이 하나씩 감소)

//linked list 처럼 list->

typedef struct _node
{
    int data;
    struct _node *next;

} Node;

typedef struct _LinkedList
{
    Node *head;
    int NumOfData;

} List;

void StackInit(List *list);
void Push(List *list, int data);
int Pop(List *list);
int IsEmpty(List *list);
void LinearSearch(List *list);
int main()
{
    List list;

    StackInit(&list);

    printf("elements...\n\n");
    Push(&list, 3);
    Push(&list, 4);
    Push(&list, 6);
    Push(&list, 10);
    Push(&list, 12);
    Push(&list, 20);
    LinearSearch(&list);
    printf(" elements pop: ");
    while (!IsEmpty(&list))
    {

        printf("%d ", Pop(&list));
    }
    return 0;
}

void LinearSearch(List *list)
{
    
    Node *temp=list->head;
    while (temp!=NULL){

        printf("%d\n",temp->data);
        temp=temp->next;


    }
}
void StackInit(List *list)
{
    list->head=NULL;
    list->NumOfData=0;

}
int IsEmpty(List *list)
{
    if(list->head==NULL){
        return TRUE;
    }else{
        return FALSE;
    }
}
void Push(List *list, int data)
{
    //STACK이니 앞에서 부터 쌓이는 느낌으로 넣는 거
    // 그래서 list->head만 사용(새로운 노드를 생성하고 head에 추가)
    //먼저 쌓이는게 나중에 나가는 선입후출 형식
    // 그래서 앞에서 부터 쌓인다.
    
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->next=list->head;// 새로운 노드가 가르키는 것은 현재 stack의 top
    //list->head => stack->top; 하나
    /*
    새 노드는 이전 head 노드를 가리키고, head는 새 노드를 가리킴.
    */
    list->head=newNode;
    list->NumOfData++;
    //넣는걸 밑에서부터 넣으니
    //출력할때는 맨위에 있는 것 부터

}

int Pop(List *list)
{
    //스택의 맨 위에 쌓인 head 제거
    //head가 가리키는 노드를 제거하고, head를 다음 노드로 이동.
    // head가 여기서 top이다
    // top에서 하나씩 줄여나가는 느낌

    if (IsEmpty(list)) {
        printf("Stack is empty!\n");
        return -1;
    }

    Node *delNode;
    delNode=list->head;    
    int retData=delNode->data;
    list->head=list->head->next;
    //top이 가르키는 노드 즉 head를 빼내고 top은 두번째 노드(head->next)를 가리킴
    free(delNode);
    delNode=NULL;
    list->NumOfData--;

    return retData;



}

