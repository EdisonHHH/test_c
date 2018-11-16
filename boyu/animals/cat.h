#include"animal_base.h"

typedef struct cat_s_ cat_t;

struct cat_s_
{
	animal_t base;

    //char *owner;
	//void (*hunt)(const char *rabbit);
};

cat_t *cat_init();
void cat_die(cat_t *cat);
