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
	if (d1->S < d2->S) return 0;			// x 좌표가 작은 것이 앞에 위치
	else if (d1->x == d2->x)				// x 좌표가 같으면
		if (d1->N < d2->N) return 0;		// y 좌표가 작은 것이 앞에 위치	
		else return 1;
	else return 1;
}

void Sorting(List* plist) {
	int a, su = 0;
	Ldata Tmp, Addr[100];

	Tmp = plist->Head;
	while (Tmp = Tmp->Next) {			// 첫 번째 자료부터 모든 자료의 포인터를
		Addr[su++] = Tmp;				// 배열에 저장
	}

	plist->Head->Next->Next = NULL;		// 첫 자료의 Next를 NULL로 설정
	plist->NumOfData = 1;

	for (a = 1; a < su; a++) {			// 두 번째 자료 이후부터 모든 자료를
		Addr[a]->Next = 0;				// Next 포인터를 NULL로 설정하여
		LInsert(plist, Addr[a]);		// 리스트에 추가(Sorting Rule 적용)
	}
}

int main(void) {
	int a, A[10] = { 6, 2, 7, 9, 8, 3, 5, 4, 0, 1 };
	List* MyList = (List*)malloc(sizeof(List));
	Ldata point = (Point*)malloc(sizeof(Point)), rpoint;		// 검색 자료를 전달 받을 변수
	InitList(MyList);					// 리스트의 초기화
	printf("\n새로운 노드를 리스트의 앞에 추가\n");
	LInsert(MyList, NewPoint(1, 2));
	LInsert(MyList, NewPoint(2, 3));
	LInsert(MyList, NewPoint(3, 4));

	SetSortRule(MyList, WholsPred);
	printf("\n오름차순 Sorting Rule 적용 자료 추가\n");
	for (a = 0; a < 10; a += 2) {					// 리스트에 자료 추가 
		LInsert(MyList, NewPoint(A[a], A[a + 1]));
	}
	printf("\n오름차순 정렬\n");
	Sorting(MyList);
	LPrint(MyList);			// 리스트 자료의 출력

	printf("\n좌표에 3이 포함된 모든 점 삭제\n");
	if (LFirst(MyList, point)) {
		if (point->x == 3 || point->y == 3) { rpoint = LRemove(MyList);
			printf("(%d,%d)제거\n", rpoint->x, rpoint->y);
		}
		while (LNext(MyList, point)) {
			if (point->x == 3 || point->y == 3) { rpoint = LRemove(MyList);
				printf("(%d,%d)제거\n", rpoint->x, rpoint->y);
			}
		}
	}
	printf("\n남아 있는 모든 점 리스트\n");
	LPrint(MyList);					// 리스트 자료의 출력
}
