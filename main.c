#include "c_string.h"

#include <stdio.h>

int main()
{
	string s = String("prova");
	for (size_t i = 0; i < s->size; i++) {
		printf("%c", s->str[i]);	
	}
	printf("\n");
	printf("s size: %ld\n", s->size);
}
