#include "Array.hpp"
#include <algorithm>
#include <cstring>

template<typename T>
Array<T>::Array(int size)
    : _size(size), _elementCount(0), _value(new T[size]) {
}

template<typename T>
Array<T>::Array(std::initializer_list<T> initializer)
    : _size(initializer.size()), _elementCount(initializer.size()), _value(new T[initializer.size()]) {
}

template<typename T>
int Array<T>::Size()
{
	return _elementCount;
}

template<typename T>
int Array<T>::Stack(T& element)
{
    if (_elementCount >= _size)
    {
        _Resize();
    }
    _value[_elementCount++] = element;
}

template<typename T>
void Array<T>::_Resize()
{
    size_t newSize = _size * 2;
    T* newValue = new T[newSize];

    memcpy(newValue, _value, _size * sizeof(T));

    _size = newSize;
    delete[] _value;
    _value = newValue;
}

template<typename T>
Array<T>& Array<T>::operator=(std::initializer_list<T> initializer) {
    delete[] _value;

    _size = initializer.size();
    _elementCount = initializer.size();
    _value = new T[_size];
    std::copy(initializer.begin(), initializer.end(), _value);

    return *this;
}

template<typename T>
Array<T>::~Array()
{
    delete[] _value;
}