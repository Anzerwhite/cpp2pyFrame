#include "PyConnector.h"
#include <iostream>

// ����һ���оͳ�ʼ������ʵ�� ��������̰߳�ȫ
PyConnector* PyConnector::ptr_PyConnector = new (std::nothrow) PyConnector();

PyConnector* PyConnector::GetInstance()
{
	return ptr_PyConnector;
}

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
	Py_Initialize(); // ��ʼ��python������
	PyObject* sysPath = PySys_GetObject(SYS_PATH);
	PyObject* pPath = PyUnicode_FromString(P_PATH);
	PyObject* pPath_packages = PyUnicode_FromString(P_PATH_PACKAGES);
	PyList_Append(sysPath, pPath);
	Py_DECREF(pPath);
	PyList_Append(sysPath, pPath_packages);
	Py_DECREF(pPath_packages);

	pModule_TESTFILE = PyImport_ImportModule(TESTFILE_MODULE); // ������ΪtestFile��Pythonģ��

}

PyConnector::~PyConnector()
{
}

PyObject* PyConnector::getModuleTest() {
	return pModule_TESTFILE;
}

