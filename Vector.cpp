#include "Vector.h"

#include <cstdarg>


Vector::Vector(int siz, ...) : _size( (static_cast<unsigned int>(siz) ) ), _data(NULL)
{
	_data = new double[_size];
	va_list arg;
	va_start (arg, siz);
	for (int i = 0 ; i< siz; i++) {
		_data[i] = va_arg(arg, double);
	}
	va_end (arg);
}

Vector::Vector(const Vector& vec){
	_size = vec._size;
	if(_size > 0){
		_data = new double[_size];
	}
	for(unsigned i=0; i< _size; i++){
		_data[i] = vec._data[i];
	}

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

// pre
Vector& Vector::operator++(){
	for(unsigned i=0; i< _size; i++){
		_data[i] += 1.0;
	}
	return *this;
}

//post
Vector Vector::operator++(int){
	Vector temp(*this);
	operator++();
	return temp;
}

Vector& Vector::operator=(const Vector& vec){

	if(this != &vec){
		delete[] _data;
		_size = vec._size;
		_data = new double[_size];
		for(unsigned i=0; i< _size; i++){
			_data[i] = vec._data[i];
		}
	}

	return *this;
}

Vector Vector::create(int siz, ...)
{
	Vector vec(siz);
	delete[] vec._data;
	vec._data = new double[siz];

	va_list arg;
	va_start (arg, siz);
	for (int i = 0 ; i< siz; i++) {
		vec._data[i] = va_arg(arg, double);
	}

	va_end (arg);

	return vec;

}

Vector Vector::operator+(const Vector& vec)
{

	Vector temp(*this);
	for(unsigned i=0; i< _size; i++){
		temp._data[i] += vec._data[i];
	}
	return temp;

}



