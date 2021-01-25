#ifndef __ENGINE_H__
#define __ENGINE_H__


#include "api.h"


#ifdef __cplusplus
extern "C"{
#endif 

struct engine_t{

	GLboolean init; //флаг инициализации
	//------------------------------------
    // угол поворота камеры
	float angle;
	// координаты вектора направления движения камеры
	float lx, lz;
	// XZ позиция камеры
	float x, z;
	//Ключи статуса камеры. Переменные инициализируются нулевыми значениями
	//когда клавиши не нажаты
	float deltaAngle;
	float deltaMove;
	GLsizei Height, Width;
    //-------------------------------------
    // GLvoid (*_reshape)(GLsizei width, GLsizei height);
	//  void (*_pressKey)(int key, int xx, int yy) ;
	//  void (*_releaseKey)(int key, int x, int y);	
	//  void (*_renderScene)(void);

};

#include "render/render.h"
#include "kb/kb.h"

typedef struct engine_t engine;

engine* engine_get_handle();



GLvoid reshape(int w, int h);
engine* engine_init();

// void pressKey(int key, int xx, int yy) ;
// void releaseKey(int key, int x, int y) ;

void renderScene();

#ifdef __cplusplus
}
#endif // DEBUG

#endif // __ENGINE_H__
