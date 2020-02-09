/** Dependencies **********************************************************************************/

#include "maths.h"

/** Declarations **********************************************************************************/

void assert(const float2& a, const float& x, const float& y)
{
    if (a[0] != x || a[1] != y) throw "float2 error!";
}

void assert(const float3& a, const float& x, const float& y, const float& z)
{
    if (a[0] != x || a[1] != y || a[2] != z) throw "float3 error!";
}

void assert(const float4& a, const float& x, const float& y, const float& z, const float& w)
{
    if (a[0] != x || a[1] != y || a[2] != z || a[3] != w) throw "float4 error!";
}

void test_float2()
{
    // test 1
    {
        float2 a{};
        assert(a, 0, 0);

        float2 b{ 1 };
        assert(b, 1, 1);

        float2 c{ (float*)b };
        assert(c, 1, 1);

        float2 d{ float2{ 2, 3 } };
        assert(d, 2, 3);
    }
    // test 2
    {
        float2 a{ 1, 2 };

        float2 e{ a.x };
        assert(e, 1, 1);

        float2 f{ a.xy };
        assert(f, 1, 2);

        float2 g{ a.x, 4 };
        assert(g, 1, 4);

        float2 h{ 5, a.y };
        assert(h, 5, 2);

        float2 i{ a.x, a.y };
        assert(i, 1, 2);
    }
};

void test_float3()
{
    // test 1
    {
        float3 a{};
        assert(a, 0, 0, 0);

        float3 b{ 1 };
        assert(b, 1, 1, 1);

        float3 c{ (float*)b };
        assert(c, 1, 1, 1);

        float3 d{ float3{ 2, 3, 4 } };
        assert(d, 2, 3, 4);

        float3 e{ float2{ 5, 6 }, 7 };
        assert(e, 5, 6, 7);

        float3 f{ 8, float2{ 9, 10 } };
        assert(f, 8, 9, 10);
    }
    // test 2
    {
        float3 a{ 1, 2, 3 };

        float3 b{ a.x };
        assert(b, 1, 1, 1);
        
        float3 c{ a.xyz };
        assert(c, 1, 2, 3);
        
        float3 d{ a.xy, 5 };
        assert(d, 1, 2, 5);
        
        float3 e{ 6, a.yz };
        assert(e, 6, 2, 3);
        
        float3 f{ a.xy, a.z };
        assert(f, 1, 2, 3);

        float3 g{ a.x, a.yz };
        assert(g, 1, 2, 3);
    }
};

void test_float4()
{
    // test 1
    {
        float4 a{};
        assert(a, 0, 0, 0, 0);

        float4 b{ 1 };
        assert(b, 1, 1, 1, 1);

        float4 c{ (float*)b };
        assert(c, 1, 1, 1, 1);

        float4 d{ float4{ 2, 3, 4, 5 } };
        assert(d, 2, 3, 4, 5);

        float4 e{ float3{ 6, 7, 8 }, 9 };
        assert(e, 6, 7, 8, 9);

        float4 f{ 10, float3{ 11, 12, 13 } };
        assert(f, 10, 11, 12, 13);

        float4 g{ float2{ 18, 19 }, 20, 21 };
        assert(g, 18, 19, 20, 21);

        float4 h{ 22, 23, float2{ 24, 25 } };
        assert(h, 22, 23, 24, 25);

        float4 i{ float2{ 14, 15 }, float2{ 16, 17 } };
        assert(i, 14, 15, 16, 17);
    }
    // test 2
    {
        float4 a{ 1, 2, 3, 4 };

        float4 b{ a.x };
        assert(b, 1, 1, 1, 1);

        float4 c{ a.xyzw };
        assert(c, 1, 2, 3, 4);

        float4 d{ a.xyz, 10 };
        assert(d, 1, 2, 3, 10);

        float4 e{ 11, a.yzw };
        assert(e, 11, 2, 3, 4);

        float4 f{ a.xyz, a.w };
        assert(f, 1, 2, 3, 4);

        float4 g{ a.x, a.yzw };
        assert(g, 1, 2, 3, 4);

        float4 h{ a.xy, a.zw };
        assert(h, 1, 2, 3, 4);

        float4 i{ a.xy, 12, 13 };
        assert(i, 1, 2, 12, 13);

        float4 j{ 14, 15, a.zw };
        assert(j, 14, 15, 3, 4);
    }
};

int main()
{
    int float2_size = sizeof(float2);
    int float3_size = sizeof(float3);
    int float4_size = sizeof(float4);

    test_float2();
    test_float3();
    test_float4();

    int z = 0;
};

/**************************************************************************************************/