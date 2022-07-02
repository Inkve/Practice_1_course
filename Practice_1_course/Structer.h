#pragma once
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <Windows.h>
#include <iostream>
#include <ctime>
#include <string>

int Get_Random_Number(int, int);
int Input_Number(std::string);
void print_separator();

class data_array {
protected:
	std::vector <int> data;
	int m, n;

public:
	data_array(int, int);
	void print_initial();
	void cyclic_shift(int);
	void print_modified();
};