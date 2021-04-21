#include <iostream>
#include <stack>

// preorder 종주를 하면서 각 노드의 값을 출력

// 입력값 : 
//       10
//    /      \
//   7       16
//  /  \    /   \
// 2   8   11   18

// 반환값 : 10, 7, 2, 8, 16, 11, 18

struct TreeNode
{
	int val;
	TreeNode* leftNode;
	TreeNode* rightNode;

	TreeNode(int x, TreeNode* left = nullptr, TreeNode* right = nullptr)
		: val(x), leftNode(left), rightNode(right) { }
};

void PreorderTraversal(TreeNode* root)
{
	if (root == nullptr)
		return;

	std::cout << root->val << " ";

	PreorderTraversal(root->leftNode);
	PreorderTraversal(root->rightNode);
}

void PreorderTraversalStack(TreeNode* root)
{
	std::stack<TreeNode*> s;
	s.push(root);

	while (!s.empty())
	{
		TreeNode* curNode = s.top();
		s.pop();

		std::cout << curNode->val << " ";

		if (curNode->leftNode != nullptr)
			s.push(curNode->rightNode);

		if (curNode->rightNode != nullptr)
			s.push(curNode->leftNode);
	}
}

int main(void)
{
	TreeNode* node0 = new TreeNode(18);
	TreeNode* node1 = new TreeNode(11);
	TreeNode* node2 = new TreeNode(8);
	TreeNode* node3 = new TreeNode(2);

	TreeNode* node4 = new TreeNode(16, node1, node0);
	TreeNode* node5 = new TreeNode(7, node3, node2);

	TreeNode* root = new TreeNode(10, node5, node4);

	PreorderTraversal(root);

	std::cout << "\n";

	PreorderTraversalStack(root);

	return 0;
}