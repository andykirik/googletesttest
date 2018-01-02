// class1.h
#pragma once

#include <common.h>

class Class1
{
public:
	Class1();
	bool IsOkay();
	void SetOkay(EAnswer answer);
private:
	EAnswer m_answer{ EAnswer::NO };
};