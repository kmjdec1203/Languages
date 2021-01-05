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

List* InitList(void);				// 리스트의 초기화
void	LInsert(List*, Ldata);		// 자료 삽입
int		LFirst(List*, Ldata*);		// 첫 자료가 있는가?
int		LNext(List*, Ldata*);		// 다음 자료가 있는가?
Ldata	LRemove(List*);				// 자료 삭제
void	LPrint(List*);					// 리스트 자료의 출력
#endif // !_ARRAY_LIST_H_