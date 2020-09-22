#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NodePointList.h"

void SetSortRule(List* plist, int(*comp)(Ldata, Ldata)) {
	plist->comp = comp;
}

void InitList(List* plist) {		// ����Ʈ�� �ʱ�ȭ
	Ldata Head = (Point*)malloc(sizeof(Point));
	plist->Head = Head;
	plist->Head->Next = NULL;
	plist->NumOfData = 0;
	plist->comp = NULL;
}

void PNode(Ldata pnode) {			// ��� �ڷ��� ���
	printf(" (%d,%d) ", pnode->x, pnode->y);
}

void LPrint(List* plist) {
	Ldata pdata = plist->Head->Next;

	while (pdata) {
		PNode(pdata);
		pdata = pdata->Next;
	} printf("\n");
}

void SInsert(List* plist, Ldata pdata) {
	Ldata Before = plist->Head;
	while (Before->Next && plist->comp(pdata, Before->Next)) {
		Before = Before->Next;
	}
	pdata->Next = Before->Next;
	Before->Next = pdata;
}

void LInsert(List* plist, Ldata pdata) {		// �ڷ� ����
	if (plist->comp)
		SInsert(plist, pdata);
	else {
		pdata->Next = plist->Head->Next;
		plist->Head->Next = pdata;
	}
	plist->NumOfData++;
	LPrint(plist);
}

int LFirst(List* plist, Ldata pdata) {	// ù �ڷᰡ �ִ°�?
	if (plist->Head->Next) {			// ù �ڷᰡ ������
		plist->Before = plist->Head;
		plist->Cur = plist->Head->Next;		// ù �ڷ� ��ġ�� �� ��ġ�� ����

		pdata->x = plist->Cur->x;			// �� ��ġ �ڷḦ ���� ������ ����
		pdata->y = plist->Cur->y;
		return 1;		// ù �ڷ� ����
	}
	return 0;			// ����� �ڷᰡ ����
}

int LNext(List* plist, Ldata pdata) {		// ���� �ڷᰡ �ִ°�?
	if (plist->Cur->Next) {					// ���� �ڷᰡ ������
		plist->Before = plist->Cur;
		plist->Cur = plist->Cur->Next;		// ���� �ڷ� ��ġ�� �� ��ġ�� ����

		pdata->x = plist->Cur->x;			// �� ��ġ �ڷḦ ���� ������ ����
		pdata->y = plist->Cur->y;
		return 1;		//���� �ڷ� ����
	}
	return 0;			// ���� �ڷ� ����
}

Ldata LRemove(List* plist) {			// �ڷ� ����
	if (plist->NumOfData) {
		Ldata rpos = plist->Cur;		// ����Ʈ�� �� ��ġ�� ������ ��ġ�� ����

		plist->Before->Next = rpos->Next;	// ��尡 ������ �� ���� ���� ����
		plist->Cur = plist->Before;			// ������ �� ���� �˻��� ���Ͽ� �� ��ġ ����
		plist->NumOfData--;					// �ڷ� ���� ����

		return rpos;						// ������ �ڷ��� ���� ���� ��ȯ
	}
}