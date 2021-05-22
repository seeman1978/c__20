//
// Created by zhaoyue on 2021/5/20.
//

int myfunc(int i) {
    *(int*)(nullptr) = i; /* line 7 */
    return i - 1;
}

int main(){
    myfunc(8);
}

