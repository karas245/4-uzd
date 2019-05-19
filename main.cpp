#include "classVector.h"


int main()
{


    Vector<int> n(10,9);

    n.pushBack(98);cout << "\n";
    int sk=n.getSz();

    for(int i=sk;i<sk+10;i++)
        n.pushBack(i);
    cout << n.getSz() << " ////////" << endl;
    for(int i=0;i<n.getSz();i++)
    {
        n[i]=n[i]-1;
        cout << n[i] << " " ;
    }

    cout << endl;
    cout << n.Back() << endl;
    for(int i=0;i<n.getSz();i++)
    {

        cout << n[i] << " " ;
    }cout << endl;
    cout << n.getSz() << " ******" << endl;
    for(int i=0;i<n.getSz();i++)
    {

        cout << n[i] << " " ;
    }cout << endl;
    cout << n[50] << endl; cout << " ***";
    cout << n[2] << " veikia" << endl;
    for(int i=0;i<n.getSz();i++)
    {

        cout << n[i] << " " ;
    }cout << endl;
    n.popBack();
    for(int i=0;i<n.getSz();i++)
    {

        cout << n[i] << " " ;
    }cout << endl;
    for(int i=0;i<n.getSz();i++)
    {

        cout << n[i] << " " ;
    }cout << endl;



    return 0;
}
