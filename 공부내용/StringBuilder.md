### Java StringBuilder & StringBuffer

* 문자열 조작에 적합하게 만들어진 클래스이다.

* 객체 내부에 있는 버퍼에 문자열을 담아두고 거기서 조작을 하기 때문에 String처럼 많은 객체를 생성하지 않고도 문자열 조작을 할 수 있다.

* 두 클래스는 생성자와 함수의 형태, 기능이 거의 동일하여 둘 중 어느것을 사용해도 무방하다고 볼 수 있다.

  #### 차이점

  멀티스레드가 동시에 하나의 객체를 사용할 때 데이터에 손상이 가거나 교착 상태에 빠질 위험을 방지하는 장치가 있느냐 없느냐의 차이점이 있다. StringBuffer에는 그런 위험을 방지하는 장치가 있고, StringBuilder에는 그런 장치가 없다. 

  * 대신 멀티스레드시가 아니라면 불필요한 장치가 없는 StringBuilder가 성능이 더 좋다.

  #### 사용법

  이 두 클래스를 사용하여 문자열을 조작하려면 객체를 생성해야 한다.

  ex) StringBuilder sb = new StringBuiler();

### StringBuilder & String

* 두 클래스도 유사한 점이 많다.

  #### 차이점

  String 클래스는 불변인 데 반해 StringBuilder 클래스는 가변적이라는 차이점이 있다. 즉, String 클래스의 문자열은 한 번 생성되면 메모리 내부에서 변경이 불가능하다. 

  String 과 StringBuilder 객체의 문자열 결합 연산을 여러번 반복 실행하는 경우 전체 시실행 시간에 대한 비교 연산을 보면, 문자열 결합 연산이나, String 클래스의 concat() 메소드 실행시보다 StringBuilder 클래스의 append() 메소드를 이용한 문자열 결합 연산이 훨씬 적은 시간이 소요되는 것을 볼 수 있다. 

  **결론적으로, 문자열 결합 연산이 여러 번 반복되는 경우 StringBuilder 클래스를 이용한 문자열 결합 연산이 훨씬 더 효율적이다.**

### StringBuilder

1. StringBuilder 클래스는 내부적으로 문자가 저장되는 가변 길이의 배열과 같이 작동된다.

2. StringBuilder 클래스는 문자열 결합 등의 액션을 수행할 때 새로운 문자열을 만들어내지 않고, 기존의 문자열에 추가될 뿐이다.

* StringBuilder 클래스가 제공하는 메소드 목록

  **length()**

  **capacity()**

  **append()**

  **insert()**

  **delete()**

  **replace()**

  **reverse()**

  **toString()**