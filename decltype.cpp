//
// Created by zhaoyue on 2020/9/4.
//
//使用了后置返回类型的语法
template <class T, class U>
auto operator+(const Matrix<T>& a, const Matrix<U>& b)->Matrix<decltype(T{}+U{})>
{
    Matrix<decltype(T{}+U{})> res;
    for (int i=0; i!=a.rows(); ++i)
        for (int j = 0; j != a.cols(); ++j) {
            res(i, j) += a(i, j) + b(i, j);
        }
    retrun res;
}