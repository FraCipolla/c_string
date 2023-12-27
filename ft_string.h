#pragma once

#include <stdarg.h>

typedef char * it;
typedef struct s_string {
	char *str;
	char *data;
	it start;
	char *(*begin)();
}	t_string;

#define STRING(x) { .str=#x, .begin=&#x[0] }
t_string *string_arr[64];

#define index 0
#define BEGIN(i) char *begin_##i() { return &string_arr[i]->str[0]; }
#define CASE(i) case i: s->begin = &begin_##i; return
// #define HOOK_BEGIN(i) &(t_string){.begin=&begin_##i}

BEGIN(0);BEGIN(10);BEGIN(20);BEGIN(30);BEGIN(40);BEGIN(50);BEGIN(60);
BEGIN(1);BEGIN(11);BEGIN(21);BEGIN(31);BEGIN(41);BEGIN(51);BEGIN(61);
BEGIN(2);BEGIN(12);BEGIN(22);BEGIN(32);BEGIN(42);BEGIN(52);BEGIN(62);
BEGIN(3);BEGIN(13);BEGIN(23);BEGIN(33);BEGIN(43);BEGIN(53);BEGIN(63);
BEGIN(4);BEGIN(14);BEGIN(24);BEGIN(34);BEGIN(44);BEGIN(54);BEGIN(64);
BEGIN(5);BEGIN(15);BEGIN(25);BEGIN(35);BEGIN(45);BEGIN(55);
BEGIN(6);BEGIN(16);BEGIN(26);BEGIN(36);BEGIN(46);BEGIN(56);
BEGIN(7);BEGIN(17);BEGIN(27);BEGIN(37);BEGIN(47);BEGIN(57);
BEGIN(8);BEGIN(18);BEGIN(28);BEGIN(38);BEGIN(48);BEGIN(58);
BEGIN(9);BEGIN(19);BEGIN(29);BEGIN(39);BEGIN(49);BEGIN(59);

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
	t_string *new = &(t_string){.str = str, .data = str};
	string_arr[i] = new;
	switch_begin(i, string_arr[i]);
	return (string_arr[i++]);
}
