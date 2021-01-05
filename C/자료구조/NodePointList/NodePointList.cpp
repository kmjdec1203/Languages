#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NodePointList.h"

void SetSortRule(List* plist, int(*comp)(Ldata, Ldata)) {
	plist->comp = comp;
}

void InitList(List* plist) {		// 리스트의 초기화
	Ldata Head = (Point*)malloc(sizeof(Point));
	plist->Head = Head;
	plist->Head->Next = NULL;
	plist->NumOfData = 0;
	plist->comp = NULL;
}

void PNode(Ldata pnode) {			// 노드 자료의 출력
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

void LInsert(List* plist, Ldata pdata) {		// 자료 삽입
	if (plist->comp)
		SInsert(plist, pdata);
	else {
		pdata->Next = plist->Head->Next;
		plist->Head->Next = pdata;
	}
	plist->NumOfData++;
	LPrint(plist);
}

int LFirst(List* plist, Ldata pdata) {	// 첫 자료가 있는가?
	if (plist->Head->Next) {			// 첫 자료가 있으면
		plist->Before = plist->Head;
		plist->Cur = plist->Head->Next;		// 첫 자료 위치를 현 위치로 설정

		pdata->x = plist->Cur->x;			// 현 위치 자료를 전달 변수에 복사
		pdata->y = plist->Cur->y;
		return 1;		// 첫 자료 있음
	}
	return 0;			// 저장된 자료가 없음
}

int LNext(List* plist, Ldata pdata) {		// 다음 자료가 있는가?
	if (plist->Cur->Next) {					// 다음 자료가 있으면
		plist->Before = plist->Cur;
		plist->Cur = plist->Cur->Next;		// 다음 자료 위치를 현 위치로 설정

		pdata->x = plist->Cur->x;			// 현 위치 자료를 전달 변수에 복사
		pdata->y = plist->Cur->y;
		return 1;		//다음 자료 있음
	}
	return 0;			// 다음 자료 없음
}

Ldata LRemove(List* plist) {			// 자료 삭제
	if (plist->NumOfData) {
		Ldata rpos = plist->Cur;		// 리스트의 현 위치를 삭제할 위치로 설정

		plist->Before->Next = rpos->Next;	// 노드가 삭제된 후 연결 관계 설정
		plist->Cur = plist->Before;			// 삭제한 후 연속 검색을 위하여 현 위치 변경
		plist->NumOfData--;					// 자료 개수 감소

		return rpos;						// 삭제된 자료의 전달 변수 반환
	}
}