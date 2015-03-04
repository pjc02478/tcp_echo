UNDERSTAND TEMPLATE TYPE DEDUCTION
====

* 함수 템플릿을 사용할 때 __T__와 __ParamType__은 다르다.
```C++
template <typename T>
void f(const T &param);

int x = 123;
f(x); // T -> int, ParamType -> const int &
```

* __T__는 __expr__과 __ParamType__을 기반으로 추론된다.

1. ParamType이 참조이거나 포인터이고 전역(universal) 참조는 아닌 경우.
  * __expr__이 참조라면 참조 부분을 무시한다.
  * __ParamType__과 다른 __expr__의 타입을 패턴 매칭해 T를 결정한다.
```C++
template <typename T>
void func(T &param);

int x = 27;
const int cx = x;
const int &rx = x;

func(x); // T -> int, ParamType -> int &
func(cx); // T -> const int, ParamType -> const int &
func(rx); // T -> const int, ParamType -> const int &
```

2. ParamType이 전역(universal) 참조인 경우.
  * __expr__이 lvalue라면 __T__와 __ParamType__은 lvalue로 추론된다.
  * __expr__이 rvalue라면 case1의 규칙이 적용된다.
```C++
template <typename T>
void func(T &&param);

int x = 27;
const int cx = x;
const int &rx = x;

func(x); // T -> int &, ParamType -> int &
func(cx); // T -> const int &, ParamType -> const int &
func(rx); // T -> const int &, ParamType -> const int &
func(27); // T -> int, ParamType -> int &&
```

3. 둘 다 아닐 때
  * __expr__이 참조형이라면 참조를 무시한다.
  * __expr__이 const이거나 volatile이라면 무시한다.
```C++
template <typename T>
void func(T param);

int x = 27;
const int cx = x;
const int &rx = x;

func(x); // T -> int, ParamType -> int
func(cx); // T -> int, ParamType -> int
func(rx); // T -> int, ParamType -> int
```

배열
----
* 배열과 포인터 타입은 같지 않다. 배열이 포인터 타입으로 변환되어서 들어가는 것일 뿐
* 참조형을 사용할 경우 배열의 참조형을 넘겨받을 수 있다.
```C++
template <typename T, std::size_t N>
sizte_t arraySize(T (&)[N])
```
함수
----
* 함수 타입도 포인터로 변환(편입)시킬 수 있다.
```C++
void func(int);

template <typename T>
void f1(T param);
template <typename T>
void f2(T &param);

f1(func); //void(*)(int)
f2(func); //void(&)(int)
```
