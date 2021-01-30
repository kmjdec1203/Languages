# 02: 제네릭(Generics)

## 타입 안전성(Type Safe)

객체지향 프로그램 개발에 있어 타입은 굉장히 중요하다. 고정된 코드에서는 크게 문제가 되지 않지만 실행과정에서 동적으로 전달되는 객체를 참조해야 하는 경우 잘못된 타입이 전달되면 문제가 된다.

조금 다른 경우이긴 하지만 예를 들어 다음 코드는 문제가 있다.

```java
Color color = new Color("red");
```

* Color 객체를 생성하는데 "red"라는 문자열이 생성됨
* 컴파일상에는 문제가 없으나 만일 만자열 값이 잘못된 것이라면 실행중 에러가 발생

이 경우에는 enum 을 사용하는 것이 바람직하다.

```java
Color color = new Color(Color.RED);
```

이와 같이 객체 타입으로 지정을 해버리면 컴파일 시 잘못된 색상을 사용할 가능성이 원천 차단된다. 마찬가지로 다양한 타입으로 데이터가 구성될 수 있는 클래스를 설계할 때 제네릭을 사용하면 이와 같은 타입 문제를 해결할 수 있다.

## 제네릭

예를 들어 `ArraList` 는 배열과 유사한 자료구조를 제공하는 클래스로 `Object` 타입의 객체를 저장할 수 있다.

그런데 `Object` 클래스는 `모든 자바 클래스의 슈퍼 클래스` 이므로 모든 자바 클래스가 원소로 들어갈 수 있다는 의미가 된다. 매우 편한 구조이기는 하지만 ArrayList로부터 참조 원소들을 꺼내 사용할 때 타입들이 서로 다를 수 있기 때문에 메서드의 사용 등이 차이가 있어 `타입 비교`를 해야 하는 문제가 발생한다.

이와 같이 다양한 타입의 객체들을 다루는 메서드나 컬렉션 클래스의 컴파일 과정에 `타입체크(compile-time type check)`를 해주는 기능을 제네릭이라고 한다.

제네릭 사용의 장점은 다음과 같다.

* 제네릭 클래스 타입의 객체를 생성할 때 개발자가 원하는 타입을 지정할 수 있음
* 타입 안전성을 제공
* 의도하지 않은 타입의 객체가 저장되는 것을 막아 잘못 형변환되는 오류를 방지
* 형변환의 번거로움을 줄여줌 -> 간결한 코드 유지 가능

```java
class Storage<T> {
    T item;
    // getter, setter 생략
}

class App {
    public static void main(String[] args) {
        Storage<String> storage = new Storage();
    }
}
```

* 타입파라미터를 의미하며 임의의 객체타입 지정이 가능
* 타입파라미터는 원시형은 안 되고 객체타입만 가능하므로 `int`의 경우 `Integer` 랩퍼클래스를 사용
* new에서는 <> 타입 명시하지 않아도 됨 (타입 추론 가능)

제네릭을 사용할 때 주의할 점은 다음과 같다.

* T는 인스턴스 변수로 간주되기 때문에 static 멤버에는 타입변수 T를 사용할 수 없음
* 제네릭 타입의 배열을 생성하는 것은 불가능
* new, instanceof 연산자의 경우 컴파일 시점에 타입 T를 명확하게 알아야 하기 때문에 T를 피연산자로 사용할 수 없음

## 기본적인 제네릭 클래스 생성과 사용 예제

```java
public class Storage<T> {
    T item;

    public T getItem() {
        return item;
    }

    public void setItem(T item) {
        this.item = item;
    }
}
```

```java
public class GenericsTest1 {
	public static void main(String[] args) {
		Storage<String> storage1 = new Storage<>();
		storage1.setItem("MyItem");
		System.out.println(storage1.getItem());

		Storage<Integer> storage2 = new Storage<>();
		storage2.setItem(20201121);
		System.out.println(storage2.getItem());
	}
}
```

* 동일한 Storage 클래스를 사용하지만 각각 `String` 과 `Integer` 타입으로 선언
* 선언된 타입 파라미터에 따라 setItem() 의 값의 타입 일치를 컴파일러가 체크

### 실행결과

```
MyItem
20201121
```