#include "dog.h"
#include <stdlib.h>
/**
 * init_dog - initializes a variable of type struct dog.
 * @d: pointer to struct
 * @name: parameter of dog name
 * @age: parameter of age of the dog
 * @owner: pinter parameter to owner of the dog
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{<F11><F11><F11><F11>
		if (d == NULL)
		{
			return;
		}
		d->name = name;
		d->age = age;
		d->owner = owner;
}
