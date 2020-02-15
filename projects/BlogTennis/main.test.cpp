/** Dependencies **********************************************************************************/

#include "maths.h"

/** Declarations **********************************************************************************/

template<typename T, unsigned int S>
void assert(const T* a, const T(&b)[S])
{
    unsigned int i;
    for (i = 0; i < S && a[i] == b[i]; i++);
    if (i != S) throw "assert error";
}

//void assert<float, >(const float2& a, const float& x, const float& y)
//{
//    if (a[0] != x || a[1] != y) throw "float2 error!";
//}
//
//void assert<float, >(const float3& a, const float& x, const float& y, const float& z)
//{
//    if (a[0] != x || a[1] != y || a[2] != z) throw "float3 error!";
//}
//
//void assert<float, >(const float4& a, const float& x, const float& y, const float& z, const float& w)
//{
//    if (a[0] != x || a[1] != y || a[2] != z || a[3] != w) throw "float4 error!";
//}

void test_float2()
{
    if (sizeof(float2) != (2 * 4)) throw "float2 :: invalid size!";

    // test 1
    {
        float2 a{};
        assert<float, 2>(a, { 0, 0 });

        float2 b{ 1 };
        assert<float, 2>(b, { 1, 1 });

        float2 d{ float2{ 2, 3 } };
        assert<float, 2>(d, { 2, 3 });
    }
    // test 2
    {
        float2 a{ 1, 2 };

        float2 e{ a.x };
        assert<float, 2>(e, { 1, 1 });

        float2 f{ a.xy };
        assert<float, 2>(f, { 1, 2 });

        float2 g{ a.x, 4 };
        assert<float, 2>(g, { 1, 4 });

        float2 h{ 5, a.y };
        assert<float, 2>(h, { 5, 2 });

        float2 i{ a.x, a.y };
        assert<float, 2>(i, { 1, 2 });
    }
};

void test_float2x2()
{
    if (sizeof(float2x2) != (2 * 2 * 4)) throw "float2x2 :: invalid size!";

    float2x2 a{};
    assert<float, 4>(a, { 0, 0, 0, 0 });

    float2x2 b{ 1 };
    assert<float, 4>(b, { 1, 1, 1, 1 });

    float2x2 c{ a };
    assert<float, 4>(c, { 0, 0, 0, 0 });

    float2x2 d{ float2{ 1, 2 }, float2{ 3, 4 } };
    assert<float, 4>(d, { 1, 2, 3, 4 });

    float2x2 e{ 1, 2, 3, 4 };
    assert<float, 4>(e, { 1, 2, 3, 4 });
};

void test_float2x3()
{
    if (sizeof(float2x3) != (2 * 3 * 4)) throw "float2x3 :: invalid size!";

    float2x3 a{};
    assert<float, 6>(a, { 0, 0, 0, 0, 0, 0 });

    float2x3 b{ 1 };
    assert<float, 6>(b, { 1, 1, 1, 1, 1, 1 });

    float2x3 c{ a };
    assert<float, 6>(c, { 0, 0, 0, 0, 0, 0 });

    float2x3 d{ float3{ 1, 2, 3 }, float3{ 4, 5, 6 } };
    assert<float, 6>(d, { 1, 4, 2, 5, 3, 6 });

    float2x3 e{ float2{ 1, 2 }, float2{ 3, 4 }, float2{ 5, 6 } };
    assert<float, 6>(e, { 1, 2, 3, 4, 5, 6 });

    float2x3 f{ 1, 2, 3, 4, 5, 6 };
    assert<float, 6>(f, { 1, 2, 3, 4, 5, 6 });
};

void test_float2x4()
{
    if (sizeof(float2x4) != (2 * 4 * 4)) throw "float2x4 :: invalid size!";

    float2x4 a{};
    assert<float, 8>(a, { 0, 0, 0, 0, 0, 0, 0, 0 });

    float2x4 b{ 1 };
    assert<float, 8>(b, { 1, 1, 1, 1, 1, 1, 1, 1 });

    float2x4 c{ a };
    assert<float, 8>(c, { 0, 0, 0, 0, 0, 0, 0, 0 });

    float2x4 d{ float4{ 1, 2, 3, 4 }, float4{ 5, 6, 7, 8 } };
    assert<float, 8>(d, { 1, 5, 2, 6, 3, 7, 4, 8 });

    float2x4 e{ float2{ 1, 2 }, float2{ 3, 4 }, float2{ 5, 6 }, float2{ 7, 8 } };
    assert<float, 8>(e, { 1, 2, 3, 4, 5, 6, 7, 8 });

    float2x4 f{ 1, 2, 3, 4, 5, 6, 7, 8 };
    assert<float, 8>(f, { 1, 2, 3, 4, 5, 6, 7, 8 });
}

