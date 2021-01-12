#pragma warning(disable:4996)
// AddressBook.cpp
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

//////////////////////////////////////////////////
// �ּҷ��� ����� ������ ����
#define DATA_FILE_NAME	"Address.dat"

//////////////////////////////////////////////////
struct USERDATA {
	char szName[32];	// �̸�
	char szPhone[32];	// ��ȭ��ȣ
	USERDATA* pNext;
};

// Head, Tail ������ ���� �� ����
USERDATA* pHead = nullptr;
USERDATA* pTail = nullptr;

//////////////////////////////////////////////////
// �Լ� ����
USERDATA* FindNode(char* pszName);
int AddNewNode(char* pszName, char* pszPhone);
void Add();
void Search();
void PrintAll();
int RemoveNode(char* pszName);
void Remove();
int PrintUI();
int LoadList(const char* pszFileName);
int SaveList(const char* pszFileName);
void ReleaseList();


//////////////////////////////////////////////////
int main() {
	int nMenu = 0;
	LoadList(DATA_FILE_NAME);

	// ���� �̺�Ʈ �ݺ���
	while ((nMenu = PrintUI()) != 0) {
		switch (nMenu)
		{
		case 1:		// Add
			Add();
			break;
		case 2:		// Search
			Search();
			break;
		case 3:		// Print all
			PrintAll();
			break;
		case 4:		// Remove
			Remove();
			break;
		}
	}
	// ���� ���� ���Ϸ� �����ϰ� �޸𸮸� �����Ѵ�.
	SaveList(DATA_FILE_NAME);
	ReleaseList();
	return 0;
}
// �Լ� ����
//////////////////////////////////////////////////
// ����Ʈ���� �̸����� Ư�� ��带 �˻��ϴ� �Լ�
USERDATA* FindNode(char* pszName)
{
	USERDATA* pTmp = pHead;
	while (pTmp != NULL) {
		if (strcmp(pTmp->szName, pszName) == 0)
			return pTmp;

		// ���� ���� �̵�
		pTmp = pTmp->pNext;
	}

	// ��ġ�ϴ� �����͸� ã�� ���� ���
	return NULL;
}

///////////////////////////////////////////////////////////////
int AddNewNode(char* pszName, char* pszPhone)
{
	USERDATA* pNewUser = NULL;

	// ���� �̸��� �̹� �����ϴ��� Ȯ���Ѵ�.
	if (FindNode(pszName) != NULL) return 0;

	// �޸𸮸� Ȯ���Ѵ�.
	pNewUser = new USERDATA;
	memset(pNewUser, 0, sizeof(USERDATA));

	// �޸𸮿� ���� �����Ѵ�.
	sprintf(pNewUser->szName, "%s", pszName);
	sprintf(pNewUser->szPhone, "%s", pszPhone);
	pNewUser->pNext = nullptr;

	// ���ο� ��尡 ����Ʈ �������� ���Եȴ�.
	if (pTail == nullptr) {		// ����Ʈ�� ����� ��, ���� ��尡 ó�� �����
		pHead = pNewUser;
	}
	else {
		pTail->pNext = pNewUser;
	}

	pTail = pNewUser;

	return 1;
}

///////////////////////////////////////////////////////////////
// �̸��� �Է¹޾� ����Ʈ�� �߰��ϴ� �Լ�
void Add()
{
	char szName[32] = { 0 };
	char szPhone[32] = { 0 };

	cout << "Input name : ";
	fflush(stdin);
	cin >> szName;

	cout << "Input phone number : ";
	fflush(stdin);
	cin >> szPhone;

	// ������ ����Ʈ�� �߰��Ѵ�.
	AddNewNode(szName, szPhone);
}

///////////////////////////////////////////////////////////////
// Ư�� ��带 �˻��ϴ� �Լ�
void Search()
{
	char szName[32] = { 0 };
	USERDATA* pNode = NULL;

	cout << "Input name : ";
	fflush(stdin);
	cin >> szName;

	pNode = FindNode(szName);
	if (pNode != NULL) {
		cout << "[" << pNode << "] " << pNode->szName << "\t"
			<< pNode->szPhone << " [" << pNode->pNext << "]\n";
	}
	else {
		cout << "ERROR: �����͸� ã�� �� �����ϴ�.";
	}

	cin.get();
}

