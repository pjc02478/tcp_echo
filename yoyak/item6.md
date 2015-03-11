auto가 제대로 동작하지 않을 경우 명시적 타입 초기화를 사용하자
====

auto를 사용해서 원하는 결과값을 얻을 수 없는 경우
----
```C++
std::vector<bool> a;

auto t = v[0];
v[0] = v[1];
v[1] = t;
```
위의 경우에서 t의 타입은 __bool__이 아닌 std::vector<bool>::reference로 결정된다.<br>
이는 std::vector<bool>이 템플릿 특수화를 통해 일반 벡터와 다르게 동작하기 때문이다.

명시적 타입 초기화 관용구
----
* __static_cast__를 사용해 auto의 타입을 명시적으로 지정해준다.
```C++
auto v = static_cast<TYPE>(value);
```
* 위의 예제에서 명시적 타입 초기화를 사용하면 정상적으로 동작한다.
```C++
auto t = static_cast<bool>(v[0]);
/* ... */
```
