#include<iostream>
#include"cppCaller.h"
#include<vector>
using namespace std;

int main() {
    CppCaller cppCaller{}; // ��ʼ��һ������
    // ���ò��Ժ������鿴�Ƿ�ɹ�����python�ű�
    vector<int> result = cppCaller.testFn({ 100, 200, 300, 400 });

    cout << "\n����Ϊpython�ű��ڵ����������ΪC++�˵������\n";
    cout << "\n����ֵΪ��";
    for (int item : result) {
        cout << item << ' ';
    }
    cout << endl;
    return 0;
}