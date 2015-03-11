추론된 타입 알기
====

IDE
----
* IDE 프로그램에서 알아낼 수 있다.

컴파일러 진단
----
* 일부러 에러를 내서 에러 메세지를 보고 타입을 알아내는 방식
```C++
template <typename T>
class TD;

TD<decltype(x)> a;
// 위의 라인에서 에러가 발생하고
// error: aggregate 'TD<int> a' has incomplete type and cannot be defined
// 에러 메세지를 통해서 x의 타입이 int인것을 알 수 있다.
```

런타임에 알아보기
----
* 실행 시간에 타입 알아내기
* typeid 연산자 사용
```C++
typeid(int).name() // 'int'
```
* const, reference, volatile 속성이 사라진 타입을 알려준다.
```C++
int &x = y;
const int z = 12;

typeid(x).name() // 'int'
typeid(z).name() // 'int'
```
* Boost.TypeIndex를 사용하면 해결할 수 있다.
```C++
const int &x = y;

boost::typeindex::type_id_with_cvr<x>.pretty_name()
/// 'const int &'
```
