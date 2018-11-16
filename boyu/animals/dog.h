#include"animal_base.h"

typedef struct dog_s_ dog_t;

struct dog_s_
{
	animal_t base;

    char *owner;
	void (*hunt)(const char *rabbit);
};

dog_t *dog_init();
void dog_die(dog_t *dog);
