#include<stdio.h>

//#include"animal_base.h"
#include"dog.h"
#include"cat.h"
int main(int argc,const char *argv[])
{
	animal_t *dog=(animal_t*)dog_init("Jack","HHH");

	//printf("My owner is %s\n",dog->owner);
	animal_eat(dog,"bones");
	animal_walk(dog,5);
	animal_talk(dog,"wuang wuang wuang...");
	//dog->hunt("XiaoBaiTu");

	cat_t *cat=cat_init("John");
	animal_eat((animal_t*)cat,"fish");
	animal_walk((animal_t*)cat,3);
	animal_talk((animal_t*)cat,"miao miao miao...");
	return 0;
}
