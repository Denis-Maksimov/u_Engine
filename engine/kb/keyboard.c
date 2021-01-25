

#include <stdlib.h>
#include <stddef.h>
#include <u_hash.h>
#include "kb.h"

hash_table* root=0;


void key_push(int key, void(*cb)(void))
{
   root = addnode(root, key , cb);
}

void key_process(int key, int xx, int yy) 
{
    cb a=get_data_by_key(root, key);
    if(a){
        a();
    }
}


