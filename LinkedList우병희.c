

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
    Node *head; //node pointer���� Ư�� ��忡 �ּҸ� ��� �ִ� ����
    Node *tail;
    Node *curr; // node���� ������ ������ �ִ� node(pointer),���� ��带 ����Ű�� pointer
    //����Ʈ ��ȸ�� ���� ��ġ ������ ����
    int NumOfData; //list�� �ִ� ������(node)�� ��

} List;

void ListInit(List *list);
void ListInsert(List *list, int data); // tail�� �����͸� �߰��ϴ� ���
void LinearSearch(List *list);
int IsEmpty(List *list);
int Count(List *list);
void DeleteAll(List *list); // ������ ������(node)�� ��� �����ϴ� ���,������ head����

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
    //Node newNode �̷��� local������ ���� ���ư�
    // �����Ҵ��ϸ� newNode��� ������ ���������� �Ҵ��Ų �޸𸮴� ��������
    //�Լ����� ���ư��� ������ ���ư��ϱ�
    //�޸𸮴� ���α׷����ų� free�ؾ� ���ư�
    newNode -> data=data;
    newNode -> next=NULL; // next�� �ʱ� �� null�� �ؾ� �� �ȱ׷��� dummy�ּ� ���� ����
    if(IsEmpty(list)){
        //ó�� ����� node�� head���� tail
        list->head=newNode;
        list->tail=newNode;
        //ó������ head�� tail�� ����
    }else{
        // tail�� ����� ������ tail�� next�� newNode �� ���� node�� ���� ���� �ǰ�
        // �� ������ ����� tail(���λ��� node)�� newNode�̴�.

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
    list->curr=list->head; // head���� curr������ �����ϰ� ���� node�� �̵��ϴ� �ʱ�ȭ�� head��

    while (list->curr!=NULL){

        printf("%d\n",list->curr->data);
        list->curr=list->curr->next;
        //curr�� ó���� head�̰� 
        //head�� next�� �� ���� node�� data�̴�(head������ �ϳ��� �ִٸ� �̰� tail)
        //�׷��Ƿ� list->curr�� list->curr->next�� �Ǵ� ���� �״��� node�� �Ѿ�� ���� �ΰ�

    }
}

void DeleteAll(List *list)
{
    Node *delNode; //�̹� �Ҵ�� ��� �����ϱ� ���ؼ� �̷��� ���� ��
    //Node *delNode = (Node *)malloc(sizeof(Node)); �����Ҵ��� ���ؼ� ���� ��
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

/*
�� ������ ���ο� Node Ÿ���� �޸� ������ �������� �Ҵ��մϴ�.
malloc �Լ��� ������ ũ��(sizeof(Node))�� �޸� ����� �Ҵ��ϰ�, �� �޸� ����� ���� �ּҸ� ��ȯ�մϴ�.
�� ����� ���ο� Node�� ������ �� ���˴ϴ�. ��, ���� ����Ʈ�� ���ο� ��带 �߰��� �� �̷� ������� �޸𸮸� �Ҵ��ϰ�, ����� ������ �� �����͸� �����մϴ�.
���� �Ҵ�� �޸𸮴� ��� �� free() �Լ��� ȣ���Ͽ� ��������� �����ؾ� �մϴ�. �׷��� ������ �޸� ������ �߻��� �� �ֽ��ϴ�.
Node *delNode;:

�� ������ �ܼ��� Node Ÿ���� ������ ���� delNode�� �����մϴ�. �� ��, ���� Node Ÿ���� �޸� ������ �Ҵ���� �ʽ��ϴ�.
delNode�� �̹� �����ϴ� Node ��ü�� ����Ű�� �� ���� �� �ֽ��ϴ�. ���� ���, ���� ����Ʈ�� ��带 ����Ű�ų� ��ȸ�ϴ� �� ���˴ϴ�.
�� ����� ���ο� �޸� �Ҵ��� �ʿ����� ���� ��Ȳ���� ���˴ϴ�. ���� ���, ����Ʈ���� ��带 �����ϴ� ���, delNode�� ����Ͽ� ������ ��带 ����Ű�� free() �Լ��� �޸𸮸� ������ �� �ֽ��ϴ�.
����, Node *delNode = (No
*/