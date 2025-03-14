#include"SList.h"
// 实现单链表的增删改查


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

// 打印
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

//头部插入删除/尾部插入删除

// 尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x) // 需要双层指针，不然的话pphead就只是一个副本，改变副本没办法改变真正的pphead
{
	SLTNode* newnode = GETNode(x);
	// 如果整个链表为空
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

// 头插
void SLTPushFront(SLTNode** pphead, SLTDataType x) {
	SLTNode* newnode = GETNode(x);
	newnode->next = *pphead; // 指向头结点
	*pphead = newnode; // 将新节点设置成头节点

}

// 尾删
void SLTPopBack(SLTNode** pphead) {
	if (*pphead == NULL) {
		printf("NULL");
	}
	else if ((*pphead)->next == NULL) { // ->的优先级高于*
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

// 头删
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

//查找
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
//在指定位置之前插入数据
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
			printf("要插入的位置错误， 不在链表中");
			return;
		}
		else {
			SLTNode* newnode = GETNode(x);
			newnode->next = cur;
			pre->next = newnode;
		}
	}
}

//删除pos节点
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
			printf("要删除的位置错误， 不在链表中");
			return;
		}
		else {
			pre->next = cur->next;
			free(cur);
		}
	}

}
//在指定位置之后插入数据
void SLTInsertAfter(SLTNode** pphead, SLTNode* pos, SLTDataType x) {
	SLTNode* cur = *pphead;
	while (cur != NULL && cur != pos) {
		cur = cur->next;
	}
	if (cur == NULL) {
		printf("要插入的位置错误，不在链表中");
	}
	else {
		SLTNode* newnode = GETNode(x);
		newnode->next = cur->next;
		cur->next = newnode;
	}
}
//删除pos之后的节点
void SLTEraseAfter(SLTNode** pphead, SLTNode* pos) {
	SLTNode* cur = (*pphead) -> next;
	while (cur -> next != NULL && cur != pos) {
		cur = cur->next;
	}
	if (cur ->next == NULL) {
		printf("要删除的位置错误，不在链表中");
	}
	else {
		SLTNode* del = cur->next;
		cur->next = del->next;
		free(del);
	}
}
//销毁链表
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
		*pphead = NULL; // 外部头指针置为NULL
		printf("销毁成功");
	}

}