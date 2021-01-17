# 01: 조건문(Conditional statement)

조건문은 조건에 따라 프로그램을 수행하기 위해 사용한다. 관계 연산자와 함께 사용되며 `if, switch`문이 대표적이다.

즉, 프로그램에서 뭔가의 입력을 받아 입력된 값에 따라 동작을 다르게 하거나 특정 조건에 따라 처리되도록 하는 경우 조건문을 사용한다고 볼 수 있다.

대표적인 조건문은 `if`이며 다양한 조건 구성을 위해 `if~else if`등이 사용된다. `switch`문은 조건값에 따라 수행 블럭을 구분해서 정의할 수 있다. 이 외 `3항연산`과 같이 참/거짓에 따른 간단한 조건 연산을 수행할 수 있는 구문도 있다.

## 1) if 문

> 조건에 따라 코드 블럭을 수행한다.

```java
if(조건식) {
    실행 코드 블럭
}
```

* 수행 문장이 하나라면 중괄호 `{}` 생략 가능
* 수행 조건은 `관계연산과 논리연산의 조합`을 통해 설정 가능
* 조건에 따라 처리를 다르게 하기 위해서는 `if~else if`문을 사용함
* 단순 `if`문을 나열해 사용하는 것은 바람직하지 않음
* `if`블럭 안에 또다른 `if` 블럭의 사용이 가능함

```java
// if, else if
if(power < 10) {
    slowdown();
}
else if((power > 100) && (time <= 50) {
    gofaster();
}
else {
    go();
}
```

* power가 10 이하이면 slowdown() 수행
* power가 100 이상이고 time이 50보다 같거나 작으면 gofaster() 수행
* 이외의 조건에는 go() 수행

## 2) switch 문

> 조건값에 따른 처리 블럭을 구분해서 처리할 수 있도록 구조화한 구문으로 상황에 따라 `if~else if`문의 대체가 가능하다.

```java
switch(입력 변수) {
    case 조건값: 
    	실행 구문;
    	break;
    ..
    default: 기본 실행 구문;
}
```

* 입력 변수는 정수형, 문자 혹은 문자열
* 실행 구문은 별도의 `{}` 없이 구문을 나열해 사용
* 실행 구문의 마지막에 반드시 `break` 를 넣어야 함. 그렇지 않으면 이후 조건의 구문들도 실행됨
* default는 조건에 해당하는 입력값이 없는 경우 실행되는 코드를 기술함
* 입력 변수의 값과 매칭되는 경우 수행하는 코드를 지정하는 것으로 복잡한 조건 체크는 한계가 있음

## 3) 3항연산

> 간단하게 구현할 수 있는 조건문으로 비교적 간단한 `if~else` 구문 처리에 적합하다.

```java
조건? true인 경우 수행문장 : false인 경우 수행문장;
```

* 조건이 true인 경우 ? 다음에 오는 문장이 수행됨
* 조건이 false인 경우 : 오른쪽 문장이 수행됨

```java
String result = (login)? "로그인성공":"로그인실패";
```

## 조건문 예제

```java
import java.util.Scanner;

    public class Conditional {
        void login() {
            Scanner scan = new Scanner(System.in);

            System.out.print("## 아이디를 입력하세요: ");		
            String uname = scan.next();

            System.out.print("# 비밀번호를 입력하세요: ");
            String pwd = scan.next();

            if(uname.equals("hong") && pwd.equals("1234")) {
            System.out.println("인증 확인!! -> 로그인 성공");
            }
            else {
            System.out.println("아이디나 비밀번호가 틀렸습니다.!!");
            }
        }

    void check() {
        int cnt = 10;
        String msg = cnt > 0? "새로운 쪽지가 있습니다.!!" : "새로운 쪽지가 없습니다.!!";
        System.out.println(msg);
    }

    public static void main(String[] args) {
        Conditional con = new Conditional();

        while(true) {
            System.out.printf("# 메뉴를 선택하세요 (1:로그인, 2:쪽지확인, x:종료) ==> ");
            Scanner scan = new Scanner(System.in);
            String sel = scan.next();

            switch(sel) {
            case "1": con.login();break;
            case "2": con.check();break;
            case "x": System.exit(0);
            default : System.out.println("잘못된 입력 입니다.!!");
            }	
        }
    }
}
```

* 로그인 메뉴는 아이디와 비밀번호를 입력받고 if 문을 이용해 주어진 값과 맞는지 확인
* 쪽지 확인의 경우 cnt 변수값에 따라 3항 연산을 이용해 출력할 메시지를 결정
* x 는 프로그램 종료, 이외 값 입력 시 `잘못된 입력` 출력됨

### 실행결과(예시)

```java
# 메뉴를 선택하세요 (1:로그인, 2:쪽지확인, x:종료) ==> 1
## 아이디를 입력하세요: hong
# 비밀번호를 입력하세요: 23454
아이디나 비밀번호가 틀렸습니다.!!
# 메뉴를 선택하세요 (1:로그인, 2:쪽지확인, x:종료) ==> 1
## 아이디를 입력하세요: hong
# 비밀번호를 입력하세요: 1234
인증 확인!! -> 로그인 성공
# 메뉴를 선택하세요 (1:로그인, 2:쪽지확인, x:종료) ==> 2
새로운 쪽지가 있습니다.!!
# 메뉴를 선택하세요 (1:로그인, 2:쪽지확인, x:종료) ==> x
```