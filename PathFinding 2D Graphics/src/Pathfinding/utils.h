#pragma once
#include <conio.h>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

using i8 = char;
using i16 = short;
using i32 = int;

using ui8 = unsigned char;
using ui16 = unsigned short;
using ui32 = unsigned int;

using f32 = float;

#define RED_WRITE "\x1b[31m"
#define BLUE_WRITE "\x1b[34m"
#define WHITE_WRITE "\x1b[37m"

#define BLACK_BG "\x1b[40m"
#define GREEN_BG "\x1b[42m"

std::random_device rd;
std::mt19937 gen(rd());

class v2i16
{
	public:
		i16 x;
		i16 y;

		bool operator==(const v2i16& other) const;
		bool operator!=(const v2i16& other) const;
};

