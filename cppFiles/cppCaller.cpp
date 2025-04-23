#include "cppCaller.h"
#include "PyConnector.h"
#include<vector>

CppCaller::CppCaller()
{
    // ��pyConnect�����л�ȡpythonģ��ʵ��
    pModule = PyConnector::GetInstance()->getModuleTest();
}

CppCaller::~CppCaller()
{
}

std::vector<int> CppCaller::testFn(std::vector<int> data)
{

    // ����һ�����ڽ��ս��������
    std::vector<int> result{};

    // ����ʵ�ֶ�.pyd�ļ��еĺ����Ĳ�����ǰ����ǰ��Ĳ���û���⣬pModule�����ǿ�ָ��
    if (pModule != nullptr) {
        PyObject* pFunc = PyObject_GetAttrString(pModule, "test_cpp2py"); // ��ȡ������������дҪ���õĺ�����������������test_cpp2py
        if (pFunc && PyCallable_Check(pFunc)) { // �жϸú����Ƿ�����ҿɵ���

            // ��������������c++��python�����Ͳ���Ӧ������Ҫת��
            // ������ݴ����vector���͵�data������һ����Ӧ�б�list
            PyObject* pData = PyList_New(data.size());
            for (int i = 0; i < data.size(); ++i) {
                PyList_SetItem(pData, i, PyLong_FromLong(data[i])); // ����Ҫ��data[i]ת��Ϊpython����
            }

            // ����һ�������б���һ������Ϊ�����б�Ĳ�������������Ϊ1
            PyObject* pArgs = PyTuple_Pack(1, pData);
            // ���øú���
            PyObject* pValue = PyObject_CallObject(pFunc, pArgs); // ���ú���
            Py_DECREF(pArgs);

            // ������ֵ
            if (pValue != nullptr) {
                ;
                // ��pValue��ȡֵ
                for (Py_ssize_t i = 0; i < PyList_Size(pValue); ++i) {
                    result.push_back(PyLong_AsLong(PyList_GetItem(pValue, i)));
                }
                Py_DECREF(pValue);
            }
            Py_DECREF(pFunc);
        }
    }
    else {
        // ֤�������⣬pModuleΪ��ָ����
        PyErr_Print(); // ��ӡ������Ϣ
    }
    return result; // ���ؽ��
}
