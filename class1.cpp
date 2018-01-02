// class1.cpp
#include <class1.h>
#include <iostream>

Class1::Class1()
{
	//std::cout << "Class1:::Class1" << std::endl;
}

bool Class1::IsOkay()
{
	return EAnswer::YES == m_answer;
}

void Class1::SetOkay(EAnswer answer)
{
	m_answer = answer;
}