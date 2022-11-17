// 순회
#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;
//		 15
//	 4		 20
// 	1	 	 16 25
TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

// 전위 순회
preorder(TreeNode* root) 
{
	 if (root != NULL) { // 종료 조건
		 printf("[%d] ", root->data); // 노드 방문(여기서 방문은 출력하는 것으로 정의하자. 방문은 응용에 따라 의미가 달라질 수 있다.)
		 preorder(root->left);	// 왼쪽 서브 트리 순회
		 preorder(root->right);	// 오른쪽 서브 트리 순회
	}
}
// 중위 순회
Inorder(TreeNode* root)
{
	if (root != NULL) { // 종료 조건
		Inorder(root->left);	// 왼쪽 서브 트리 순회
		printf("[%d] ", root->data); // 노드 방문
		Inorder(root->right);	// 오른쪽 서브 트리 순회
	}
}
// 후위 순회
postorder(TreeNode* root)
{
	if (root != NULL) { // 종료 조건
		postorder(root->left);	// 왼쪽 서브 트리 순회
		postorder(root->right);	// 오른쪽 서브 트리 순회
		printf("[%d] ", root->data); // 노드 방문
	}
}

int main() {
	printf("전위 순회 결과 : "); // [15] [4] [1] [20] [16] [25]
	preorder(root);
	printf("\n");

	printf("중위 순회 결과 : "); // [1] [4] [15] [16] [20] [25]
	Inorder(root);
	printf("\n");

	printf("후위 순회 결과 : "); // [1] [4] [16] [25] [20] [15]
	postorder(root);
	printf("\n");

	return 0;
}