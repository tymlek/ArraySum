// ArraySumC.cpp

#include "ArraySumC.h"

long array_sum_c(long array_of_int[], unsigned count)
{
	long sum = 0;

	for (auto i = 0; i != count; ++i)
		sum += array_of_int[i];

	return sum;
}
