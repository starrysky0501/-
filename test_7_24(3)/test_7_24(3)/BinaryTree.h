#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<stdlib.h>
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
void BinaryTreeDestory(BTNode** root);
int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelKSize(BTNode* root, int k);
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// 遍历
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);
// 非递归遍历
void BinaryTreeLevelOrder(BTNode* root);// 层序遍历
int BinaryTreeComplete(BTNode* root);   // 判断二叉树是否是完全二叉树
void TestBinaryTree1();
void TestBinaryTree2();
void TestBinaryTree3();