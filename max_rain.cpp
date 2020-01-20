#include <iostream>
#include <string>

using namespace std;


int leftMax(int height[], int iSize, int iPos)
{
	if(iPos < 0 || iPos >= iSize) return -1;

	int iTmp = 0;
	for(int i = 0; i < iPos; ++i)
	{
		if(height[i] > iTmp) iTmp = height[i];
	}

	return iTmp;
}


int rightMax(int height[], int iSize, int iPos)
{
	if(iPos < 0 || iPos >= iSize) return -1;

	int iTmp = 0;
	for(int i = iPos + 1; i < iSize; ++i)
	{
		if(height[i] > iTmp) iTmp = height[i];
	}

	return iTmp;
}


int min(int i, int j)
{
	if(i >= j) return j;

	return i;
}


int maxRain(int height[], int iSize)
{
	int iTotal = 0;

	for(int i = 0; i < iSize - 1; ++i)
	{	
		int iLeft = leftMax(height, iSize, i);
		int iRight = rightMax(height, iSize, i);

		if(iLeft >=  height[i] && iRight >= height[i])
		{
			iTotal += min(iLeft, iRight) -  height[i];	//第i个位置的水量
		}
	}

	return iTotal;
};




int main()
{
	int src[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	
	int iRet = maxRain(src, 12);

	cout << "result:" << iRet << endl;

	return 0;
}

