#include "c_string.h"
# include <stdlib.h>

string String(char *str)
{
	size_t i = 0;
	while (str[i])
		++i;
	string s = malloc(sizeof(t_string));
	s->str = malloc(sizeof(char) * i + 1);
	i = -1;
	while (str[++i])
		s->str[i] = str[i];
	s->str[i] = 0;
	s->size = i;
	s->end = &str[i];
	return s;
}
