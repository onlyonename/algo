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
        _pSonNum[i] = 1;        //初始每个孩子结点个数为1
    }
    
    _iCount = iNum;
}


// 在查找的同时,修正树的高度.每次查找都会修正,修到最后,树的高度不会超过2
int UF::findRoot(int i)
{
    while(_pParent[i] != i) // 根结点的parent为自己
    {
        _pParent[i] = _pParent[_pParent[i]];
        
        i = _pParent[i];
    }   

    return i;
}


int UF::connect(int p, int q)
{
    int iRootP = findRoot(p);
    int iRootQ = findRoot(q);

    if(iRootP == iRootQ) return 0;

    if(_pSonNum[p] > _pSonNum[q])   //把小的挂在大的下面
    {
        _pParent[q] = p;
        _pSonNum[p] += _pSonNum[q];
    }
    else
    {
        _pParent[p] = q;
        _pSonNum[q] += _pSonNum[p];
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



