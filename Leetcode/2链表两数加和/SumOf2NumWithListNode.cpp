// SumOf2NumWithListNode.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include <iostream>
using namespace std;

static auto x = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	return 0;
}();

class Solution {
public:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr || l2 == nullptr) return nullptr;
		int extra = 0;
		ListNode *pNode = new ListNode(0);
		ListNode *pHead = pNode;
		while (l1 || l2 || extra)
		{
			extra += l1 ? l1->val : 0 + l2 ? l2->val : 0;
			pNode->next = new ListNode(extra % 10);
			pNode = pNode->next; extra /= 10;
			l1 = (l1 ? l1->next : nullptr); l2 = (l2 ? l2->next : nullptr);
		}

		return pHead->next;
	}
};

int main()
{
    return 0;
}

