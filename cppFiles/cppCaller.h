#pragma once
#include<Python.h>
#include "constants.h"
#include<vector>

class CppCaller {
public:
	CppCaller();
	~CppCaller();

	std::vector<int> testFn(std::vector<int> data);

private:
	PyObject* pModule;

};
