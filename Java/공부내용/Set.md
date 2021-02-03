## Set

Set 인터페이스는 List와 유사하지만 `중복이 허용되지 않고` 기본적으로는 `순서가 유지되지 않는다`. 구현 클래스로는 HashSet, LinkedHashSet, EnumSet, TreeSet, CopyOnWriteArraySet 등이 있으며 가장 널리 사용되는 것은 `HashSet` 이다. 순서가 필요한 경우 `LinkedHashSet` 클래스나 SortedSet 인터페이스를 구현한 `TreeSet` 등을 사용할 수 있다. 

주요 메서드는 다음과 같다.

|          메서드           |                             설명                             |
| :-----------------------: | :----------------------------------------------------------: |
|      add(), addAll()      | 기존에 없는 새로운 요소를 추가, 컬렉션 데이터를 한번에 추가하는 것도 가능 |
|          clear()          |                       모든 요소를 삭제                       |
| contains(), containsAll() | 인자의 객체를 포함하고 있는지 확인, 컬렉션 전체를 비교할 수도 있음 |
|          isEmpty          |                  요소가 하나도 없는지 확인                   |
|        iterator()         |       현재 Set의 객체에 접근할 수 있는 iterator를 반환       |
|   remove(), removeAll()   |          특정 객체를 삭제하거나 컬렉션 전체를 삭제           |
|          size()           |               Set에 저장된 요소의 크기를 반환                |
|         toArray()         |                현재 Set의 요소를 배열로 반환                 |

### `HashSet, LinkedHashSet`

`가장 대표적인 Set` 구현 클래스이다. 데이터가 중복되지 않는 자료구조가 필요한 경우 사용할 수 있으며 LinkedHashSet의 경우 데이터가 입력된 순서로 저장된다.

#### `기본 사용법`

Collection과 마찬가지로 타입 선언은 인터페이스 타입으로 하고 객체 생성은 HashSet이나 LinkedHashSet을 사용하는 형태이다.

```java
Set<String> s1 = new HashSet<>();
Set<String> s2 = Set.of("three","four");

s1.addAll(Arrays.asList("one","two"));
s1.addAll(s2);
s1.add("five");
s1.add("two"); // 기존에 있으므로 새로 추가 안됨
s1.remove("five");
boolean check = s1.contains("one");
```

LinkedHashSet 의 경우 생성 클래스만 다르고 사용하는 방법은 기본적으로 동일하다.

```java
LinkedHashSet<String> lset = new LinkedHashSet<>();
lset.addAll(Arrays.asList("one","two","three","four"));
lset.add("five");
```

Iterator가 필요한 경우 다음과 같이 Iterator 객체를 가지고 와 사용할 수 있다.

```java
Iterator<String> iter = lset.iterator();
while(iter.hasNext()) {
    System.out.println(iter.next());
}
```

### `TreeSet`

`SortedSet` 인터페이스를 구현한 클래스이다. HashSet과 동일하게 중복된 데이터를 저장할 수 없으며 LinkedHashSet이 입력한 순서로 저장되는 것과 달리 오름차순으로 데이터를 정렬한다.

```java
Set<Integer> tset = new TreeSet<>();
tset.addAll(Arrays.asList(50,10,60,20));
```

만일 내림차순으로 정렬하기를 원한다면 다음과 같이 스트림 api를 사용할 수 있다.

```java
tset.stream().sorted((o1, o2) -> o2.toString().compareTo(o1.toString())).forEach(System.out::println);
```

## 다양한 Set 객체 생성과 데이터 다루기 예제

```java
public class SetTest {
    public static void main(String[] args) {
        // create new Set
        Set<String> s1 = new HashSet<>();
        Set<String> s2 = Set.of("three", "four");

        // add element to Set
        s1.addAll(Arrays.asList("one", "two"));
        s1.addAll(s2);
        s1.add("five");
        s1.add("two");
        s1.remove("five");

        System.out.println("## element in Set");
        System.out.println(s1);

        // print all elements using stream api
        s1.stream().forEach(System.out::println);

        System.out.println("## check exist element in Set");
        System.out.println(s1.contains("one"));

        // create new LinkedHashSet and add elements
        Set<String> lset = new LinkedHashSet<>();
        lset.addAll(Arrays.asList("one", "two", "three", "four"));
        lset.add("five");

        System.out.println("\n## element in LinkedHashSet");
        System.out.println(lset);

        // get Iterator from LinkedHashSet
        System.out.println("## print element using Iterator");
        Iterator<String> iter = lset.iterator();
        while (iter.hasNext()) {
            System.out.println(iter.next());
        }

        // create new TreeSet and add elements
        Set<Integer> tset = new TreeSet<>();
        tset.addAll(Arrays.asList(50, 10, 60, 20));

        System.out.println("\n## elements in TreeSet");
        System.out.println(tset);

        // Ascending sort with stream api
        System.out.println("## Descending sort with stream api");
        tset.stream().sorted((o1, o2) -> o1.toString().compareTo(o2.toString())).forEach(System.out::println);
    }
}
```

* HashSet과 LinkedHashSet은 생성 방법만 다르고 사용 방법은 동일
* HashSet은 순서무관 LinkedHashSet은 추가한 순서대로 TreeSet은 오름차순으로 관리
* 스트림을 사용하면 원본 데이터는 유지되고 정렬된 복사본을 사용하는 형태

### 실행결과

```java
## element in Set
[four, one, two, three]
four
one
two
three
## check exist element in Set
true

## element in LinkedHashSet
[one, two, three, four, five]
## print element using Iterator
one
two
three
four
five

## elements in TreeSet
[10, 20, 50, 60]
## Ascending sort with stream api
60
50
20
10
```