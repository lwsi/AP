/*****************************************************************************
** File Name:        List.h
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

#pragma once

/**--------------------------------------------------------------------------*
**                         Self-Type Definition                              *
**---------------------------------------------------------------------------*/
struct ListNode
{
	int       Val;
	ListNode* Next;
	ListNode(int x) : val(x), Next(NULL) {}
};

__declspec(dllexport) ListNode* CreateListNode(int value);
__declspec(dllexport) void ConnectListNodes(ListNode* pCurrent, ListNode* pNext);
__declspec(dllexport) void PrintListNode(ListNode* pNode);
__declspec(dllexport) void PrintList(ListNode* pHead);
__declspec(dllexport) void DestroyList(ListNode* pHead);
__declspec(dllexport) void AddToTail(ListNode** pHead, int value);
__declspec(dllexport) void RemoveNode(ListNode** pHead, int value);
