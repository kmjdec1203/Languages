# 03: 배열(Arrays)

프로그램을 작성하는 과정에는 여러 `데이터`가 필요하다. 예를 들어 `100명의 학생의 성적`을 처리한다고 할 때 각각의 성적 값을 변수에 할당한다면 `100개의 변수`가 필요하다. 이런 경우 배열을 이용하면 `하나의 변수명`으로 100개의 데이터를 처리할 수 있다.

배열은 컴퓨터 프로그램에서 데이터를 처리하기 위해 만든 구조중 하나로 대부분의 언어에 존재하며 개념도 비슷하다. 배열의 경우 다소 불편한 부분들이 있기 때문에 실제 프로그램 구현에는 LIST, MAP 등의 자료구조가 사용된다.  

## 배열의 특징

가장 `대표적인 자료구조`이다. 데이터를 순차적으로 저장해 `0부터 시작`하는 `인덱스`를 통해 접근할 수 있다.

* 일반적으로 배열은 선언할 때 크기가 고정됨
* 데이터를 순차적으로만 접근할 수 있어 위치를 모르는 경우 효율이 떨어짐
* 배열에 들어가는 데이터는 모두 동일한 자료형이어야 함
* 배열 중간에 값을 추가하려면 기존 데이터를 모두 이동시켜야 함

## 배열 선언 및 데이터 사용

```java
int scores[] = {95,100,87,91};
int[] scores = {95,100,87,91};
int[] scores = new int[4];
scores[2] = 90; // 3번째 요소(87)을 90으로 변경.

System.out.println(scores[0]);
```

* 자바에서 배열 선언 시 `타입[] 변수명` 혹은 `타입 변수명[]` 형식을 모두 사용할 수 있음
* 배열 선언 시 크기를 지정하거나 초기 데이터로 크기가 고정됨
* 배열 원소에 접근은 `배열명[인덱스]` 형식으로 사용
* 인덱스는 0부터 시작
* `배열.length` 를 통해 배열의 크기를 구할 수 있음

## 배열의 주요 메서드

자바에서 배열을 다루기 위한 메서드는 Arrays 클래스에 정의되어 있다. 따라서 배열과 관련된 처리를 위해서는 Arrays 클래스의 메서드를 활용할 수 있다.

* 배열은 크기가 고정되어 있고 데이터를 다루기가 불편함
* 따라서 List 등으로 변경해서 처리할 필요가 있음
* Arrays 클래스의 모든 메서드는 static 이므로 인스턴스 생성 없이 사용 가능
* `java.util` 패키지 import가 필요함

### `asList()`

* 배열을 ArrayList로 변환해 자바 컬렉션 API를 사용할 수 있다
* 다만 반환되는 ArrayList는 크기가 고정된 타입으로 새롭게 값을 추가할 수 없다

```java
String[] cars = {"hyundai","bmw","benz","toyota"};
ArrayList car_list = Arrays.asList(cars);
```

### `toString()`

* 모든 자바 Object 에 포함된 메서드로 기본은 Object ID를 출력함
* 배열 자체를 System.out.println() 등에서 출력하면 데이터가 출력되지 않고 Object ID가 출력됨
* Arrays.toString()을 이용하면 데이터를 출력할 수 있음

```java
System.out.println(cars);  // Object ID가 출력됨.
System.out.println(Arrays.toString(cars));  // ["hyundai","bmw","benz","toyota"]
```

### `sort()`

* 배열 원소를 정렬한다. 원본 배열 자체가 원소들이 정렬된 순서로 변경됨
* sort(array, Comparator), sort(array, int fromindex, int toindex)를 이용해 내림차순 정렬 및 구간 정렬 등이 가능하다
* 구간 정렬의 경우 `fromindex ~ toindex-1`까지를 범위로 함

```java
Arrays.sort(cars);  // [benz, bmw, hyundai, toyota]
Arrays.sort(cars, Collections.reverseOrder());  // [toyota, hyundai, bmw, benz]
Arrays.sort(cars, 0,2); // [hyundai, toyota, bmw, benz]
```

### `copyOf()`

* 배열을 복사해서 새로운 배열로 변환
* copyOfRage() 는 특정 범위만 변환
* 구간 복사의 경우 `fromindex ~ toindex-1` 까지를 범위로 함

```java
// 앞의 마지막 예제 결과에 이어짐.
String[] cars_copied = Arrays.copyOf(cars);  //[hyundai, toyota, bmw, benz]
String[] cars_copied = Arrays.copyOfRange(cars, 0,2);   // [hyundai, toyota]
```

## 다차원 배열

다차원 배열은 하나 이상의 배열을 포함하고 있는 배열의 구조를 말한다.

* 2차원 배열은 배열 요소로 1차원 배열을 가지는 배열
* 3차원 배열은 배열 요소로 2차원 배열을 가지는 배열
* 4차원 배열은 배열 요소로 3차원 배열을 가지는 배열

