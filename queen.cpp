#include <iostream>
#include <string>

using namespace std;


//八皇后问题,用回溯法


void print(char (*p)[4],    int iNum)
{
	for(int i = 0; i < iNum; ++i)
	{
		for(int j = 0; j < iNum; ++j)
		{
			cout << p[i][j] << " ";
		}

		cout << endl;
	}

	return;
}


bool isValid(char (*p)[4],    int iNum, int x, int y)
{
	int i,j;
	for(i = x - 1; i >= 0; --i)	//检查同一列
	{
		if(p[i][y] == 'Q') return false;	
	}

	for(i = x - 1, j = y - 1; i >= 0 && j >= 0; --i,--j)		//检查左斜边
	{
		if(p[i][j] == 'Q') return false;
	}
	
	
	for(i = x - 1, j = y + 1; i >= 0 && j < iNum; --i,++j)		//检查右斜边
	{
		if(p[i][j] == 'Q') return false;
	}

	return true;
}




int queen(char (*p)[4], int iNum, int iStartRow, int& iFindNum)
{
	if(iStartRow <= iNum && iFindNum == iNum)
	{
		print(p, iNum);
		return 0;
	}

	for(int col = 0; col < iNum; ++col)
	{
		if(!isValid(p, iNum, iStartRow, col))
		{
			continue;
		}

		p[iStartRow][col] = 'Q';
		++iFindNum;
		cout << iStartRow << col << " ok, iFindNum:" << iFindNum << endl;

		queen(p, iNum, iStartRow + 1, iFindNum);

		p[iStartRow][col] = 'S';
		--iFindNum;
	}


 	return 0;
}



int main()
{
	const int iNum = 4;	//4皇后

	char p[iNum][iNum];		

	for(int i = 0; i < iNum; ++i)
	{
		for(int j = 0; j < iNum; ++j)
		{
			p[i][j] = 'S';
		}
	}

	print(p, iNum);

	int iFindNum = 0;
	queen(p, iNum, 0, iFindNum);

	return 0;
}

