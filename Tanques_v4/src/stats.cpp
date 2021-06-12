#include "stats.h"
stats::stats() {
	health = 0;
	armor = 0;
	speed = 1;
	damage = 1;
}
stats stats::operator + (stats stats2) {
	stats stats1;
	stats1.health =health+ stats2.health;
	stats1.armor =armor+ stats2.armor;
	stats1.speed = speed*stats2.speed;
	stats1.damage = damage*stats2.damage;
	return stats1;
}
void stats::sethealth(float h) {
	health = h;
}
void stats::setarmor(float a) {
	armor = a;
}
void stats::setspeed(float s) {
	speed = s;
}
void stats::setdamage(float d) {
	damage = d;
}