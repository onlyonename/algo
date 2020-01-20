#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int permutation(const vector<int>& v, vector<int>& item, vector<vector<int> >& result)
{
	if(item.size() == v.size())
	{
		cout << "finish one item" << endl;		
		result.push_back(item);
		return 0;
	}
	
	for(int i = 0; i < v.size(); ++i)
	{
		vector<int>::iterator iter = find(item.begin(), item.end(), v[i]);

		if(iter != item.end())
		{
			continue;	
		}		
	
		cout << "insert:" << v[i] << " ";
		item.push_back(v[i]);
		
		permutation(v, item, result);
		
		item.pop_back();
	}
	
	return 0;
}



int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	//v.push_back(4);
	
	vector<int> item;
	vector<vector<int> > result;
	permutation(v, item, result);


	for(int i = 0; i < result.size(); ++i)
	{
		for(vector<int>::const_iterator iter = result[i].begin(); iter != result[i].end(); ++iter)
		{
			cout << *iter << " ";
		}
		
		cout << endl;
	}


	return 0;
}

