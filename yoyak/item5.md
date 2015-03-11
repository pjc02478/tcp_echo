auto를 사용하자
====

* __auto__는 초기화 하지 않고 사용할 수 없다.
```C++
int a; // 에러 없음
auto b; // 에러
```
* 엄청나게 긴 타입 이름의 경우 가독성이 떨어진다.
```C++
std::function<int(int,int)> func = 
  [](int a,int b){ return 1; };

// 위의 문장은 아래의 문장으로 간결하게 만들 수 있다.

auto func = 
  [](int a,int b){ return 1; };
```

* 클로져를 사용할 경우 __auto__를 사용하는것이 이득이다.
  * std::function을 사용할 경우
    * std::function은 모든 종류의 함수 객체를 담을 수 있는 범용성을 가지고 있기 때문에 구제적인 클로져 타입보다 더 많은 메모리를 소비한다.
  * auto를 사용할 경우
    * 구제화 된 클로져 형식을 사용하기 때문에 저장 공간과 호출 시간에 있어서 이득을 볼 수 있다.

* auto를 사용할 경우 포팅에 유리하다.
빌드 환경이 달라질 경우 명시적 타입 사용은 불편할 수 있다.
```C++
vertor<int> a;

unsigned int len = a.size();
// vector.size()의 반환값의 타입은 32비트와 64비트일 때에 차이가 난다.
// 따라서 auto를 사용하면 환경에 따라 능동적인 처리를 할 수 있다.
```

* 명시적인 선언과 실 사용이 다른 경우 auto를 사용하자
```C++
std::unordered_map<std::string, int> m;

for (std::pair<std::string, int>& p : m){}
```
unordered_map의 key는 항상 const로 변환된다.<br>
따라서 위의 for문에서는 실제로 unordered_map 내부에서 사용되는 pair와 형식이 다르기 때문에 복사를 통해 임시 객체가 생성된다.<br>
이 때 __auto__를 사용하면 이런 문제도 해결할 수 있고, 코드의 간결성도 확보할 수 있다.

