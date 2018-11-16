#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"cat.h"

static void cat_eat(char *food);
static void cat_walk(int step);
static void cat_talk(char *msg);

cat_t* cat_init(const char *name)
{
	cat_t *cat=(cat_t*)malloc(sizeof(cat_t));
	animal_t *animal=(animal_t*)animal_init(name);
	memcpy(&(cat->base),animal,sizeof(animal_t));
	
	cat->base.animal_ops->eat=cat_eat;
	cat->base.animal_ops->walk=cat_walk;
	cat->base.animal_ops->talk=cat_talk;
	
	free(animal);
	return cat;
}

void cat_die(cat_t *cat)
{
	animal_die(&cat->base);
	free(cat);
}

static void cat_eat(char *food)
{
	printf("I'm a cat,I eat %s\n",food);
}

static void cat_walk(int steps)
{
	printf("I'm a cat,I can jump %d steps one time\n",steps);
}
static void cat_talk(char *msg)
{
	printf("I'm a cat,I talk my language %s\n",msg);
}