void test_float3()
{
    if (sizeof(float3) != (3 * 4)) throw "float3 :: invalid size!";

    // test 1
    {
        float3 a{};
        assert<float, 3>(a, { 0, 0, 0 });

        float3 b{ 1 };
        assert<float, 3>(b, { 1, 1, 1 });

        float3 d{ float3{ 2, 3, 4 } };
        assert<float, 3>(d, { 2, 3, 4 });

        float3 e{ float2{ 5, 6 }, 7 };
        assert<float, 3>(e, { 5, 6, 7 });

        float3 f{ 8, float2{ 9, 10 } };
        assert<float, 3>(f, { 8, 9, 10 });
    }
    // test 2
    {
        float3 a{ 1, 2, 3 };

        float3 b{ a.x };
        assert<float, 3>(b, { 1, 1, 1 });
        
        float3 c{ a.xyz };
        assert<float, 3>(c, { 1, 2, 3 });
        
        float3 d{ a.xy, 5 };
        assert<float, 3>(d, { 1, 2, 5 });
        
        float3 e{ 6, a.yz };
        assert<float, 3>(e, { 6, 2, 3 });
        
        float3 f{ a.xy, a.z };
        assert<float, 3>(f, { 1, 2, 3 });

        float3 g{ a.x, a.yz };
        assert<float, 3>(g, { 1, 2, 3 });
    }
};

void test_float3x2()
{
    if (sizeof(float3x2) != (3 * 2 * 4)) throw "float3x2 :: invalid size!";

    float3x2 a{};
    assert<float, 6>(a, { 0, 0, 0, 0, 0, 0 });

    float3x2 b{ 1 };
    assert<float, 6>(b, { 1, 1, 1, 1, 1, 1 });

    float3x2 c{ a };
    assert<float, 6>(c, { 0, 0, 0, 0, 0, 0 });

    float3x2 d{ float3{ 1, 2, 3 }, float3{ 4, 5, 6 } };
    assert<float, 6>(d, { 1, 2, 3, 4, 5, 6 });

    float3x2 e{ float2{ 1, 2 }, float2{ 3, 4 }, float2{ 5, 6 } };
    assert<float, 6>(e, { 1, 3, 5, 2, 4, 6 });

    float3x2 f{ 1, 2, 3, 4, 5, 6 };
    assert<float, 6>(f, { 1, 2, 3, 4, 5, 6 });
};

void test_float3x4()
{
    if (sizeof(float3x4) != (3 * 4 * 4)) throw "float3x4 :: invalid size!";

    float3x4 a{};
    assert<float, 12>(a, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });

    float3x4 b{ 1 };
    assert<float, 12>(b, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 });

    float3x4 c{ a };
    assert<float, 12>(c, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });

    float3x4 d{ float4{ 1, 2, 3, 4 }, float4{ 5, 6, 7, 8 }, float4{ 9, 10, 11, 12 } };
    assert<float, 12>(d, { 1, 5, 9, 2, 6, 10, 3, 7, 11, 4, 8, 12 });

    float3x4 e{ float3{ 1, 2, 3 }, float3{ 4, 5, 6 }, float3{ 7, 8, 9 }, float3{ 10, 11, 12 } };
    assert<float, 12>(e, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 });

    float3x4 f{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    assert<float, 12>(f, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 });
}

