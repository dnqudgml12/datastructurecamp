/*
�ش� ��ũ�帮��Ʈ�� �⺻���� ��ɰ� ���Ҿ�, ������������ �����͸� �����ϴ� ��ɰ� Ư�� ��带 �����ϴ� ����� �߰��Ѵ�.
*/
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
    Node *head;
    Node *tail;
    Node *curr;
    Node *prev;
    int NumOfData; // ������ ���Խÿ� �ش� �� ���� ��Ű��

} List;

void ListInit(List *list);
void ListInsert(List *list, int data);
void ListInsertAscending(List *list, int data); // �����߰��� �Լ�1 : �����͸� ������������ �����Ѵ�.
void LinearSearch(List *list);                  // Search->LinearSearch�� �Լ��� ����
int IsEmpty(List *list);
int Count(List *list);
int Delete(List *list, int data); // ���� �߰��� �Լ�3: Ư����带 �����Ѵ�.
void DeleteAll(List *list);

int main()
{

    List list;
    ListInit(&list);
    IsEmpty(&list);

    printf("inserting Ascending data...\n\n");
    ListInsertAscending(&list, 10);
    ListInsertAscending(&list, 2);
    ListInsertAscending(&list, 8);
    ListInsertAscending(&list, 3);
    ListInsertAscending(&list, 20);
    ListInsertAscending(&list, 14);

    printf("Elements : ");
    LinearSearch(&list);
    printf("\n\n");

    printf("Choosing data is deleted!\n\n");
    printf("%d is deleted!\n", Delete(&list, 3));
    printf("\nData list after deleting : ");
    LinearSearch(&list);

    return 0;
}

void ListInit(List *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->curr = NULL;
    list->prev = NULL;
    list->NumOfData = 0;
}

int IsEmpty(List *list)
{
    if (list->head == NULL)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
void ListInsert(List *list, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (IsEmpty(list))
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->NumOfData++;
}

void ListInsertAscending(List *list, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data; // 우리가 찾으려는 데이터 값을 가지고 있는 것
    newNode->next = NULL;
    if (IsEmpty(list))
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        list->prev = NULL;
        list->curr = list->head;
        while (list->curr != NULL && list->curr->data < data)
        {
            /*
            새 데이터가 삽입될 위치의 바로 전 노드(list->prev)와 바로 다음 노드(list->curr)를 찾음
            */
            //오름차순으로 정렬된 linkedlist에 새로운 노드를 넣는과정
            // 리스트 순회하면서 삽입하려는 데이터보다 작은 데이터를 가진 노드를 찾고
            // 삽입하려는 데이터가 현재노드(list-<curr)의 데이터보다 클때까지 리스트를 순
            list->prev = list->curr;
            list->curr = list->curr->next;
            // prev가 curr이 되면 curr은 다시 curr의 next로 간다
        }
        if (list->prev == NULL)//시작점 일때
        {
            newNode->next = list->head;
            list->head = newNode;
            // newNode의  next는 기존 list->head이다.
            //  기존 list->head는 newNode가 들어오면 list->head는 newNode가 된다.
        }
        else
        {
            newNode->next = list->curr;
            list->prev->next = newNode;
            //prev랑 curr안에 들어가려면 prev->next가 newNode가 되야 한다.

            if (list->curr = NULL)
            { // prev,curr이 같이 이동하면서 prev가 끝이면 curr이 NULL
                list->tail = newNode;
                // 끝에 있으니까 새로운 데이터는 list->tail
            }
        }
    }
    list->NumOfData++;
}

int Count(List *list)
{
    return list->NumOfData;
}

void LinearSearch(List *list)
{
    list->curr = list->head;
    while (list->curr != NULL)
    {
        printf("%d", list->curr->data);
        list->curr = list->curr->next;
    }
}

int Delete(List *list, int data)
{

    //우리가 삭제하려는 data는 curr
    //삭제 전에 prev를 curr의 오른쪽에 노드와 연결 해야 하며
    //시작점의 삭제이면 list->head를 list->head->next로 바꾼다.
    //끝이면 list -> prev를 list->tail로 변환시킨다.
    Node *delNode;
    if ((IsEmpty(list)))
    {

        return FALSE;
        // delNode=list->head;
        // list->head=list->head->next;
        // free(delNode);
    }

    list->prev = NULL;
    list->curr = list->head;
    // list->curr은 탐색을 위한 포인터 변수

    while (list->curr != NULL && list->curr->data != data)
    {
/*

리스트를 순회하면서 주어진 데이터와 일치하는 데이터를 가진 노드(list->curr)를 찾습니다. 데이터가 일치하지 않는 동안 리스트를 계속 순회합니다. 이 루프를 통해 삭제하고자 하는 노드를 정확히 식별할 수 있으며, 노드를 삭제하기 전에 list->prev와 list->curr 포인터를 적절히 설정하여 노드 삭제 후 리스트의 연결성을 유지할 수 있습니다.*/
        list->prev = list->curr;
        list->curr = list->curr->next;
    }
    
    if (list->curr == NULL) // 못찾았으면 curr이 이동하다가 최종끝인 NULL로 감
    // 맨끝 노드의 next는 NULL이니까
    {
        return FALSE;
    }

    delNode = list->curr;

    if (delNode == list->head)
    { // 삭제 하는 곳이 시작점 일때
        list->head = list->head->next;
    }

    else
    {
        list->prev->next = delNode->next;
        // 삭제할 노드 앞에 있는 node를(next를 통해 연결하니까)
        //  list->prev를 이어주려 하니까  list->prev->next를 delNode->next로

        if (delNode == list->tail)
        {
            list->tail = list->prev;
            // list->prev가 새로운 list->tail이 된다.
        }
    }
    free(delNode); // 특정 변수 삭제 삭제하기 전에 이어주고 삭제
    delNode=NULL;
    list->NumOfData--;
    return data;
}

void DeleteAll(List *list)
{
    Node *delNode;
    while (!(IsEmpty(list)))
    {
        delNode = list->head;
        list->head = list->head->next;
        free(delNode);
    }

    list->tail = NULL;
    list->curr = NULL;
    list->NumOfData = 0;
}