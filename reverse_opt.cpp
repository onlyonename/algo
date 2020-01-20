#include <iostream>
#include <string>

using namespace std;

//交换字符串.指定k,如k=3,则如abcdefg变成efgabcd,即将最后k个前移


//对调数组元素
int exchange(char* begin, char* end)
{
	while(begin < end)
	{
		int tmp = *begin;
		*begin = *end;
		*end = tmp;
		
		++begin;
		--end;
	}

	return 0;
}



int main()
{
	char src[] = "abcdefg";
	cout << "original:" << src << endl;
	
	int k = 3;
	
	//交换前半部分
	char* p = src;
	char* q = p + (sizeof(src) - 1) - k - 1;
	exchange(p, q);
	
	p = src + (sizeof(src) - 1) - k;
	q = p + k - 1;
	exchange(p, q);
	
	
	p = src;
	q = src + sizeof(src) - 1 - 1;
	exchange(p, q);
	
	cout << "final:" << src << endl;
	
	return 0;
}

