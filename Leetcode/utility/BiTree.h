/*****************************************************************************
** File Name:        BiTree.h
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

#pragma once

/**--------------------------------------------------------------------------*
**                         Self-Type Definition                              *
**---------------------------------------------------------------------------*/
struct BiTreeNode
{
	int Val;
	BiTreeNode* pLeft;
	BiTreeNode* pRight;
};

/*---------------------------------------------------------------------------*
**                          Export Function Declare                          *
**---------------------------------------------------------------------------*/
__declspec(dllexport) BiTreeNode* CreateBiTreeNode(int Val);
__declspec(dllexport) void ConnectTreeNodes(BiTreeNode* pParent, BiTreeNode* pLeft, BiTreeNode* pRight);
__declspec(dllexport) void PrintTreeNode(const BiTreeNode* pNode);
__declspec(dllexport) void PrintTree(const BiTreeNode* pRoot);
__declspec(dllexport) void DestroyTree(BiTreeNode* pRoot);
