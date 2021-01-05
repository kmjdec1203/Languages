#ifndef _NODE_POINT_LIST_H_
#define	_NODE_POINT_LIST_H_

typedef struct _point {
	int x, y;
	struct _point* Next;
} Point;

typedef	Point		*Ldata;

typedef	struct _pointlist {
	Ldata Head, Before, Cur;
	int NumOfData;
	int (*comp)(Ldata, Ldata);
} PointList;
typedef PointList List;

void InitList(List*);				// 리스트의 초기화
void	LInsert(List*, Ldata);		// 자료 삽입
int		LFirst(List*, Ldata);		// 첫 자료가 있는가?
int		LNext(List*, Ldata);		// 다음 자료가 있는가?
Ldata	LRemove(List*);				// 자료 삭제
void	LPrint(List*);					// 리스트 자료의 출력
void	SetSortRule(List*, int(*comp)(Ldata, Ldata));
#endif // !_ARRAY_LIST_H_