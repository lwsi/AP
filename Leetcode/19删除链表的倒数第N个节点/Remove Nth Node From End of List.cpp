// Remove Nth Node From End of List.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "List.h"

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* pNode = head;
		ListNode* fast = head;
		ListNode* slow = head;
		for (int i = 0; i < n; ++i) fast = fast->next;
		if (fast == nullptr)
		{
			pNode = head->next;
			delete head; head = nullptr;
			return pNode;
		}
		while (fast->next != nullptr)
		{
			fast = fast->next;
			slow = slow->next;
		}
		ListNode* pNext = slow->next;
		slow->next = pNext->next;
		delete pNext; pNext = nullptr;
		return head;
	}
};

int main()
{

    return 0;
}

