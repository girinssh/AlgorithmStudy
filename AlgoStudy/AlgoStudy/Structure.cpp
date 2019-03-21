#include <iostream>
#include "pch.h"

template<typename T> class Structure {
public:
	virtual int Insert() = 0;
	virtual int Remove() = 0;
	
	virtual int Length() = 0;
	virtual int CheckRange() = 0;

	virtual void Print() = 0;
};