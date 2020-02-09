#include "maths.h"

// ** Object Definitions *************************
    
    maths::mat3::mat3() { for (int y = 0; y < 3; y++) for (int x = 0; x < 3; x++) this->elements[y][x] = 0; }
    maths::mat3::mat3(float n) { for (int y = 0; y < 3; y++) for (int x = 0; x < 3; x++) this->elements[y][x] = y == x ? n : 0; }
    maths::mat3::mat3(const mat3 & n) { for (int y = 0; y < 3; y++) for (int x = 0; x < 3; x++) this->elements[y][x] = n.elements[y][x]; }
    void maths::mat3::operator=(const mat3 & n) { for (int y = 0; y < 3; y++) for (int x = 0; x < 3; x++) this->elements[y][x] = n.elements[y][x]; }
    float3 & maths::mat3::operator[](const int index) { return this->elements[index]; }
    const float3 & maths::mat3::operator[](const int index) const { return this->elements[index]; }

// ** Method Definitions *************************

    float3 maths::operator*(const mat3 & aa, const float3 & bb)
    {
        float3 result;
        result.x = aa.elements[0][0] * bb.x + aa.elements[1][0] * bb.y + aa.elements[2][0] * bb.z;
        result.y = aa.elements[0][1] * bb.x + aa.elements[1][1] * bb.y + aa.elements[2][1] * bb.z;
        result.z = aa.elements[0][2] * bb.x + aa.elements[1][2] * bb.y + aa.elements[2][2] * bb.z;
        return result;
    }
    maths::mat3 maths::operator*(const mat3 & aa, const mat3 & bb)
    {
        mat3 result;
        for (int y = 0; y < 3; y++)
            for (int x = 0; x < 3; x++)
                for (int i = 0; i < 3; i++) result[y][x] += aa.elements[i][x] * bb.elements[y][i];
        return result;
    }
    bool maths::operator==(const mat3 & aa, const mat3 & bb)
    {
        for (int i = 0; i < 3; i++)
            if (aa.elements[i] != bb.elements[i]) return false;
        return true;
    }
    bool maths::operator!=(const mat3 & aa, const mat3 & bb)
    {
        for (int i = 0; i < 3; i++)
            if (aa.elements[i] != bb.elements[i]) return true;
        return false;
    }

// ***********************************************