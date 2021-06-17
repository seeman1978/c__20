//
// Created by 王强 on 2021/6/17.
//

#include <c++/v1/string>
#include <c++/v1/iostream>

union T{
    std::string s;  //string有非平凡的构造函数
    int n;
};

///c++标准规定，任何非引用类型都可以成为联合体的数据成员
union U{
    std::string s;  //string有非平凡的构造函数
    int n;
public:
    U(){
        new (&s)std::string;
    }

    ~U(){
        using namespace std;
        s.~string();
    }
};

struct Student{
    Student(bool b, int i) : gender{b}, age{i}{};
    bool gender;
    int age;
};

//枚举式的类
class Singer{
public:
    enum class Type{STUDENT, NATIVE, FOREIGNER};
    Singer(bool b, int i):student(b, i){
        t = Type::STUDENT;
    };
    explicit Singer(int i): id{i}{
        t = Type::NATIVE;
    };
    Singer(const char* n, int count){
        int size = (count > 9) ? 9 : count;
        memcpy(name, n, size);
        name[size+1] = '\0';
        t = Type::FOREIGNER;
    };
    ~Singer()=default;

    void print(){
        switch (t) {
            case Type::STUDENT:{
                std::cout << "Student's age is " << student.age << ". Student's gender is " << student.gender << '\n';
                break;
            }
            case Type::NATIVE:{
                std::cout << "Student's id is " << id << '\n';
                break;
            }
            case Type::FOREIGNER:{
                std::cout << "Student's name is " << name << '\n';
                break;
            }
            default:{
                std::cout << "Default Student " << '\n';
                break;
            }
        }
    }
private:
    Type t;
    union {//匿名的非受限联合体
        Student student;
        int id;
        char name[10];
    };
};

int main(){
    //T t;    //Call to implicitly-deleted default constructor of 'T'
    U u;
    Singer s1{true, 13};
    s1.print();
    Singer s2{310217};
    s2.print();
    Singer s3{"J Michael", 9};
    s3.print();
}
