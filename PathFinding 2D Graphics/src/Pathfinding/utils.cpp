#include "utils.h"

bool v2i16::operator==(const v2i16& other) const
{
	if ((x == other.x) and (y == other.y))
	{
		return true;
	}

	return false;
}

bool v2i16::operator!=(const v2i16& other) const
{
	if ((x != other.x) or (y != other.y))
	{
		return true;
	}

	return false;
}
