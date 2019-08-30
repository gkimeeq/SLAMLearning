**1.下载**

切换到`root`用户。

```
$su root  # 切换root用户，要输入密码
#cd  # 切换到root的家目录
#wget http://bitbucket.org/eigen/eigen/get/3.3.7.tar.gz  # 下载Eigen
```

**2.解压安装**

```
#tar -zxvf 3.3.7.tar.gz  # 解压
```

然后会有一个类似于`eigen-eigen-xxxxxxxxxxxxxxx`的文件夹。

```
#cd eigen-eigen-xxxxxxxxxxxxxxx  # 进入eigen解压的目录
#mkdir build  # 新建一个build文件夹
#cd build  # 进入build文件夹
#cmake ..  # 用cmake生成Makefile
#make install  # 安装
```

默认安装目录为`/usr/local/include/eigen3`。Eigen库只有头文件组成，没有`.so`或`.a`那样的共享库或静态库，很神奇的一个库。因此在使用时，引入头文件即可，不需要链接库文件。

**3.示例**

参考官方的例子：[http://eigen.tuxfamily.org/dox/GettingStarted.html](http://eigen.tuxfamily.org/dox/GettingStarted.html)。

```
$cd  # 回到家目录
$mkdir EigenExample  # 建一个文件夹
$cd EigenExample  # 进入这个文件夹
$vi TestEigen.cpp  # 编辑C++代码
```
然后输入以下代码：

```
#include <iostream>
#include <Eigen/Dense>  // 稠密矩阵的代数运算，如求逆，特征值等

using namespace std;

int main(int argc, char** argv) {
    Eigen::MatrixXd m(2,2);  // 声明一个2x2的矩阵
    m(0, 0) = 3;  // 开始矩阵赋值
    m(1, 0) = 2.5;
    m(0, 1) = -1;
    m(1, 1) = m(1, 0) + m(0, 1);
    cout << m << endl;  // 打印矩阵
    return 0;
}
```

接下来写一个`CMakeLists.txt`。

```
$vi CMakeLists.txt
```

内容如下：

```
# 声明需要的cmake最小版本为2.8
cmake_minimum_required(VERSION 2.8)
# 声明cmake工程
project(Eigen)
# 设置编译模式为发布模式
set(CMAKE_BUILD_TYPE "Release")
# 设置编译参数
set(CMAKE_CXX_FLAGS "-O3")
# 添加Eigen头文件
include_directories("/usr/local/include/eigen3")
# 添加一个可执行程序
add_executable(TestEigen TestEigen.cpp)
```

然后编译：

```
$mkdir build  # 新建build文件夹
$cd build  # 进入build文件夹
$cmake ..  # 用cmake生成Makefile
$make  # 编译，会生成一个TestEigen的可执行文件
$./TestEigen  # 执行
```
输出的结果为：

```
   3    -1
2.5  1.5
```

源码可于github下载：[https://github.com/gkimeeq/SLAMLearning](https://github.com/gkimeeq/SLAMLearning)。
