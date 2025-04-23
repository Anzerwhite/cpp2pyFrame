#include "PyConnector.h"
#include <iostream>

// 代码一运行就初始化创建实例 ，本身就线程安全
PyConnector* PyConnector::ptr_PyConnector = new (std::nothrow) PyConnector();

PyConnector* PyConnector::GetInstance()
{
	return ptr_PyConnector;
}

// 删除实例
void PyConnector::deleteInstance()
{
	if (ptr_PyConnector)
	{
		delete ptr_PyConnector;
		ptr_PyConnector = nullptr;
	}
}

PyConnector::PyConnector()
{
    // 初始化python解释器
	Py_Initialize(); 

    // 配置环境变量
	PyObject* sysPath = PySys_GetObject(SYS_PATH);
	PyObject* pPath = PyUnicode_FromString(P_PATH);
	PyObject* pPath_packages = PyUnicode_FromString(P_PATH_PACKAGES); 
	PyList_Append(sysPath, pPath);
	Py_DECREF(pPath); // 释放对象
	PyList_Append(sysPath, pPath_packages);
	Py_DECREF(pPath_packages); // 释放对象

    // 导入名为testFile的Python模块
	pModule_TESTFILE = PyImport_ImportModule(TESTFILE_MODULE); 

}

PyConnector::~PyConnector()
{
    Py_Finalize(); // 结束python解释器
}

// 获取对应python文件的模块
PyObject* PyConnector::getModuleTest() {
	return pModule_TESTFILE;
}

