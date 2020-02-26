#pragma once
/** Dependencies **********************************************************************************/

#include <maths/maths.h>

typedef enum CommandType {
    COMMAND_TYPE_LINE,
    COMMAND_TYPE_POINT,
    COMMAND_TYPE_TRIANGLE
} CommandType;

typedef struct CommandData {
    float3 coord;
    float4 color;
} CommandData;

template<CommandType T> struct Command;

/** Declarations **********************************************************************************/

// COMMAND_TYPE_LINE
template<> struct Command<COMMAND_TYPE_LINE> { CommandData a, b; };

// COMMAND_TYPE_POINT
template<> struct Command<COMMAND_TYPE_POINT> { CommandData a; };

// COMMAND_TYPE_TRIANGLE
template<> struct Command<COMMAND_TYPE_TRIANGLE> { CommandData a, b, c; };




template<typename T> void swap(T& a, T& b) { static T c; c = a; a = b; b = c; };

/**************************************************************************************************/