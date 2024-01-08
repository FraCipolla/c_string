#include <stdio.h>
#include "ft_string.h"

int main()
{
	t_string *s = {String("test")};
	printf("begin: %s\n", s->begin());
	printf("data: %s\n", s->data);
	printf("current: %s\n", s->current);
	printf("capacity: %ld\n", s->capacity);
	printf("end(): %s\n", s->end() - 1);
	printf("at(): %c\n", s->at(2));
	printf("empty(): %s\n",s->empty()? "true" : "false");
	printf("compare %d\n", s->compare("tess"));
	printf("substr: %s\n", s->substr((pos){.start=1, .skip='t'}));
	printf("find: %d\n", s->find('e'));
	printf("equal true: %s\n", s->equal("test")? "true" : "false");
	printf("equal false: %s\n", s->equal("testo")? "true" : "false");
	s->push_back('e');
	s->push_back('s');
	s->push_back('t');
	printf("data: %s\n", s->data);
	s->append(" prova");
	printf("data: %s\n", s->data);
	const char *c_str = s->c_str();
	printf("c_str: %s\n", c_str);

	printf("contain: %s\n", s->contain("es") ? "true" : "false");
	printf("contain: %s\n", s->contain("pippo") ? "true" : "false");

	printf("\ncopy constructor test:\n\n");
	t_string *s2 = {String(s)};
	printf("begin: %s\n", s2->begin());
	printf("data: %s\n", s2->data);
	printf("current: %s\n", s2->current);
	printf("capacity: %ld\n", s2->capacity);
	printf("end(): %s\n", s2->end() - 1);
	printf("at(): %c\n", s2->at(2));
	printf("empty(): %s\n",s2->empty()? "true" : "false");
	printf("compare %d\n", s2->compare("tess"));
	printf("substr: %s\n", s2->substr((pos){.start=1}));
	s2->clear();
	printf("data: %s\n", s2->data);
	printf("current: %s\n", s2->current);
}
