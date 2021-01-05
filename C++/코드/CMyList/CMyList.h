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
	~CMyList() { // 노드 전체 삭제 (메모리 해제)
	}
	void Insert(int num);	// 새로운 노드 생성(메모리 할당) 및 link 연결
	void PrintData();
	bool Find(int num);
private:
	Node* pHead = nullptr;
	Node* pTail = nullptr;
};