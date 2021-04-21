#include <iostream>

// �ð����⵵�� ����Ͽ� �־��� List�� ���������� n��° node�� ã�ƶ�

// �Է°� : head -> 2 -> 1 -> 3 -> 6 -> 10 -> 5, 2��°
// ��ȯ�� : 10

struct ListNode
{
	int val;
	ListNode* nextNode;
	ListNode(int x, ListNode* next) : val(x), nextNode(next) { }
};

ListNode* FindNthNodeFromLast(ListNode* head, int n)
{
	ListNode* normalPtr = head;
	ListNode* accelerate = head;

	for (int i = 0; i < n - 1 && accelerate != NULL; ++i)
		accelerate = accelerate->nextNode;

	while (accelerate != NULL && accelerate->nextNode != NULL)
	{
		normalPtr = normalPtr->nextNode;
		accelerate = accelerate->nextNode;
	}

	return normalPtr;
}

int main(void)
{
	ListNode* n0 = new ListNode(5, NULL);
	ListNode* n1 = new ListNode(10, n0);
	ListNode* n2 = new ListNode(6, n1);
	ListNode* n3 = new ListNode(3, n2);
	ListNode* n4 = new ListNode(1, n3);
	ListNode* n5 = new ListNode(2, n4);

	std::cout << FindNthNodeFromLast(n5, 2)->val << std::endl;

	delete n0;
	delete n1;
	delete n2;
	delete n3;
	delete n4;



	return 0;
}