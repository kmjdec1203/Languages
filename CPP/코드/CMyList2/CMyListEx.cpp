#include "CMyListEx.h"

void CMyListEx::Insert_tail(int num)
{
	CMyList::Insert_tail(num);
	PrintData_head();
}

void CMyListEx::Insert_head(int num)
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

		if (GetHead() == nullptr) {
			SetTail(newNode);
		}
		else {
			GetHead()->f_link = newNode;
			newNode->b_link = GetHead();
		}
		SetHead(newNode);
		SetLength(GetLength() + 1);
		PrintData_head();
	}
}

bool CMyListEx::Find(int num)
{
	if (overlap == 0) {
		Node* head = GetHead();
		while (head) {
			if (head->data == num)
				return true;
			else {
				head = head->b_link;
			}
		}
		return false;
	}
	return false;
}

void CMyListEx::Change_overlap()
{
	overlap++;
	overlap %= 2;
}

void CMyListEx::Remove_head()
{
	Node* head = GetHead();
	if (GetLength() == 1) {
		delete(head);
		SetLength(GetLength() - 1);
		SetTail(nullptr);
		SetHead(nullptr);
		return;
	}
	else if (GetLength() == 0) {
		cout << "삭제할 데이터가 없습니다!" << endl;
		return;
	}
	else {
		head = head->b_link;
		delete(head->f_link);
		head->f_link = nullptr;
		SetLength(GetLength() - 1);
		SetHead(head);
		PrintData_head();
		return;
	}
}

void CMyListEx::Remove_tail()
{
	Node* tail = GetTail();
	if (GetLength() == 1) {
		delete(tail);
		SetLength(GetLength() - 1);
		SetTail(nullptr);
		SetHead(nullptr);
		return;
	}
	else if (GetLength() == 0) {
		cout << "삭제할 데이터가 없습니다!" << endl;
		return;
	}
	tail = tail->f_link;
	delete(tail->b_link);
	tail->b_link = nullptr;
	SetLength(GetLength() - 1);
	SetTail(tail);
	PrintData_tail();
	return;
}

void CMyListEx::PrintData_head()
{
	CMyList::PrintData_head();
	cout << "데이터 개수 : " << GetLength() << "개\n" << endl;
}

void CMyListEx::PrintData_tail()
{
	Node* tail = GetTail();
	Node* head = GetHead();
	if (head == nullptr) {
		cout << "출력할 데이터가 없습니다." << endl;
	}
	else {
		cout << "\nCMyList 데이터 : ";
		cout << "[Tail] ";
		while (tail) {
			if (tail->f_link) {
				cout << tail->data << " - ";
			}
			else {
				cout << tail->data;
			}
			tail = tail->f_link;
		}
		cout << " [Head]" << endl;
		cout << "데이터 개수 : " << GetLength() << "개\n" << endl;
	}
}

void CMyListEx::ShowMenu()
{
	cout << "-------------------" << endl;
	cout << "CMyListEx 메뉴" << endl; 
	cout << "1 삽입 Head" << endl; 
	cout << "2 삽입 Tail" << endl;
	cout << "3 삭제 Head" << endl;
	cout << "4 삭제 Tail" << endl; 
	cout << "5 출력 Head->Tail" << endl;
	cout << "6 출력 Tail->Head" << endl;
	cout << "7 중복 설정 바꾸기" << endl;
	cout << "0 종료" << endl;
	cout << "-------------------\n" << endl;
	cout << "메뉴를 고르세요(숫자 입력) : ";
}
