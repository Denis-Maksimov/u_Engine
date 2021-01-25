#include <engine.h>


int main(int argc, char **argv) {
 
	
	// инициализация GLUT и создание окна
	glutInit(&argc, argv);
	
	engine_init();
 
	// главный цикл
	glutMainLoop();
 
	return 1;
}

