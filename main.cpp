#include "classVector.h"

#include <vector>

int main()
{

    std::vector<int> v1;
    Vector<int> v2;
    /*
    auto start = std::chrono::system_clock::now();
    for(int i=0;i<1000000;i++)
    {
        v1.push_back(i);
        //if(i%100000==0) cout << v1[i] << endl;
    }

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    cout << "Programa uztruko : " << elapsed_seconds.count() << " sekundziu\n";*/
    int szs = 0;
	int v1_add = 0;
	int v2_add = 0;

    for (int i=0;i<1000000;i++)
    {
		if (v1.capacity() != szs) {
			szs = v1.capacity();
			v1_add++;
		}
		v1.push_back(i);
	}
	szs = 0;

	for (int i=0;i<1000000;i++)
    {
		if (v2.capacity() != szs) {
			szs = v2.capacity();
			v2_add++;
		}
		v2.push_back(i);
	}

	cout << v1_add << " " << v2_add << endl;
    return 0;
}
