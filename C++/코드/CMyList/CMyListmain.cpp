#include <iostream>
#include "CMyList.h"
using namespace std;
int main() {
	CMyList list;
	int menu, num;
	cout << "----------------\nCMyList �޴�\n1 ����\n2 ���\n0 ����\n----------------\n";
	do {
		cout << "�޴��� ������(���� �Է�) : ";
		cin >> menu;
		if (menu == 1) {
			cout << "���� �Է����ּ���: ";
			cin >> num;
			list.Find(num);
			if (list.Find(num) == true) {
				cout << "�ߺ��� ���Դϴ�." << endl;
			}
			else list.Insert(num);
		}
		else if (menu == 2)
			list.PrintData();
		else if(menu == 0) {
			cout << "�����մϴ�.";
			return 0;
		}
		else {
			cout << "0, 1, 2 �� ���ڸ� �Է��ϼ���~!" << endl;
			cout << "----------------\nCMyList �޴�\n1 ����\n2 ���\n0 ����\n----------------\n";
		}
	} while (menu != 0);
	return 0;
}