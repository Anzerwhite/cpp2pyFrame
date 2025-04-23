#pragma once
#include"constants.h"
#include <Python.h>

class PyConnector
{
public:
	// 获取单实例
	static PyConnector* GetInstance();

	// 释放单实例，进程退出时调用
	static void deleteInstance();
	PyObject* getModuleTest();


private:
	// 将其构造和析构成为私有的, 禁止外部构造和析构
	PyConnector();
	~PyConnector();

	// 将其拷贝构造和赋值构造成为私有函数, 禁止外部拷贝和赋值
	PyConnector(const PyConnector& signal);
	const PyConnector& operator=(const PyConnector& signal);

private:
	// 唯一单实例对象指针
	static PyConnector* ptr_PyConnector;
	PyObject* pModule_TESTFILE;
};