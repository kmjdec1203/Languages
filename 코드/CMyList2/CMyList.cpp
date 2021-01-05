#include "CMyList.h"

void CMyList::Insert_tail(int num)
{
	if (Find(num) == true) {
		cout << num << "는 중복입니다!" << endl;
		return;
	}
	else {
		Node* newNode = new Node;

		newNode->data = num;
		newNode->b_link = nullptr;
		newNode->f_link = nullptr;

		if (GetTail() == nullptr) {
			SetHead(newNode);
		}
		else {
			GetTail()->b_link = newNode;
			newNode->f_link = GetTail();
		}
		SetTail(newNode);
		m_nLength++;
	}
}

bool CMyList::Find(int num) {
	Node* head = pHead;
	while (head) {
		if (head->data == num)
			return true;
		else {
			head = head->b_link;
		}
	}
	return false;
}

void CMyList::ShowMenu()
{
	cout << "----------------\nCMyList 메뉴\n1 삽입\n2 출력\n0 종료\n----------------\n";
}

Node* CMyList::GetHead() const
{
	return pHead;
}

void CMyList::SetHead(Node* tmp)
{
	pHead = tmp;
}

Node* CMyList::GetTail() const
{
	return pTail;
}

void CMyList::SetTail(Node* tmp)
{
	pTail = tmp;
}

int CMyList::GetLength() const
{
	return m_nLength;
}

void CMyList::SetLength(int num)
{
	m_nLength = num;
}

void CMyList::PrintData_head()
{
	Node* head = pHead;
	if (head == nullptr) {
		cout << "출력할 데이터가 없습니다." << endl;
	}
	else {
		cout << "\nCMyList 데이터 : ";
		cout << "[Head] ";
		while (head) {
			if (head->b_link) {
				cout << head->data << " - ";
			}
			else {
				cout << head->data;
			}
			head = head->b_link;
		}
		cout << " [Tail]" << endl;
	}
}
