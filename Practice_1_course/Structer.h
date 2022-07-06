#pragma once
#include <Windows.h>
#include <iostream>
#include <string>

int Input_Number(std::string);
void print_separator();

class data_array {
protected:
	int m, n;
	int *data;

public:
	data_array(int, int);
	void print_initial();
	void cyclic_shift();
	void print_modified();
	~data_array();
};