///////////////////////////////////////////////////////////////
// ����Ʈ�� ����ִ� ��� �����͸� ȭ�鿡 ����ϴ� �Լ�
void PrintAll()
{
	USERDATA* pTmp = pHead;
	while (pTmp != NULL) {
		cout << "[" << pTmp << "] " << pTmp->szName << "\t"
			<< pTmp->szPhone << " [" << pTmp->pNext << "]\n";
		pTmp = pTmp->pNext;
	}

	cin.get();
}

///////////////////////////////////////////////////////////////
// Ư�� ��带 �˻��ϰ� �����ϴ� �Լ�
int RemoveNode(char* pszName)
{
	USERDATA* pPrevNode = nullptr;
	USERDATA* pDelete = pHead;

	while (pDelete != nullptr) {
		if (strcmp(pDelete->szName, pszName) == 0) {
			if (pPrevNode == nullptr) {		// ���� ��尡 ó�� ����� ��!
				pHead = pDelete->pNext;
			}
			else {
				if (pDelete == pTail)	// ���� ��尡 ������ ����� ��!
					pTail = pPrevNode;
				pPrevNode->pNext = pDelete->pNext;
			}
			delete pDelete;
			return 1;
		}

		pPrevNode = pDelete;
		pDelete = pDelete->pNext;
	}
	return 0;
}

///////////////////////////////////////////////////////////////
// �̸��� �Է¹޾� �ڷḦ �˻��ϰ� �����ϴ� �Լ�
void Remove()
{
	char szName[32] = { 0 };
	USERDATA* pNode = NULL;

	cout << "Input name : ";
	fflush(stdin);
	cin >> szName;

	RemoveNode(szName);
}

///////////////////////////////////////////////////////////////
// �޴��� ����ϴ� User Interface(UI) �Լ�
int PrintUI()
{
	int nInput = 0;

	cout << "\n[1]Add	[2]Search	[3]Print all	[4]Remove	[0]Exit\n:";

	// ����ڰ� ������ �޴��� ���� ��ȯ�Ѵ�.
	cin >> nInput;
	return nInput;
	return 0;
}

///////////////////////////////////////////////////////////////
// ������ ���Ͽ��� ������ �о�� ����Ʈ�� �ϼ��ϴ� �Լ�
int LoadList(const char* pszFileName)
{
	FILE* fp = NULL;
	USERDATA user = { 0 };

	fp = fopen(pszFileName, "rb");
	if (fp == NULL)
		return 0;

	ReleaseList();

	while (fread(&user, sizeof(USERDATA), 1, fp)) {
		AddNewNode(user.szName, user.szPhone);
	}

	fclose(fp);
	return 0;
}

///////////////////////////////////////////////////////////////
// ����Ʈ ���·� �����ϴ� ������ ���Ͽ� �����ϴ� �Լ�
int SaveList(const char* pszFileName)
{
	FILE* fp = NULL;
	USERDATA* pTmp = pHead;

	fp = fopen(pszFileName, "wb");
	if (fp == NULL) {
		cout << "ERROR: ����Ʈ ������ ���� ���� ���� ���߽��ϴ�.";
		cin.get();
		return 0;
	}

	while (pTmp != NULL) {
		if (fwrite(pTmp, sizeof(USERDATA), 1, fp) != 1) {
			cout << "ERROR: " << pTmp->szName
				<< "�� ���� ������ �����ϴ� �� �����߽��ϴ�.\n";
		}
		pTmp = pTmp->pNext;
	}

	fclose(fp);
	return 1;
}

///////////////////////////////////////////////////////////////
// ����Ʈ�� ��� �����͸� �����ϴ� �Լ�
void ReleaseList()
{
	USERDATA* pTmp = pHead;
	USERDATA* pDelete = nullptr;

	while (pTmp != nullptr) {
		pDelete = pTmp;
		pTmp = pTmp->pNext;

		delete pDelete;
	}

	pHead = nullptr;
}
