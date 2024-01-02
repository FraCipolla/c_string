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
	char *data;
	size_t size;
	size_t capacity;
	char *(*begin)();
	char *(*end)();
	char *(*at)(size_t j);
	bool (*empty)();
	void (*clear)();
	int (*compare)(char *other);
	char *(*substr)(pos range);
	int (*find)(char c);
}	t_string;

t_string *string_arr[8];

#define BEGIN(i) char *begin_##i() { return &string_arr[i]->data[0]; }
#define END(i) char *end_##i() { return &string_arr[i]->data[string_arr[i]->size]; }
#define AT(i) char *at_##i(size_t j) { if (j > string_arr[i]->size) return &string_arr[i]->data[0]; return &string_arr[i]->data[j]; }
#define EMPTY(i) bool empty_##i() { return string_arr[i]->size == 0; }
#define CLEAR(i) void clear_##i() { for (size_t s = 0; s < string_arr[i]->size; s++) {string_arr[i]->data[s] = 0;} string_arr[i]->size = 0; }
#define COMPARE(i) int compare_##i(char *other) { int j = 0; while (other[j] && string_arr[i]->data[j]) { if (other[j] != string_arr[i]->data[j]) return other[j] - string_arr[i]->data[j]; j++;} return 0; }
#define SUBSTR(i) char *substr_##i(pos range) { int size = 0; if (range.start > string_arr[i]->size) return NULL; else if (range.end > string_arr[i]->size) range.end = size; if (range.start > range.end) { size = string_arr[i]->size - range.start; range.end = string_arr[i]->size; } else if (range.start < range.end) size = range.end - range.start; char *ret = malloc(sizeof(char) * size + 1); int k = 0; for (size_t n = range.start; n < range.end; n++) { if (range.skip != 0 && string_arr[i]->data[n] == range.skip) continue; ret[k++] = string_arr[i]->data[n]; } ret[k] = 0; return ret; }
#define FIND(i) int find_##i(char c) { for (size_t n = 0; n < string_arr[i]->size; n++) if (string_arr[i]->data[n] == c) return n; return 0; }
#define CASE(i) case i: s->begin = &begin_##i; s->end = &end_##i; s->at = &at_##i; s->empty = &empty_##i; s->clear = &clear_##i; s->compare = &compare_##i; s->substr = &substr_##i; s->find = &find_##i; return
#define COUNTER(i) BEGIN(i) END(i) AT(i) FIND(i) EMPTY(i) COMPARE(i) SUBSTR(i) CLEAR(i)
#define BUILD_STRING() COUNTER(__COUNTER__)

BUILD_STRING()
BUILD_STRING()
BUILD_STRING()
BUILD_STRING()
BUILD_STRING()
BUILD_STRING()
BUILD_STRING()
BUILD_STRING()

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
	if (i < 7)
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