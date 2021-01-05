#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NodePointList.h"
//#include "NodePointList.cpp"

Ldata NewPoint(char N, int K, int E, int M, int C, int S, int R) {
	Ldata Npoint = (Node*)malloc(sizeof(Node));
	Npoint->N = N;
	Npoint->K = K;
	Npoint->E = E;
	Npoint->M = M;
	Npoint->C = C;
	Npoint->S = S;
	Npoint->R = R;
	Npoint->Next = NULL;
	return Npoint;
}

int WholsPred(Ldata d1, Ldata d2) {
	if (d1->S < d2->S) return 0;			// x ��ǥ�� ���� ���� �տ� ��ġ
	else if (d1->x == d2->x)				// x ��ǥ�� ������
		if (d1->N < d2->N) return 0;		// y ��ǥ�� ���� ���� �տ� ��ġ	
		else return 1;
	else return 1;
}

void Sorting(List* plist) {
	int a, su = 0;
	Ldata Tmp, Addr[100];

	Tmp = plist->Head;
	while (Tmp = Tmp->Next) {			// ù ��° �ڷ���� ��� �ڷ��� �����͸�
		Addr[su++] = Tmp;				// �迭�� ����
	}

	plist->Head->Next->Next = NULL;		// ù �ڷ��� Next�� NULL�� ����
	plist->NumOfData = 1;

	for (a = 1; a < su; a++) {			// �� ��° �ڷ� ���ĺ��� ��� �ڷḦ
		Addr[a]->Next = 0;				// Next �����͸� NULL�� �����Ͽ�
		LInsert(plist, Addr[a]);		// ����Ʈ�� �߰�(Sorting Rule ����)
	}
}

int main(void) {
	int a, A[10] = { 6, 2, 7, 9, 8, 3, 5, 4, 0, 1 };
	List* MyList = (List*)malloc(sizeof(List));
	Ldata point = (Point*)malloc(sizeof(Point)), rpoint;		// �˻� �ڷḦ ���� ���� ����
	InitList(MyList);					// ����Ʈ�� �ʱ�ȭ
	printf("\n���ο� ��带 ����Ʈ�� �տ� �߰�\n");
	LInsert(MyList, NewPoint(1, 2));
	LInsert(MyList, NewPoint(2, 3));
	LInsert(MyList, NewPoint(3, 4));

	SetSortRule(MyList, WholsPred);
	printf("\n�������� Sorting Rule ���� �ڷ� �߰�\n");
	for (a = 0; a < 10; a += 2) {					// ����Ʈ�� �ڷ� �߰� 
		LInsert(MyList, NewPoint(A[a], A[a + 1]));
	}
	printf("\n�������� ����\n");
	Sorting(MyList);
	LPrint(MyList);			// ����Ʈ �ڷ��� ���

	printf("\n��ǥ�� 3�� ���Ե� ��� �� ����\n");
	if (LFirst(MyList, point)) {
		if (point->x == 3 || point->y == 3) { rpoint = LRemove(MyList);
			printf("(%d,%d)����\n", rpoint->x, rpoint->y);
		}
		while (LNext(MyList, point)) {
			if (point->x == 3 || point->y == 3) { rpoint = LRemove(MyList);
				printf("(%d,%d)����\n", rpoint->x, rpoint->y);
			}
		}
	}
	printf("\n���� �ִ� ��� �� ����Ʈ\n");
	LPrint(MyList);					// ����Ʈ �ڷ��� ���
}
