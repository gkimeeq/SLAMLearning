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
