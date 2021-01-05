#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

List* InitList(void) {		// ����Ʈ�� �ʱ�ȭ
	List* plist = (List*)malloc(sizeof(List));
	memset(plist->Array, 0, sizeof(Ldata)* LEN_List);
	plist->comp = NULL;
	plist->NumOfData = 0;
	return plist;
}

void SInsert(List* plist, Ldata pdata) {
	int Cur = plist->NumOfData;
	while (Cur > 0 && plist->comp(plist->Array[Cur - 1], pdata)) {		// ���� �ڷᰡ ���� �ڷẸ�� ũ��
		plist->Array[Cur] = plist->Array[Cur - 1];						// ���� �ڷḦ �� �ڸ��� �ű�� �۾���
		Cur--;															// �ڸ��� ã�� ������ �ݺ�
	}
	plist->Array[Cur] = pdata;		// ã���� �ڸ��� �ڷḦ �����ϰ�
	plist->NumOfData++;				// ����Ʈ ���� �ڷ� ������ ����
}

void LInsert(List* plist, Ldata pdata) {			// �ڷ� ����
	if (plist->NumOfData >= LEN_List) {
		printf("����Ʈ�� ������ �ڷḦ �߰��� �� �����ϴ�\n"); return;
	}
	if (plist->comp) SInsert(plist, pdata);
	else			plist->Array[plist->NumOfData++] = pdata;
}

void LPrint(List* plist) {				// ����Ʈ �� ��� �ڷ��� ���
	int a = 0;
	while (a < plist->NumOfData) {
		printf("%3d\n", plist->Array[a++]);
	} printf("\n");
}


int LFirst(List* plist, Ldata* pdata) {				// ù �ڷᰡ �ִ°�?
	if (plist->NumOfData) {
		plist->CurPosition = 0;
		*pdata = plist->Array[0];
		return 1;	// ù �ڷ� ����
	}
	return 0;		// ����� �ڷᰡ ����
}

int LNext(List* plist, Ldata* pdata) {				// ���� �ڷᰡ �ִ°�?
	if (plist->CurPosition < plist->NumOfData) {
		plist->CurPosition++;
		*pdata = plist->Array[plist->CurPosition];
		return 1;	// ���� �ڷ� ����
	}
	return 0;	// ���� �ڷ� ����
}

Ldata LRemove(List* plist) {
	int rpos = plist->CurPosition;			// ������ ��ġ
	Ldata rdata = plist->Array[rpos];		// ������ �ڷ�
	plist->CurPosition = rpos - 1;			// ������ ���� Current Position

	while (rpos < plist->NumOfData) {		// �ڷ��� ������ ������ �ڸ� ä��
		plist->Array[rpos] = plist->Array[rpos + 1];
		rpos++;
	}
	plist->NumOfData--;	// �ڷ� ���� ����
	return rdata;		// ������ �ڷ� ��ȯ
}