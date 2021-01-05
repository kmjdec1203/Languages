## 패키지 (Package)

패키지는 비슷한 성격의 자바 클래스들을 모아 넣는 자바의 디렉토리이다.  (폴더와 동일한 개념이다)

> 사용법
>
> * 패키지를 만들 때는 package라는 키워드를 사용한다.
> * 다른 클래스에서, 예를 들어 HouseKim 클래스를 사용하려면 import jump2java.house.HouseKim; 처럼 import를 해야한다.
> * 또는 import jump2java.house.*; 와 같이 *기호를 이용할 수도 있다.
>   (만약 HouseKim과 동일한 패키지 내에 있는 클래스라면 HouseKim 클래스를 사용하기 위해서 import를 따로 할 필요는 없다. => 같은 패키지 내에서는 import없이 사용이 가능하다.)

> 좋은점
>
> * 클래스의 분류가 용이하다. (비슷한 것 끼리 묶으므로)
> * 패키지가 다르다면 동일한 클래스명을 사용할 수 있다.

#### 예시

-HousePark, HouseKim 등의 클래스들이 있다면 이것을 house라는 패키지로 분류하면 편리할 것이다.

*HouseKim.java*

```
package jump2java.house;

public class HouseKim {
}
```

*HousePark.java*

```
package jump2java.house;

public class HousePark {
}
```

위 두개의 클래스를 작성하고 저장하면 이 파일이 저장되는 디렉토리에 다음과 같은 구조의 파일들이 생성되는 것을 확인할 수 있다.

```
src/jump2java/house/HouseKim.java
src/jump2java/house/HousePark.java
bin/jump2java/house/HouseKim.class
bin/jump2java/house/HousePark.class
```

house라는 폴더가 자동으로 생성되고 house폴더 밑에 HouseKim과 HousePark 파일이 생성된것을 확인할 수 있다.