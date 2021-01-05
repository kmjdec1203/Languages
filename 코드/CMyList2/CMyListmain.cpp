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
			cout << "0, 1, 2, 3, 4, 5, 6 , 7 중 숫자를 입력하세요~!\n" << endl;
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
			cout << "\n삽입할 데이터를 입력해주세요 : ";
			cin >> num;
			myListex.Insert_head(num);
			break;
		case 2:
			cout << "\n삽입할 데이터를 입력해주세요 : ";
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
			printf("중복 설정을 변경합니다.\n\n");
			break;
		case 0:
			cout << "종료합니다.";
			delete &myListex;
			return 0;
		default:
			cout << "0, 1, 2, 3, 4, 5, 6 , 7 중 정해진 범위에서 입력하세요~!" << endl;
			continue;
		}
	}
	return 0;
}