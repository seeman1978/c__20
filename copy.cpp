//
// Created by 王强 on 2020/3/5.
//

//
// Created by 王强 on 2020/3/5.
//

#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;
int main()
{
    // 给定
    // /dir1 含有 /dir1/file1 、 /dir1/file2 、 /dir1/dir2
    // 而 /dir1/dir2 含有 /dir1/dir2/file3
    std::filesystem::copy("/dir1", "/dir3");
    // 之后
    // 创建 /dir3 （拥有 /dir1 的属性）
    // /dir1/file1 被复制到 /dir3/file1
    // /dir1/file2 被复制到 /dir3/file2

    // ……但在下一句后，递归拷贝
    std::filesystem::copy("/dir1", "/dir3", std::filesystem::copy_options::recursive);
    // 创建 /dir3 （拥有 /dir1 的属性）
    // /dir1/file1 被复制到 /dir3/file1
    // /dir1/file2 被复制到 /dir3/file2
    // 创建 /dir3/dir2 （拥有 /dir1/dir2 的属性）
    // /dir1/dir2/file3 被复制到 /dir3/dir2/file3
}