#ifndef __KB_H__
#define __KB_H__


typedef void(*cb)(void);

void key_push(int key, void(*cb)(void));
void key_process(int key, int xx, int yy) ;


#endif // __KB_H__