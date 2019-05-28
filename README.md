# 4-uzd

### 1) Funkcijos

```c++
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
 ```
 ```c++
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
 ```
 ```c++
  void reserve()
    {
        T* tem = elem;

        elem = new T[cap+1000];
        std::copy(&tem[0], &tem[sz], &elem[0]);
        delete[] tem;
        cap=cap+100;
    }
 ```
 ```c++
 void pop_back()
    {
        sz=sz-1;
        T* temp=elem;
        elem= new T[sz];
        for(int i=0; i< sz; i++)
        {
            elem[i]=temp[i];
        }
        delete[] tem;

    }
 ```
 ```c++
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
```

### 2) Analizė

#### ``` vector<int> ```

Sukuriami vektoriai ir užpildomi int reikšmėmis [0 ; dydis)

| KONTEINERIS\DYDIS |  1 000   |  10 000  |  100 000  | 1 000 000 | 10 000 000 |
| ----------------- | -------- | -------- | --------- | --------- | ---------- |
| STD::VECTOR       | 0.001002 | 0.000965 | 0.003989  | 0.027925  |  0.203256  |
| CUSTOM VECTOR     | 0.000276 | 0.000963 | 0.008976  | 7.590750  |   1233.72  |


### 3) Atminties perskirstymas
 
#### std::vector<int> 21 karta
#### custom vector 1000 kartų

### 4) Užpildo 100 000 studentų sąrašu
#### std::vector 0.226447 sekundes
#### custom vector 64.9517 sekundes
 
 
