#ifndef _ANIMAL_H_
#define _ANIMAL_H_
typedef struct animal_s_ animal_t;
typedef struct animal_ops_s_ animal_ops_t;

struct animal_s_
{
	char *name;
	animal_ops_t *animal_ops;
};

struct animal_ops_s_
{
	void (*eat)(char *food);
	void (*walk)(int steps);
	void (*talk)(char *msg);
};
animal_t* animal_init(const char *name);

void animal_eat(animal_t *animal,char *food);
void animal_walk(animal_t *animal,int steps);
void animal_talk(animal_t *animal,char *msg);

void animal_die(animal_t *animal);

#endif
