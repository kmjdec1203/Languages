#pragma once
#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* f_link;
	Node* b_link;
};
class CMyList
{
public:
	CMyList() {}
	~CMyList() { // ��� ��ü ���� (�޸� ����)
	}

	void Insert_tail(int num);	// ���ο� ��� ����(�޸� �Ҵ�) �� link ����
	void PrintData_head();
	virtual bool Find(int num);
	void ShowMenu();
	Node* GetHead() const;
	void SetHead(Node* tmp);
	Node* GetTail() const;
	void SetTail(Node* tmp);
	int GetLength() const;
	void SetLength(int num);

private:
	Node* pHead = nullptr;
	Node* pTail = nullptr;
	int m_nLength = 0;
};