#include <iostream>
#include <string>
#include <map>

using namespace std;



int min(int i, int j, int k)
{
	int iMin = i;

	if(iMin > j) iMin = j;

	if(iMin > k) iMin = k;

	return iMin;
}



int inCache(int i, int j, map<int, map<int, int> >& mCache)
{
	map<int, map<int, int> >::const_iterator iter = mCache.find(i);

	if(iter == mCache.end()) return -1;

	const map<int, int>& mTmp = iter->second;
	map<int, int>::const_iterator iter1 = mTmp.find(j);

	if(iter1 == mTmp.end()) return -2;

	return iter1->second;
}



int minDistance(const string& s1, const string& s2, int i, int j, map<int, map<int, int> >& mCache)
{
	if(j == -1) return i + 1;	//依次删除

	if(i == -1) return j + 1;	//依次插入

	int iRet = inCache(i, j, mCache);
	if(iRet > 0)
	{
		return iRet;
	}

	if(s1.at(i) == s2.at(j))
	{
		iRet = minDistance(s1, s2, i - 1, j - 1, mCache);	//skip
		mCache[i][j] = iRet;
		return iRet;
	}

	int iVar1, iVar2, iVar3;

	//插入
	iVar1 = minDistance(s1, s2, i, j - 1, mCache) + 1;
	
	//替换
	iVar2 = minDistance(s1, s2, i - 1, j - 1, mCache) + 1;

	//删除
	iVar3 = minDistance(s1, s2, i - 1, j, mCache) + 1;

	iRet = min(iVar1, iVar2, iVar3);
	mCache[i][j] = iRet;

	return iRet;
}




int main()
{
	string s1 = "horse";
	string s2 = "ros";

	map<int, map<int, int> > mCache;	// i, j, value

	int iRet = minDistance(s1, s2, s1.size() - 1, s2.size() - 1, mCache);

	cout << "s1:" << s1 << ",s2:" << s2 << ",result:" << iRet << endl;

	mCache.clear();	//这里记得清空
	s1 = "intention";
	s2 = "execution";

	iRet = minDistance(s1, s2, s1.size() - 1, s2.size() - 1, mCache);

	cout << "s1:" << s1 << ",s2:" << s2 << ",result:" << iRet << endl;

	return 0;
}

