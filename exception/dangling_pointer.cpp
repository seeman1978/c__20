//
// Created by zhaoyue on 2021/5/20.
//

int myfunc(int i) {
    int *pI = new int{i};
    delete pI;
    int m = 10;
    int *pP = new int{22};
    *pI = i;
    int j = *pI;
    return j;
}

int main(){
    myfunc(8);
}

