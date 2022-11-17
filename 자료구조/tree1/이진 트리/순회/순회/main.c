// ��ȸ
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

// ���� ��ȸ
preorder(TreeNode* root) 
{
	 if (root != NULL) { // ���� ����
		 printf("[%d] ", root->data); // ��� �湮(���⼭ �湮�� ����ϴ� ������ ��������. �湮�� ���뿡 ���� �ǹ̰� �޶��� �� �ִ�.)
		 preorder(root->left);	// ���� ���� Ʈ�� ��ȸ
		 preorder(root->right);	// ������ ���� Ʈ�� ��ȸ
	}
}
// ���� ��ȸ
Inorder(TreeNode* root)
{
	if (root != NULL) { // ���� ����
		Inorder(root->left);	// ���� ���� Ʈ�� ��ȸ
		printf("[%d] ", root->data); // ��� �湮
		Inorder(root->right);	// ������ ���� Ʈ�� ��ȸ
	}
}
// ���� ��ȸ
postorder(TreeNode* root)
{
	if (root != NULL) { // ���� ����
		postorder(root->left);	// ���� ���� Ʈ�� ��ȸ
		postorder(root->right);	// ������ ���� Ʈ�� ��ȸ
		printf("[%d] ", root->data); // ��� �湮
	}
}

int main() {
	printf("���� ��ȸ ��� : "); // [15] [4] [1] [20] [16] [25]
	preorder(root);
	printf("\n");

	printf("���� ��ȸ ��� : "); // [1] [4] [15] [16] [20] [25]
	Inorder(root);
	printf("\n");

	printf("���� ��ȸ ��� : "); // [1] [4] [16] [25] [20] [15]
	postorder(root);
	printf("\n");

	return 0;
}