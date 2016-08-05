#include "Vector.h"

#include <cstdarg>


Vector::Vector(int siz, ...) : _size( (static_cast<unsigned int>(siz) ) ), _data(NULL)
{
	// http://www.cse.unt.edu/~donr/courses/4410/NOTES/stdarg/
	_data = new double[_size];
	va_list arg;
	va_start (arg, siz);
	for (unsigned int i = 0 ; i< siz; i++) {
		_data[i] = va_arg(arg, double);
	}
	va_end (arg);
}

Vector::~Vector()
{
	if(_data != NULL) delete[] _data;
}

ostream& operator<<(ostream& outStr, const Vector& vec)
{

	outStr<<"(";

	//____________
	if(vec._data == NULL && vec._size != 0)
	{
		for(unsigned int i = 0; i < vec._size; i++)
		{
			outStr<<"0";
			if(i < vec._size - 1)
			{
			outStr<<", ";
			}
		}

	}

	//__________________

	if(vec._data != NULL && vec._size != 0)
	{
		for(unsigned int i = 0; i < vec._size; i++)
		{
			outStr<<vec._data[i];
			if(i < vec._size - 1)
			{
			outStr<<", ";
			}
		}

	}

	outStr<<")"<<endl;
	return outStr;
}

/*
{
	const char charCoords[] = "     A   B   C   D   E   F   G   H";
	const char horLine[]    = "   +---+---+---+---+---+---+---+---+";
	gotoXY(0, BOARD_POS);
	outStr << charCoords << endl;
	outStr << horLine << endl;

	for (int i = BOARD_SIZE - 1; i >= 0; i--) {
		outStr << setw(2) << i + 1 << " ";
		for (unsigned j = 0; j < BOARD_SIZE; j++) {
			outStr << "| " << b.b[i][j] << " ";
		}
		outStr << "| " << i + 1 << endl;
		outStr << horLine << endl;
	}
	outStr << charCoords << endl;

    return outStr;
}
*/
