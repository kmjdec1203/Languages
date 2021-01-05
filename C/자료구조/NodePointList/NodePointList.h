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

void InitList(List*);				// ����Ʈ�� �ʱ�ȭ
void	LInsert(List*, Ldata);		// �ڷ� ����
int		LFirst(List*, Ldata);		// ù �ڷᰡ �ִ°�?
int		LNext(List*, Ldata);		// ���� �ڷᰡ �ִ°�?
Ldata	LRemove(List*);				// �ڷ� ����
void	LPrint(List*);					// ����Ʈ �ڷ��� ���
void	SetSortRule(List*, int(*comp)(Ldata, Ldata));
#endif // !_ARRAY_LIST_H_