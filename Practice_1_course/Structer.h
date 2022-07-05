#pragma once
#include <cstdlib>
#include <Windows.h>
#include <iostream>
#include <ctime>
#include <string>

int Get_Random_Number(int, int);
int Input_Number(std::string);
void print_separator();

class data_array {
protected:
	int m, n;
	int *data;

public:
	data_array(int, int);
	void print_initial();
	void cyclic_shift(int);
	void print_modified();
	~data_array();
};