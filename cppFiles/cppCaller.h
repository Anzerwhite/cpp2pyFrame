#pragma once
#include<Python.h>
#include "constants.h"
#include<vector>

class CppCaller {
public:
	CppCaller();
	~CppCaller();

	// 你自己的业务函数
	std::vector<int> testFn(std::vector<int> data);
private:
	// 该类对应调用的python模块，可写多个，但从职责设计角度上建议只调用一个模块，减少耦合
	PyObject* pModule;
};
