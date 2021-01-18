# 02: 반복문(Loop statement)

반복문은 특정 코드 블럭을 반복하기 위해 사용한다. `for, while`문이 대표적이며 보통 관계 연산자와 함께 많이 사용한다.

즉, 특정 조건에 따라 동일한 작업을 반복해서 수행하기 위한 구문이다. 조건문과 함께 프로그램의 로직을 설계하는 데 꼭 필요한 구문이다. 특정 문제 해결을 위해 처리 로직을 만드는 것을 알고리즘이라 하고, 알고리즘 구현에 조건문과 반복문이 주요 역할을 수행한다.

대표적인 반복문은 `for, while, do~while` 등이 있다. 모든 반복문은 조건을 벗어나는 조건이 잘못 설정된 경우 무한루프에 빠질 수 있으므로 주의해야 한다.

```java
for(초깃값 ; 조건식 ; 증감식) {
    ...
}
```

* 가장 기본적이며 전통적인 for의 형태
* for문의 초깃값, 조건식, 증감식은 생략이 가능
* 단, 세미콜론은 있어야 하며 for(;;)는 무한루프가 됨

```java
for(변수 : 집합형데이터) {
    ...
}
```

* for-each, 혹은 for-in 형식의 구문
* 배열, Collection과 같은 집합형 데이터 처리에 적합
* 집합형 데이터 크기만큼 루프를 돌면서 원소를 변수로 받아 처리

```java
while(조건식) {
    ...
}
```

* 조건식이 참인 경우 반복하는 구조
* while문 내에서 조건식이 변경되지 않으면 무한루프가 될 수 있음

```java
do {
    ...
} while(조건식);
```

* do 코드 블럭이 반드시 한번은 수행되는 구조
* do~while 로만 구현할 수 있는 경우는 없으므로 잘 사용되지 않음

## 반복문 예제

```java
public class Loop {
    public static void main(String[] args) {
        int power = 13;
        String members[] = {"홍길동","김길동","김사랑","아무개"};

        // 0 ~ 9 까지 즉 10회 반복
        for(int i=0;i<10;i++) {
            System.out.println(i);
        }

        // 배열의 인덱스를 이용해 데이터 출력
        for(int i=0;i<10;i++) {
            System.out.println(members[i]);
        }

        // 배열 데이터 크기만큼 반복하면서 String 타입 데이터를 가지고 옴.
        for(String name : members) {
            System.out.println(name);
        }

        // power > 10 보다 큰 경우에는 go() 함수를 호출해 동작시키고 power를 1감소
        while(power > 10) {
            System.out.println("go");
            power--;
        }
        System.out.println("stop");
    }
}
```

* for문에 의해 0~9까지의 값이 출력
* 문자열 배열값을 for-each 형태로 출력
* while 조건값 변경으로 3번 출력 후 종료

### 실행결과

```java
0
1
2
3..9 (생략됨)
홍길동
김길동
김사랑
아무개
go
go
go
stop
```