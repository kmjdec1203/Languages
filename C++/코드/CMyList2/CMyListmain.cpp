#include <iostream>
#include "CMyListEx.h"
using namespace std;
int main() {
	int menu, num;
	CMyListEx myListex(10);
	
	while (1) {
		myListex.ShowMenu();
		cin >> menu;
		while (cin.fail()==true) {
			cout << "0, 1, 2, 3, 4, 5, 6 , 7 �� ���ڸ� �Է��ϼ���~!\n" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			myListex.ShowMenu();
			cin >> menu;
		}
		cin.clear();
		cin.ignore(1024, '\n');
		switch (menu)
		{
		case 1:
			cout << "\n������ �����͸� �Է����ּ��� : ";
			cin >> num;
			myListex.Insert_head(num);
			break;
		case 2:
			cout << "\n������ �����͸� �Է����ּ��� : ";
			cin >> num;
			myListex.Insert_tail(num);
			break;
		case 3:
			myListex.Remove_head();
			break;
		case 4:
			myListex.Remove_tail();
			break;
		case 5:
			myListex.PrintData_head();
			break;
		case 6:
			myListex.PrintData_tail();
			break;
		case 7:
			myListex.Change_overlap();
			printf("�ߺ� ������ �����մϴ�.\n\n");
			break;
		case 0:
			cout << "�����մϴ�.";
			delete &myListex;
			return 0;
		default:
			cout << "0, 1, 2, 3, 4, 5, 6 , 7 �� ������ �������� �Է��ϼ���~!" << endl;
			continue;
		}
	}
	return 0;
}