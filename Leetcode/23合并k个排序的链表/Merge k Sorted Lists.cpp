// Merge k Sorted Lists.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
		ListNode* mergeCore(ListNode* l1, ListNode* l2)
		{
			ListNode* pNode = new ListNode(0);
			ListNode* pHead = pNode;
			while (l1 != nullptr && l2 != nullptr)
			{
				if (l1->val < l2->val)
				{
					pNode->next = l1;
					l1 = l1->next;
				}
				else
				{
					pNode->next = l2;
					l2 = l2->next;
				}
				pNode = pNode->next;
			}
			if (l1 != nullptr) pNode->next = l1;
			if (l2 != nullptr) pNode->next = l2;
			return pHead->next;
		}
		ListNode* mergeKLists1(vector<ListNode*>& lists) {
			if (lists.empty()) return nullptr;
			int n = lists.size();
			while (n > 1) {
				int k = (n + 1) / 2;
				for (int i = 0; i < n / 2; ++i) {
					lists[i] = mergeCore(lists[i], lists[i + k]);
				}
				n = k;
			}
			return lists[0];
		}
	static struct comp { bool operator()(ListNode* l, ListNode* r) { return l->val > r->val; } };
	ListNode* mergeKLists2(vector<ListNode*>& lists)
	{
		priority_queue<ListNode*, vector<ListNode*>, comp> q;
		for (auto l : lists) if (l) q.push(l);
		if (q.empty()) return nullptr;
		ListNode* result = q.top();
		q.pop();
		if (result->next) q.push(result->next);
		ListNode* pNode = result;
		while (!q.empty())
		{
			pNode->next = q.top();
			q.pop();
			pNode = pNode->next;
			if (pNode->next) q.push(pNode->next);
		}
		return result;
	}
	ListNode* mergeKLists3(vector<ListNode*>& lists)
	{
		ListNode* pHead = new ListNode(0);
		ListNode* pNode = pHead;
		vector<ListNode*> v;
		for (auto i : lists) if (i) v.push_back(i);
		make_heap(v.begin(), v.end(), comp());
		while (!v.empty())
		{
			pNode->next = v.front();
			pop_heap(v.begin(), v.end(), comp());
			v.pop_back();
			pNode = pNode->next;
			if (pNode->next)
			{
				v.push_back(pNode->next);
				push_heap(v.begin(), v.end(), comp());
			}
		}
		return pHead->next;
	}
};

int main()
{

    return 0;
}

