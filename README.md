# c_string
C interpretation of type String

Hi all! This is a simple project i made to teach myself how to use macros and some polymorphism in C. To do so, I decided to try to implement C++ strings as similar as possible, avoiding the redundant of passing the string calling the method as parameter.
To do so, I had to declared a fixed number of strings as global var and generate functions to assign to internal string struct function pointers.
Obviously, this came with many downside, first of all the need to predefine the number of string we're going to use, and the incapacity to add strings at comptime (you can only assign them to an array of string struct pointers).
It will probably have some benefit, the same you can find in C++ strings. For example, you can know the size of a string at O(1), using the internal size, you can call methods without passing the string to it, it will also take 'self' as parameter internally. You can do stuffs like throwing an error if you try to access out of bound memory.

## **index:**
  - Introduction
  - Start
  - Declaring functions

### Introduction
In C **macros** are simply text substitution that happens during the preprocessor. That's basically it, plain and simple. That also means that you can define **keyword**, because preprocessor doesn't know anything about keywords, according to [GNU manual](https://gcc.gnu.org/onlinedocs/cpp/Macros.html).
The idea behind the project is to:
  - declare a stuct to define the string elements
  - declare a global array of pointer to this struct
  - declare a function for every methods for every string inside the global string *[], each with different name based on the index
  - assign the right functions to the new generated string
Moving from this, we can start built our header in a way that C preprocessor will handle all the declarations.

### Start
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

### Declaring functions
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
This macro generate a function with an unique name based on the 'i' value. The **##** is needed for concatenation(see https://gcc.gnu.org/onlinedocs/cpp/Concatenation.html)
