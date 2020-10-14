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

private:
    Matrix_slice<N> desc;   //定义N个维度大小的切片
    std::vector<T> elems;   //元素
};

#endif //C__20_MATRIX_H
