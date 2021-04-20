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
};

ListNode* InsertionSort(ListNode* head)
{
	ListNode* key = head, *tmp;

	while (key->nextNode != NULL)
	{
		if (key->val > key->nextNode->val)
		{
			tmp = key->nextNode; // tmp = 7
			key->nextNode = key->nextNode->nextNode; // 10 -> 6
			tmp->nextNode = head; // 7 -> 2
			head = key = tmp; //
			continue;
		}

		key = key->nextNode;
	}

	return head;
}

int main(void)
{
	ListNode n0(20, NULL);
	ListNode n1(6, &n0);
	ListNode n2(7, &n1);
	ListNode n3(10, &n2);
	ListNode head(2, &n3);

	ListNode* iter = InsertionSort(&head);

	while (iter != NULL)
	{
		std::cout << iter->val << std::endl;
		iter = iter->nextNode;
	}

	return 0;
}