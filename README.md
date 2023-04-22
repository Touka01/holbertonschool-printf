Simple printf() Implementation in C
'printf' is a standard C library function used to output formatted text to the console. It takes a format string and any additional arguments specified in the format string, and prints out the formatted text.

How to Compile
To use this implementation of printf(), follow these steps:

Download the folowing files and save them in a single directory.
myprintf.c Containing the source code of the printf function.
main.h Header file containing prototypes of the functions used by the source code. This is included in the rest of the files through the expression: #include "main.h"
get_and_out.c Containing auxiliar functions.
function.c Containing auxiliar functions.
Compile the code, using:
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format \*.c -o myprintf
Usage
Call the myprintf() function using the same format specifiers as the standard printf() function. This implementation of printf() supports the following format specifiers:

%d: integer

%i: integer

%s: string

%c: character

%%: litteral percent symbol

For example:
myprintf("Hello, I'm %s! I'm %d years old.\n", "mouayed", 25);
The expected output is:
Hello, I'm mouayed! I'm 25 years old.
Limitations
This implementation of printf() has some limitations compared to the standard printf() function. Here are a few things to keep in mind:

It does not support all the format specifiers and options that are available in the standard printf() function.

It may not be as efficient as the standard printf() function, especially for large or complex output.

It does not perform any input validation, so it is possible to cause buffer overflows or other security issues if you pass in invalid input.

It is not type-safe, so it is possible to pass in arguments of the wrong type and cause undefined behavior.

Test
If you want to test this function you can download any of the files included in the Tests folder. To do this you must include the file in the same folder as the rest, and you must compile everything again.

Then you can run it using this command:

./a.out
