#include <iostream>
#include <string>

using namespace std;

//交换字符串.指定k,如k=3,则如abcdefg变成efgabcd,即将最后k个前移

int exchange(char* src, int size, int k)
{
	int step_num = 0;	//跳到新位置的结点数
	for(int i = 0; step_num < size; ++i)
	{
		int start = i;
		int cur = start;
		int pre_value = src[cur];
		
		do{
			int pos = (cur + k) % size;
			int tmp = src[pos];
			src[pos] = pre_value;
			cur = pos;
			++step_num;
			pre_value = tmp;
		}while(cur != start);
	}

	return 0;
}



int main()
{
	char src[] = "abcdefg";
	cout << "original:" << src << endl;
	
	exchange(src, sizeof(src) - 1, 3);
	
	cout << "final:" << src << endl;
	
	return 0;
}

