import numpy as np

print('enter python success')  # 成功找到该脚本


def test_cpp2py(data):
    """
    一个含参函数，用于测试cpp文件调用含第三方包的python脚本
    :param data: 一个测试列表
    :return:
    """
    data_after_np = np.array(data)
    print('successful, and data is: ', data_after_np)  # 输出
    return [1, 2, 3, 4]  # 这里笔者偷懒就直接传一个固定列表返回给调用方了