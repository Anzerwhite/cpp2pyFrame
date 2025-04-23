#include<iostream>
#include"cppCaller.h"
#include<vector>
using namespace std;

int main() {
    CppCaller cppCaller{}; // 初始化一个对象
    // 调用测试函数，查看是否成功调用python脚本
    vector<int> result = cppCaller.testFn({ 100, 200, 300, 400 });

    cout << "\n上面为python脚本内的输出，下面为C++端的输出：\n";
    cout << "\n返回值为：";
    for (int item : result) {
        cout << item << ' ';
    }
    cout << endl;
    return 0;
}