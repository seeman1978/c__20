//
// Created by 王强 on 2020/5/27.
//

#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
    // 创建三个 string 的 unordered_map （映射到 string ）
    std::unordered_map<std::string, std::string> u = {
            {"RED", "#FF0000"},
            {"GREEN", "#00FF00"},
            {"BLUE", "#0000FF"}
    };

    for(const auto& n : u){
        std::cout << "key:[" << n.first << "] value:[" << n.second << "]\n";
    }

    // 添加新入口到 unordered_map
    u["BLACK"] = "#000000";
    u["WHITE"] = "#FFFFFF";

    //修改BLUE的值
    u["BLUE"] = "##0000ff";

    // 用关键输出值
    std::cout << "The HEX of color RED is:[" << u["RED"] << "]\n";
    std::cout << "The HEX of color BLACK is:[" << u["BLACK"] << "]\n";
    std::cout << "The HEX of color BLUE is:[" << u["BLUE"] << "]\n";

    return 0;
}