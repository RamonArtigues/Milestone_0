# Cheatsheet — Libft

Guía rápida de comandos para el día a día del proyecto. Asume que estás en la
raíz del repo (`Milestone_0/`) salvo que se indique lo contrario.

---

## 1. Compilar la librería (raíz)

| Comando         | Qué hace                                              |
|-----------------|-------------------------------------------------------|
| `make`          | Compila `libft.a` (igual que `make all`)              |
| `make clean`    | Borra los `.o`                                        |
| `make fclean`   | Borra los `.o` + `libft.a`                            |
| `make re`       | `fclean` + recompila todo desde cero                  |

**Verificar que `libft.a` se generó bien:**

```sh
ls -lh libft.a              # tamaño y existencia
ar t libft.a                # lista los .o dentro del archive
nm libft.a | grep ' T '     # símbolos (funciones) exportados
```

---

## 2. Tests con minunit

Los tests están en `tests/`. Tienen su propio Makefile que automáticamente
compila `libft.a` si no existe.

| Comando (desde `tests/`)  | Qué hace                                       |
|---------------------------|------------------------------------------------|
| `make`                    | Compila el binario `run_tests`                 |
| `make run`                | Compila + ejecuta los tests                    |
| `make re`                 | Recompila desde cero (sin ejecutar)            |
| `make re run`             | Recompila y ejecuta — útil tras cambios        |
| `make clean`              | Borra los `.o` de tests                        |
| `make fclean`             | Borra `.o` + binario `run_tests`               |

**Atajo desde la raíz** (un solo comando):

```sh
make re && cd tests && make re run && cd ..
```

**Salida sin colores ANSI** (útil para copiar/pegar):

```sh
cd tests && make run 2>&1 | sed 's/\x1b\[[0-9;]*m//g'
```

---

## 3. Añadir una función nueva (flujo completo)

Pongamos que vas a implementar `ft_bzero`. Los pasos son **siempre los mismos**:

```sh
# 1. Crea el archivo .c en la raíz (con su #include "libft.h")
$EDITOR ft_bzero.c

# 2. Añade el prototipo a libft.h (en la sección correspondiente)
$EDITOR libft.h

# 3. Añade el archivo a SRCS en el Makefile principal
$EDITOR Makefile

# 4. Activa el test: en tests/test_libft.c
#    - cambia "#if 0" -> "#if 1" del bloque de ft_bzero
#    - descomenta "mu_run_test(test_ft_bzero);" en all_tests()
$EDITOR tests/test_libft.c

# 5. Compila y testea
make re && cd tests && make re run
```

Si el test pasa: commit. Si falla: arregla la implementación y repite el paso 5.

---

## 4. Git — flujo habitual

```sh
git status                      # ver qué cambió
git diff                        # ver el contenido de los cambios
git diff --staged               # ver cambios ya en staging

git add ft_bzero.c libft.h Makefile tests/test_libft.c
git commit -m "Add ft_bzero with tests"

git push                        # subir a GitHub (gracias al credential helper, sin pedir token)
git pull                        # bajar cambios del remoto
```

**Ver historial:**

```sh
git log --oneline -10           # últimos 10 commits, una línea cada uno
git log -p ft_strlen.c          # historia detallada de un archivo
```

**Deshacer cambios sin commitear** (¡cuidado, pierdes el trabajo!):

```sh
git restore ft_atoi.c           # descarta cambios en un archivo
git restore --staged ft_atoi.c  # quita del staging (no descarta el cambio)
```

---

## 5. Inspeccionar `libft.a`

```sh
# Lista los archivos objeto dentro del archive
ar t libft.a

# Lista todos los símbolos (funciones) que exporta
nm libft.a | grep ' T '

# Extrae un .o del archive (útil para debugging)
ar x libft.a ft_strlen.o
```

---

## 6. Verificar Norm (cuando quieras)

Si tienes `norminette` instalado:

```sh
norminette ft_*.c libft.h        # checkea normas 42 en todos los .c y el header
norminette --help
```

Si no lo tienes y lo quieres:

```sh
pip3 install --user norminette
```

(esto es opcional; los tests verifican comportamiento, norminette verifica estilo)

---

## 7. Empezar de cero

Cuando quieras una limpieza total:

```sh
make fclean                     # limpia raíz
cd tests && make fclean && cd ..  # limpia tests
```

Tras esto solo quedan los `.c`, `.h`, `Makefile`, `README.md` y `tests/*.c|*.h|Makefile`.

---

## 8. Trucos varios

**Recompilar solo un archivo:**

```sh
make ft_strlen.o
```

**Compilar un mini programa que use libft (sin instalar):**

```sh
cc tu_test.c libft.a -I. -o tu_test
./tu_test
```

**Buscar dónde se usa una función:**

```sh
grep -n "ft_strlen" *.c
```

**Contar líneas de código:**

```sh
wc -l ft_*.c libft.h
```
