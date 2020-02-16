#include "maths.h"

// ** Object Definitions *************************
    //
    //maths::mat2::mat2() { for (int i = 0; i < 2; i++) this->elements[i] = float2{ 0, 0 }; }
    //maths::mat2::mat2(float n) { for (int y = 0; y < 2; y++) for (int x = 0; x < 2; x++) this->elements[y][x] = y == x ? n : 0; }
    //maths::mat2::mat2(const mat2 & n) { for (int i = 0; i < 2; i++) this->elements[i] = n.elements[i]; }
    //void maths::mat2::operator=(const mat2 & n) { for (int i = 0; i < 2; i++) this->elements[i] = n.elements[i]; }
    //float2 & maths::mat2::operator[](const int index) { return this->elements[index]; }
    //const float2 & maths::mat2::operator[](const int index) const { return this->elements[index]; }

// ** Method Definitions *************************

    float2 maths::operator*(const mat2 & aa, const float2 & bb)
    {
        float2 result;
        result.x = aa.rows[0][0] * bb.x + aa.rows[1][0] * bb.y;
        result.y = aa.rows[0][1] * bb.x + aa.rows[1][1] * bb.y;
        return result;
    }
    maths::mat2 maths::operator*(const mat2 & aa, const mat2 & bb)
    {
        mat2 result(0);
        for (int y = 0; y < 2; y++)
            for (int x = 0; x < 2; x++)
                for (int i = 0; i < 2; i++) result.rows[y][x] += aa.rows[i][x] * bb.rows[y][i];
        return result;
    }
    bool maths::operator==(const mat2 & aa, const mat2 & bb)
    {
        for (int i = 0; i < 2; i++)
            if (aa.rows[i] != bb.rows[i]) return false;
        return true;
    }
    bool maths::operator!=(const mat2 & aa, const mat2 & bb)
    {
        for (int i = 0; i < 2; i++)
            if (aa.rows[i] != bb.rows[i]) return true;
        return false;
    }

// ***********************************************