객체지향 프로그래밍 개념이 정착하기 이전에는 복잡한 자료구조 처리를 위해 다차원 배열을 사용했다.

단순히 정형화된 구조의 복잡한 데이터를 기계적으로 처리하는 데이터 분석이나 주어진 데이터를 통해 프로그램을 구성하는 게임 등에는 여전히 많이 사용되고 있으나 일반적인 프로그램 개발에는 2차원 배열 정도만 사용하고 있다.

예를 들어 5과목씩 수강하는 학생들의 성적을 처리하기 위해 다음과 같이 2차원 배열을 만들 수 있다.

```java
int[][] allScores = { {90,85,70,55,60},{96,88,81,91,75} ....};
```

* 배열의 원소가 또 다른 배열
* 배열 원소의 접근은 `allScores[0][1]`과 같이 사용 -> 85

만일 여기에 학과별로 구분을 추가한다면 다음과 같이 3차원 배열로 확장할 수 있다.

```java
int[][][] allScores = { 
    {
        {90,85,70,55,60},
        {96,88,81,91,75},
        {96,88,81,91,75},
        {96,88,81,91,75}
    },
    {
        {91,82,73,54,65},
        {96,87,88,99,80},
        {91,82,83,94,75},
        {96,87,88,99,70}
    },
    {
        {92,83,74,55,66},
        {97,88,89,90,71},
        {92,83,84,95,76},
        {97,88,89,90,71}
    }
    ...    
};
```

* 배열의 기본 원소 구성은 학과가 되어 학과별로 2차원 배열로 학생별 성적을 가지고 있다고 볼 수 있다
* 예를 들어 2번째 학과의 3번째 학생의 첫 번째 과목 성적은 `allScores[1][2][0]` 과 같이 접근 -> 91

## 배열 예제

```java
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Array {

    public static void main(String[] args) {
        // 1. Declare and initialize an array
        System.out.println("# 1. Declare and initialize an array");
        int[] scores = { 95, 100, 87, 91 };
        scores[2] = 90; // 3번째 요소(87)을 90으로 변경.

        System.out.println(scores);
        for (int i = 0; i < scores.length; i++) {
            System.out.println(scores[i]);
        }

        // 2. Arrays method: toString(), asList()
        System.out.println("\n# 2. Arrays method: toString(), asList()");
        String[] cars = { "hyundai", "bmw", "benz", "toyota" };
        List<String> car_list = Arrays.asList(cars);
        System.out.println(car_list);
        System.out.println(car_list.get(1));
        // car_list.add("ford"); error

        // 3. Arrays method: sort(array, Comparator), sort(array, int fromindex, int toindex)
        System.out.println("\n# 3. Arrays method: sort(array, Comparator), sort(array, int fromindex, int toindex)");
        Arrays.sort(cars);
        System.out.println(Arrays.asList(cars));

        Arrays.sort(cars, Collections.reverseOrder());
        System.out.println(Arrays.asList(cars));

        Arrays.sort(cars, 0, 2);
        System.out.println(Arrays.asList(cars));

        // 4. Arrays method: copyOf, copyOfRange
        System.out.println("\n# 4. Arrays method: copyOf, copyOfRange");
        String[] cars_copied1 = Arrays.copyOf(cars, cars.length);
        System.out.println(Arrays.asList(cars_copied1));

        String[] cars_copied2 = Arrays.copyOfRange(cars, 0, 2);
        System.out.println(Arrays.asList(cars_copied2));

        // 5. Multiple Array
        System.out.println("\n# 5. Multiple Array");
        int[][][] allScores = {
                { { 90, 85, 70, 55, 60 }, { 96, 88, 81, 91, 75 }, { 96, 88, 81, 91, 75 }, { 96, 88, 81, 91, 75 } },
                { { 91, 82, 73, 54, 65 }, { 96, 87, 88, 99, 80 }, { 91, 82, 83, 94, 75 }, { 96, 87, 88, 99, 70 } },
                { { 92, 83, 74, 55, 66 }, { 97, 88, 89, 90, 71 }, { 92, 83, 84, 95, 76 }, { 97, 88, 89, 90, 71 } } };
        System.out.println(allScores[1][2][0]);
    }
}
```

### 실행결과

```java
# 1. Declare and initialize an array
[I@6a6824be
95
100
90
91

# 2. Arrays method: toString(), asList()
[hyundai, bmw, benz, toyota]
bmw

# 3. Arrays method: sort(array, Comparator), sort(array, int fromindex, int toindex)
[benz, bmw, hyundai, toyota]
[toyota, hyundai, bmw, benz]
[hyundai, toyota, bmw, benz]

# 4. Arrays method: copyOf, copyOfRange
[hyundai, toyota, bmw, benz]
[hyundai, toyota]

# 5. Multiple Array
91
```