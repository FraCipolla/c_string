#include <stdio.h>
#include "ft_string.h"

int main()
{
	t_string *s2 = String("seconda prova");
	printf("%s\n", s2->begin());
	printf("%s\n", s2->data);
	printf("%s\n", s2->current);
	printf("%s\n", s2->end() - 1);
	printf("%s\n", s2->at(4));
}
