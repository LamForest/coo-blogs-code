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

class MyVector : public std::vector<int>
{
    typedef int T;
    typedef std::vector<int> vector;

public:
    MyVector() : vector(){};

    MyVector(const MyVector &rhs) : vector(rhs)
    {
        cout << "vector ctor copy" << endl;
    }

    MyVector(MyVector &&rhs) : vector(std::move(rhs))
    {
        cout << "vector ctor move" << endl;
    }

    MyVector &operator=(const MyVector &rhs)
    {
        cout << "vector operator= copy" << endl;
        vector::operator=(rhs);
        return *this;
    }

    MyVector &operator=(MyVector &&rhs)
    {
        cout << "vector operator= move" << endl;
        vector::operator=(rhs);
        return *this;
    }
};

MyVector filter(const MyVector &v)
{
    MyVector ret;
    for (int i : v)
    {
        if (i > 0 && i % 2 == 0)
        {
            ret.push_back(i);
        }
    }
    cout << "function filter return" << endl;
    return ret;
}

MyVector someFuncReturnVector()
{
    MyVector v;
    v.reserve(3);
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);

    return v;
}

int main()
{
    // MyVector a;
    // a.push_back(1);
    // std::iota(a.begin(), a.end(), 0);
    // std::vector<int> b = filter(a);
    MyVector b;
    // b = a;

    // b = filter(a);
    b = someFuncReturnVector();

    return 0;
}