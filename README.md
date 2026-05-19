*Este proyecto ha sido creado como parte del currículo de 42 por rartigue.*

# Libft

## Descripción

`libft` es el primer proyecto del cursus de **42**. Consiste en construir una
librería propia en C que reimplementa una serie de funciones de la `libc`
(prefijadas con `ft_`), más un conjunto de funciones adicionales útiles.

Esta librería se compila en un archivo estático `libft.a` y se reutiliza
durante el resto del cursus.

Las funciones siguen estrictamente los prototipos y comportamientos definidos
en las páginas del `man` correspondientes — la única diferencia es el prefijo
`ft_`.

## Instrucciones

### Compilar la librería

```sh
make
```

Esto genera `libft.a` en la raíz del repositorio.

Targets disponibles:

| Target  | Acción                                  |
|---------|-----------------------------------------|
| `all`   | Compila `libft.a` (es el target por defecto) |
| `clean` | Elimina los archivos objeto `.o`        |
| `fclean`| `clean` + elimina `libft.a`             |
| `re`    | `fclean` seguido de `all`               |

Todos los `.c` se compilan con `-Wall -Wextra -Werror`, según exige el subject.

### Usar la librería en otro proyecto

```c
#include "libft.h"
```

```sh
cc tu_codigo.c libft.a -o tu_programa
```

### Ejecutar los tests (no entregables)

Los tests están en el subdirectorio `tests/` y usan [minunit](http://www.jera.com/techinfo/jtns/jtn002.html),
un framework minimalista de testing en C.

```sh
cd tests && make run
```

Esto compila `libft.a` (si no lo está ya), enlaza el binario de tests y lo
ejecuta. Cada función tiene su propio bloque de tests con casos de borde.

## Recursos

- **Subject oficial**: `linft.pdf` (en la raíz del repositorio).
- **Manuales del sistema**: `man 3 string`, `man 3 stdlib`, `man 3 ctype`,
  `man 3 strlcpy`, etc. son la referencia autoritativa de comportamiento.
- **42 Norm**: la normativa de estilo de 42, verificable con
  [norminette](https://github.com/42School/norminette).
- **minunit**: framework de testing usado en `tests/` (header `tests/minunit.h`).

### Uso de IA

Durante el desarrollo se utilizó Claude (Anthropic) como asistente para:

- Comparar las firmas de las funciones frente al estándar 42 (verificación de
  `size_t` y `const`) y refactorizar a las firmas correctas.
- Estructurar el `Makefile` cumpliendo las normas del subject (`-Wall -Wextra
  -Werror`, targets `all/clean/fclean/re`, uso de `ar`).
- Diseñar la suite de tests con `minunit` y redactar casos de borde basados en
  el `man` de cada función.

La **implementación lógica** de cada función ha sido escrita personalmente — la
IA se ha utilizado como herramienta de revisión, scaffolding y testing, no como
solución del problema.

## Lista de funciones

### Part 1 — Funciones de libc

| Función      | Implementada |
|--------------|--------------|
| `ft_isalpha` | ✓            |
| `ft_isdigit` | ✓            |
| `ft_isalnum` | ✓            |
| `ft_isascii` | ✓            |
| `ft_isprint` | ✓            |
| `ft_strlen`  | ✓            |
| `ft_memset`  | ✓            |
| `ft_bzero`   | pendiente    |
| `ft_memcpy`  | pendiente    |
| `ft_memmove` | pendiente    |
| `ft_strlcpy` | ✓            |
| `ft_strlcat` | ✓            |
| `ft_toupper` | ✓            |
| `ft_tolower` | ✓            |
| `ft_strchr`  | pendiente    |
| `ft_strrchr` | pendiente    |
| `ft_strncmp` | ✓            |
| `ft_memchr`  | pendiente    |
| `ft_memcmp`  | pendiente    |
| `ft_strnstr` | ✓            |
| `ft_atoi`    | ✓            |
| `ft_calloc`  | pendiente    |
| `ft_strdup`  | ✓            |

### Part 2 — Funciones adicionales

| Función         | Implementada |
|-----------------|--------------|
| `ft_substr`     | ✓            |
| `ft_strjoin`    | ✓            |
| `ft_strtrim`    | pendiente    |
| `ft_split`      | ✓            |
| `ft_itoa`       | pendiente    |
| `ft_strmapi`    | pendiente    |
| `ft_striteri`   | pendiente    |
| `ft_putchar_fd` | pendiente    |
| `ft_putstr_fd`  | pendiente    |
| `ft_putendl_fd` | pendiente    |
| `ft_putnbr_fd`  | pendiente    |

### Part 3 — Listas enlazadas (Bonus)

No implementadas todavía. Irán en archivos `*_bonus.c` separados, con regla
`bonus` en el Makefile.
