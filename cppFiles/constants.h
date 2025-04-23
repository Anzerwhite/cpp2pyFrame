#pragma once
#define SYS_PATH "path" 
#define P_PATH "./pyFiles" // 这里改成.py/.pyd文件所在目录的路径,原理类似于环境变量
#define P_PATH_PACKAGES "./python310/Lib/site-packages"  // 这里改成所用的python解释器所pip的第三方包的路径

// 以下为所调用的python文件的名称(无需后缀)，写作常量方便管理
#define	TESTFILE_MODULE "testFile"