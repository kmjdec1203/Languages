#pragma once
#include "CMyList.h"
class CMyListEx :
	public CMyList
{
private:
	int overlap = 0;
public:
	CMyListEx() {}
	CMyListEx(int data) {
		Insert_head(data);
	}
	CMyListEx(CMyList& rhs) {
		Node* move = rhs.GetHead();
		while (move) {
			this->Insert_tail(move->data);
			move = move->b_link;
		}
	}
	
	~CMyListEx() {}	

	void Insert_tail(int num);	// 새로운 노드 생성(메모리 할당) 및 link 연결
	void Insert_head(int num);
	virtual bool Find(int num);
	void Change_overlap();
	void Remove_head();
	void Remove_tail();
	void PrintData_tail();
	void PrintData_head();
	static void ShowMenu();
};

