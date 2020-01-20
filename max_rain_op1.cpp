#include <iostream>
#include <string>

using namespace std;


int leftMax(int* pLeftMax, int iSize, int iPos)
{
	if(iPos < 0 || iPos >= iSize) return -1;

	int* p = pLeftMax + iPos;
	return *p;
}


int rightMax(int* pRightMax, int iSize, int iPos)
{
	if(iPos < 0 || iPos >= iSize) return -1;

	int* p = pRightMax + iPos;
	return *p;
}


int calcMax(int height[], int iSize, int* pLeftMax, int* pRightMax)
{
	int iLeftMax = -1;
	int iRightMax = -1;

	int i = 0 , j = iSize - 1;
	for(; i < iSize && j >= 0; ++i, --j)
	{
		// 左边
		pLeftMax[i] = iLeftMax;
		
		if(height[i] > iLeftMax)
		{
			iLeftMax = height[i];
		}
		
		// 右边
		pRightMax[j] = iRightMax;
		
		if(height[j] > iRightMax)
		{
			iRightMax = height[j];
		}
	}

	return 0;
}



int min(int i, int j)
{
	if(i >= j) return j;

	return i;
}


int maxRain(int height[], int iSize, int* pLeftMax, int* pRightMax)
{
	int iTotal = 0;

	for(int i = 0; i < iSize - 1; ++i)
	{	
		int iLeft = leftMax(pLeftMax, iSize, i);
		int iRight = rightMax(pRightMax, iSize, i);

		cout << "i:" << i << ",iLeft:" << iLeft << ", iRight:" << iRight << endl;

		if(iLeft > height[i] && iRight > height[i])
		{
			iTotal += min(iLeft, iRight) -  height[i];	//第i个位置的水量
		}
	}

	return iTotal;
};




int main()
{
	int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};

	int iArraySize = sizeof(height) / sizeof(int);

	cout << "iArraySize:" << iArraySize << endl;

	int* pLeftMax = new int[iArraySize];		//第i个元素的值,表示src[i]左边最大的数
	int* pRightMax = new int[iArraySize];

	calcMax(height, iArraySize, pLeftMax, pRightMax);
	
	int iRet = maxRain(height, iArraySize, pLeftMax, pRightMax);

	cout << "result:" << iRet << endl;

	return 0;
}

