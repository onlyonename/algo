#include <iostream>
#include <string>

using namespace std;



int min(int i, int j, int k)
{
	int iMin = i;

	if(iMin > j) iMin = j;

	if(iMin > k) iMin = k;

	return iMin;
}


int minDistance(const string& s1, const string& s2, int i, int j)
{
	if(j == -1) return i + 1;	//依次删除

	if(i == -1) return j + 1;	//依次插入

	if(s1.at(i) == s2.at(j))
	{
		return minDistance(s1, s2, i - 1, j - 1);	//skip
	}

	int iRet = min(minDistance(s1, s2, i, j - 1) + 1,	//插入
		minDistance(s1, s2, i - 1, j - 1) + 1,			//替换
		minDistance(s1, s2, i - 1, j) + 1);				//删除

	return iRet;
}




int main()
{
	string s1 = "horse";
	string s2 = "ros";

	int iRet = minDistance(s1, s2, s1.size() - 1, s2.size() - 1);

	cout << "s1:" << s1 << ",s2:" << s2 << ",result:" << iRet << endl;

	s1 = "intention";
	s2 = "execution";

	iRet = minDistance(s1, s2, s1.size() - 1, s2.size() - 1);

	cout << "s1:" << s1 << ",s2:" << s2 << ",result:" << iRet << endl;

	return 0;
}

