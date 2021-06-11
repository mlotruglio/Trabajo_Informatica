#include "freeglut.h"
#include <math.h>
#include "mundo.h"
#include <stdlib.h>
#include "draw.h"
mundo mundial;
void dibujaejes(float size);
void OnDraw(void);
void OnTimer(int value);
void onkeyup(unsigned char key, int x, int y);
void onkeydown(unsigned char key, int x, int y);
void mousepasivemotion(int x, int y);
void mousemotion(int button,int state,int x, int y);
void main(int argc,char* argv[]){
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");
	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, 800/600.0f, 0.1, 150);
	//Registrar los callbacks
	glutPassiveMotionFunc(mousepasivemotion);
	glutMotionFunc(mousepasivemotion);
	glutDisplayFunc(OnDraw);
	glutTimerFunc(16,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(onkeydown);
	glutKeyboardUpFunc(onkeyup);
	glutMouseFunc(mousemotion);
	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();	
}
void OnDraw(void){
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	mundial.draw();
	dibujaejes(2);
	glutSwapBuffers();
}
void OnTimer(int value){
	mundial.refresh();
	glutTimerFunc(16,OnTimer,0);
	glutPostRedisplay();
}
void dibujaejes(float size) {
	glColor3ub(255, 255, 255);
	glutSolidCube(0.1 * size);
	glTranslatef(0, 0, size);
	glColor3ub(0, 255, 0);
	glutSolidCube(0.1 * size);
	glTranslatef(0, size, -size);
	glColor3ub(0, 0, 255);
	glutSolidCube(0.1 * size);
	glTranslatef(size, -size, 0);
	glColor3ub(255, 0, 0);
	glutSolidCube(0.1 * size);
	glTranslatef(-size, 0, 0);
	glColor3ub(255, 255, 255);
}
void onkeyup(unsigned char key, int x, int y) {
	mundial.key(key,x,y,false);
}
void onkeydown(unsigned char key, int x, int y) {
	mundial.key(key,x,y,true);
}
void mousepasivemotion(int x, int y) {
	mundial.mousemotion(x,y);
}
void mousemotion(int button, int state, int x, int y) {
	mundial.mousemotion(x,y);
	mundial.mouseclick(button, state);
}