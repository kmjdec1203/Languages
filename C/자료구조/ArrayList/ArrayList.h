#ifndef _ARRAY_LIST_H_
#define	_ARRAY_LIST_H_

#define	LEN_List	50
typedef	int			Ldata;
typedef	struct _arraylist {
	Ldata Array[LEN_List];
	int CurPosition;
	int NumOfData;
	int (*comp)(Ldata, Ldata);
} ArrayList;
typedef ArrayList List;

List* InitList(void);				// ����Ʈ�� �ʱ�ȭ
void	LInsert(List*, Ldata);		// �ڷ� ����
int		LFirst(List*, Ldata*);		// ù �ڷᰡ �ִ°�?
int		LNext(List*, Ldata*);		// ���� �ڷᰡ �ִ°�?
Ldata	LRemove(List*);				// �ڷ� ����
void	LPrint(List*);					// ����Ʈ �ڷ��� ���
#endif // !_ARRAY_LIST_H_