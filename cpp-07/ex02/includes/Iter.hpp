#pragma once

#include <cstddef>

template <typename T, typename Func>
void iter(T *array, size_t length, Func function)
{
	for (size_t i = 0; i < length; ++i)
	{
		function(array[i]);
	}
}