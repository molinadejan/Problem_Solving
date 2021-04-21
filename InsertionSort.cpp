#include <iostream>

// Insertion Sort 알고리즘을 사용해서 작은 값이 앞으로 오도록 
// List를 정렬한 다음 head를 반환하는 함수를 만드세요.

// 입력값 : head -> 2 -> 10 -> 7 -> 6 -> 20
// 반환값 : head -> 2 -> 6 -> 7 -> 10 -> 20

struct ListNode
{
	int val;
	ListNode* nextNode;
	ListNode(int x, ListNode* next) : val(x), nextNode(next) {}
	~ListNode() {std::cout << val << " delete!\n"; }
};

void PrintList(ListNode* start)
{
	ListNode* iter = start;

	while (iter != NULL)
	{
		std::cout << iter->val << " ";
		iter = iter->nextNode;
	}

	std::cout << std::endl;
}

ListNode* InsertionSort(ListNode* head)
{
	ListNode* key = head, *tmp;

	while (key->nextNode != NULL)
	{
		if (key->val > key->nextNode->val)
		{
			tmp = key->nextNode;
			key->nextNode = key->nextNode->nextNode;
			tmp->nextNode = head;
			head = key = tmp;

			PrintList(head);

			continue;
		}

		key = key->nextNode;
	}

	return head;
}

int main(void)
{
	ListNode* n0 = new ListNode(20, NULL);
	ListNode* n1 = new ListNode(6, n0);
	ListNode* n2 = new ListNode(7, n1);
	ListNode* n3 = new ListNode(10, n2);
	ListNode* n4 = new ListNode(2, n3);

	InsertionSort(n4);

	delete n0;
	delete n1;
	delete n2;
	delete n3;
	delete n4;

	return 0;
}