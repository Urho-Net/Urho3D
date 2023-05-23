//
// Struct defines that we use to cast blittable classes,
// so that the C++ compiler will return a value that our P/Invoke
// layer can consume
//

#ifndef URHO_INTEROP_H
#define URHO_INTEROP_H

typedef struct IntVector2
{
    int x, y;
}IntVector2;

typedef struct Vector2
{
    float x, y;
}Vector2;

typedef struct Vector3
{
    float x, y, z;
}Vector3;

typedef struct IntVector3
{
    int x, y, z;
}IntVector3;

typedef struct Vector4
{
    float x, y, z, w;
}Vector4;

typedef struct Quaternion
{
    float w, x, y, z;
}Quaternion;

typedef struct Color
{
    float r, g, b, a;
}Color;

typedef struct Rect
{
    Vector2 min;
    Vector2 max;
}Rect;

typedef struct IntRect
{
    int left, top, right, bottom;
}IntRect;

typedef struct BoundingBox
{
    Vector3 min, max;
    int defined; // TBD ELI changed from bool to int
}BoundingBox;

typedef struct Plane
{
    Vector3 normal, absNormal;
    float d;
}Plane;

typedef struct Matrix3
{
    float m00;
    float m01;
    float m02;
    float m10;
    float m11;
    float m12;
    float m20;
    float m21;
    float m22;
}Matrix3;

typedef struct Matrix3x4
{
    float m00;
    float m01;
    float m02;
    float m03;
    float m10;
    float m11;
    float m12;
    float m13;
    float m20;
    float m21;
    float m22;
    float m23;
};

typedef struct Matrix4
{
    float m00;
    float m01;
    float m02;
    float m03;
    float m10;
    float m11;
    float m12;
    float m13;
    float m20;
    float m21;
    float m22;
    float m23;
    float m30;
    float m31;
    float m32;
    float m33;
}Matrix3x4;

#endif
