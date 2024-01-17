

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct _node
{
    int data;
    struct _node *next;

} Node;

typedef struct _LinkedList
{
    Node *head; //node pointer변수 특정 노드에 주소를 담고 있는 변수
    Node *tail;
    Node *curr; // node현재 본인이 가지고 있는 node(pointer),현재 노드를 가르키는 pointer
    //리스트 순회시 현재 위치 추적에 유용
    int NumOfData; //list에 있는 데이터(node)의 수

} List;

void ListInit(List *list);
void ListInsert(List *list, int data); // tail에 데이터를 추가하는 방식
void LinearSearch(List *list);
int IsEmpty(List *list);
int Count(List *list);
void DeleteAll(List *list); // 생성된 데이터(node)를 모두 삭제하는 방식,삭제는 head부터

int main()
{

    List list;
    ListInit(&list);
    IsEmpty(&list);

    printf("Insert Data ...\n\n");
    ListInsert(&list, 10);
    ListInsert(&list, 42);
    ListInsert(&list, 54);
    ListInsert(&list, 66);
    ListInsert(&list, 89);
    printf("Elements : \n");
    LinearSearch(&list);
    printf("\n\n");

    printf("count %d\n",Count(&list));
    

    printf("Delete Data\n");
    DeleteAll(&list);
    IsEmpty(&list);
    return 0;
}

void ListInit(List *list)
{
    list->head=NULL;
    list->curr=NULL;
    list->tail=NULL;
    list->NumOfData=0;
}

int IsEmpty(List *list)
{
    if(list->head==NULL){
        printf("It is empty");
        return TRUE;

    }else{
        return FALSE;
    }
}

void ListInsert(List *list, int data)
{
    Node *newNode=(Node *)malloc(sizeof(Node));
    //Node newNode 이러면 local값으로 값이 날아감
    // 동적할당하면 newNode라는 변수는 없어지지만 할당시킨 메모리는 남아있음
    //함수에서 날아가면 변수는 날아가니까
    //메모리는 프로그램끄거나 free해야 날아감
    newNode -> data=data;
    newNode -> next=NULL; // next는 초기 값 null로 해야 됨 안그러면 dummy주소 값이 생김
    if(IsEmpty(list)){
        //처음 생기는 node는 head이자 tail
        list->head=newNode;
        list->tail=newNode;
        //처음에는 head와 tail이 동일
    }else{
        // tail이 생기면 그전에 tail의 next가 newNode 즉 다음 node를 위한 것이 되고
        // 그 다음에 생기는 tail(새로생긴 node)가 newNode이다.

        list->tail->next=newNode;
        list->tail=newNode;
    }

    list -> NumOfData++;
}



int Count(List *list)
{
    return list->NumOfData;
}

void LinearSearch(List *list)
{
    list->curr=list->head; // head부터 curr값으로 설정하고 옆에 node로 이동하니 초기화를 head로

    while (list->curr!=NULL){

        printf("%d\n",list->curr->data);
        list->curr=list->curr->next;
        //curr은 처음엔 head이고 
        //head의 next가 그 다음 node의 data이다(head다음에 하나만 있다면 이게 tail)
        //그러므로 list->curr이 list->curr->next가 되는 것은 그다음 node로 넘어가는 과정 인것

    }
}

void DeleteAll(List *list)
{
    Node *delNode;
    while (!IsEmpty(list))
    {
        delNode=list->head;
        list->head=list->head->next;
        free(delNode);
        
    }

    list->tail=NULL;
    list->curr=NULL;
    list->NumOfData=0;
    


}