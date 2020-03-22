//kmp字符串匹配算法
#include <iostream>
#include <stdlib.h>


using namespace std;


void createNext(char* pattern, int size, int* next)
{
    cout << "size:" << size << endl;   
 
    next[0] = -1;
    next[1] = 0;

    int j = 0;
    int k = -1;

    while(j < size)
    {
        if(k == -1 || pattern[j] == pattern[k])
        {
            next[++j] = ++k;
        }
        else
        {
            k = next[k];
        }   
    }

    cout << "next info:" << endl;

    for(int i = 0; i < size; ++i)
        cout << next[i] << endl;
      
    return;
}


int search(char* src, int src_len, char* pattern, int pattern_len)
{
    //找到了返回下标,没找到返回-1

    int* next = (int*)malloc(sizeof(int) * pattern_len);
    createNext(pattern, pattern_len, next);


    int i = 0;
    int j = 0;

    while(i < src_len && j < pattern_len)
    {
        if(j == -1 || src[i] == pattern[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }
    }

    if(j == pattern_len)
    {
        return i - j;
    }

    return -1;
}





int main()
{
    char src[] = "abcabdabeabcdabad";
    char pattern[] = "abcdab";

    cout << search(src, sizeof(src) - 1, pattern, sizeof(pattern) - 1) << endl;

    return 0;
}


