# c_string
C interpretation of type String

Hi all! This is a simple project i made to teach myself how to use macros and some polymorphism in C. To do so, I decided to try to implement C++ strings as similar as possible, avoiding the redundant of passing the string calling the method as parameter.
To do so, I had to declared a fixed number of strings as global var and generate functions to assign to internal string struct function pointers.
Obviously, this came with many downside, first of all the need to predefine the number of string we're going to use, and the incapacity to add strings at comptime (you can only assign them to an array of string struct pointers).
It will probably have some benefit, the same you can find in C++ strings. For example, you can know the size of a string at O(1), using the internal size, you can call methods without passing the string to it, it will also take 'self' as parameter internally. You can do stuffs like throwing an error if you try to access out of bound memory.

## **index:**
  - [Introduction](#introduction)
  - [Start](#start)
  - [Declaring functions](#declaring-functions)
  - [Build up](#build-up)
  - [Testing](#testing)

## Introduction
In C **macros** are simply text substitution that happens during the preprocessor. That's basically it, plain and simple. That also means that you can define **keyword**, because preprocessor doesn't know anything about keywords, according to [GNU manual](https://gcc.gnu.org/onlinedocs/cpp/Macros.html).
The idea behind the project is to:
  - declare a stuct to define the string elements
  - declare a global array of pointer to this struct
  - declare a function for every methods for every string inside the global string *[], each with different name based on the index
  - assign the right functions to the new generated string
Moving from this, we can start built our header in a way that C preprocessor will handle all the declarations.

## Start
First thing first, we need to define our structure:
```
typedef struct s_string {
  char *data;
  size_t size;
  size_t capacity;
  void (*clear)();
} t_string;
```
Nothing special here. I just declared some basic member and one function pointer as example. data will be our actual string, size the length of the string, capacity its total allocated memory, and clear() our method to reset the string. After this I declared the global array:
```
t_string *string_arr[8];
```
I've choosed to use just 8 strings, we don't need them for everything, and we can reuse them anyway.

## Declaring functions
In my project I used a nested macro to generate a progressive number using the **__COUNTER__** predefined macro. Has explained by GNU manual:
> If you want to stringize the result of expansion of a macro argument, you have to use two levels of macros

so we build one level of indirection, we expand __COUNTER__ macro to its value, and pass that value to any method we want to build. The first passage will look like:
```
#define BUILD_STRING() COUNTER(__COUNTER__)
```
Calling BUILD_STRING() will be expanded to COUNTER(0) the first time it's being called, to COUNTER(1) the second, and so on.
Now we have to define che COUNTER(i) macro. COUNTER will take the __COUNTER__ value and use it to generate specific functions based on the value. To do so, let's first define a macro to generate the clear() method.
```
#define CLEAR(i) void clear_##i() { for (size_t s = 0; s < string_arr[i]->size; s++) {string_arr[i]->data[s] = 0;} string_arr[i]->size = 0; }
```
This macro generate a function with an unique name based on the 'i' value. The **##** is needed for concatenation(see https://gcc.gnu.org/onlinedocs/cpp/Concatenation.html). So we will create a function like:
```
void clear_0()
{
  for (size_t s = 0; s < string_arr[i]->size; s++) {
    string_arr[i]->data[s] = 0;
  }
  string_arr[i]->size = 0;
}
```
We can simulate methods because the function already know the right position of the string to work with.
Now the only thing left is to 'hook' the function generated function to the right string inside the string_array. Unfortunately we can't do this during preprocessor phase, but we can easly do this when constructing the string.
***Tip:
you can check all preprocessor expansions compiling with -E flag (using gcc), and choose to redirect the output on a file.
Note that this method will expand any prepocessor directives, like #define, #include and so on***

## Build up
First of all, let's define our costructor. It will be a simple function that return the initialized t_string pointing to the correct index.
```
#define SMALL_CHUNK 128
#define MEDIUM_CHUNK 256
#define BIG_CHUNK 512
static int i = 0;
t_string *String_char(char *str)
{
	if (string_arr[i]) {
		free(string_arr[i]->data);
		free(string_arr[i]);
	}
	size_t size = 0;
	while (str[size])
		size++;
	if (!(string_arr[i] = malloc(sizeof(t_string)))) {
		perror("malloc");
		exit (0);
	}
	size_t data_size = size <= SMALL_CHUNK ? SMALL_CHUNK : size <= MEDIUM_CHUNK ? MEDIUM_CHUNK : BIG_CHUNK;
	string_arr[i]->data = malloc(sizeof(char) * data_size);
	for (size_t j = 0; j < size; j++) {
		string_arr[i]->data[j] = str[j];
	}
	string_arr[i]->data[size] = 0;
	string_arr[i]->current = &string_arr[i]->data[0];
	string_arr[i]->size = size;
	string_arr[i]->capacity = data_size;
	switch_string(i, string_arr[i]); // assign methods
	t_string *ret = string_arr[i];
	if (i < 7)
		++i;
	else
		i = 0;
	return (ret);
}
```
The above is quite self explanatory. The only mention is about the char * allocation. I decided to allocate fixed amount of bytes instead of the actual string length. This is done for performance improvement, avoiding to reallocate data anytime we need to append some chars. The other big note is about the **NULL** terminating char of data. It is obviously not needed, since we already have size to use to iterate the string. This is just merely for an easier C compatibility, it could be avoided adding a method that return a C style string like c_str(). If we reache the last index of string_arr, we go back to index 0.
We also have to define the function **switch_string**. This function is needed to assign the right methods to the string.
```
#define CASE(i) case i: s->clear() = &clear_##i; return
void switch_string(int i, t_string *s)
{
	switch (i)
	{
	CASE(0);
	CASE(1);
	CASE(2);
	... until 7
	}
}
```
I had again to use macro to do this. Since we've learnt how to concatenate value to macro, we can do magic and define a macro to append the right index to the corresponding function. After prepocessor, the code will look like this:
```
switch (i)
	{
	case 0: s->clear() = &clear_##0; return;
	case 1: s->clear() = &clear_##1; return;
	...
	}
```

## Testing

