#include <initializer_list>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <optional>

#pragma once
template <typename T>
class Array
{
public:
	Array(int size);
	Array(std::initializer_list<T> initializer);
	int Size();
	int Stack(T& element);
    int Stack(T element);
    T* Pop();
    friend std::ostream& operator<<(std::ostream& os, const Array& arr)
    {
        if (arr._elementCount == 0) {
            return os << "[]";
        }

        os << '[';
        for (std::size_t i = 0; i < arr._elementCount; ++i) {
            os << arr._value[i];
            if (i < arr._elementCount - 1) {
                os << ", ";
            }
        }
        return os << ']';
    }

    std::string AsString();

private:
	int _size;
	int _elementCount;

	T* _value;

	void _Resize();

	~Array();
};




template<typename T>
Array<T>::Array(int size)
    : _size(size), _elementCount(0), _value(new T[size]) {
}

template<typename T>
Array<T>::Array(std::initializer_list<T> initializer)
    : _size(initializer.size()), _elementCount(initializer.size()), _value(new T[initializer.size()]) {
    delete[] _value;

    _size = initializer.size();
    _elementCount = initializer.size();
    _value = new T[_size];
    std::copy(initializer.begin(), initializer.end(), _value);
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
inline int Array<T>::Stack(T element)
{
    if (_elementCount >= _size)
    {
        _Resize();
    }
    _value[_elementCount++] = element;
    return _elementCount;
}

template<typename T>
inline T* Array<T>::Pop()
{
    if (_elementCount <= 0)
    {
        return nullptr;
    }
    return &_value[--_elementCount];
}

template<typename T>
inline std::string Array<T>::AsString()
{
    std::string result;
    if (_elementCount == 0) {
        return "[]";
    }

    result = '[';
    for (std::size_t i = 0; i < _elementCount; ++i) {
        result += std::to_string(_value[i]);
        if (i < _elementCount - 1) {
            result += ", ";
        }
    }
    result += ']';
    return result;
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
Array<T>::~Array()
{
    delete[] _value;
}