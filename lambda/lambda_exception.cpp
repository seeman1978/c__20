//
// Created by wq on 2021/5/4.
//

int main() // C4297 expected
{
    []() noexcept { throw 5; }();
}