#include "maths.h"

// ** Object Definitions *************************

    //maths::mat3::mat3() { for (int y = 0; y < 3; y++) for (int x = 0; x < 3; x++) this->elements[y][x] = 0; }
    //maths::mat3::mat3(float n) { for (int y = 0; y < 3; y++) for (int x = 0; x < 3; x++) this->elements[y][x] = y == x ? n : 0; }
    //maths::mat3::mat3(const mat3 & n) { for (int y = 0; y < 3; y++) for (int x = 0; x < 3; x++) this->elements[y][x] = n.elements[y][x]; }
    //void maths::mat3::operator=(const mat3 & n) { for (int y = 0; y < 3; y++) for (int x = 0; x < 3; x++) this->elements[y][x] = n.elements[y][x]; }
    //float3 & maths::mat3::operator[](const int index) { return this->elements[index]; }
    //const float3 & maths::mat3::operator[](const int index) const { return this->elements[index]; }

// ** Method Definitions *************************

    float3 maths::operator*(const mat3 & aa, const float3 & bb)
    {
        float3 result;
        result.x = aa.rows[0][0] * bb.x + aa.rows[1][0] * bb.y + aa.rows[2][0] * bb.z;
        result.y = aa.rows[0][1] * bb.x + aa.rows[1][1] * bb.y + aa.rows[2][1] * bb.z;
        result.z = aa.rows[0][2] * bb.x + aa.rows[1][2] * bb.y + aa.rows[2][2] * bb.z;
        return result;
    }
    maths::mat3 maths::operator*(const mat3 & aa, const mat3 & bb)
    {
        mat3 result;
        for (int y = 0; y < 3; y++)
            for (int x = 0; x < 3; x++)
                for (int i = 0; i < 3; i++) result.rows[y][x] += aa.rows[i][x] * bb.rows[y][i];
        return result;
    }
    bool maths::operator==(const mat3 & aa, const mat3 & bb)
    {
        for (int i = 0; i < 3; i++)
            if (aa.rows[i] != bb.rows[i]) return false;
        return true;
    }
    bool maths::operator!=(const mat3 & aa, const mat3 & bb)
    {
        for (int i = 0; i < 3; i++)
            if (aa.rows[i] != bb.rows[i]) return true;
        return false;
    }

// ***********************************************