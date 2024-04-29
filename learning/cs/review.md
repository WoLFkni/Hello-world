![[recitation.txt]]
## 1
> compile
## 2
```
类型：决定变量代表的大小
char ： 1个byte
int ：4个byte
```
```
65:
char: 'A'
int: 65
```
```
''表示字符
""表示字符串
```
```
cout : 类型为ostream
	cout << expr
	连接显示器
	output file stream 连接一个文件，输出到文件里
cin ：类型为istream
	cin >> x
	file stream(fstream?) 从文件里读取
	istringstream iss(s)把字符串转成一个输入流
```
```
隐式转换：更不精确转换为更精确
精确
long double
double 
float
unsigned long
long
unsigned int 
int
unsigned short
short 
char
bool
不精确
```
```
expression表达式：有类型，可求值
	cout 是一个表达式，不是一个statement
statement：No type and value
	contain expression
不能连续比大小
	-2 < -1 < 0:
		true < 0类型不对应 -> true转换为int类型 -> 1<0 -> false
	正确：-2 < -1 && -1 < 0
<expr1> && <expr2> 如果expr1为false，则不判断expr2
<expr1> || <expr2> 如果expr1为true，则不判断expr2
```
```
avoid short-circuit evaluation combing side effect
	e.g. a = b < c
	有时也使用：见链表Optimized Insertion：(current = *pcurrent) ! = nullpull
```
```C++
do {

}while(condition)
```
```
break:跳出最近的循环
continue:跳过下一次循环
	for循环里不会跳过a++
```
```
function：
不是void类型：一定要有返回值
主函数：int类型，返回0
```
```
局部变量
	在函数调用时分配frame包含局部变量
	call-by-value：copy值，执行完了之后把值返回，只在frame里进行作用，对main函数里的变量没有影响
	返回的时候，栈会被销毁
全局变量
loop variable
	作用域只在循环里
变量作用域
	从里往外推：最先出现的变量定义在哪
	同名变量在一个block statement里只能出现一个
```
```
Reference 
	不产生新的变量，只是再给一个名字
		void incr(int& v);
		incr(a);
		相当于给了a另一个名字v
```
```
L-value 
	可以取地址：变量的内存区域开始的地址
	CHAR_BIT 一个byte有多少bit，一般情况下是8
R-value
	只存在于逻辑层面，只是用来计算的
	编译器可能把它放在内存里，但是在C++层面只是逻辑上存在
L-value expressions
	能求出一个左值
		variable所有的变量都会根据类型分配一块地址
		assignment
		reference
R-value expressions
	算出来的值是一个逻辑运算结果
		算数表达式
		逻辑表达式
		函数调用
R-value position放左值：隐式转换
	read: data used as R-value
	decay: a pointer to its first element
```
![[Pasted image 20240429112338.png]]
![[Pasted image 20240429112100.png]]
```
指针
	右值(地址)
指针变量
	普通变量
	类型：T*
	值：指针的值
解引用
	对象：右值，把指针转换回它指向的地址
		int *p;
		p = &a;
	*p是一个L-value，是把p转换成右值，然后解引用 -> a
		cout << *p << endl;
	打印的是a的data，因为cout需要一个右值，所以把a转换成右值。
```
** \*p =\*p+1 **
```
l
	type : T**
	指向一个T*类型的左值的指针(假设叫l1)
l1
	type : T*
	指向一个T类型的左值的指针
```
```
reference 给另一个名字
```