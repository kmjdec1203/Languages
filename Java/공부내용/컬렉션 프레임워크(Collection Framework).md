# 02: 컬렉션 프레임워크(Collection Framework)

컬렉션 프레임워크는 자바에서 데이터를 저장하는 클래스들을 `표준화한 설계 구조`를 말한다. 이러한 구조를 바탕으로 자바의 기본 자료구조 클래스들이 구성되어 있으며 체계화되고 `일관된 구조` 를 가지게 되었다.

Collection, Map, List, Set 인터페이스를 중심으로 다음과 같은 클래스 계층구조를 형성하고 있다.

![img](https://dinfree.com/lecture/language/img/java5.png)

다음은 주요 인터페이스에 대한 설명이다.

| 인터페이스 |                       설 명                       |               특 징               |          대표 구현 클래스          |
| :--------: | :-----------------------------------------------: | :-------------------------------: | :--------------------------------: |
|    List    |             순서가 있는 데이터의 집합             |       데이터의 중복을 허용        |       ArrayList, LinkedList        |
|    Set     |        순서를 유지하지 않는 데이터의 집합         |   데이터의 중복을 허용하지 않음   |       HashSet, LinkedHashSet       |
|    Map     | 키(key)와 값(value)의 쌍으로 이루어진 데이터 집합 | 순서 유지 X, 키 중복 X, 값 중복 O | HashMap, LinkedHashMap, Properties |

## Collection 인터페이스

List와 Set의 상위 인터페이스이다. 즉, List와 Set을 구현한 모든 클래스들은 Collection 인터페이스의 메서드를 사용할 수 있으므로 구현클래스와 상관없이 동일한 방법으로 데이터를 다룰 수 있다.

컬렉션 안에 들어가는 데이터들은 모든 타입이 가능하지만 타입이 다른 경우 일관된 처리가 어렵기 때문에 타입 파라미터를 사용한다.

```java
Collection<String> c = new HashSet<>();
```

* 순서가 없고 데이터 중복을 허용하지 않는 자료구조인 HashSet 객체 생성
* 저장되는 데이터는 문자열로 한정
* 원래는 `new HashSet<String>();` 이지만 타입추론을 통해 생략 가능

### `컬렉션 객체의 생성`

모든 컬렉션 클래스들은 `java.util` 패키지에 들어있다. 컬렉션 객체를 생성하는 방법은 참조변수 선언 시 상위 인터페이스 타입을 사용하고 객체 생성은 필요에 따라 구체적인 클래스들을 사용하는 형식이다.

```java
ArrayList<String> list = new ArrayList<>();		// 권장안됨
List<String> list = new ArrayList<>();		// 권장됨
```

컬렉션 객체를 생성하는 방법은 다양하며 상황에 따라 적절한 방법을 사용하면 된다.

```java
Collection<String> c1 = new HashSet<>();
Collection<String> c2 = Arrays.asList("three", "four");
Collection<String> c3 = Collections.singletion("five");
```

* c1 : 빈 HashSet 객체를 생성. 데이터는 직접 add() 메서드를 통해 넣어야 함
* c2 : 두개의 데이터를 가지는 List 객체를 생성
* c3 : 데이터가 하나인 유일한 인스턴스를 보장하는 Set 객체를 생성

### `컬렉션에 데이터 추가, 삭제`

데이터 추가는 `add(), addAll()` 메서드를 사용한다. 지정된 타입의 데이터를 하나씩 추가할 때는 `add()`, 컬렉션 타입을 추가할 때는 `addAll()`을 이용해 개별 원소를 꺼내어 추가하는 방식이다.

```java
c1.add("one");
c1.addAll(c2);
```

데이터의 삭제는 remove(), removeAll(), retainAll(), clear() 등의 메서드를 사용한다. retainAll() 의 경우 인자의 데이터를 제외한 나머지 데이터를 모두 삭제하는 메서드이고 clear() 는 모든 데이터를 삭제한다.

```java
c1.remove("one");
c1.remove("c2");
c1.retainAll("four");
c1.clear();
```

### `컬렉션 데이터 확인 및 변환`

특정 데이터가 컬렉션 안에 존재하는지 혹은 비어있는지를 확인할 수 있으며 크기를 구할 수 있다.

```java
c1.isEmpty();
c1.contains("zero");
c1.containsAll(c2);
```

컬렉션 데이터의 크기는 `size()` 메서드를 통해 구현할 수 있으며 데이터 변환은 `toArray()` 메서드를 이용해 배열 형태로 변경할 수 있다. 다만 `Object 타입으로 리턴` 되므로 특정 타입을 원한다면 해당 객체 생성 코드를 넣어주어야 한다.

```java
int size = c1.size();
Object[] converted1 = c1.toArray();
String[] converted2 = c1.toArray(new String[c1.size()]);
```

### `컬렉션 데이터의 사용`

컬렉션에 들어있는 데이터를 사용하기 위해서는 `다소 복잡한 과정`을 거쳐야 한다. 컬렉션 자체는 구체적인 구현이 아니므로 직접적으로 데이터에 접근하는 방법은 포함되어 있지 않다.

List나 Set 인터페이스를 이용해 처리하거나 Collection 인터페이스 타입으로 처리하려면 다음의 방법중 하나를 사용할 수 있다.

#### `a) 배열로 변환해서 for문과 사용`

특정 위치의 데이터를 직접 선택할 필요 없이 순차적으로 모든 데이터를 사용하는 경우 단순하게 for 문만 사용해도 된다.

```java
for(String s : c1) {
    System.out.println(s);
}
```

그러나 특정 위치의 데이터를 직접 다루고자 한다면 앞에서 다룬 toArray() 메서드를 이용해 배열로 변환해 사용하는 방법을 사용해야 한다. 배열 데이터는 인덱스로 접근할 수 있으므로 각각의 데이터를 차례로 접근하거나 특정 위치 데이터를 직접 접근해 사용할 수 있다.

```java
String[] converted2 = c1.toArray(new String[c1.size()]);
for(int i = 0; i < converted2.length; i++) {
    System.out.println(converted2[i]);
}
```

#### `b) Iterator를 사용`

Iterator는 다음 데이터에 접근하는 방법을 제공하는 인터페이스이다. Collection 인터페이스는 Iterable 인터페이스를 상속받고 있으며 iterator() 메서드로 Iterator 객체를 구현할 수 있다.

획득한 데이터를 조작하거나 다른 메서드의 인자로 전달하는 등 필요한 작업에 활용할 수 있다.

```java
Iterator iter = c1.iterator();
while(iter.hasNext()) {
    System.out.println(iter.next());
}
```

#### `c) forEach()를 사용`

마지막으로 forEach() 메서드를 사용하는 방법이다.

```java
c1.forEach(s -> System.out.println(s));
c1.forEach(System.out::println);
```



## Collection 종합 예제

```java
public class CollectionTest {
    public static void main(String[] args) {
        // Create a new HashSet and add data
        Collection<String> c1 = new HashSet<>();
        c1.add("one");
        c1.add("two");

        // Create a new List with two values
        Collection<String> c2 = Arrays.asList("three", "four");
        Collection<String> c3 = Collections.singleton("five");

        // add all data in c2, c3 to c1
        c1.addAll(c2);
        c1.addAll(c3);

        // get size of collection
        System.out.println("Size of c1 : " + c1.size());

        // convert collection to array
        Object[] converted1 = c1.toArray();
        String[] converted2 = c1.toArray(new String[c1.size()]);

        // print all data in collection using for loop
        for (String s : c1) {
            System.out.println(s);
        }

        // access and print all data in the array which converted from collection
        for (int i = 0; i < converted2.length; i++) {
            System.out.println(converted2[i]);
        }

        // get Iterator object from collection and access the data
        Iterator iter = c1.iterator();
        while (iter.hasNext()) {
            System.out.println(iter.next());
        }

        // run specific code using every elements in the collection
        c1.forEach(System.out::println);
    }
}
```

* 최종적으로 컬렉션 c1의 데이터는 one, two, three, four, five가 됨
* HashSet의 특성상 순서가 보장되지 않으므로 데이터를 넣는 순서대로 출력되는 것은 아님
* 4가지 방법으로 데이터를 출력하고 있으므로 동일 결과가 4번 반복됨

### 실행결과

```
Size of c1 : 5
four
one
two
three
five
four
...
```