# C++_4

## class

```c++
#include <iostream>
using namespace std;
// 생성자 함수: 객체가 생성될 때 자동으로 호출 된다.
// 소멸자 함수: 객체가 삭제될 때 자동으로 호출 된다.
/*
* 함수이름 > 클래스 이름 동일
* 함수 반환형식 x
* 생성자 다중정의가 가능(매개변수) 함수이름()
* 소멸자 유일!! ~함수이름()
*/
class CTest {
    // 접근제어지시자
    /*
    * public: 외부에서 멤버 접근 모두 허용
    * protected: 외부에서 일단 차단, 상속 파생 클래스 허용
    * private: 외부에서 모두 차단!
    */
    // 멤버변수
    // 멤버함수
    int m_nData;	// private!! (접근제어지시자가 없으면 자동으로...)
public:
    CTest() {       // 매개변수가 없는 생성자 > 디폴트 생성자
        m_nData = 0;
        cout << "CText() 생성자" << endl;
    }      // 생성자
    ~CTest() {
        cout << "~CTest() 소멸자" << endl;
    }     // 소멸자
    void SetData(int n) { m_nData = n; }
    int GetData() { return m_nData; }
};
int main() {

    cout << "main() 시작" << endl;
    // CTest t; // 객체선언 > 인스턴스 생성 > 생성자!!
    
    CTest* pt = new CTest;

    delete pt;

    cout << "main() 끝" << endl;
   
    return 0;
}
```

실행결과: 

**main() 시작
CText() 생성자
~CTest() 소멸자
main() 끝**

-new와 delete가 각각 생성자와 소멸자를 호출함

=> 위 main() 함수에서 CTest() 함수를 호출하지 않아도 저렇게 결과값이 나온다.

----

* new 
  * 메모리 동적할당
  * 동적 객체 생성 (생성자 호출)
* delete 
  - 메모리 해제
  - 객체 삭제 (소멸자 호출)
