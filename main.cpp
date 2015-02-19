// main.cpp

#include <iostream>
#include <chrono>
#include "ArraySumAsm.h"
#include "ArraySumC.h"

//-----------------------------------------------------------------------------

int main()
{
	const unsigned array_size = 100000;

	// Fill an array with pseudorandom integers
	long array_of_int[array_size];
	for (auto i = 0; i != array_size; ++i)
		array_of_int[i] = rand();

	std::cout<<"Please wait...\n";

	// Test the Assembly language function
	long result = 0;
	auto start = std::chrono::steady_clock::now();
	
	result = array_sum_asm(array_of_int,array_size);

	auto stop = std::chrono::steady_clock::now();

	std::cout<<"Elpased ASM time: "
		<<std::chrono::duration_cast<std::chrono::nanoseconds>(stop-start).count()
		<<"ns.\n"<<"Sum of elements: "<<result<<std::endl;

	// Test the C++ language function
	result = 0;
	start = std::chrono::steady_clock::now();
	
	result = array_sum_c(array_of_int,array_size);

	stop = std::chrono::steady_clock::now();

	std::cout<<"Elpased C++ time: "
		<<std::chrono::duration_cast<std::chrono::nanoseconds>(stop-start).count()
		<<"ns.\n"<<"Sum of elements: "<<result<<std::endl;

	return 0;
}
