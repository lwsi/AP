/*****************************************************************************
** File Name:        List.cpp
** Author:           SiQi_Wang
** Date:             2018/03/01
** Version:          1.0
** Description:      Copyright(c) 2018, All rights reserved.
******************************************************************************
**                         Important Edit History                            *
** --------------------------------------------------------------------------*
** DATE           NAME             DESCRIPTION                               *
** 2018/03/01    SiQi_Wang             Create                                *
******************************************************************************/

/*---------------------------------------------------------------------------*
**                         Include Files                                     *
**---------------------------------------------------------------------------*/
#include "stdafx.h"
#include "List.h"
#include <cstdio>
#include <cstdlib>

/*---------------------------------------------------------------------------*
**                       Export Function Definition                          *
**---------------------------------------------------------------------------*/

ListNode* CreateListNode(int value)
{
	ListNode* pNode = new ListNode();
	pNode->Val = value;
	pNode->Next = nullptr;

	return pNode;
}

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
	if (pCurrent == nullptr)
	{
		printf("Error to connect two nodes.\n");
		exit(1);
	}

	pCurrent->Next = pNext;
}

void PrintListNode(ListNode* pNode)
{
	if (pNode == nullptr)
	{
		printf("The node is nullptr\n");
	}
	else
	{
		printf("The key in node is %d.\n", pNode->Val);
	}
}

void PrintList(ListNode* pHead)
{
	printf("PrintList starts.\n");

	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		printf("%d\t", pNode->Val);
		pNode = pNode->Next;
	}

	printf("\nPrintList ends.\n");
}

void DestroyList(ListNode*pHead)
{
	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		pHead = pHead->Next;
		delete pNode;
		pNode = pHead;
	}
}

void AddToTail(ListNode** pHead, int value)
{
	ListNode* pNew = new ListNode();
	pNew->Val = value;
	pNew->Next = nullptr;

	if (*pHead == nullptr)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->Next != nullptr)
			pNode = pNode->Next;

		pNode->Next = pNew;
	}
}

void RemoveNode(ListNode** pHead, int value)
{
	if (pHead == nullptr || *pHead == nullptr)
		return;

	ListNode* pToBeDeleted = nullptr;
	if ((*pHead)->Val == value)
	{
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->Next;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->Next != nullptr && pNode->Next->Val != value)
			pNode = pNode->Next;

		if (pNode->Next != nullptr && pNode->Next->Val == value)
		{
			pToBeDeleted = pNode->Next;
			pNode->Next = pNode->Next->Next;
		}
	}

	if (pToBeDeleted != nullptr)
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}