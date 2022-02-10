/**
* @file
* @brief
* @details
* @author		qiangwang
* @date		    2022/2/10
* @par Copyright(c): 	2022 mega. All rights reserved.
*/

class VECTOR3D
{
public:
    // operations, etc...

    union
    {
        float m[3];

        struct
        {
            float x, y, z;
        };
    };
};

int main(){
    VECTOR3D v{};
    // same effect
    v.m[0] = 1.0f;
    v.x = 1.0f;
}