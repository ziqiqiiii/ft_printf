# ft_printf

ft_printf is a compact reimplementation of the C standard library function `printf` created as a 42 School project. The goal is to implement a simplified, robust `ft_printf` that demonstrates handling variadic arguments, formatting of common types, and low-level I/O using `write(2)`.

## Purpose

This project implements `ft_printf(const char *format, ...)` supporting a common subset of format specifiers. It is intended as an educational exercise in parsing format strings, using `va_list`, and writing small, well-tested helper routines for printing strings and numbers.

## Supported format specifiers

- `%c` — character
- `%s` — string (prints `(null)` for `NULL` pointers)
- `%d`, `%i` — signed decimal integer
- `%u` — unsigned decimal integer
- `%x` — unsigned hexadecimal (lowercase)
- `%X` — unsigned hexadecimal (uppercase)
- `%p` — pointer (printed as `0x...`)
- `%%` — literal percent sign

## Features

- Parses a format string and dispatches to specialized helper functions for each specifier.
- Returns the exact number of characters printed (same contract as `printf`).
- Handles edge cases such as `NULL` strings and `INT_MIN` safely.
- Packaged as a static library (`libftprintf.a`) with a `Makefile` for convenient build and test.

## Build & Run

Build the static library:

```bash
make
```

Run the provided quick test target (compiles and runs a temporary executable):

```bash
make test
```

Clean build artifacts:

```bash
make clean    # remove object files
make fclean   # remove objects and library
make re       # fclean then all
```

To compile a program that uses `ft_printf`:

```bash
gcc -Wall -Wextra -Werror -I ./ your_program.c libftprintf.a -o your_program
```

## Usage example

Example `main.c` using `ft_printf`:

```c
#include "ft_printf.h"

int main(void)
{
	int printed = ft_printf("Hello %s, number=%d, hex=%x, ptr=%p, percent=%%\n",
							"world", 42, 255, (void *)0xdeadbeef);
	ft_printf("Printed %d characters\n", printed);
	return 0;
}
```

## Implementation notes

Contract:
- Input: a format string and variadic arguments.
- Output: writes formatted output to `stdout` and returns an `int` count of characters printed.

Core flow:
1. `ft_printf` iterates the format string byte-by-byte.
2. On `%`, advance to the specifier and call `printf_specifiers` with the `va_list` and specifier.
3. `printf_specifiers` dispatches to helper functions:
   - `%d`/`%i` → `ft_putnbr` (signed integer, handles `INT_MIN`)
   - `%u` → `ft_putnbr_u` (unsigned decimal)
   - `%x`/`%X` → `hexdecimal_l` / `hexdecimal_u` (recursive hex printing)
   - `%p` → `printf_pointer` (prints `0x` then hex)
   - `%s` → `ft_putstr` (prints `(null)` for `NULL`)
   - `%c`/`%%` → `ft_putchar`

Key implementation details:
- Numeric printing often uses recursion (divide-and-conquer) to print digits in order.
- Hex conversion prints digits using `ft_putchar` with calculated ASCII offsets for `a-f`/`A-F`.
- All low-level output uses `write(1, ...)` from `<unistd.h>`.

## Edge cases

- `NULL` strings are printed as `(null)` to avoid undefined behavior.
- `INT_MIN` is handled explicitly in `ft_putnbr` to avoid negation overflow.

