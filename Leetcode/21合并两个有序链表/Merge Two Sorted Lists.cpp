// Merge Two Sorted Lists.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* pNode = new ListNode(0);
		ListNode* pHead = pNode;
		while (l1 != nullptr && l2 != nullptr)
		{
			if (l1->val < l2->val) { pNode->next = l1; l1 = l1->next; }
			else { pNode->next = l2; l2 = l2->next; }
			pNode = pNode->next;
		}
		if (l1 != nullptr) pNode->next = l1;
		if (l2 != nullptr) pNode->next = l2;
		return pHead->next;
	}
};

int main()
{
	return 0;
}

