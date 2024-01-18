/*

양방향 연결리스트를 통해서
스택과 큐 기능을 동시에 구현한다.
이를 위해서는 덱(Dequeue)를 이용한다.
Dequeue이란? 앞부분에 대한 삽입과 추출 뒤 부분에 대한 삽입과 추출이 모두 가능한 자료구조이다.

tail에 대한 삭제가 매우 용의하다.
*/
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct _node
{
    int data;
    struct _node *left;
    struct _node *right;

} Node;

typedef struct _LinkedList
{
    Node *head;
    Node *tail;
    int NumOfData; // 데이터 삽입시에 해당 값 증가 시키기

} List;

void ListInit(List *list);
void AddFirst(List *list, int data);
int DeleteFirst(List *list);
void AddLast(List *list, int data);
int DeleteLast(List *list);
int IsEmpty(List *list);
int Count(List *list);

int main()
{

    List list;
    ListInit(&list);

    AddFirst(&list, 3);
    AddFirst(&list, 2);
    AddFirst(&list, 1);

    AddLast(&list, 4);
    AddLast(&list, 5);
    AddLast(&list, 6);

    printf("delete from Head : ");
    while (!IsEmpty(&list))
        printf("%d ", DeleteFirst(&list));
    printf("\n");

    AddFirst(&list, 3);
    AddFirst(&list, 2);
    AddFirst(&list, 1);

    AddLast(&list, 4);
    AddLast(&list, 5);
    AddLast(&list, 6);

    printf("delete from Last : ");

    while (!IsEmpty(&list))
        printf("%d ", DeleteLast(&list));

    return 0;
}

int IsEmpty(List *list)
{
    if(list->head==NULL){
        return TRUE;
    }else{
        return FALSE;
    }
}

void ListInit(List *list)
{
    list->head=NULL;
    list->tail=NULL;
    list->NumOfData=0;
}
void AddFirst(List *list, int data)
{
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->left=NULL; //마지막 노드
    newNode->right=list->head; //  newNode를 list->head와 연결

    if (IsEmpty(list))
    {
        list->head=newNode;
        list->tail=newNode;

    }else{
        list->head->left=newNode; // 연결한 newNode를 list->head로 만들기
        list->head=newNode;
    }
    
    
    list->NumOfData++;



    
}
int DeleteFirst(List *list)
{
    //앞에서 부터 head부터 삭제
    Node *delNode;
    delNode=list->head;
    int retData=delNode->data;
    list->head=list->head->right;
    free(delNode);
    if(list->head){
        list->head->left=NULL;//헤드가 있으면 새로운 값 들어오기전 젤 왼쪽이 비어있음
    }else{
        list->tail=NULL; // 리스트가 비어있는것
    }
    list->NumOfData--;
    delNode=NULL;
    return retData;

}
void AddLast(List *list, int data)
{
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->right=NULL;//마지막 노드
    newNode->left=list->tail; // newNode를 list->tail과 연결
    if(IsEmpty(list)){
        list->head=newNode;
        list->tail=newNode;
    }else
    {
        
    list->tail->right=newNode;
    list->tail=newNode;

    }
    


    list->NumOfData++;
}
int DeleteLast(List *list)
{
    //뒤에서 부터 tail부터 삭제
    Node *delNode;
    delNode=list->tail;
    int retData= delNode->data;
    list->tail=list->tail->left;
    if(list->tail){
        list->tail->right=NULL;//헤드가 있으면 새로운 값 들어오기전 젤 왼쪽이 비어있음
    }else{
        list->head=NULL; // 리스트가 비어있는것
    }
    free(delNode);
    list->NumOfData--;
    delNode=NULL;
    return retData;


}

int Count(List *list)
{
    return list->NumOfData;
}