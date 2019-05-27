#ifndef CLASSVECTOR_H_INCLUDED
#define CLASSVECTOR_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <locale>
#include <math.h>
#include <chrono>


#include <memory>
#include <new>
using std::cout;
using std::endl;
using std::string;

template <class T>
class Vector
{
private:
    T *elem;
    unsigned int sz;
    unsigned int cap;

public:
    typedef T * iterator;
    typedef const T * const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

    Vector()
    {
        sz=0;
        cap=0;
        elem= new T[sz];
    }
    Vector(unsigned int siz, T val)
    {
        sz = siz;
        cap = sz+1000;
        elem = new T[cap];
        for (int i = 0; i < sz; i++)
            elem[i] = val;
    }
    Vector(unsigned int siz)
    {
        sz = siz;
        cap=sz+1000;
        elem =  new T[cap];
        for(int i=0; i<sz; i++)
        {
            elem[i] = i+1;

        }
    }
    Vector(const Vector& v)
    {
        sz=v.sz;
        cap=v.cap;
        elem= new T[cap];
        for(int i=0; i<sz; i++)
        {
            elem[i]=v.elem[i];
        }

    }

    ~Vector()
    {
        delete[] elem;
    }
    int size() const
    {
        return sz;
    }
    int capacity() const
    {
        return cap;
    }
    bool empty()
    {
        return sz==0;
    }
    void push_back(T el)
    {
        if(sz<cap)
        {
            elem[sz] = el;
            sz++;
        }
        else
        {
            reserve();
            elem[sz] = el;
            sz++;
        }

    }
    T & operator[](unsigned int index)
    {
        if ( index > sz || index < 0)
            throw std::out_of_range("operator[]: out of bounds");
        return elem[index];
    }
    Vector & operator =(const Vector & v)
    {
        cap=v.capacity();
        sz = v.sz;
        for (int i=0; i<v.sz; i++)
            elem[i] = v.elem[i];

    }
    friend std::ostream& operator<<(std::ostream& os, const Vector& v)
    {
        os << v.elem;
        return os;
    }
    T& front()
    {
        if (sz == 0)
            throw std::out_of_range("empty vector");
        else
            return elem[0];
    }
    T& back()
    {
        if (sz == 0)
            throw std::out_of_range("empty vector");
        else
            return elem[sz-1];
    }
    T& at(int index)
    {
        if ( index > sz || index < 0)
            throw std::out_of_range("operator[]: out of bounds");
        return elem[index];
    }

    void assign(int siz,const T& val)
    {
        sz=siz;
        cap=sz+1000;
        delete[] elem;
        elem= new T[siz];
        for (int i=0; i<sz; i++)
        {
            elem[i]=val;
        }

    }
    void pop_back()
    {
        sz=sz-1;
        T* temp=elem;
        elem= new T[sz];
        for(int i=0; i< sz; i++)
        {
            elem[i]=temp[i];
        }

    }
    void reserve()
    {
        T* tem = elem;

        elem = new T[cap+1000];
        std::copy(&tem[0], &tem[sz], &elem[0]);
        delete[] tem;
        cap=cap+100;
    }
    void clear()
    {
        delete[] elem;
        sz = 0;
    }
    void shrink_to_fit()
     {
         if (sz == cap) return;

         T *tem = elem;
         elem=new T[sz];
         for(int i=0;i<sz;i++)
         {
             elem[i]=tem[i];
         }
         cap = sz;
         delete[] tem;

     }
    void resize(int siz)
    {
        if(siz > sz)
        {
            while(cap<siz)
            {
                reserve();
            }
        }

        T* tem = elem;
        elem= new T[siz];
        if(siz>sz)
        {
            for(int i=0; i<sz; i++)
            {
                elem[i]=tem[i];
            }

            for(int i=sz; i<siz; i++)
            {
                elem[i]=0;
            }
        }
        else
        {
            for(int i=0; i<siz; i++)
            {
                elem[i]=tem[i];
            }
        }
        delete[] tem;
        sz=siz;


    }

    iterator begin()
    {
        if (sz == 0)
            throw std::out_of_range("empty vector");
        return elem;
    }
    iterator end()
    {
        if (sz == 0)
            throw std::out_of_range("empty vector");
        return elem + sz;
    }
    reverse_iterator rbegin()
    {
        return reverse_iterator(end());
    }
    reverse_iterator rend()
    {
        return reverse_iterator(begin());
    }

};



#endif // CLASSVECTOR_H_INCLUDED
