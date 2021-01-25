#ifndef __KB_H__
#define __KB_H__

#include <stdlib.h>
#include <u_std.h>
#include <engine.h>

// #ifdef __cplusplus
// extern "C"{
// #endif 


enum k_type{
    k_press=0,
    k_release,
    k_sum
};


void keyboard_init();

typedef void(*cb)(struct engine_t*, int, int, int);

void key_push(int key, cb _cb, enum k_type type);

// void key_process(int key, int xx, int yy) ;
// #ifdef __cplusplus
// }
// #endif // DEBUG

#endif // __KB_H__