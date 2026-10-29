#pragma once

#include <iostream>
#include <vector>

#define RED_WRITE "\033[31m"
#define YELLOW_WRITE "\033[33m"
#define BLUE_WRITE "\033[34m"
#define WHITE_WRITE "\033[37m"

#define BLACK_BG "\033[40m"
#define GREEN_BG "\033[42m"

#define DEFAULT "\033[0m"

using namespace std;

using i8 = char;
using i16 = short;
using i32 = int;

using f32 = float;

class v2i16
{
public:
    i16 x;
    i16 y;

    bool operator==(const v2i16& other) const;
    bool operator!=(const v2i16& other) const;
};
