#include <iostream>
#include <string>


using namespace std;


//规则: .代表匹配任意字符, *代表重复任意次前面的字符,包括0次

bool isMatch(const string& sText, int i, const string& sPattern, int j)
{
    if(i >= sText.size())
    {   
        if(j >= sPattern.size()) return true;

        if(j + 1 < sPattern.size() && sPattern.at(j + 1) == '*')
        {
            if(j + 1 == sPattern.size()) return true;

            return isMatch(sText, i, sPattern, j + 2);
        }

        return false;
    }

    if(j >= sPattern.size())
    {
        if(i >= sText.size())   return true;

        return false;
    }
    
    if(sPattern.at(j) == sText.at(i) || sPattern.at(j) == '.')  //当前位置匹配
    {
        if(sPattern.at(j + 1) == '*')
        {
            return isMatch(sText, i + 1, sPattern, j);
        }
        else
        {
            return isMatch(sText, i + 1, sPattern, j + 1);
        }
    }
    else    //当前位置不匹配
    {
        if(sPattern.at(j + 1) == '*')
        {
            return isMatch(sText, i, sPattern, j + 2);
        }
    }
    
    return false;
}




int main()
{
    const string sText = "abcdefg";

    const string sPattern1 = "ab.*";
    const string sPattern2 = "b.*";



	

	return 0;
}

