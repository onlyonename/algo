#include "DynamicFactory.h"
#include <stdio.h>  



//继承这个类时,会创建好相应的
class Test1 : public DynamicCreate<Test1>  
{  
public:  
    // 注意：使用gcc，一定要显示申明构造函数，否则不会执行注册代码  
    Test1() {}  
};  




int main()
{
	Test1* p1 = DynamicFactory::Instance().Create<Test1>("Test1");
	printf("Create Test1 %s\n", (p1 ? "success" : "failure"));
	
	

	return 0;
}
