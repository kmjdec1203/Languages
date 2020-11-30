# C++_3

### class

> 형식
>
> class 클래스 이름 (첫 문자 대문자) {
>
> ​	접근제어 지시자 (없으면 자동으로 private로)
>
> ​	멤버변수:
>
> ​	멤버변수:
>
> }; 



### 접근 제어 지시자

* public, protected, private가 있다.



### 생성자 함수

클래스 이름과 동일한 이름의 함수, 반환현식 X

(멤버변수를 초기화)

```c++
class USERDATA {
public:
	// 멤버 변수
	int nAge;
	std::string szName;
	// 멤버 함수
	USERDATA() {
		nAge = 30;
		szName = "권민정";
	}
	void Print() {
		std::cout << nAge << " " << szName << std::endl;
	}
};

int main() {
	USERDATA user;	// 객체 생성 > 인스턴스 생성 > 생성자 호출
	user.Print();
	return 0;
}
```

실행 화면 : 30 

​					권민정