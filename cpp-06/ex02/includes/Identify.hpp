#pragma once
#include "Base.hpp"

class Identifier
{
public:
	static Base *generate();
	static void identify(Base *p);
	static void identify(Base &p);
};
