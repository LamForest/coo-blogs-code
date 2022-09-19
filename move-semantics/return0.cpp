#include <utility>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <numeric>

using std::cout;
using std::endl;

void *operator new(size_t size)
{
    cout << "New operator overloading: malloc " << size << " bytes " << endl;
    void *p = malloc(size);
    return p;
}

void operator delete(void *p)
{
    cout << "Delete operator overloading " << endl;
    free(p);
}

std::vector<int> someFuncReturnVector()
{
    std::vector<int> v(4);
    return v;
}

int main()
{
    // std::vector<int> a(4);
    std::vector<int> b;
    // b = a;
    b = someFuncReturnVector();

    return 0;
}