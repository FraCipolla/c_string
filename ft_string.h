#pragma once

#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_pos {
	size_t start;
	size_t end;
	int skip;
}	pos;

typedef struct s_string {
	char *current;
	char data[128];
	size_t size;
	size_t capacity;
	char *(*begin)();
	char *(*end)();
	char *(*at)(int j);
	bool (*empty)();
	void (*clear)();
	int (*compare)(char *other);
	char *(*substr)(pos range);
}	t_string;

t_string *string_arr[64];

#define BEGIN(i) char *begin_##i() { return &string_arr[i]->data[0]; }
#define END(i) char *end_##i() { return &string_arr[i]->data[string_arr[i]->size]; }
#define AT(i) char *at_##i(int j) { return &string_arr[i]->data[j]; }
#define EMPTY(i) bool empty_##i() { return string_arr[i]->size == 0; }
#define CLEAR(i) void clear_##i() { for (size_t s = 0; s < string_arr[i]->size; s++) {string_arr[i]->data[s] = 0;} string_arr[i]->size = 0; }
#define COMPARE(i) int compare_##i(char *other) { int j = 0; while (other[j] && string_arr[i]->data[j]) { if (other[j] != string_arr[i]->data[j]) return other[j] - string_arr[i]->data[j]; j++;} return 0; }
#define SUBSTR(i) char *substr_##i(pos range) { int size = 0; if (range.start > string_arr[i]->size) return NULL; else if (range.end > string_arr[i]->size) range.end = size; if (range.start > range.end) { size = string_arr[i]->size - range.start; range.end = string_arr[i]->size; } else if (range.start < range.end) size = range.end - range.start; char *ret = malloc(sizeof(char) * size + 1); int k = 0; while (range.start < range.end) ret[k++] = string_arr[i]->data[range.start++]; ret[k] = 0; return ret; }
#define CASE(i) case i: s->begin = &begin_##i; s->end = &end_##i; s->at = &at_##i; s->empty = &empty_##i; s->clear = &clear_##i; s->compare = &compare_##i; s->substr = &substr_##i; return
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
EMPTY(0);EMPTY(10);EMPTY(20);EMPTY(30);EMPTY(40);EMPTY(50);EMPTY(60);EMPTY(1);EMPTY(11);EMPTY(21);EMPTY(31);EMPTY(41);EMPTY(51);EMPTY(61);
EMPTY(2);EMPTY(12);EMPTY(22);EMPTY(32);EMPTY(42);EMPTY(52);EMPTY(62);EMPTY(3);EMPTY(13);EMPTY(23);EMPTY(33);EMPTY(43);EMPTY(53);EMPTY(63);
EMPTY(4);EMPTY(14);EMPTY(24);EMPTY(34);EMPTY(44);EMPTY(54);EMPTY(64);EMPTY(5);EMPTY(15);EMPTY(25);EMPTY(35);EMPTY(45);EMPTY(55);
EMPTY(6);EMPTY(16);EMPTY(26);EMPTY(36);EMPTY(46);EMPTY(56);EMPTY(7);EMPTY(17);EMPTY(27);EMPTY(37);EMPTY(47);EMPTY(57);
EMPTY(8);EMPTY(18);EMPTY(28);EMPTY(38);EMPTY(48);EMPTY(58);EMPTY(9);EMPTY(19);EMPTY(29);EMPTY(39);EMPTY(49);EMPTY(59);
CLEAR(0);CLEAR(10);CLEAR(20);CLEAR(30);CLEAR(40);CLEAR(50);CLEAR(60);CLEAR(1);CLEAR(11);CLEAR(21);CLEAR(31);CLEAR(41);CLEAR(51);CLEAR(61);
CLEAR(2);CLEAR(12);CLEAR(22);CLEAR(32);CLEAR(42);CLEAR(52);CLEAR(62);CLEAR(3);CLEAR(13);CLEAR(23);CLEAR(33);CLEAR(43);CLEAR(53);CLEAR(63);
CLEAR(4);CLEAR(14);CLEAR(24);CLEAR(34);CLEAR(44);CLEAR(54);CLEAR(64);CLEAR(5);CLEAR(15);CLEAR(25);CLEAR(35);CLEAR(45);CLEAR(55);
CLEAR(6);CLEAR(16);CLEAR(26);CLEAR(36);CLEAR(46);CLEAR(56);CLEAR(7);CLEAR(17);CLEAR(27);CLEAR(37);CLEAR(47);CLEAR(57);
CLEAR(8);CLEAR(18);CLEAR(28);CLEAR(38);CLEAR(48);CLEAR(58);CLEAR(9);CLEAR(19);CLEAR(29);CLEAR(39);CLEAR(49);CLEAR(59);
COMPARE(0);COMPARE(10);COMPARE(20);COMPARE(30);COMPARE(40);COMPARE(50);COMPARE(60);COMPARE(1);COMPARE(11);COMPARE(21);COMPARE(31);COMPARE(41);COMPARE(51);COMPARE(61);
COMPARE(2);COMPARE(12);COMPARE(22);COMPARE(32);COMPARE(42);COMPARE(52);COMPARE(62);COMPARE(3);COMPARE(13);COMPARE(23);COMPARE(33);COMPARE(43);COMPARE(53);COMPARE(63);
COMPARE(4);COMPARE(14);COMPARE(24);COMPARE(34);COMPARE(44);COMPARE(54);COMPARE(64);COMPARE(5);COMPARE(15);COMPARE(25);COMPARE(35);COMPARE(45);COMPARE(55);
COMPARE(6);COMPARE(16);COMPARE(26);COMPARE(36);COMPARE(46);COMPARE(56);COMPARE(7);COMPARE(17);COMPARE(27);COMPARE(37);COMPARE(47);COMPARE(57);
COMPARE(8);COMPARE(18);COMPARE(28);COMPARE(38);COMPARE(48);COMPARE(58);COMPARE(9);COMPARE(19);COMPARE(29);COMPARE(39);COMPARE(49);COMPARE(59);
SUBSTR(0);SUBSTR(10);SUBSTR(20);SUBSTR(30);SUBSTR(40);SUBSTR(50);SUBSTR(60);SUBSTR(1);SUBSTR(11);SUBSTR(21);SUBSTR(31);SUBSTR(41);SUBSTR(51);SUBSTR(61);
SUBSTR(2);SUBSTR(12);SUBSTR(22);SUBSTR(32);SUBSTR(42);SUBSTR(52);SUBSTR(62);SUBSTR(3);SUBSTR(13);SUBSTR(23);SUBSTR(33);SUBSTR(43);SUBSTR(53);SUBSTR(63);
SUBSTR(4);SUBSTR(14);SUBSTR(24);SUBSTR(34);SUBSTR(44);SUBSTR(54);SUBSTR(64);SUBSTR(5);SUBSTR(15);SUBSTR(25);SUBSTR(35);SUBSTR(45);SUBSTR(55);
SUBSTR(6);SUBSTR(16);SUBSTR(26);SUBSTR(36);SUBSTR(46);SUBSTR(56);SUBSTR(7);SUBSTR(17);SUBSTR(27);SUBSTR(37);SUBSTR(47);SUBSTR(57);
SUBSTR(8);SUBSTR(18);SUBSTR(28);SUBSTR(38);SUBSTR(48);SUBSTR(58);SUBSTR(9);SUBSTR(19);SUBSTR(29);SUBSTR(39);SUBSTR(49);SUBSTR(59);

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