void test_float4()
{
    if (sizeof(float4) != (4 * 4)) throw "float4 :: invalid size!";

    // test 1
    {
        float4 a{};
        assert<float, 4>(a, { 0, 0, 0, 0 });

        float4 b{ 1 };
        assert<float, 4>(b, { 1, 1, 1, 1 });

        float4 d{ float4{ 2, 3, 4, 5 } };
        assert<float, 4>(d, { 2, 3, 4, 5 });

        float4 e{ float3{ 6, 7, 8 }, 9 };
        assert<float, 4>(e, { 6, 7, 8, 9 });

        float4 f{ 10, float3{ 11, 12, 13 } };
        assert<float, 4>(f, { 10, 11, 12, 13 });

        float4 g{ float2{ 18, 19 }, 20, 21 };
        assert<float, 4>(g, { 18, 19, 20, 21 });

        float4 h{ 22, 23, float2{ 24, 25 } };
        assert<float, 4>(h, { 22, 23, 24, 25 });

        float4 i{ float2{ 14, 15 }, float2{ 16, 17 } };
        assert<float, 4>(i, { 14, 15, 16, 17 });
    }
    // test 2
    {
        float4 a{ 1, 2, 3, 4 };

        float4 b{ a.x };
        assert<float, 4>(b, { 1, 1, 1, 1 });

        float4 c{ a.xyzw };
        assert<float, 4>(c, { 1, 2, 3, 4 });

        float4 d{ a.xyz, 10 };
        assert<float, 4>(d, { 1, 2, 3, 10 });

        float4 e{ 11, a.yzw };
        assert<float, 4>(e, { 11, 2, 3, 4 });

        float4 f{ a.xyz, a.w };
        assert<float, 4>(f, { 1, 2, 3, 4 });

        float4 g{ a.x, a.yzw };
        assert<float, 4>(g, { 1, 2, 3, 4 });

        float4 h{ a.xy, a.zw };
        assert<float, 4>(h, { 1, 2, 3, 4 });

        float4 i{ a.xy, 12, 13 };
        assert<float, 4>(i, { 1, 2, 12, 13 });

        float4 j{ 14, 15, a.zw };
        assert<float, 4>(j, { 14, 15, 3, 4 });
    }
};

void test_float4x2()
{
    if (sizeof(float4x2) != (4 * 2 * 4)) throw "float4x2 :: invalid size!";

    float4x2 a{};
    assert<float, 8>(a, { 0, 0, 0, 0, 0, 0, 0, 0 });

    float4x2 b{ 1 };
    assert<float, 8>(b, { 1, 1, 1, 1, 1, 1, 1, 1 });

    float4x2 c{ a };
    assert<float, 8>(c, { 0, 0, 0, 0, 0, 0, 0, 0 });

    float4x2 d{ float4{ 1, 2, 3, 4 }, float4{ 5, 6, 7, 8 } };
    assert<float, 8>(d, { 1, 2, 3, 4, 5, 6, 7, 8 });

    float4x2 e{ float2{ 1, 2 }, float2{ 3, 4 }, float2{ 5, 6 }, float2{ 7, 8 } };
    assert<float, 8>(e, { 1, 3, 5, 7, 2, 4, 6, 8 });

    float4x2 f{ 1, 2, 3, 4, 5, 6, 7, 8 };
    assert<float, 8>(f, { 1, 2, 3, 4, 5, 6, 7, 8 });
}

void test_float4x3()
{
    if (sizeof(float4x3) != (4 * 3 * 4)) throw "float4x3 :: invalid size!";

    float4x3 a{};
    assert<float, 12>(a, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });

    float4x3 b{ 1 };
    assert<float, 12>(b, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 });

    float4x3 c{ a };
    assert<float, 12>(c, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });

    float4x3 d{ float4{ 1, 2, 3, 4 }, float4{ 5, 6, 7, 8 }, float4{ 9, 10, 11, 12 } };
    assert<float, 12>(d, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 });

    float4x3 e{ float3{ 1, 2, 3 }, float3{ 4, 5, 6 }, float3{ 7, 8, 9 }, float3{ 10, 11, 12 } };
    assert<float, 12>(e, { 1, 4, 7, 10, 2, 5, 8, 11, 3, 6, 9, 12 });

    float4x3 f{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    assert<float, 12>(f, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 });
}

int main()
{
    auto float2_size = sizeof(float2);
    auto float2x2_size = sizeof(float2x2);
    auto float2x3_size = sizeof(float2x3);
    auto float3_size = sizeof(float3);
    auto float3x2_size = sizeof(float3x2);
    auto float4_size = sizeof(float4);

    test_float2();
    test_float2x2();
    test_float2x3();
    test_float2x4();
    
    test_float3();
    test_float3x2();
    test_float3x4();

    test_float4();
    test_float4x2();
    test_float4x3();
};

/**************************************************************************************************/