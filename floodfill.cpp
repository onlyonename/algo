#include <iostream>
#include <string>

using namespace std;


//是否在二维数组里
bool in_area(int hor, int col, int x, int y)
{
	if((x >= 0 && x <= hor) && (y >= 0 && y <= col))
	{	
		return true;
	}

	return false;
}


int fill(int (&src)[3][3], int x, int y, int ori_color, int dst_color)
{
	if(!in_area(3, 3, x, y)) return -1;
	
	if(src[x][y] != ori_color) return -2;
	
	if(src[x][y] == -1) return -3;
	
	src[x][y] = -1;	//先标记,记下状态,表示这个结点已处理,防止死循环

	fill(src, x, y - 1, ori_color, dst_color);
	fill(src, x - 1, y, ori_color, dst_color);
	fill(src, x, y + 1, ori_color, dst_color);
	fill(src, x + 1, y, ori_color, dst_color);
	
	src[x][y] = dst_color;
	
	return 0;
}


void print(int (&src)[3][3])
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
			cout << src[i][j] << " "; 
		cout << endl;
	}
}

int main()
{
	int src[3][3] = {{1,1,1},{1,1,0},{1,0,1}};
	cout << "before:" << endl;
	print(src);


	int x = 1;
	int y = 1;
	int color = 2;
	fill(src, 1, 1, 1, 2);
	
	cout << "after:" << endl;
	print(src);
	
	return 0;
}

