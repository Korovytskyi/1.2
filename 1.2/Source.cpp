#include <iostream>
#include <Windows.h>

#include "kvadratnamatr.cpp"

using namespace std;
int main()
{
    int x;
    cout << "porydok matruci = "; cin >> x;
    unsigned int rank = x;
    kvadratnamatr mt(rank);

    for (unsigned int i = 0; i < rank; i++) {
        for (unsigned int j = 0; j < rank; j++) {
            mt[i][j] = i * rank + j + 1;
        }
    }

    mt.print();
    std::cout << std::endl << "diagonal: " << mt.diagonal();
    std::cout << std::endl << "sumUp: " << mt.sumUp();
    std::cout << std::endl << "sumDown: " << mt.sumDown();

    std::cin.get();
}
