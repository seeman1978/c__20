//
// Created by wq on 22-10-13.
//
#include <iostream>
#include <set>

using namespace std;

class StudentT {

public:
    int id;
    string name;
public:
    StudentT(int _id, const string& _name) : id(_id), name(_name) {
    }
    int getId() const{
        return id;
    }
    string getName() const{
        return name;
    }
};

inline bool operator< (const StudentT &s1, const StudentT &s2) {
    return  s1.getId() < s2.getId();
}

int main() {

    set<StudentT> st;
    StudentT s1(0, "Tom");
    StudentT s2(1, "Tim");
    st.insert(s1);
    st.insert(s2);
    set<StudentT>::iterator itr;
    for (itr = st.begin(); itr != st.end(); itr++) {
        cout << itr->getId() << " " << itr->getName() << endl;
    }
    return 0;
}