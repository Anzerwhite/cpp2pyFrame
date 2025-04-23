#include "cppCaller.h"
#include "PyConnector.h"
#include<vector>

CppCaller::CppCaller()
{
    // 从pyConnect单例中获取python模块实例
    pModule = PyConnector::GetInstance()->getModuleTest();
}

CppCaller::~CppCaller()
{
}

std::vector<int> CppCaller::testFn(std::vector<int> data)
{

    // 声明一个用于接收结果的数组
    std::vector<int> result{};

    // 下面实现对.pyd文件中的函数的操作（前提是前面的操作没问题，pModule不会是空指针
    if (pModule != nullptr) {
        PyObject* pFunc = PyObject_GetAttrString(pModule, "test_cpp2py"); // 获取函数，这里填写要调用的函数名，笔者这里是test_cpp2py
        if (pFunc && PyCallable_Check(pFunc)) { // 判断该函数是否存在且可调用

            // 创建参数，由于c++和python的类型不对应，所以要转化
            // 这里根据传入的vector类型的data来创建一个对应列表list
            PyObject* pData = PyList_New(data.size());
            for (int i = 0; i < data.size(); ++i) {
                PyList_SetItem(pData, i, PyLong_FromLong(data[i])); // 这里要对data[i]转化为python类型
            }

            // 构建一个参数列表，第一个参数为参数列表的参数数量，这里为1
            PyObject* pArgs = PyTuple_Pack(1, pData);
            // 调用该函数
            PyObject* pValue = PyObject_CallObject(pFunc, pArgs); // 调用函数
            Py_DECREF(pArgs);

            // 处理返回值
            if (pValue != nullptr) {
                // 从pValue中取值
                for (Py_ssize_t i = 0; i < PyList_Size(pValue); ++i) {
                    result.push_back(PyLong_AsLong(PyList_GetItem(pValue, i)));
                }
                Py_DECREF(pValue);
            }
            Py_DECREF(pFunc);
        }
    }
    else {
        // 证明有问题，pModule为空指针了
        PyErr_Print(); // 打印错误信息
    }
    return result; // 返回结果
}
