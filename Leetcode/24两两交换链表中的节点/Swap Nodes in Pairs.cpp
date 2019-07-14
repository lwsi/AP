// Swap Nodes in Pairs.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

 struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == nullptr) return nullptr;
		else if (head->next == nullptr) return head;
		ListNode* pre = head;
		ListNode* cur = pre->next;
		pre->next = swapPairs(cur->next);
		cur->next = pre;
		return cur;
	}
};

int main()
{
    return 0;
}

