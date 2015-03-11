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


decltype의 예외
----
* 표현식의 결과가 __lvalue__일 경우 __lvalue_reference__로 추론한다.
  * 변수 이름만 하나 들어올 경우 __lvalue__로 추론됨.
```C++
int a;

decltype(a) // int
decltype((a)) // int&
decltype(a=1) // int&
```
* 문제될 수 있는 상황
```C++
decltype(auto) inc2(int x){
  return ++x;
}
```
위의 경우 x는 지역변수인데 지역변수의 레퍼런스를 리턴한다.
