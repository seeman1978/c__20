//
// Created by zhaoyue on 2020/10/14.
//

#include <cstddef>
#include <vector>
#include <initializer_list>

#ifndef C__20_MATRIX_H
#define C__20_MATRIX_H

template<typename T, size_t N>
class Matrix{
public:
    static constexpr size_t s_order = N;
    using value_type = T;
    using iterator = typename std::vector<T>::iterator;
    using const_iterator = typename std::vector<T>::const_iterator;

    Matrix()=default;
    Matrix(Matrix&&)=default;   //移动构造函数
    Matrix& operator=(Matrix&&) = default;
    Matrix(Matrix const&)=default; //拷贝构造函数
    Matrix& operator=(Matrix const&)=default;
    ~Matrix()=default;

    template<typename U>
    Matrix(const Matrix_ref<U, N>& x): desc{x.desc}, elems{x.begin(), x.end()}{
        static_assert(Convertible<U,T>(), "Matrix constructor: incompatible element types");
    };    //从Matrix_ref构造
    template<typename U>
    Matrix& operator=(const Matrix_ref<U,N>& x){
        static_assert(Convertible<U,T>(), "Matrix =:incompatible element types");
        desc = x.desc;
        elems.assign(x.begin(), x.end());
        return *this;
    };  //从Matrix_ref赋值

    template<typename... Exts>
    explicit Matrix(Exts... exts):desc{exts...}, elems(desc.size)
    {};  //指明每一维大小

    Matrix(Matrix_initializer<T,N>);    //列表初始化
    Matrix& operator=(Matrix_initializer<T,N> init){
        Matrix_impl::derive_extents(init, desc.extents);    //从初始化器列表推断维度大小
        elems.reserve(desc.size);
        Matrix_impl::insert_flat(init, elems);
        assert(elems.size() == desc.size);
    }; //列表赋值

    template<typename U>
    Matrix(std::initializer_list<U>)=delete; //除元素外，不使用{}
    template<typename U>
    Matrix& operator=(std::initializer_list<U>)=delete;

    //维数
    static constexpr size_t order(){
        return N;
    }
    //第n维元素数
    size_t extent(size_t n) const{
        return desc.extents[n];
    }
    //元素总数
    size_t size() const{
        elems.size();
    }
    //定义下标操作的切片
    const Matrix_slice<N>& descriptor() const{
        return desc;
    }
    //平坦元素访问
    T* data(){
        return elems.data();
    }
    const T* data() const{
        return elems.data();
    }

    //下标和切片
    template<typename... Args>
    Enable_if<Matrix_impl::Requesting_element<Args...>(), T&>
            operator()(Args... args);

    template<typename... Args>
    Enable_if<Matrix_impl::Requesting_element<Args...>(), const T&>
            operator()(Args... args) const;

    template<typename... Args>
    Enable_if<Matrix_impl::Requesting_slice<Args...>(), Matrix_ref<T,N>>
    operator()(consg Args&... args);

    template<typename... Args>
    Enable_if<Matrix_impl::Requesting_slice<Args...>(), Matrix_ref<const T,N>>
    operator()(const Args&... args) const;

    Matrix_ref<T, N-1> operator[](size_t i){
        return row(i);
    }

    Matrix_ref<const T, N-1> operator[](size_t i) const{
        return row(i);
    }

    Matrix_ref<T, N-1> row(size_t n);
    Matrix_ref<const T,N-1> row(size_t n) const;

    Matrix_ref<T,N-1> col(size_t n);
    Matrix_ref<const T, N-1> col(size_t n) const;

    //算数运算
    template<typename F>
    Matrix& apply(F f){
        for (auto& x: elems){
            f(x);
        }
        return *this;   //返回*this使得链式语法成为可能
    };

    template<typename M, typename F>
    Matrix& apply(const M& m, F f){
        assert(same_extents(desc, m.descriptor()));
        for (auto i=begin(), j=m.begin(); i!=end(); ++i, ++j){
            f(*i, *j);
        }
        return *this;
    };

    Matrix& operator=(const T& value);

    Matrix& operator+=(const T& value){
        return apply([&](T& a){ a+=value;});
    };
    Matrix& operator-=(const T& value);
    Matrix& operator*=(const T& value);
    Matrix& operator/=(const T& value);
    Matrix& operator%=(const T& value);

    template<typename M>
    Enable_if<Matrix_type<M>(), Matrix<T,N>&>
    operator+=(const M& m){
        static_assert(m.order()==N, "+=: mismatched Matrix dimensions");
        assert(same_extents(desc, m.descriptor()));
        return apply(m, [](T& a, Value_type<M>&b){a+b;});
    };

    template<typename M>
    Matrix& operator-=(const M& x);


private:
    Matrix_slice<N> desc;   //定义N个维度大小的切片
    std::vector<T> elems;   //元素
};

template<typename T, size_t N>
Matrix<T, N> operator+(const Matrix<T,N>& m, const T& value){
    Matrix<T, N> res = m;
    res += value;
    return res;
}

template<typename T, size_t N>
Matrix<T, N> operator+(const Matrix<T,N>& a, const Matrix<T,N>& b){
    Matrix<T, N> res = a;
    res += b;
    return res;
}

#endif //C__20_MATRIX_H
