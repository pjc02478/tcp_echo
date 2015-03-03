UNDERSTAND AUTO TYPE DEDUCTION
====

* auto 타입 추론은 한가지 예외를 제외하면 템플릿 타입 추론과 같다.
* auto를 통해 생성된 변수는 auto가 템플릿의 T역할을 한다. 그리고 나머지 형식 지정자들은 ParamType의 역할을 한다.
```C++
// 형식 지정자
auto x = 27; // auto
const auto cx = x; // const auto
const auto &rx = x; // const auto &
```

예외
----
* auto에서 중괄호를 사용하면 initializer_list로 변환된다.
```C++
int x1 = {27}; // int, 27
int x2{27}; // int, 27

auto x3 = {27}; // initializer_list<int>, {27}
auto x4{27}; // initializer_list<int>, {27}
```
* 반대로 initializer_list로의 추론은 auto에서만 동작하고 template에서는 변환되지 않는다.
```C++
template <typename T>
void f(T param);

f({1,2,3}); //error
```

예외2
----
* C++14에서 반환형식에서의 auto나, 파라미터의 auto의 경우 auto추론이 아닌 템플릿 타입 추론이 일어난다.
```C++
auto f(){
  return {1,2,3}; //error
}
```
```C++
auto lambda = [](const auto &p){};

lambda({1,2,3}); //error
```
