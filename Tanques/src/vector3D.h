#pragma once
class vector3D
{
public:
	//ATRIBUTOS 
	float x;
	float y;
	float z;
	//METODOS 
	vector3D(float xv=0 , float yv=0 ,float zv=0); // (1)constructor 
	float modulo(); // (2) modulo del vector 
	vector3D unitario(); // (4) devuelve un vector unitario 
	vector3D operator - (vector3D); // (5) resta de vectores 
	vector3D operator + (vector3D); // (6) suma de vectores 
	float operator *(vector3D); // (7) producto escalar 
	vector3D operator /(float ); //Division
	vector3D operator *(float); // (8) producto por un escalar 
};