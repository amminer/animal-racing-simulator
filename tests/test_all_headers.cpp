#include "Animal.h"
#include "LLL.h"
#include "CLL.h"
#include "Race.h"
#include "Stable.h"
#include "Stadium.h"

int main(void)
{
	Cat cat();
	Hare hare();
	Tortoise tortoise();
	LLL<Animal> lll();
	CLL<Animal*> cll();
	Race race();
	Stable stable();
	Stadium stadium();
}
