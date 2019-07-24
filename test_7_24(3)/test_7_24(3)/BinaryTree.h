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
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
void BinaryTreeDestory(BTNode** root);
int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelKSize(BTNode* root, int k);
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// ����
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);
// �ǵݹ����
void BinaryTreeLevelOrder(BTNode* root);// �������
int BinaryTreeComplete(BTNode* root);   // �ж϶������Ƿ�����ȫ������
void TestBinaryTree1();
void TestBinaryTree2();
void TestBinaryTree3();