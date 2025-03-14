#pragma once
#include<stdio.h>
#include <stdlib.h>

typedef int SLTDataType;
typedef struct SListNode SLTNode;

void SLTPrint(SLTNode* phead);

//ͷ������ɾ��/β������ɾ��
void SLTPushBack(SLTNode** pphead, SLTDataType x);
void SLTPushFront(SLTNode** pphead, SLTDataType x);
void SLTPopBack(SLTNode** pphead);
void SLTPopFront(SLTNode** pphead);

//����
SLTNode* SLTFind(SLTNode* phead, SLTDataType x);
//��ָ��λ��֮ǰ��������
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//ɾ��pos�ڵ�
void SLTErase(SLTNode** pphead, SLTNode* pos);
//��ָ��λ��֮���������
void SLTInsertAfter(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//ɾ��pos֮��Ľڵ�
void SLTEraseAfter(SLTNode** pphead, SLTNode* pos);
//��������
void SListDesTroy(SLTNode** pphead);
