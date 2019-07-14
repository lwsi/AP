// Reverse Nodes in k-Group.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == nullptr || k == 1) return head;
		int count = 0;
		ListNode *preheader = new ListNode(0);
		preheader->next = head;
		ListNode *pre = preheader, *cur = preheader, *nex;
		while (cur = cur->next) ++count;
		while (count >= k)
		{
			cur = pre->next;
			nex = cur->next;
			for (int i = 1; i < k; ++i)
			{
				cur->next = nex->next;
				nex->next = pre->next;
				pre->next = nex;
				nex = cur->next;
			}
			pre = cur;
			count -= k;
		}
		return preheader->next;
	}
};

int main()
{
    return 0;
}

