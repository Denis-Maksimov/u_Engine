#ifndef __API__
#define __API__

#ifdef _WIN32


#include <windows.h>		// ������������ ���� ��� ������������� ������� Windows

#include <gl/gl.h>			// ������������ ���� ���������� opengl32
#include <gl/glu.h>			// ������������ ���� ���������� glu32
#include <gl/glaux.h>		// ������������ ���� ���������� glaux
#include <gl/glut.h>		// ������������ ���� ���������� glut32
#else // 

#ifdef __APPLE__
#include <freeglut.h>
#else
#include <GL/freeglut.h>
#endif
#endif


#include <stdlib.h>
#include <math.h>



#endif
