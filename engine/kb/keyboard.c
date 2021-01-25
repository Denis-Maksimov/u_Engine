#include "kb.h"



void move_forward(engine* en,int x, int y){
    puts("fwd");
    en->deltaMove = 0.5f;
}
void move_backward(engine* en,int x, int y){
    en->deltaMove =-0.5f;
}

void rotate_left(engine* en,int x, int y)
{
    en->deltaAngle = -0.01f;
}
void rotate_right(engine* en,int x, int y)
{
    en->deltaAngle = -0.01f;
}

void rotate_stop(engine* en,int x, int y){
    en->deltaAngle = 0.0f;
}
void move_stop(engine* en,int x, int y){
    en->deltaMove = 0;
}







hash_table* ht_key[k_sum]={0};



void key_push(int key, cb _cb, enum k_type type)
{
   ht_key[type] = addnode(ht_key[type], key , _cb);
//    printf("%ld=?%ld",_cb ,get_data_by_key(ht_key[type], key));
}




static void key_process(int key, int xx, int yy, enum k_type type) 
{
    
    engine* en=engine_get_handle();

    cb a=get_data_by_key(ht_key[type], key);
    // printf("key %d\n",key);
    if(a){
        // puts("call");
        a(en ,key, xx, yy);
    }
}


void init_key_funcs()
{
    key_push(GLUT_KEY_LEFT,  rotate_left, k_press);
    key_push(GLUT_KEY_RIGHT, rotate_right, k_press);
    key_push(GLUT_KEY_UP,    move_stop,   k_press);
    key_push(GLUT_KEY_DOWN,  move_stop,   k_press);

    key_push(GLUT_KEY_LEFT,  rotate_stop, k_release);
    key_push(GLUT_KEY_RIGHT, rotate_stop, k_release);
    key_push(GLUT_KEY_UP,    move_stop,   k_release);
    key_push(GLUT_KEY_DOWN,  move_stop,   k_release);

}






void pressKey(int key, int x, int y) 
{
        
        engine* en=engine_get_handle();
        key_process(key, x, y, k_press);
	
}
 
void releaseKey(int key, int x, int y) 
{
        engine* en=engine_get_handle();
        key_process(key, x, y, k_press);
	
}

void keyboard_init()
{
    //назначаем клавиши
    init_key_funcs();
    //регистрируем обработчики
    glutSpecialFunc(pressKey);		
	glutIgnoreKeyRepeat(1);
	glutSpecialUpFunc(releaseKey);	
}


