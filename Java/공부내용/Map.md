# 04: Map

> Map은 List 계열과 달리 순차적으로 데이터를 관리하지 않고 Key와 Value의 쌍으로 데이터를 관리한다.

## Map 개요

Map은 Collection 인터페이스를 상속받지 않으며 그 자체로 인터페이스로 여러 Map 구현클래스를 가지고 있다. 가장 대표적인 클래스는 `HashMap`이다.

* Map은 Collection 인터페이스를 상속하지 않음
* Key 집합은 Set으로 볼 수 있음
* Value 집합은 Collection으로 볼 수 있음

기본적인 Map 사용방식은 다음과 같다.

```java
Map<String,String> map = new HashMap<>();
map.put("109875","홍길동");
map.put("109894","김사랑");
System.out.println(map.get("109894")); // 김사랑
```

* 타입 파라미터로 Key, Value의 타입을 지정
* 문자열 이외에 클래스 타입도 가능
* 필요한 데이터를 찾기 위해서는 Key를 인자로 사용

다음과 같은 주요 메서드를 사용해 데이터를 추가, 검색, 삭제 등의 작업을 수행할 수 있으며 특히 전체 데이터를 출력하거나 하는 경우 key, value의 값을 각각 Set과 Collection 타입으로 변환하는 메서드가 유용하게 사용된다.

|     메서드      |                          설명                          |
| :-------------: | :----------------------------------------------------: |
| put(), putAll() | 새로운 요소를 추가, 데이터를 한번에 추가하는 것도 가능 |
|      get()      |           특정 Key에 해당하는 값을 가지고 옴           |
|    remove()     |                     Map 요소 삭제                      |
|   entrySet()    |        Key와 Value 값 모두를 Entry 객체로 변환         |
|    keySet()     |               key 요소만 Set 객체로 변환               |
|     size()      |                      크기를 반환                       |
|    values()     |         value 요소만 Collection 타입으로 반환          |

## Map 기본 예제

```java
public class MapTest {

    public static void main(String[] args) {
        Map<String, String> map = new HashMap<>();
        map.put("1922876", "Apple Iphone");
        map.put("1922877", "Apple Ipad");
        map.put("2136861", "Samsung Galaxy");
        map.put("2136863", "Samsung Tablet");

        System.out.println("1922877: " + map.get("1922877"));

        System.out.println("--------------------");
        for (Map.Entry<String, String> entry : map.entrySet()) {
            System.out.printf("%s:%s\n", entry.getKey(), entry.getValue());
        }

        System.out.println("--------------------");
        for (String s : map.keySet()) {
            System.out.printf("%s\n", s);
        }

        System.out.println("--------------------");
        for (String s : map.values()) {
            System.out.printf("%s\n", s);
        }
    }
}
```

* map.entrySet()을 이용해 k, v로 구성된 Entry 객체를 가져와 출력에 사용
* map.keySet()과 values()를 이용해 각각 key와 value의 목록을 처리

## Map과 List를 함께 사용한 예제

```java
public class MapListTest {
    public static void main(String[] args) {
        List<Integer> s1 = Arrays.asList(95, 89, 93, 87, 94);
        List<Integer> s2 = Arrays.asList(99, 79, 91, 89, 91);
        List<Integer> s3 = Arrays.asList(93, 81, 95, 88, 99);

        Map<String, List<Integer>> student = new HashMap<>();
        student.put("홍길동", s1);
        student.put("김사랑", s2);
        student.put("아무개", s3);

        Scanner scan = new Scanner(System.in);
        System.out.print("## 성적 조회할 이름을 입력하세요: ");
        String input = scan.next();

        int total = 0;
        for (int s : student.get(input)) {
            total += s;
        }

        System.out.printf("총점: %d, 평균: %d", total, total / 5);
    }
}
```