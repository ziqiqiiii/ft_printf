# ft_printf
This is the first circle of 42 core programme project. Basically a project that mimic the function printf() in c.
In this project, I am trying to code a ft_printf function that can deal with %c %d %s %i %p %u %x %X.

%c is used to printf character.

%s is used to printf string.

%d is for decimal (base 10).

%i is integer (base 10).

%u is unsigned integer (base 10).

%x is hexadecimal (base 16) lowercase.

%X is hexadecimal (base 16) uppercase.

%p is pointer.

In my ft_printf_utils.c file is all the functions that kinda similar in libft but a modified version. Exp = ft_putnbr ft_putchar ft_putstr.
While the ft_printf.c file contain functions that I code in this project.

The target "test" in Makefile is used to compile all the source file and run executable file.
