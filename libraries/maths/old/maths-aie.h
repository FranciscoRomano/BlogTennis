#pragma once

#include <cmath>
#include "maths.h"

namespace maths
{
    struct Vector2 : public vec2
    {
        inline Vector2() : vec2() {};
        inline Vector2(float n) : vec2(n) {};
        inline Vector2(const vec2 & n) : vec2(n) {};
        inline Vector2(const Vector2 & n) : vec2(n) {};
        inline Vector2(float x, float y) : vec2(x, y) {};
        // Vector 2 :: maths methods
        inline void normalise() {
            float length = this->magnitude();
            this->x /= length;
            this->y /= length;
        };
        inline float dot(const Vector2 & n) { return maths::dot(*this, n); }
        inline float magnitude() { return std::sqrt(maths::dot(*this, *this)); }
        // Vector 2 :: operator overloading
        inline operator float*() { return &this->x; }
        inline void operator=(const vec2 & n) { this->x = n.x, this->y = n.y; }
        inline void operator=(const Vector2 & n) { this->x = n.x, this->y = n.y; }
        inline float & operator[](const int index) { return operator float *()[index]; }
    };

    struct Vector3 : public vec3
    {
        inline Vector3() : vec3(0) {};
        inline Vector3(float n) : vec3(n) {};
        inline Vector3(const vec3 & n) : vec3(n) {};
        inline Vector3(const Vector3 & n) : vec3(n) {};
        inline Vector3(float x, float y, float z) : vec3(x, y, z) {};
        // Vector 3 :: maths methods
        inline void normalise() {
            float length = this->magnitude();
            this->x /= length;
            this->y /= length;
            this->z /= length;
        };
        inline vec3 cross(const Vector3 & n) { return maths::cross(*this, n); }
        inline float dot(const Vector3 & n) { return maths::dot(*this, n); }
        inline float magnitude() { return std::sqrt(maths::dot(*this, *this)); }
        // Vector 3 :: operator overloading
        inline operator float*() { return &this->x; }
        inline void operator=(const vec3 & n) { this->x = n.x, this->y = n.y, this->z = n.z; }
        inline void operator=(const Vector3 & n) { this->x = n.x, this->y = n.y, this->z = n.z; }
        inline float & operator[](const int index) { return operator float *()[index]; }
    };

    struct Vector4 : public vec4
    {
        inline Vector4() : vec4() {};
        inline Vector4(float n) : vec4(n) {};
        inline Vector4(const vec4 & n) : vec4(n) {};
        inline Vector4(const Vector4 & n) : vec4(n) {};
        inline Vector4(float x, float y, float z, float w) : vec4(x, y, z, w) {};
        // Vector 4 :: maths methods
        inline void normalise() {
            float length = this->magnitude();
            this->x /= length;
            this->y /= length;
            this->z /= length;
            this->w /= length;
        };
        inline float dot(const Vector4 & n) { return maths::dot(*this, n); }
        inline float magnitude() { return std::sqrt(maths::dot(*this, *this)); }
        // Vector 4 :: operator overloading
        inline operator float*() { return &this->x; }
        inline void operator=(const vec4 & n) { this->x = n.x, this->y = n.y, this->z = n.z, this->w = n.w; }
        inline void operator=(const Vector4 & n) { this->x = n.x, this->y = n.y, this->z = n.z, this->w = n.w; }
        inline float & operator[](const int index) { return operator float *()[index]; }
    };

    struct Matrix2 : public mat2
    {
        int size = 4;
        inline Matrix2() : mat2() {};
        inline Matrix2(float n) : mat2(n) {};
        inline Matrix2(const mat2 & n) : mat2(n) {};
        inline Matrix2(const Matrix2 & n) : mat2(n) {};
        inline Matrix2(float n1, float n2, float n3, float n4) {            
            this->elements[0] = vec2(n1, n2);
            this->elements[1] = vec2(n3, n4);
        };
        // Matrix 2 :: operator overloading
        inline void setRotate(float angle) {
            this->elements[0] = vec2(std::cos(angle), std::sin(angle));
            this->elements[1] = vec2(-std::sin(angle), std::cos(angle));
        }
        inline operator float*() { return &this->elements[0][0]; }
        inline vec2 & operator[](const int index) { return this->elements[index]; }
        inline void operator=(const mat2 & n) { for (int i = 0; i < 2; i++) this->elements[i] = n.elements[i]; }
        inline void operator=(const Matrix2 & n) { for (int i = 0; i < 2; i++) this->elements[i] = n.elements[i]; }
    };

