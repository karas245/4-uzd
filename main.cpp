#include "classVector.h"

#include <vector>
#include "fun.h"

void time()
{
    std::vector<int> v1;
    Vector<int> v2;

    auto start = std::chrono::system_clock::now();
    for(int i=0;i<100000;i++)
    {
        v1.push_back(i);

    }

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    cout << "std::vector uztruko : " << elapsed_seconds.count() << " sekundziu\n";
     start = std::chrono::system_clock::now();
    for(int i=0;i<100000;i++)
    {
        v2.push_back(i);

    }
    end = std::chrono::system_clock::now();
    elapsed_seconds = end-start;
    cout << "custom vector uztruko : " << elapsed_seconds.count() << " sekundziu\n";
}
void memory()
{
    std::vector<int> v1;
    Vector<int> v2;
    int v1_add = 0;
	int v2_add = 0;

    for (int i=0;i<1000000;i++)
    {
		if (v1.capacity() == v1.size()) {
			v1_add++;
		}
		v1.push_back(i);
	}

	for (int i=0;i<1000000;i++)
    {
		if (v2.capacity() == v2.size()) {
			v2_add++;
		}
		v2.push_back(i);
	}

	cout << v1_add << " " << v2_add << endl;
}

void uzd3()
{
    std::vector<Studentas> v1;
    Vector<Studentas> v2;
    Studentas stud;
    string vardas="Vardas";
    string pavarde="Pavarde";
    vector<int> nd={5,8,9,6,7,3};
    int e=8;
    stud.setVar(vardas);
    stud.setPav(pavarde);
    stud.setV(nd);
    stud.setEgz(e);
    auto start = std::chrono::system_clock::now();
    for(int i=0;i<100000;i++)
    {
        v1.push_back(stud);
    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    cout << "std::vector uztruko : " << elapsed_seconds.count() << " sekundziu\n";
     start = std::chrono::system_clock::now();
    for(int i=0;i<100000;i++)
    {
        v2.push_back(stud);
    }
    end = std::chrono::system_clock::now();
    elapsed_seconds = end-start;
    cout << "custom vector uztruko : " << elapsed_seconds.count() << " sekundziu\n";
}
int main()
{


	time();
	memory();
    uzd3();
    return 0;
}
