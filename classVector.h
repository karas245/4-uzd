#ifndef CLASSVECTOR_H_INCLUDED
#define CLASSVECTOR_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <locale>
#include <math.h>

using std::cout;
using std::endl;
using std::string;

template <class T>
class Vector{
private:
    T *elem;
    unsigned int sz;
    unsigned int cap;

public:
    Vector() { sz=0;cap=0; elem=0;}
    Vector(unsigned int siz,unsigned int capa)
    {
        sz = siz;
        cap=capa;
        elem =  new T[sz];
        for(int i=0; i<sz; i++)
        {
            elem[i] = i+1;
            cout << elem[i] << " ";
        }
        cout << "\n";
    }
    //Vector(unsigned int sz, const T & initial);
    Vector(const Vector<T> & v);
    ~Vector() { delete[] elem;}
    int getSz() const{return sz;}

    void pushBack(T el)
    {
        if(sz<cap)
        {
            elem[sz] = el;
            sz++;
        }
        else {
            cap=cap+1;
            elem[sz] = el;
            sz++;
        }

    }
    T & operator[](unsigned int index)
    {

        return elem[index];

    }
    friend std::ostream& operator<<(std::ostream& os, const Vector& v)
    {
        os << v.elem;
        return os;
    }
    T& Front() {return elem[0];}
    T& Back() {return elem[sz-1];}
    void popBack()
    {
        elem[sz-1].delete();
        sz=sz-1;

    }



};
/*
 template <class T>
 Vector <T>::Vector()
{
 my_size = 0;
 my_capacity= 0;
 buffer = 0;
}*/


#endif // CLASSVECTOR_H_INCLUDED
