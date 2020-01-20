//求两个字符串的最长公共子序列,s1=abcdf s2=ackf,则resut=acf

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>


using namespace std;


int key(int i, int j)
{
	return (i << 32 | j);
}


int max(int i, int j)
{
	if(i >= j) return i;
	
	return j;
}


int longest(char s1[], int i, char s2[], int j, map<int, int>& mCache)
{
	if(i <= -1 || j <= -1) return 0;

	int k = key(i, j);
	map<int, int>::iterator iter  = mCache.find(k);
	if(iter != mCache.end()) return iter->second;
	
	if(s1[i] == s2[j])
	{
		int iRet = longest(s1, i - 1, s2, j - 1) + 1;
		
	}


	return max(longest(s1, i - 1, s2, j), longest(s1, i, s2, j - 1));
}



int main()
{
	char s1[] = "abcdefg";
	char s2[] = "amkcwfug";

	map<int, int> mCache;

	int iRet = longest(s1, strlen(s1) - 1, s2, strlen(s2) - 1);

	cout << "longest len:" << iRet << endl;

	return 0;
}