static int i = 0;

t_string *String_char(char *str)
{
	size_t size = 0;
	while (str[size])
		size++;
	string_arr[i] = malloc(sizeof(t_string));
	for (size_t j = 0; j < size; j++) {
		string_arr[i]->data[j] = str[j];
	}
	string_arr[i]->data[size] = 0;
	string_arr[i]->current = &string_arr[i]->data[0];
	string_arr[i]->size = size;
	string_arr[i]->capacity = sizeof(string_arr[i]->data);
	switch_begin(i, string_arr[i]);
	t_string *ret = string_arr[i];
	if (i < 64)
		++i;
	else
		i = 0;
	return (ret);
}

t_string *String_t_string(t_string *str)
{
	string_arr[i] = malloc(sizeof(t_string));
	for (size_t j = 0; j < str->size; j++) {
		string_arr[i]->data[j] = str->data[j];
	}
	string_arr[i]->data[str->size] = 0;
	string_arr[i]->current = &str->data[0];
	string_arr[i]->size = str->size;
	string_arr[i]->capacity = str->capacity;
	switch_begin(i, string_arr[i]);
	t_string *ret = string_arr[i];
	if (i < 64)
		++i;
	else
		i = 0;
	return (ret);
}

#define String(obj) _Generic( (obj), char * : String_char, t_string * : String_t_string) ((obj))