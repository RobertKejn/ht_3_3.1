#pragma once
#include "smart_array.h"
#include <exception>
#include <stdexcept>

smart_array::smart_array(int n) {
	if (n >= 0) arr = new int[n];
	else throw std::length_error("array length must be greater than or equal to zero");
	actual_length = n;
}
smart_array::~smart_array() {
	delete[] arr;
}

smart_array::smart_array() { arr = new int[0]; }

smart_array& smart_array::operator=(const smart_array& v) {
	virtual_length = v.virtual_length;
	actual_length = v.actual_length;
	delete[] arr;
	arr = new int[actual_length];
	for (int i = 0; i < actual_length; ++i) {
		arr[i] = v.arr[i];
	}
	return *this;
}

void smart_array::add_element(int n) {
	if (virtual_length < actual_length) arr[virtual_length++] = n;
	else {
		int* new_arr = new int[actual_length * 2];
		for (int i = 0; i < actual_length; ++i) {
			new_arr[i] = arr[i];
		}
		new_arr[virtual_length++] = n;
		delete[] arr;
		actual_length *= 2;
		arr = new_arr;
	}
}

int smart_array::operator[](int n) {
	if (n < virtual_length) return arr[n];
	else throw std::out_of_range("Index is outside array bounds");
}

int smart_array::get_element(int n) {
	if (n < virtual_length) return arr[n];
	else throw std::out_of_range("Index is outside array bounds");
}