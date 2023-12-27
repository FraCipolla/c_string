#include <stdio.h>
#include "ft_string.h"

int main()
{
	int i = 0;
	t_string *s = String("prova");
	printf("%s\n", s->begin());
	printf("%s\n", s->data);
	printf("%s\n", s->current);
	t_string *s2 = String("seconda prova");
	printf("%s\n", s2->begin());
	printf("%s\n", s2->data);
	printf("%s\n", s2->current);
	printf("%s\n", s2->end() - 1);
}
