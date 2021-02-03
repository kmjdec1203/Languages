# 03: List, Set

> List와 Set은 모두 Collection 인터페이스를 상속받고 있으며 List의 구현 클래스들은 AbstractList 클래스를 상속 받는 구조이다.

## 리스트(List)

List 인터페이스는 배열과 유사한 자료구조로 `중복이 허용`되면서 `저장순서가 유지`되는 구조를 제공한다. 구현 클래스로는 Vector, ArrayList, LinkedList가 있으며 가장 널리 사용되는 것은 `ArrayList`이다.

주요 메서드는 다음과 같다.

|     메서드      |                             설명                             |
| :-------------: | :----------------------------------------------------------: |
| add(), addAll() | 새로운 요소를 추가, 위치를 지정하거나 컬렉션 데이터를 한번에 추가하는 것이 가능 |
|      get()      |             지정된 위치(index)에 있는 객체 반환              |
|    indexOf()    |                   객체의 위치(index) 반환                    |
|  lastIndexOf()  |        List의 마지막 요소로부터 역방향으로 위치 변환         |
| listIterator()  |       List의 객체에 접근할 수 있는 ListIterator를 반환       |
|    remove()     |    지정된 위치에 있는 객체를 삭제하고 삭제된 객체를 반환     |
|      set()      |                  지정된 위치에 객체를 저장                   |
|     sort()      |              지정된 Comparator로 List 요소 정렬              |
|    subList()    |         지정된 범위에 있는 객체를 새로운 List로 변환         |

### `ArrayList, LinkedList`

`가장 대표적인 List` 구현 클래스이다. 일반적으로 모든 용도에서 사용할 수 있으나 데이터 추가나 삭제가 잦은 경우 처리속도에 문제가 있을 수 있다.

ArrayList는 `내부적으로 배열 구조`를 사용하고 있으므로 중간에 데이터가 추가되거나 삭제될 경우 기존 데이터를 복사해 새로운 구조를 만들어야 하기 때문에 이와 같은 경우에는 `LinkedList`를 사용할 것을 권장한다.

#### `기본 사용법`

Collection과 마찬가지로 타입 선언은 인터페이스 타입으로 하고 객체 생성은 ArrayList나 LinkedList를 사용하는 형태이다.

```java
List<String> l1 = new ArrayList<>();
List<String> l2 = Arrays.asList("one", "two");
List<String> l3 = List.of("three", "four");

l1.add("five");
l1.addAll(l2);
l1.set(0,"zero");

System.out.println(l1.get(0));
```

LinkedList의 경우 생성 클래스만 다르고 사용하는 방법은 동일하며 내부적으로 요소의 추가와 삭제 등을 처리하는 방법에 차이가 있다.

```java
LinkedList<String> llist = new LinkedList<>();
llist.addAll(l2);
llist.addAll(1,l3);
llist.add("five");
```

### `정렬`

원소들의 정렬을 위해서는 다양한 방법이 사용될 수 있다. 기본적으로는 `Collections.sort(List<T> list)`를 사용할 수 있다. 이 경우 내림차순으로 정렬이 이루어지며 원래 List 객체는 원소들이 정렬된 결과로 바뀌게 된다. 이 방법으로는 오름차순 정렬은 할 수 없고 `Comparator`를 추가로 인자로 작성해 주어야 가능하다.

```java
Collections.sort(l1);
System.out.println(l1);
```

또다른 방법으로는 List의 `sort(Comparator <? super E> c)` 메서드를 이용하는 것이다. 이 경우 정렬 방법을 다루는 Comparator 객체가 필요하게 된다. 별도 클래스로 만든 요소 타입을 사용하고 있다면 해당 클래스에 Comparable 인터페이스를 구현하고 compareTo() 메서드를 구현해주면 되고 그렇지 않다면 sort() 메서드의 인자 부분에 직접 내부 익명 클래스로 구현하는 방법을 사용할 수 있다.

```java
l1.sort(new Comparator<Object>() {
    @Override
    public int compare(Object o1, Object o2) {
        return o2.toString().compareTo(o1.toString());
    }
});
```

* 여기서는 오름차순 정렬로 두번째 인자 .compareTo() 결과를 리턴하면 된다.
* 내림차순의 경우 첫번째 인자 compareTo() 결과를 리턴하면 된다.
* compare() 결과는 같으면 0, 자신이 크면 양수, 인자가 크면 음수를 리턴

```java
l1.stream().sorted((o1, o2) -> o2.toString().compareTo(o1.toString())).forEach(System.out::println);
```

* List 객체를 stream() 메서드를 이용해 스트림으로 변환한 다음 sorted() 메서드를 사용
* sorted() 는 람다식을 이용해 Comparator를 구현하는 형식임
* 변환된 스트림은 forEach() 를 이용해 출력

## ArrayList, LinkedList 생성과 데이터 다루기 예제

```java
public class ListTest {
    public static void main(String[] args) {
        // create new List
        List<String> l1 = new ArrayList<>();
        List<String> l2 = Arrays.asList("one", "two");
        List<String> l3 = List.of("three", "four");

        // add data to List
        l1.addAll(l2);
        l1.addAll(1, l3);
        l1.add("five");

        System.out.println("## element in List");
        System.out.println(l1);

        // create new LinkedList and add data
        LinkedList<String> llist = new LinkedList<>();
        llist.addAll(l2);
        llist.addAll(1, l3);
        llist.add("five");

        System.out.println("## element in LinkedList");
        System.out.println(llist);

        // access data with index
        System.out.println("## first element: " + l1.get(0));
        System.out.println("## last index of three: " + l1.lastIndexOf("three"));

        // change data in List
        l1.set(0, "zero");
        System.out.println("## after set(): element in LinkedList");
        System.out.println(l1);

        // Descending sort
        Collections.sort(l1);
        System.out.println("## Descending sort of l1");
        System.out.println(l1);

        // Ascending sort
        l1.sort(new Comparator<Object>() {
            @Override
            public int compare(Object o1, Object o2) {
                return o2.toString().compareTo(o1.toString());
            }

        });
        System.out.println("## Ascending sort of l1");
        System.out.println(l1);

        // Ascending sort with stream api
        System.out.println("## Ascending sort with stream api");
        l1.stream().sorted((o1, o2) -> o2.toString().compareTo(o1.toString())).forEach(System.out::println);
    }
}
```

### 실행결과

```
## element in List
[one, three, four, two, five]
## element in LinkedList
[one, three, four, two, five]
## first element: one
## last index of three: 1
## after set(): element in LinkedList
[zero, three, four, two, five]
## Descending sort of l1
[five, four, three, two, zero]
## Ascending sort of l1
[zero, two, three, four, five]
## Ascending sort with stream api
zero
two
three
four
five
```