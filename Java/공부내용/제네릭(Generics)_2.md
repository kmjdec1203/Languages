## 제네릭 고급 사용

### `제네릭 메서드`

이번에는 메서드의 선언에 제네릭이 사용되는 형태를 살펴보겠다. 메서드의 인자 혹은 리턴에 제네릭이 사용될 수 있으며 다양한 타입을 처리해야 하는 경우 유용하게 활용할 수 있다.

앞에서 만든 Storage 를 인자로 하는 메서드는 다음과 같이 선언될 수 있다.

```java
public <T> void print(Storage<T> storage) {
}
```

* 인자에 제네릭 클래스를 사용한 경우 메서드 앞에 붙여주어야 함

리턴타입 역시 제네릭 클래스를 사용할 수 있다.

```java
public List<String> getList() {
}
```

인자와 리턴이 모두 제네릭을 가지는 경우에는 다소 복잡할 수 있다.

```java
public <T> List<Character> convert(Storage<T> storage) {
}
```

* 다음에 나오는 와일드 카드 사용도 가능

### `와일드 카드`

제네릭 타입을 사용할 때 발생할 수 있는 문제점으로 특정 제네릭 타입을 인자로 받는 메서드를 구현하는 상황을 예로 들 수 있다. 앞에서 만든 Storage 를 인자로 하는 메서드를 살펴보도록 한다.

```java
public void print(Storage<String>) {
    ...
}
```

인자로 String 타입 파라미터를 가지는 Storage 클래스가 지정되어 있기 때문에 Storage 타입은 해당 메서드를 이용할 수 없다. 인자가 다르니 메서드 오버로딩을 사용하면 어떻게 될까? 아쉽게도 제네릭의 경우 클래스 타입 자체는 동일하므로 오버로딩이 적용되지 않는다. 만약 허용된다고 해도 필요한 타입마다 메서드를 오버로딩하는 것도 바람직한 구조는 아니다.

이 경우 와일드 카드를 사용해 사용할 수 있는 타입에 유연성을 부여하는 방법이 있다.

```java
public void print(Storage<? extends Storage) {
    
}
```

* ? 는 사실상 Object 클래스라고 볼 수 있음
* extends, super 를 통해 올 수 있는 타입의 관계를 특정할 수 있음
* ? extends T : T 와 그 자손만 가능
* ? super T : T 와 그 부모만 가능

## 제네릭 메서드 및 와일드 카드 사용 예제

```java
import java.util.ArrayList;
import java.util.List;

public class GenericsTest2 {
    public <T> List<Character> convert(Storage<T> storage) {
        ArrayList<Character> list = new ArrayList<>();

        String s = String.valueOf(storage.getItem());
        int size = s.length();
        for (int i = 0; i < size; i++) {
            list.add(s.charAt(i));
        }
        return list;
    }

    public static void main(String[] args) {
        Storage<String> s1 = new Storage<>();
        s1.setItem("MyItem");

        Storage<Integer> s2 = new Storage<>();
        s2.setItem(20201121);

        GenericsTest2 gt2 = new GenericsTest2();

        System.out.println(gt2.convert(s1));
        System.out.println(gt2.convert(s2));
    }
}
```

* 앞에서 만든 Storage 클래스를 활용
* 2개의 서로 다른 타입을 가지는 Stroage 인스턴스 생성
* convert() 메서드는 Storage 타입을 받아 getItem() 결과를 문자열로 변환
* 문자열을 Character List 로 변환해서 리턴

### 실행결과

```
[M, y, I, t, e, m]
[2, 0, 2, 0, 1, 1, 2, 1]
```