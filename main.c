#include <stdio.h>
#include "ft_string.h"

int main()
{
	t_string *s = String("test");
	printf("begin: %s\n", s->begin());
	printf("data: %s\n", s->data);
	printf("current: %s\n", s->current);
	printf("capacity: %ld\n", s->capacity);
	printf("end(): %s\n", s->end() - 1);
	printf("at(): %s\n", s->at(2));
	printf("empty(): %s\n",s->empty()? "true" : "false");
	printf("compare %d\n", s->compare("tess"));
	printf("substr: %s\n", s->substr((pos){.start=1}));
	s->clear();
	printf("data: %s\n", s->data);
	printf("current: %s\n", s->current);
}
