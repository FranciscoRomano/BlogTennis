#include "maths.h"

// ** Object Definitions *************************

    //maths::mat4::mat4() { for (int y = 0; y < 4; y++) for (int x = 0; x < 4; x++) this->elements[y][x] = 0; }
    //maths::mat4::mat4(float n) { for (int y = 0; y < 4; y++) for (int x = 0; x < 4; x++) this->elements[y][x] = y == x ? n : 0; }
    //maths::mat4::mat4(const mat4 & n) { for (int y = 0; y < 4; y++) for (int x = 0; x < 4; x++) this->elements[y][x] = n.elements[y][x]; }
    //void maths::mat4::operator=(const mat4 & n) { for (int y = 0; y < 4; y++) for (int x = 0; x < 4; x++) this->elements[y][x] = n.elements[y][x]; }
    //float4 & maths::mat4::operator[](const int index) { return this->elements[index]; }
    //const float4 & maths::mat4::operator[](const int index) const { return this->elements[index]; }

// ** Method Definitions *************************

    float4 maths::operator*(const mat4 & aa, const float4 & bb)
    {
        float4 result;
        result.x = aa.rows[0][0] * bb.x + aa.rows[1][0] * bb.y + aa.rows[2][0] * bb.z + aa.rows[3][0] * bb.w;
        result.y = aa.rows[0][1] * bb.x + aa.rows[1][1] * bb.y + aa.rows[2][1] * bb.z + aa.rows[3][1] * bb.w;
        result.z = aa.rows[0][2] * bb.x + aa.rows[1][2] * bb.y + aa.rows[2][2] * bb.z + aa.rows[3][2] * bb.w;
        result.w = aa.rows[0][3] * bb.x + aa.rows[1][3] * bb.y + aa.rows[2][3] * bb.z + aa.rows[3][3] * bb.w;
        return result;
    }
    maths::mat4 maths::operator*(const mat4 & aa, const mat4 & bb)
    {
        mat4 result;
        for (int y = 0; y < 4; y++)
            for (int x = 0; x < 4; x++)
                for (int i = 0; i < 4; i++)
                    result.rows[y][x] += aa.rows[i][x] * bb.rows[y][i];
        return result;
    }
    bool maths::operator==(const mat4 & aa, const mat4 & bb)
    {
        for (int i = 0; i < 4; i++)
            if (aa.rows[i] != bb.rows[i]) return false;
        return true;
    }
    bool maths::operator!=(const mat4 & aa, const mat4 & bb)
    {
        for (int i = 0; i < 4; i++)
            if (aa.rows[i] != bb.rows[i]) return true;
        return false;
    }

// ***********************************************