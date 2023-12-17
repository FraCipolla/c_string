#pragma once

#include <stddef.h>

typedef struct s_string {
	char *str;
	size_t size;
	char *end;
}	t_string;

typedef t_string * string;

string String(char *str);
