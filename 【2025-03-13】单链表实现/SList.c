#include"SList.h"
// ʵ�ֵ��������ɾ�Ĳ�


typedef struct SListNode
{
	SLTDataType data;
	SLTNode* next;
}SLTNode;


SLTNode* GETNode(SLTDataType x)
{
	SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
	node->data = x;
	node->next = NULL;
	return node;
}

// ��ӡ
void SLTPrint(SLTNode* phead) 
{
	SLTNode* cur = phead;
	if (cur == NULL) {
		printf("NULL");
		return;
	}
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//ͷ������ɾ��/β������ɾ��

// β��
void SLTPushBack(SLTNode** pphead, SLTDataType x) // ��Ҫ˫��ָ�룬��Ȼ�Ļ�pphead��ֻ��һ���������ı丱��û�취�ı�������pphead
{
	SLTNode* newnode = GETNode(x);
	// �����������Ϊ��
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

// ͷ��
void SLTPushFront(SLTNode** pphead, SLTDataType x) {
	SLTNode* newnode = GETNode(x);
	newnode->next = *pphead; // ָ��ͷ���
	*pphead = newnode; // ���½ڵ����ó�ͷ�ڵ�

}

// βɾ
void SLTPopBack(SLTNode** pphead) {
	if (*pphead == NULL) {
		printf("NULL");
	}
	else if ((*pphead)->next == NULL) { // ->�����ȼ�����*
		free(*pphead);
		*pphead = NULL;
	}
	else {
		SLTNode* pre = *pphead;
		SLTNode* tail = (*pphead) -> next;
		while (tail->next != NULL) {
			tail = tail->next;
			pre = pre->next;
		}
		pre->next = NULL;
		free(tail);
	}

}

// ͷɾ
void SLTPopFront(SLTNode** pphead) {
	if (*pphead == NULL) {
		printf("NULL");
		return;
	}
	else {
		SLTNode* head = *pphead;
		*pphead = head->next;
		free(head);
	}
}

//����
SLTNode* SLTFind(SLTNode* phead, SLTDataType x) {
	SLTNode* cur = phead;
	while (cur != NULL) {
		if (cur->data == x) {
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
//��ָ��λ��֮ǰ��������
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x) {
	if (pos == *pphead) {
		SLTPushFront(pphead, x);
	}
	else {
		SLTNode* pre = *pphead;
		SLTNode* cur = (*pphead)->next;
		while (cur != pos && cur != NULL) 
		{
			cur = cur->next;
			pre = pre->next;
		}
		if (cur == NULL) {
			printf("Ҫ�����λ�ô��� ����������");
			return;
		}
		else {
			SLTNode* newnode = GETNode(x);
			newnode->next = cur;
			pre->next = newnode;
		}
	}
}

//ɾ��pos�ڵ�
void SLTErase(SLTNode** pphead, SLTNode* pos) {
	if (*pphead == pos) {
		SLTPopFront(pphead);
	}
	else {
		SLTNode* pre = *pphead;
		SLTNode* cur = (*pphead)->next;
		while (cur != pos && cur != NULL)
		{
			cur = cur->next;
			pre = pre->next;
		}
		if (cur == NULL) {
			printf("Ҫɾ����λ�ô��� ����������");
			return;
		}
		else {
			pre->next = cur->next;
			free(cur);
		}
	}

}
//��ָ��λ��֮���������
void SLTInsertAfter(SLTNode** pphead, SLTNode* pos, SLTDataType x) {
	SLTNode* cur = *pphead;
	while (cur != NULL && cur != pos) {
		cur = cur->next;
	}
	if (cur == NULL) {
		printf("Ҫ�����λ�ô��󣬲���������");
	}
	else {
		SLTNode* newnode = GETNode(x);
		newnode->next = cur->next;
		cur->next = newnode;
	}
}
//ɾ��pos֮��Ľڵ�
void SLTEraseAfter(SLTNode** pphead, SLTNode* pos) {
	SLTNode* cur = (*pphead) -> next;
	while (cur -> next != NULL && cur != pos) {
		cur = cur->next;
	}
	if (cur ->next == NULL) {
		printf("Ҫɾ����λ�ô��󣬲���������");
	}
	else {
		SLTNode* del = cur->next;
		cur->next = del->next;
		free(del);
	}
}
//��������
void SListDesTroy(SLTNode** pphead) {
	if (*pphead == NULL) {
		printf("NULL");
	}
	else {
		SLTNode* cur = (*pphead);
		SLTNode* nxt = (*pphead)->next;
		while (nxt != NULL) {
			free(cur);
			cur = nxt;
			nxt = nxt->next;
		}
		free(cur);
		*pphead = NULL; // �ⲿͷָ����ΪNULL
		printf("���ٳɹ�");
	}

}