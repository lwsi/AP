/*****************************************************************************
** File Name:        BiTree.cpp
** Author:           SiQi_Wang
** Date:             2018/02/11
** Version:          1.0
** Description:      Copyright(c) 2018, All rights reserved.
******************************************************************************
**                         Important Edit History                            *
** --------------------------------------------------------------------------*
** DATE           NAME             DESCRIPTION                               *
** 2018/02/11    SiQi_Wang             Create                                *
******************************************************************************/

/*---------------------------------------------------------------------------*
**                         Include Files                                     *
**---------------------------------------------------------------------------*/
#include "stdafx.h"
#include "BiTree.h"
#include <cstdio>


/*---------------------------------------------------------------------------*
**                       Export Function Definition                          *
**---------------------------------------------------------------------------*/
BiTreeNode* CreateBiTreeNode(int Val)
{
	BiTreeNode* pNode = new BiTreeNode();
	pNode->Val = Val;
	pNode->pLeft = nullptr;
	pNode->pRight = nullptr;

	return pNode;
}

void ConnectTreeNodes(BiTreeNode* pParent, BiTreeNode* pLeft, BiTreeNode* pRight)
{
	if (pParent != nullptr)
	{
		pParent->pLeft = pLeft;
		pParent->pRight = pRight;
	}
}

void PrintTreeNode(const BiTreeNode* pNode)
{
	if (pNode != nullptr)
	{
		printf("value of this node is: %d\n", pNode->Val);

		if (pNode->pLeft != nullptr)
			printf("value of its left child is: %d.\n", pNode->pLeft->Val);
		else
			printf("left child is nullptr.\n");

		if (pNode->pRight != nullptr)
			printf("value of its right child is: %d.\n", pNode->pRight->Val);
		else
			printf("right child is nullptr.\n");
	}
	else
	{
		printf("this node is nullptr.\n");
	}

	printf("\n");
}

void PrintTree(const BiTreeNode* pRoot)
{
	PrintTreeNode(pRoot);

	if (pRoot != nullptr)
	{
		if (pRoot->pLeft != nullptr)
			PrintTree(pRoot->pLeft);

		if (pRoot->pRight != nullptr)
			PrintTree(pRoot->pRight);
	}
}

void DestroyTree(BiTreeNode* pRoot)
{
	if (pRoot != nullptr)
	{
		BiTreeNode* Left = pRoot->pLeft;
		BiTreeNode* Right = pRoot->pRight;

		delete pRoot;
		pRoot = nullptr;

		DestroyTree(Left);
		DestroyTree(Right);
	}
}
