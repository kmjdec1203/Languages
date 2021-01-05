#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

List* InitList(void) {		// 리스트의 초기화
	List* plist = (List*)malloc(sizeof(List));
	memset(plist->Array, 0, sizeof(Ldata)* LEN_List);
	plist->comp = NULL;
	plist->NumOfData = 0;
	return plist;
}

void SInsert(List* plist, Ldata pdata) {
	int Cur = plist->NumOfData;
	while (Cur > 0 && plist->comp(plist->Array[Cur - 1], pdata)) {		// 앞의 자료가 기준 자료보다 크면
		plist->Array[Cur] = plist->Array[Cur - 1];						// 앞의 자료를 뒤 자리로 옮기는 작업을
		Cur--;															// 자리를 찾을 때까지 반복
	}
	plist->Array[Cur] = pdata;		// 찾아진 자리에 자료를 저장하고
	plist->NumOfData++;				// 리스트 내의 자료 개수를 증가
}

void LInsert(List* plist, Ldata pdata) {			// 자료 삽입
	if (plist->NumOfData >= LEN_List) {
		printf("리스트가 꽉차서 자료를 추가할 수 없습니다\n"); return;
	}
	if (plist->comp) SInsert(plist, pdata);
	else			plist->Array[plist->NumOfData++] = pdata;
}

void LPrint(List* plist) {				// 리스트 내 모든 자료의 출력
	int a = 0;
	while (a < plist->NumOfData) {
		printf("%3d\n", plist->Array[a++]);
	} printf("\n");
}


int LFirst(List* plist, Ldata* pdata) {				// 첫 자료가 있는가?
	if (plist->NumOfData) {
		plist->CurPosition = 0;
		*pdata = plist->Array[0];
		return 1;	// 첫 자료 있음
	}
	return 0;		// 저장된 자료가 있음
}

int LNext(List* plist, Ldata* pdata) {				// 다음 자료가 있는가?
	if (plist->CurPosition < plist->NumOfData) {
		plist->CurPosition++;
		*pdata = plist->Array[plist->CurPosition];
		return 1;	// 다음 자료 있음
	}
	return 0;	// 다음 자료 없음
}

Ldata LRemove(List* plist) {
	int rpos = plist->CurPosition;			// 삭제할 위치
	Ldata rdata = plist->Array[rpos];		// 삭제할 자료
	plist->CurPosition = rpos - 1;			// 삭제한 후의 Current Position

	while (rpos < plist->NumOfData) {		// 자료의 끝까지 지워진 자리 채움
		plist->Array[rpos] = plist->Array[rpos + 1];
		rpos++;
	}
	plist->NumOfData--;	// 자료 개수 감소
	return rdata;		// 삭제된 자료 변환
}