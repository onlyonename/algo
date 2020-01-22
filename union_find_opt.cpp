#include <iostream>
#include <string>


using namespace std;


class UF
{
public:

    UF(int iNum);
    
    int connect(int p, int q);
    
    bool connected(int p, int q);

    inline int count() {return _iCount;}

    int findRoot(int i);

private:    

    int _iCount;    //结点个数

    int* _pParent;  //父结点数组

    int* _pSonNum;  //子结点有多少个
};


UF::UF(int iNum)
{
    _pParent = new int[iNum];
    _pSonNum = new int[iNum];
    
    for(int i = 0; i < iNum; ++i)
    {   
        _pParent[i] = i;        //父结点设成自己
        _pSonNum = 1;
    }
    
    _iCount = iNum;
}


int UF::findRoot(int i)
{
    while(_pParent[i] != i) i = _pParent[i];

    return i;
}






int UF::connect(int p, int q)
{
    int iRootP = findRoot(p);
    int iRootQ = findRoot(q);

    if(iRootP == iRootQ) return 0;

    if(_pSonNum[p] > _pSonNum[q])
    {
        
    }
    else
    {

    }


    
    --_iCount;

    return 0;
}


bool UF::connected(int p, int q)
{
    int iRootP = findRoot(p);
    int iRootQ = findRoot(q);

    return iRootP == iRootQ;
}



int main()
{
    UF uf(10);

    cout << uf.count() << endl;

    cout << uf.connected(0, 1) << endl;
    
    cout << uf.connect(0, 1) << endl;
    
    cout << uf.connected(0, 1) << endl;

    cout << uf.count() << endl;

    cout << uf.findRoot(0) << endl;
    
    cout << uf.findRoot(1) << endl;
    
	return 0;
}



