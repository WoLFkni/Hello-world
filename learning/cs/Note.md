一般来说class 的 private不应该有成员变量，虽然允许
```C++
int get() const{

}
```
> 相当于引用了`const *counter this`
> 指向常数左值的指针（指针不是const，指针的右值是一个常数左值）
```C++
class Counter{
public:
	Counter (int n,string s): cnt(n){
		cout << s << endl;
	}
private:
	int cnt;
}
```
> assert
![[Pasted image 20240508093740.png]]![[Pasted image 20240508093813.png]]