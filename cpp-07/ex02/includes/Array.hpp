#pragma once
#include <exception>
#include <cstddef>

class OutOfBoundsException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return "Index out of bounds";
	}
};

template <typename T>
class Array
{
private:
	T *_array;
	size_t _size;

public:
	Array() : _array(NULL), _size(0) {}

	Array(unsigned int n) : _array(NULL), _size(n)
	{
		if (n == 0)
		{
			_array = NULL;
		}
		else
		{
			_array = new T[n];
		}
	}

	Array(const Array &other) : _array(NULL), _size(other._size)
	{
		if (_size == 0)
		{
			_array = NULL;
		}
		else
		{
			_array = new T[_size];
			for (size_t i = 0; i < _size; ++i)
			{
				_array[i] = other._array[i];
			}
		}
	}

	Array &operator=(const Array &other)
	{
		if (this != &other)
		{
			delete[] _array;
			_size = other._size;

			if (_size == 0)
			{
				_array = NULL;
			}
			else
			{
				_array = new T[_size];
				for (size_t i = 0; i < _size; ++i)
				{
					_array[i] = other._array[i];
				}
			}
		}
		return *this;
	}

	~Array()
	{
		delete[] _array;
	}

	T &operator[](size_t index)
	{
		if (index >= _size)
			throw OutOfBoundsException();
		return _array[index];
	}

	const T &operator[](size_t index) const
	{
		if (index >= _size)
			throw OutOfBoundsException();
		return _array[index];
	}

	size_t size() const
	{
		return _size;
	}
};