    struct Matrix3 : public mat3
    {
        inline Matrix3() : mat3() {};
        inline Matrix3(float n) : mat3(n) {};
        inline Matrix3(const mat3 & n) : mat3(n) {};
        inline Matrix3(const Matrix3 & n) : mat3(n) {};
        inline Matrix3(float n1, float n2, float n3, float n4, float n5, float n6, float n7, float n8, float n9) {
            this->elements[0] = vec3(n1, n2, n3);
            this->elements[1] = vec3(n4, n5, n6);
            this->elements[2] = vec3(n7, n8, n9);
        };
        // Matrix 3 :: operator overloading
        inline void setRotateX(float angle) {
            mat4 result = rotate(vec3(1, 0, 0), angle);
            this->elements[0] = vec3(result[0].x, result[0].y, result[0].z);
            this->elements[1] = vec3(result[1].x, result[1].y, result[1].z);
            this->elements[2] = vec3(result[2].x, result[2].y, result[2].z);
        }
        inline void setRotateY(float angle) {
            mat4 result = rotate(vec3(0, 1, 0), angle);
            this->elements[0] = vec3(result[0].x, result[0].y, result[0].z);
            this->elements[1] = vec3(result[1].x, result[1].y, result[1].z);
            this->elements[2] = vec3(result[2].x, result[2].y, result[2].z);
        }
        inline void setRotateZ(float angle) {
            mat4 result = rotate(vec3(0, 0, 1), angle);
            this->elements[0] = vec3(result[0].x, result[0].y, result[0].z);
            this->elements[1] = vec3(result[1].x, result[1].y, result[1].z);
            this->elements[2] = vec3(result[2].x, result[2].y, result[2].z);
        }
        inline operator float*() { return &this->elements[0][0]; }
        inline vec3 & operator[](const int index) { return this->elements[index]; }
        inline void operator=(const mat3 & n) { for (int i = 0; i < 3; i++) this->elements[i] = n.elements[i]; }
        inline void operator=(const Matrix3 & n) { for (int i = 0; i < 3; i++) this->elements[i] = n.elements[i]; }
    };

    struct Matrix4 : public mat4
    {
        inline Matrix4() : mat4() {};
        inline Matrix4(float n) : mat4(n) {};
        inline Matrix4(const mat4 & n) : mat4(n) {};
        inline Matrix4(const Matrix4 & n) : mat4(n) {};
        inline Matrix4(float n1, float n2, float n3, float n4, float n5, float n6, float n7, float n8, float n9, float n10, float n11, float n12, float n13, float n14, float n15, float n16) {
            this->elements[0] = vec4( n1,  n2,  n3,  n4);
            this->elements[1] = vec4( n5,  n6,  n7,  n8);
            this->elements[2] = vec4( n9, n10, n11, n12);
            this->elements[3] = vec4(n13, n14, n15, n16);
        };
        // Matrix 4 :: operator overloading
        inline void setRotateX(float angle) {
            mat4 result = rotate(vec3(1, 0, 0), angle);
            this->elements[0] = result[0];
            this->elements[1] = result[1];
            this->elements[2] = result[2];
            this->elements[3] = result[3];
        }
        inline void setRotateY(float angle) {
            mat4 result = rotate(vec3(0, 1, 0), angle);
            this->elements[0] = result[0];
            this->elements[1] = result[1];
            this->elements[2] = result[2];
            this->elements[3] = result[3];
        }
        inline void setRotateZ(float angle) {
            mat4 result = rotate(vec3(0, 0, 1), angle);
            this->elements[0] = result[0];
            this->elements[1] = result[1];
            this->elements[2] = result[2];
            this->elements[3] = result[3];
        }
        inline operator float*() { return &this->elements[0][0]; }
        inline vec4 & operator[](const int index) { return this->elements[index]; }
        inline void operator=(const mat4 & n) { for (int i = 0; i < 4; i++) this->elements[i] = n.elements[i]; }
        inline void operator=(const Matrix4 & n) { for (int i = 0; i < 4; i++) this->elements[i] = n.elements[i]; }
    };

}