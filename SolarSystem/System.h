#pragma once
#include "Body.h"
#include <iostream>


class System
{
private:
	std::vector<Body*> bodies;
public:
	System();
	~System();
	void addBody(Body& body_);
	void action();
};

