// #include "engine.hpp"

// GLvoid SetProjectionMatrix(GLvoid){
//       glMatrixMode(GL_PROJECTION);            // Действия будут производиться с матрицей проекции
//       glLoadIdentity();                       // Текущая матрица (проекции) сбрасывается на единичную
//       glFrustum(-1, 1, -1, 1, 3, 10);         // Устанавливается перспективная проекция
// }

// GLvoid SetModelviewMatrix(GLvoid){
//       glMatrixMode(GL_MODELVIEW);             // Действия будут производиться с матрицей модели
//       glLoadIdentity();                       // Текущая матрица (модели) сбрасывается на единичную
//       glTranslatef(0.0, 0.0, -8.0);           // Система координат переносится на 8 единиц вглубь сцены
//       glRotatef(30.0, 1.0, 0.0, 0.0);         // и поворачивается на 30 градусов вокруг оси x,
//       glRotatef(70.0, 0.0, 1.0, 0.0);         // а затем на 70 градусов вокруг оси y
// }

#include "engine.h"




engine u_this={
    .angle=0.0, 
    .lx=0.0f, .lz=-1.0f,
    .x=0.0f, .z=5.0f,
    .deltaAngle = 0.0f,
    .deltaMove = 0
    
    };

GLvoid reshape(int w, int h)
{
	// предотвращение деления на ноль
	if (h == 0)
		h = 1;
	float ratio =  w * 1.0 / h;
	// используем матрицу проекции
	glMatrixMode(GL_PROJECTION);
	// обнуляем матрицу
	glLoadIdentity();
	// установить параметры вьюпорта
	glViewport(0, 0, w, h);
	// установить корректную перспективу
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
	// вернуться к матрице проекции
	glMatrixMode(GL_MODELVIEW);

}

engine* engine_init()
{
	
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(400,400);
	glutCreateWindow("Урок 6");

    // u_this._pressKey=pressKey;
    // u_this._releaseKey=releaseKey;
    // u_this._reshape=reshape;
    // u_this._renderScene=renderScene;


      glClearColor(0.2f, 0.5f, 0.75f, 1.0f);               // Устанавливается синий фон
      glClearDepth(1.0f);                                  // Устанавливается значение для
                                                           // заполнения буфера глубины по умолчанию
      glEnable(GL_DEPTH_TEST);                             // Включается тест глубины
      glDepthFunc(GL_LEQUAL);                              // Устанавливается значение, используемое
                                                           // в сравнениях при использовании
                                                           // буфера глубины
 
      glShadeModel(GL_SMOOTH);                             // Включается плавное затенение
      glEnable(GL_LINE_SMOOTH);                            // Включается сглаживание линий
      glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);              // Выбирается самый качественный
                                                           // режим сглаживания для линий
      glEnable(GL_BLEND);                                  // Включается смешение цветов, необходимое
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);   // для работы сглаживания и задается
                                                           // способ смешения

	  // регистрация вызовов
	  render_init();
	glutReshapeFunc(reshape);
	glutSpecialFunc(pressKey);		
		// Новые функции для регистрации
	glutIgnoreKeyRepeat(1);
	glutSpecialUpFunc(releaseKey);	
	return &u_this;									
}
inline engine* engine_get_handle()
{
	return &u_this;
}



void pressKey(int key, int xx, int yy) 
{
 
	
		if (key==GLUT_KEY_LEFT)
			u_this.deltaAngle = -0.01f;
		if(key==GLUT_KEY_RIGHT)
			u_this.deltaAngle = 0.01f;
		if(key==GLUT_KEY_UP)
			u_this.deltaMove = 0.5f;
		if(key==GLUT_KEY_DOWN)
			u_this.deltaMove = -0.5f;
	
}
 
void releaseKey(int key, int x, int y) 
{
 
	
		if((key==GLUT_KEY_LEFT )||
		   (key==GLUT_KEY_RIGHT) )
			u_this.deltaAngle = 0.0f;
		if(key==GLUT_KEY_UP||
		    key==GLUT_KEY_DOWN) 
			u_this.deltaMove = 0;
        if(key==GLUT_KEY_F1) 
			u_this.deltaMove = 0;
	
}


void computePos() 
{
	u_this.x += u_this.deltaMove * u_this.lx * 0.1f;
	u_this.z += u_this.deltaMove * u_this.lz * 0.1f;
}
 
void computeDir()
{
	u_this.angle += u_this.deltaAngle;
	u_this.lx = sin(u_this.angle);
	u_this.lz = -cos(u_this.angle);
}
 

 