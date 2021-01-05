#include "CMyList.h"

void CMyList::Insert(int num)
{
	Node* newNode = new Node;
	newNode->data = num;
	newNode->link = nullptr;
	if (pHead == NULL)
		pHead = newNode;
	else
		pTail->link = newNode;
	pTail = newNode;
	PrintData();
}

bool CMyList::Find(int num) {
	Node* head = pHead;
	while (head) {
		if (head->data == num)
			return true;
		else {
			head = head->link;
		}
	}
	return false;
}

void CMyList::PrintData()
{
	int i = 0;
	Node* head = pHead;
	cout << "CMyList ������ : ";
	while (head) {
		if (head->link) {
			cout << head->data << " - ";
		}
		else {
			cout << head->data << endl;
		}
		head = head->link;
		i++;
	}
	cout << "������ ���� : " << i << "��" << endl;
}