#include <iostream>
#include "CMyList.h"
using namespace std;
int main() {
	CMyList list;
	int menu, num;
	cout << "----------------\nCMyList 메뉴\n1 삽입\n2 출력\n0 종료\n----------------\n";
	do {
		cout << "메뉴를 고르세요(숫자 입력) : ";
		cin >> menu;
		if (menu == 1) {
			cout << "값을 입력해주세요: ";
			cin >> num;
			list.Find(num);
			if (list.Find(num) == true) {
				cout << "중복된 값입니다." << endl;
			}
			else list.Insert(num);
		}
		else if (menu == 2)
			list.PrintData();
		else if(menu == 0) {
			cout << "종료합니다.";
			return 0;
		}
		else {
			cout << "0, 1, 2 중 숫자를 입력하세요~!" << endl;
			cout << "----------------\nCMyList 메뉴\n1 삽입\n2 출력\n0 종료\n----------------\n";
		}
	} while (menu != 0);
	return 0;
}