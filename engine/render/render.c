#include "render.h"




inline void render_init()
{
    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);
}


void drawSnowMan() 
{
 	glColor3f(1.0f, 1.0f, 1.0f);
 	// тело снеговика
	glTranslatef(0.0f ,0.75f, 0.0f);
	glutSolidSphere(0.75f,20,20);
 	// голова снеговика
	glTranslatef(0.0f, 1.0f, 0.0f);
	glutSolidSphere(0.25f,20,20);
	// глаза снеговика
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0.05f, 0.10f, 0.18f);
	glutSolidSphere(0.05f,10,10);
	glTranslatef(-0.1f, 0.0f, 0.0f);
	glutSolidSphere(0.05f,10,10);
	glPopMatrix();
	// нос снеговика
	glColor3f(1.0f, 0.5f , 0.5f);
	glRotatef(0.0f,1.0f, 0.0f, 0.0f);
	glutSolidCone(0.08f,0.5f,10,2);
}

void renderScene()
{

    engine* en=engine_get_handle();
    // glutSetWindow();
	if (en->deltaMove)
		computePos();
	if (en->deltaAngle)
		computeDir();
	//очистить буфер цвета и глубины
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// обнулить трансформацию
	glLoadIdentity();
	// установить камеру
	gluLookAt(	   en->x,	1.0f,	  en->z,
				en->x+en->lx,	1.0f,  en->z+en->lz,
				0.0f,   1.0f,  0.0f		);
	// нарисуем "землю"
	glColor3f(0.9f, 0.9f, 0.9f);
	glBegin(GL_QUADS);// полигон с коондинатами
		glVertex3f(-100.0f, 0.0f, -100.0f);
		glVertex3f(-100.0f, 0.0f,  100.0f);
		glVertex3f( 100.0f, 0.0f,  100.0f);
		glVertex3f( 100.0f, 0.0f, -100.0f);
	glEnd();
	// Нарисуем 64 снеговика
	for (int i = -4; i < 4; i++)
		for (int j=-4; j < 4; j++)
		{
			glPushMatrix();
			glTranslatef(i*5.0, 0, j * 5.0);
			drawSnowMan();
			glPopMatrix();
		}
 
	glutSwapBuffers();
}
