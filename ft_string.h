#pragma once

#include <stdarg.h>
#include <stdlib.h>

typedef char * it;
typedef struct s_string {
	char current[128];
	char data[128];
	size_t size;
	size_t capacity;
	char *(*begin)();
	char *(*end)();
	char *(*at)(int j);
}	t_string;

#define STRING(x) { .str=#x, .begin=&#x[0] }
t_string *string_arr[64];

#define index 0
#define BEGIN(i) char *begin_##i() { return &string_arr[i]->data[0]; }
#define END(i) char *end_##i() { return &string_arr[i]->data[string_arr[i]->size]; }
#define AT(i) char *at_##i(int j) { return &string_arr[i]->data[j]; }
#define CASE(i) case i: s->begin = &begin_##i; s->end = &end_##i; s->at = &at_##i; return
// #define HOOK_BEGIN(i) &(t_string){.begin=&begin_##i}

BEGIN(0);BEGIN(10);BEGIN(20);BEGIN(30);BEGIN(40);BEGIN(50);BEGIN(60);BEGIN(1);BEGIN(11);BEGIN(21);BEGIN(31);BEGIN(41);BEGIN(51);BEGIN(61);
BEGIN(2);BEGIN(12);BEGIN(22);BEGIN(32);BEGIN(42);BEGIN(52);BEGIN(62);BEGIN(3);BEGIN(13);BEGIN(23);BEGIN(33);BEGIN(43);BEGIN(53);BEGIN(63);
BEGIN(4);BEGIN(14);BEGIN(24);BEGIN(34);BEGIN(44);BEGIN(54);BEGIN(64);BEGIN(5);BEGIN(15);BEGIN(25);BEGIN(35);BEGIN(45);BEGIN(55);
BEGIN(6);BEGIN(16);BEGIN(26);BEGIN(36);BEGIN(46);BEGIN(56);BEGIN(7);BEGIN(17);BEGIN(27);BEGIN(37);BEGIN(47);BEGIN(57);
BEGIN(8);BEGIN(18);BEGIN(28);BEGIN(38);BEGIN(48);BEGIN(58);BEGIN(9);BEGIN(19);BEGIN(29);BEGIN(39);BEGIN(49);BEGIN(59);
END(0);END(10);END(20);END(30);END(40);END(50);END(60);END(1);END(11);END(21);END(31);END(41);END(51);END(61);
END(2);END(12);END(22);END(32);END(42);END(52);END(62);END(3);END(13);END(23);END(33);END(43);END(53);END(63);
END(4);END(14);END(24);END(34);END(44);END(54);END(64);END(5);END(15);END(25);END(35);END(45);END(55);
END(6);END(16);END(26);END(36);END(46);END(56);END(7);END(17);END(27);END(37);END(47);END(57);
END(8);END(18);END(28);END(38);END(48);END(58);END(9);END(19);END(29);END(39);END(49);END(59);
AT(0);AT(10);AT(20);AT(30);AT(40);AT(50);AT(60);AT(1);AT(11);AT(21);AT(31);AT(41);AT(51);AT(61);
AT(2);AT(12);AT(22);AT(32);AT(42);AT(52);AT(62);AT(3);AT(13);AT(23);AT(33);AT(43);AT(53);AT(63);
AT(4);AT(14);AT(24);AT(34);AT(44);AT(54);AT(64);AT(5);AT(15);AT(25);AT(35);AT(45);AT(55);
AT(6);AT(16);AT(26);AT(36);AT(46);AT(56);AT(7);AT(17);AT(27);AT(37);AT(47);AT(57);
AT(8);AT(18);AT(28);AT(38);AT(48);AT(58);AT(9);AT(19);AT(29);AT(39);AT(49);AT(59);

void switch_begin(int i, t_string *s)
{
	switch (i)
	{
	CASE(0);
	CASE(1);
	CASE(2);
	CASE(3);
	CASE(4);
	CASE(5);
	CASE(6);
	CASE(7);
	CASE(8);
	CASE(9);
	CASE(10);
	CASE(11);
	CASE(12);
	CASE(13);
	CASE(14);
	CASE(15);
	CASE(16);
	CASE(17);
	CASE(18);
	CASE(19);
	CASE(20);
	CASE(21);
	CASE(22);
	CASE(23);
	CASE(24);
	CASE(25);
	CASE(26);
	CASE(27);
	CASE(28);
	CASE(29);
	CASE(30);
	CASE(31);
	CASE(32);
	CASE(33);
	CASE(34);
	CASE(35);
	CASE(36);
	CASE(37);
	CASE(38);
	CASE(39);
	CASE(40);
	CASE(41);
	CASE(42);
	CASE(43);
	CASE(44);
	CASE(45);
	CASE(46);
	CASE(47);
	CASE(48);
	CASE(49);
	CASE(50);
	CASE(51);
	CASE(52);
	CASE(53);
	CASE(54);
	CASE(55);
	CASE(56);
	CASE(57);
	CASE(58);
	CASE(59);
	CASE(60);
	CASE(61);
	CASE(62);
	CASE(63);
	CASE(64);
	}
}

t_string *String(char *str)
{
	static int i = 0;
	size_t size = 0;
	while (str[size])
		size++;
	string_arr[i] = malloc (sizeof(t_string));
	for (size_t j = 0; j < size; j++) {
		string_arr[i]->current[j] = str[j];
		string_arr[i]->data[j] = str[j];
	}
	string_arr[i]->current[size] = 0;
	string_arr[i]->data[size] = 0;
	string_arr[i]->size = size;
	switch_begin(i, string_arr[i]);
	t_string *ret = string_arr[i];
	if (i < 64)
		++i;
	else
		i = 0;
	return (ret);
}
