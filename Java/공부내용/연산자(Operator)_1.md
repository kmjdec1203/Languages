# 연산자(Operator)

연산자는 프로그램에서 변수의 값들을 계산하기 위해 사용한다. 사칙 연산, 대입 연산, 비트 연산, 논리 연산, 관계 연산 등이 있다.

## 사칙 연산(Arithmetic operators)

> 숫자 데이터를 이용해 기본적인 수학연산을 수행한다.

| 사칙 연산자 | 사용 예 |    의미     | 결과 |
| :---------: | :-----: | :---------: | :--: |
|      +      |  4 + 2  |  덧셈 연산  |  6   |
|      -      |  4 - 2  |  뺄쎔 연산  |  2   |
|      *      |  4 * 2  |  곱셈 연산  |  8   |
|      /      |  4 / 2  | 나누기 연산 |  2   |
|      %      |  8 % 3  | 나머지 연산 |  2   |

## 대입 연산(Assignment operators)

> 변수에 값을 대입하기 위한 연산자로 축약형과 단항 연산자 등이 포함되어 있다.

| 대입 연산자 |   사용 예    |             의미             | 결과 |
| :---------: | :----------: | :--------------------------: | :--: |
|      =      | weight = 80; | 변수 weight에 80의 값을 할당 |  80  |
|     +=      | weight += 2; | weight = weight + 2;와 같음  |  82  |
|     -=      | weight -= 2; | weight = weight - 2;와 같음  |  80  |
|     *=      | weight *= 2; | weight = weight * 2;와 같음  | 160  |
|     /=      | weight /= 2; | weight = weight / 2;와 같음  |  80  |
|     %=      | weight %= 2; | weight = weight % 2;와 같음  |  2   |
|     ++      |  weight++;   | weight = weight + 1;와 같음  |  3   |
|     --      |  weight--;   | weight = weight - 1;와 같음  |  2   |

* **단항 연산자** : ++, --와 같은 단항 연산자는 변수명 앞 혹은 뒤에 사용할 수 있다. 앞에 사용하면 값을 먼저 증/감시킨 후 변수에 대입하고, 뒤에 사용하면 현재 변수값을 사용한 다음 증/감시킨 값을 대입하게 된다.

## 연산자 예제 -사칙 연산, 대입 연산

```java
public class Operator1 {
    public static void main(String[] args) {
        int num1 = 30;
        int num2 = 14;

        int result1 = num1 * num2;
        int result2 = num1 % num2;

        System.out.printf("result1 : %d \n", result1);
        System.out.printf("result2 : %d \n", result2);
        System.out.println("-------------------");

        num1++;
        num2 *= 2;
        System.out.printf("num1++ : %d \n", num1);
        System.out.printf("num2 *= 2 : %d \n", num2);
        System.out.println("-------------------");

        System.out.printf("num1++ : %d \n", num1++);
        System.out.printf("--num1 : %d \n", --num1);
    }
}
```

+ ```++, --``` 증감 연산자의 경우 변수 앞에 사용하면 먼저 적용되고 뒤에 사용하면 현재 문장 수행 후 적용.
+ ```19라인``` 에서 증가시켰기 때문에 21라인에서 31로 출력.
+ ```25라인``` 의 경우 나중에 증가시키기 때문에 31 출력 후 32로 변경됨.
+ ```26라인``` 은 32에서 1을 먼저 감소시켰기 때문에 31로 출력.

### 실행결과

```java
result1 : 420 
result2 : 2 
-------------------
num1++ : 31 
num2 *= 2 : 28 
-------------------
num1++ : 31 
--num1 : 31 
```