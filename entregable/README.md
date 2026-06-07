*Este proyecto ha sido creado como parte del currículo de 42 por rartigue.*

# Libft

## Descripción

`libft` es la primera librería del cursus de 42. La idea del proyecto es
reconstruir una base propia en C: volver a implementar funciones de la `libc`,
añadir utilidades de strings y memoria, y dejar una librería reutilizable para
los siguientes proyectos.

Más allá de "hacer que compile", este proyecto sirve para entender bien cosas
muy básicas pero muy importantes: manejo de punteros, memoria dinámica,
recorrido de strings, comparación de bytes y escritura en file descriptors.

El resultado final se compila como una librería estática llamada `libft.a`.

## Qué incluye esta librería

La parte obligatoria está organizada en tres bloques:

- funciones de caracteres y conversión (`ft_isalpha`, `ft_isdigit`,
  `ft_toupper`, `ft_atoi`, etc.)
- funciones de memoria y strings (`ft_memset`, `ft_bzero`, `ft_memcpy`,
  `ft_memmove`, `ft_strchr`, `ft_strnstr`, `ft_strdup`, etc.)
- funciones adicionales de utilidad (`ft_substr`, `ft_split`, `ft_strtrim`,
  `ft_itoa`, `ft_strmapi`, `ft_putnbr_fd`, etc.)

En este repositorio, la **parte obligatoria está completada**.

La parte bonus de listas enlazadas todavía no está implementada.

## Instrucciones

### Compilar la librería

```sh
make
```

Eso genera `libft.a` en la raíz del repositorio.

Targets disponibles:

| Target | Qué hace |
|---|---|
| `make` / `make all` | Compila la librería |
| `make clean` | Borra los objetos |
| `make fclean` | Borra objetos y `libft.a` |
| `make re` | Recompila desde cero |

Todo compila con las flags pedidas por el subject:

```sh
-Wall -Wextra -Werror
```

### Usarla en otro proyecto

Incluye el header:

```c
#include "libft.h"
```

Y enlaza la librería al compilar:

```sh
cc main.c libft.a -o programa
```

### Ejecutar los tests

Los tests no forman parte de la entrega, pero están ahí para comprobar la
lógica de cada función antes de la evaluación.

```sh
make -C tests re run
```

La salida está en modo verbose, así que se ve qué caso concreto pasa o falla en
cada test.

## Estado del proyecto

### Parte 1 — Funciones de libc

- `ft_isalpha`
- `ft_isdigit`
- `ft_isalnum`
- `ft_isascii`
- `ft_isprint`
- `ft_strlen`
- `ft_memset`
- `ft_bzero`
- `ft_memcpy`
- `ft_memmove`
- `ft_strlcpy`
- `ft_strlcat`
- `ft_toupper`
- `ft_tolower`
- `ft_strchr`
- `ft_strrchr`
- `ft_strncmp`
- `ft_memchr`
- `ft_memcmp`
- `ft_strnstr`
- `ft_atoi`
- `ft_calloc`
- `ft_strdup`

### Parte 2 — Funciones adicionales

- `ft_substr`
- `ft_strjoin`
- `ft_strtrim`
- `ft_split`
- `ft_itoa`
- `ft_strmapi`
- `ft_striteri`
- `ft_putchar_fd`
- `ft_putstr_fd`
- `ft_putendl_fd`
- `ft_putnbr_fd`

### Parte 3 — Bonus

Pendiente.
Cuando se haga, irá en archivos `*_bonus.c` separados y con su regla `bonus`
en el `Makefile`, tal como pide 42.

## Recursos

- `linft.pdf`: subject oficial del proyecto
- `man 3 ...`: referencia principal para comportamiento y prototipos
- `tests/minunit.h`: framework mínimo usado para la batería de tests
- `CHEATSHEET.md`: guía rápida de comandos para compilar, testear y mantener el repo
- `norminette`: para comprobar la Norm de 42

## Uso de IA

Durante este proyecto he usado IA como apoyo para:

- revisar prototipos y comportamientos frente al subject
- montar y ampliar tests
- detectar casos borde que merecía la pena comprobar
- mejorar la estructura del `Makefile` y la organización del repo

No la he usado como sustituto de entender el código. La idea ha sido usarla
como herramienta de apoyo y revisión, no como atajo para saltarme el
aprendizaje.

## Nota final

Este repo intenta quedarse como una base limpia y reutilizable para el resto
del cursus. La librería no solo está pensada para aprobar `libft`, sino para
servir de apoyo real en proyectos posteriores.
