#include "vector3D.h"
#include <math.h>
vector3D::vector3D(float xv, float yv,float zv){
	x = xv;
	y = yv;
	z = zv;
}
float vector3D::modulo(){
	return (float)sqrt(x*x + y*y+z*z);
}
vector3D vector3D::unitario(){
	vector3D retorno(x, y,z);
	float mod = modulo();
	if (mod > 0.00001){
		retorno.x /= mod;
		retorno.y /= mod;
		retorno.z /= mod;
	}
	return retorno;
}
float vector3D::operator *(vector3D v) {
	float a = x * v.x + y * v.y+z*v.z;
	return a;
}
vector3D vector3D:: operator *(float a) {
	vector3D v(x * a, y * a,z*a);
	return v;
}
vector3D vector3D::operator - (vector3D v) {
	vector3D res;
	res.x = x - v.x;
	res.y = y - v.y;
	res.z = z - v.z;
	return res;
}
vector3D vector3D::operator + (vector3D v) {
	vector3D res;
	res.x = x + v.x;
	res.y = y + v.y;
	res.z = z + v.z;
	return res;
}

vector3D vector3D:: operator /(float a) {
	vector3D v(x / a, y / a, z / a);
	return v;
}