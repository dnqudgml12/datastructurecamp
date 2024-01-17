/*
1에서 n까지의 숫자를 순차적으로 스택에 삽입하였을 때에
역순으로 출력되어야 한다.

***결과 예시***
Stack output: 5 4 3 2 1
*/
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100

typedef struct _arrayStack
{
    int arr[STACK_LEN]; //하나의 배열
    int top; // 현재 위치한, 데이터를 삽입할 인덱스를 나타낸 것

} Stack;

void StackInit(Stack *s); //스택을 초기화 하는 ADT(함수)
void StackPush(Stack *s, int data); // 데이터를 삽입하는 함수
void StackPop(Stack *s); // 데이터를 삭제하는 ADT함수
int StackPeek(Stack *s); // 데이터를 반환해주는 (단, 삭제하지 않은) 함수
int StackSize(Stack *s); // 스택에 저장된 데이터의 갯수를 반환해주는 함수
int IsEmpty(Stack *s); // 스택이 비어있는지 확인해주는 함수
int IsFull(Stack *s); // 스택이 가득차 있는지 확인해주는 함수

int main()
{

    Stack s;

    StackInit(&s);

    for (int i = 0; i < 5; i++)
    {
        StackPush(&s, i + 1);
    }

    printf("Stack output: ");

    for (int i = 0; i < 5; i++)
    {

        printf("%d ", StackPeek(&s));
        StackPop(&s);
    }

    if (IsEmpty(&s))
        printf("\nStack is empty...!\n");
    else
        printf("\nStack is not Empty...!\n");

    return 0;
}

void StackInit(Stack *s)
{
    s->top=-1;  //0으로 하면 하나라도 있는 것이니 -1로 초기화
    /*
    1.스택의 시작위치를 설정한다.
    */
}

// 초기 값 다르게 하고 시험 물어봄

int IsEmpty(Stack *s)
{
    return (s->top < 0 ?TRUE:FALSE); 
    /*
    1. 만약 현재 top의 위치가 0보다 작으면, TRUE를 반환한다.
    2. 그렇지 않으면, FALSE를 반환한다.
    */
}

int IsFull(Stack *s)
{

  return (s->top >= STACK_LEN- 1) ? TRUE : FALSE;
    /*
    1. 만약 현재 top의 위치가 스택의 최종인덱스와 비교하여 크거나 같다면
    TRUE를 반환
    2. 그렇지 않으면, FALSE를 반환
    */
}
void StackPush(Stack *s, int data)
{

    if(IsFull(s)){
        printf("Stack is full!\n");
        return;
    }

    s->arr[++s->top] = data; // top의 위치를 증가
    // top 시작이 인덱스를 -1로 되니 ++통해 0으로 증가
    
    
    /*
    스택이 가득차있으면, 예외처리(단순 return 혹은 exit(), 특정 문구 출력 등)
    1.top의 위치를 증가시킨다.
    2.증가시킨 top의 위치에 해당 데이터를 삽입한다.
    */
}

void StackPop(Stack *s)
{

    if(IsEmpty(s)){
        printf("Stack is empty");
        return;
    }
    --s->top;
    /*
    스택이 비어있으면, 예외처리(단순 return 혹은 exit(), 특정 문구 출력 등)
    그렇지 않으면
    1.top의 위치를 감소시킨다.
    */
}

int StackPeek(Stack *s)
{
    if(IsEmpty(s)){
        printf("Stack is empty");
        return -1;
    }

    return s->arr[s->top];


    /*
    스택이 비어있으면, 예외처리(단순 return 혹은 exit(), 특정 문구 출력 등)
    그렇지 않으면
    1. 현재 top이 위치한 데이터의 값을 반환한다.
    */
}

int StackSize(Stack *s)
{
    return s->top+1; //시작점이 0이니까
    /*
    1. 현재 저장된 데이터의 갯수를 반환한다.
    */
}