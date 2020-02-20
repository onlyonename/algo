#include <iostream>
#include <string>
#include <stdio.h>


//对比普通类和模板类中,静态成员变量的初始化问题

using namespace std;


class FooA
{
public:
	
	struct A
	{
		A(){ cout << "A" << endl;}
	};
	
    static A a;
};

FooA::A FooA::a;	// FooA是个普通类,这个即会调用a的构造函数,创建对象。



template<typename T>
class FooB
{
public:
	
	struct B 
	{
		B(){ cout << "B" << endl;}
	};
	
    static B b;
};

template<typename T>
typename FooB<T>::B FooB<T>::b;	//b对象并不会被构造。其实不难理解，因为没有定义具体的模板参数，实际上并没有存在的类。





//如果要在模板类中,构造静态成员变量，那么得像下面这样操作
template<typename T>
class FooC
{
public:
    struct C 
	{
		C(){ cout << "CCC" << endl;}
        void f() {}		// 1 随便定义一个成员函数
    };

    FooC(){c.f();}		// 2 要在构造函数或析构函数中,执行该函数
    ~FooC(){c.f();}	

public:
    static C c;
};

template<typename T>
typename FooC<T>::C FooC<T>::c;	// 3 在类外初始化该变量


class M : public FooC<M>	// 4 通过继承的方式,实例化该模板
{
    M(){}	// 5 必须定义构造函数
};


// 上面5个条件,缺一不可,真是个复杂的过程

int main()
{
	return 0;
}

