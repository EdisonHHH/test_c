#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"animal_base.h"

animal_t* animal_init(const char *name)
{
	assert(name!=NULL);
	size_t name_len=strlen(name);

	animal_t *animal=(animal_t*)malloc(sizeof(animal_t));
	animal->name=(char*)malloc(name_len+1);
	memcpy(animal->name,name,name_len+1);
	animal->animal_ops=(animal_ops_t*)malloc(sizeof(animal_ops_t));
	
	return animal;
}

void animal_eat(animal_t *animal,char *food)
{
	animal->animal_ops->eat(food);
	return;
}

void animal_walk(animal_t *animal,int steps)
{
	animal->animal_ops->walk(steps);
	return;
}

void animal_talk(animal_t *animal,char *msg)
{
	animal->animal_ops->talk(msg);
	return;
}

void animal_die(animal_t *animal)
{
	assert(animal!=NULL);
	free(animal->name);
	free(animal->animal_ops);
	free(animal);
	return;
}
