decltype
====

* decltype은 식의 타입을 알려주는 역할을 한다
```C++
cosnt int a; // decltype(a) -> const int

bool func(); // decltype(func()) -> bool
```
* 주로 사용되는 곳은 템플릿 함수에서의 반환형 결정
```C++
template <typename A, typename B>
auto func(A a, B b) -> decltype(a+b){
  return a+b;
}
```
