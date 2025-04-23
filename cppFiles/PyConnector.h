#pragma once
#include"constants.h"
#include <Python.h>

class PyConnector
{
public:
	// ��ȡ��ʵ��
	static PyConnector* GetInstance();

	// �ͷŵ�ʵ���������˳�ʱ����
	static void deleteInstance();
	PyObject* getModuleTest();


private:
	// ���乹���������Ϊ˽�е�, ��ֹ�ⲿ���������
	PyConnector();
	~PyConnector();

	// ���俽������͸�ֵ�����Ϊ˽�к���, ��ֹ�ⲿ�����͸�ֵ
	PyConnector(const PyConnector& signal);
	const PyConnector& operator=(const PyConnector& signal);

private:
	// Ψһ��ʵ������ָ��
	static PyConnector* ptr_PyConnector;
	PyObject* pModule_TESTFILE;
};