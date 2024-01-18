#include <stdio.h>
#include <stdlib.h>

/*트리에 대한 구조체를 선언하지 않는이유?
하나의 노드만 존재하여도, 이진트리를 만족하기 때문이다.
*/
typedef struct _bTreeNode
{

    int data;
    struct _bTreeNode *left;
    struct _bTreeNode *right;

} TreeNode;

TreeNode *MakeNode(); // 노드의 생성

void setData(TreeNode *node, int data); // 노드에 데이터 저장
int getData(TreeNode *node);            // 노드에 저장된 데이터 반환

void SetLeftSubTree(TreeNode *parentNode, TreeNode *nodeToAdd);  // 왼쪽 서브 트리의 연결
void SetRightSubTree(TreeNode *parentNode, TreeNode *nodeToAdd); // 오른쪽 서브트리의 연결
TreeNode *GetLeftSubTree(TreeNode *parentNode);                  // 왼쪽 서브 트리의 주소반환
TreeNode *GetRightSubTree(TreeNode *parentNode);                 // 오른쪽 서브 트리의 주소반환
void Inorder(TreeNode *node);
void Preorder(TreeNode *node);
void Postorder(TreeNode *node);

int main()
{
    TreeNode *node1 = MakeNode();
    setData(node1, 1);
    TreeNode *node2 = MakeNode();
    setData(node2, 2);
    TreeNode *node3 = MakeNode();
    setData(node3, 3);
    TreeNode *node4 = MakeNode();
    setData(node4, 4);
    TreeNode *node5 = MakeNode();
    setData(node5, 5);
    TreeNode *node6 = MakeNode();
    setData(node6, 6);

    SetLeftSubTree(node1, node2);
    SetRightSubTree(node1, node3);
    SetLeftSubTree(node2, node4);
    SetRightSubTree(node2, node5);
    SetRightSubTree(node3, node6);

    printf("Node1's left : %d\n", getData(GetLeftSubTree(node1)));
    printf("Node2's right : %d\n\n", getData(GetRightSubTree(node2)));
    printf("preorder : ");
    Preorder(node1);
    printf("\n");

    printf("inorder : ");
    Inorder(node1);
    printf("\n");

    printf("postorder : ");
    Postorder(node1);
    printf("\n");
    return 0;
}

TreeNode *MakeNode()
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    // 메모리 값을 넣을 노드 지정
    newNode->left = NULL;
    // node의 왼쪽 만들기
    newNode->right = NULL;
    // node의 오른쪽 만들기
}

void setData(TreeNode *node, int data)
{
    if (node != NULL)
    {
        node->data = data;
        // node의 data포인터 변수에 data값넣기
    }
}
int getData(TreeNode *node)
{
    if (node != NULL)
    {
        return node->data;
        // node의 data포인터 변수 출력
    }
    return -1;
}

void SetLeftSubTree(TreeNode *parentNode, TreeNode *nodeToAdd)
{
    if (parentNode != NULL)
    {
        parentNode->left = nodeToAdd;
        // parentNode 즉 부모 노드의 left 포인터 변수에 node 값 넣기
        // 부모 노드의 왼쪽에  node 값을 지정
    }
}
void SetRightSubTree(TreeNode *parentNode, TreeNode *nodeToAdd)
{
    if (parentNode != NULL)
    {
        parentNode->right = nodeToAdd;
        // parentNode 즉 부모 노드의 right 포인터 변수에 node 값 넣기
        // 부모 노드의 오른쪽에 node값 지정
    }
}

TreeNode *GetLeftSubTree(TreeNode *parentNode)
{
    if (parentNode != NULL)
    {
        return parentNode->left;
        // parentNode의 왼쪽에 있는 값 출력
    }
    return NULL;
}
TreeNode *GetRightSubTree(TreeNode *parentNode)
{
    if (parentNode != NULL)
    {
        return parentNode->right;
        // parentNode의 오른쪽에 있는 값 출력
    }
    return NULL;
}

void Inorder(TreeNode *node)
{
    /*
    각 노드마다 재귀함수 틀(
             Inorder(node->left);
            printf("%d",node->data);
            Inorder(node->right);
    )발동하므로 node가 NULL이 되면 재귀함수 탈출 함
    Inorder은 왼쪽부모오른쪽 으로 진행
    root 노드에서 왼쪽이 null이 아니라면 왼쪽으로 이동,
    다시 그 노드에서 왼쪽이 null이 아니라면 왼쪽으로 이동
    그리고 이동한 노드에서 왼쪽이 null이면 해당 노드 출력 후 해당 노드의 오른쪽을 보고
    오른쪽이 null이라면 해당 노드의 상위 노드로 이동해서 출력후 왼쪽 탐색끝났으므로 오른쪽 탐색 이후 똑같이 탐색

    */

    if (node != NULL)
    {
        Inorder(node->left);
        printf("%d", node->data);
        Inorder(node->right);
        //
    }
}
void Preorder(TreeNode *node)
{
    /*
    각 노드마다 재귀함수틀(
            printf("%d",node->data);
            Preorder(node->left);
            Preorder(node->right);

    ) 발동하므로 node가 NULL이 되면 재귀함수 탈출 함
    Preorder은 부모왼쪽오른쪽
    항상 노드 이동하면 그 노드에서 재귀체크

    root 노드 값 출력 후 왼쪽이 null이 아니라면 왼쪽으로 이동
    왼쪽으로 이동 후 해당 노드 값 출력 후 해당 노드의 왼쪽이 null이 아니라면 다시 왼쪽으로 이동
    왼쪽으로 이동 후 해당 노드 값 출력후 해당 노드 왼쪽 null이라면 오른쪽도 보고 null이라면 상위 노드 이동
    바로 상위 노드(두번째 줄에서 이동하기 전 node)에서 왼쪽은 탐색이 끝났으므로 오른쪽 이동 똑같이 탐색
    탐색 후 마치면 다시 상위 노드 이동
    */

    if (node != NULL)
    {
        printf("%d", node->data);
        Preorder(node->left);
        Preorder(node->right);
    }
}
void Postorder(TreeNode *node)
{
    /*
     각 노드마다 재귀함수 틀(        Postorder(node->left);
            Postorder(node->right);
            printf("%d",node->data);)발동하므로 node가 NULL이 되면 재귀함수 탈출 함
    Postorder은 왼쪽오른쪽부모

    rootnode에서 왼쪽 이동 후 null이 아니라면
    해당 노드에서 다시 왼쪽이 null이 아니라면 이동 후
    그 노드에서 다시 재귀 체크
    그 노드에서 왼쪽이 null이면 오른쪽도 null인지 체크 후 null이면 그 노드 출력
    다시 해당 노드보다 상위로 (두번째 줄의 node)이동 후 그 노드의 왼쪽 탐색이 끝났으므로 오른쪽 탐색
    이후 반복

        */
    if (node != NULL)
    {

        Postorder(node->left);
        Postorder(node->right);
        printf("%d", node->data);
    }
}