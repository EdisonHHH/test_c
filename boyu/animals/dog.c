#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"dog.h"

static void dog_eat(char *food);
static void dog_walk(int step);
static void dog_talk(char *msg);
static void dog_hunt(const char *rabbit);
dog_t* dog_init(const char *name,const char *owner)
{
	dog_t *dog=(dog_t*)malloc(sizeof(dog_t));
	dog->owner=(char*)malloc(sizeof(char)*strlen(owner));
	strcpy(dog->owner,owner);
	animal_t *animal=(animal_t*)animal_init(name);
	memcpy(&(dog->base),animal,sizeof(animal_t));
	
	dog->base.animal_ops->eat=dog_eat;
	dog->base.animal_ops->walk=dog_walk;
	dog->base.animal_ops->talk=dog_talk;
	dog->hunt=dog_hunt;
	free(animal);
	return dog;
}

void dog_die(dog_t *dog)
{
	animal_die(&dog->base);
	free(dog->owner);
	free(dog);
}

static void dog_eat(char *food)
{
	printf("I'm a dog,I eat %s\n",food);
}

static void dog_walk(int steps)
{
	printf("I'm a dog,I can jump %d steps one time\n",steps);
}
static void dog_talk(char *msg)
{
	printf("I'm a dog,I talk my language %s\n",msg);
}
static void dog_hunt(const char *rabbit)
{
	printf("I'm a dog,I hunt rabbit %s\n",rabbit);
}
