#pragma once
class stats
{
public:
	stats();
	float health;
	float armor;
	float speed;
	float damage;
	stats operator + (stats);
	void sethealth(float);
	void setarmor(float);
	void setspeed(float);
	void setdamage(float);
};

