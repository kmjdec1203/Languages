#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* link;
};
class CMyList
{
public:
	CMyList() {}
	~CMyList() { // ��� ��ü ���� (�޸� ����)
	}
	void Insert(int num);	// ���ο� ��� ����(�޸� �Ҵ�) �� link ����
	void PrintData();
	bool Find(int num);
private:
	Node* pHead = nullptr;
	Node* pTail = nullptr;
};