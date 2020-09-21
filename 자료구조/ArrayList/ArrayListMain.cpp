#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
//#include "ArrayList.cpp"

void SetSortRule(List* plist, int(*comp)(Ldata, Ldata)) {
	plist->comp = comp;
}
int WholsPred(Ldata d1, Ldata d2) {
	if (d1 < d2) return 0;
	return 1;
}

int main(void) {
	List* MyList = InitList();	// ����Ʈ�� �ʱ�ȭ
	Ldata Sdata, Bdata;
	int A[10] = { 6, 2, 7, 9, 8, 3, 5, 4, 0, 1 }, a;
	
	LInsert(MyList, 1);			
	LInsert(MyList, 3);
	LInsert(MyList, 5);			// ����Ʈ�� �ڷ��߰�

	printf("%3d %3d %3d \n", MyList->Array[0], MyList->Array[1], MyList->Array[2]);	//����Ʈ �ڷ��� ���

	SetSortRule(MyList, WholsPred);

	for (a = 0; a < 10; a++) {
		LInsert(MyList, A[a]);			// ����Ʈ�� �ڷ� �߰�
	}
	LPrint(MyList);

	if (LFirst(MyList, &Sdata)) { 
		Bdata = Sdata;
		while (LNext(MyList, &Sdata)) {
			if (Bdata == Sdata) printf("�ߺ� �ڷ� %d����\n", LRemove(MyList));
			Bdata = Sdata;
		}
	}
	LPrint(MyList);			// ����Ʈ �ڷ��� ���
}