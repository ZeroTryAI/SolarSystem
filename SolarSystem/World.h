#pragma once
#include "Planet.h"
#include <vector>

class World
{
public:
	std::vector<Planet *> planet_arr;

	float elapsed_sec;

	void add_planet(Planet *p);

	void update_state(float time_step);

	void init();

private:
	void apply_gravitation_among_objects();
};