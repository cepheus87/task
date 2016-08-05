#ifndef _VECTOR_H
#define _VECTOR_H

#include <iostream>

#include <cstdlib>
#include <cstring>

using namespace std;

class Vector 
{
private:
    unsigned int _size;
    double* _data;
public:
    Vector() : _size(0), _data(NULL) {}
    Vector(unsigned int siz) : _size(siz), _data(NULL) {}
    Vector(int siz, ...);

    friend ostream& operator<<(ostream& outStr, const Vector& vec);

    ~Vector();
};

#endif // _VECTOR_H

