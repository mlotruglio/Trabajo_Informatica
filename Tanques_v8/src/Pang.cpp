#include "freeglut.h"
#include <math.h>
#include "mundo.h"
#include <stdlib.h>
#include "CoordinaJuegos.h"
#define framerate 60.0
CoordinaJuegos Control;
//mundo mundial;

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
	glutTimerFunc(1000/framerate,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
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
	Control.dibuja();
	glutSwapBuffers();
}
void OnTimer(int value){
	Control.refresh();
	glutTimerFunc(1000/framerate,OnTimer,0);
	glutPostRedisplay();
}

void onkeyup(unsigned char key, int x, int y) {
	Control.key(key,x,y,false);
}
void onkeydown(unsigned char key, int x, int y) {
	Control.key(key,x,y,true);
}
void mousepasivemotion(int x, int y) {
	Control.mousemotion(x,y);
}
void mousemotion(int button, int state, int x, int y) {
	Control.mousemotion(x,y);
	Control.mouseclick(button, state);
}