#pragma once
class smart_array {
public:
	smart_array(int n);
	smart_array();
	~smart_array();
	void add_element(int n);
	int get_element(int n);
	int operator[](int n);
	smart_array& operator=(const smart_array& v);
private:
	int* arr;
	int actual_length = 0;
	int virtual_length = 0;
};