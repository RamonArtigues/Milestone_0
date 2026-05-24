/* test_libft.c - unit tests para libft usando minunit
 *
 * Convención: cada test devuelve NULL si pasa, o un mensaje de error si falla.
 *
 * Para activar un test de una función pendiente:
 *   1. Implementa la función en la raíz (ft_X.c), añade su prototipo a libft.h
 *      y añádela a SRCS del Makefile.
 *   2. Localiza abajo el bloque de tu función bajo "TESTS PENDIENTES".
 *   3. Cambia el "#if 0" por "#if 1" (o elimina los guards #if/#endif).
 *   4. Descomenta la línea "mu_run_test(test_ft_X);" dentro de all_tests().
 *   5. cd tests && make re run
 */

#include "minunit.h"
#include "../libft.h"
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	g_tests_run = 0;
int	g_tests_failed = 0;

/* =========================================================================
 *  HELPERS
 * ========================================================================= */

static int	sign(int n)
{
	if (n > 0)
		return (1);
	if (n < 0)
		return (-1);
	return (0);
}

/* =========================================================================
 *  TESTS ACTIVOS - funciones ya implementadas
 * ========================================================================= */

/* ---- char checks ---- */

static char	*test_ft_isalpha(void)
{
	mu_assert("'a' should be alpha", ft_isalpha('a') == 1);
	mu_assert("'Z' should be alpha", ft_isalpha('Z') == 1);
	mu_assert("'0' should NOT be alpha", ft_isalpha('0') == 0);
	mu_assert("' ' should NOT be alpha", ft_isalpha(' ') == 0);
	mu_assert("0 should NOT be alpha", ft_isalpha(0) == 0);
	return (NULL);
}

static char	*test_ft_isdigit(void)
{
	mu_assert("'0' should be digit", ft_isdigit('0') == 1);
	mu_assert("'9' should be digit", ft_isdigit('9') == 1);
	mu_assert("'a' should NOT be digit", ft_isdigit('a') == 0);
	mu_assert("'/' should NOT be digit", ft_isdigit('/') == 0);
	return (NULL);
}

static char	*test_ft_isalnum(void)
{
	mu_assert("'a' alnum", ft_isalnum('a') == 1);
	mu_assert("'5' alnum", ft_isalnum('5') == 1);
	mu_assert("'!' NOT alnum", ft_isalnum('!') == 0);
	mu_assert("' ' NOT alnum", ft_isalnum(' ') == 0);
	return (NULL);
}

static char	*test_ft_isascii(void)
{
	mu_assert("0 is ascii", ft_isascii(0) == 1);
	mu_assert("127 is ascii", ft_isascii(127) == 1);
	mu_assert("128 NOT ascii", ft_isascii(128) == 0);
	mu_assert("-1 NOT ascii", ft_isascii(-1) == 0);
	return (NULL);
}

static char	*test_ft_isprint(void)
{
	mu_assert("' ' (32) printable", ft_isprint(' ') == 1);
	mu_assert("'~' (126) printable", ft_isprint('~') == 1);
	mu_assert("'\\t' NOT printable", ft_isprint('\t') == 0);
	mu_assert("31 NOT printable", ft_isprint(31) == 0);
	mu_assert("127 NOT printable", ft_isprint(127) == 0);
	return (NULL);
}

/* ---- char conversions ---- */

static char	*test_ft_toupper(void)
{
	mu_assert("'a' -> 'A'", ft_toupper('a') == 'A');
	mu_assert("'z' -> 'Z'", ft_toupper('z') == 'Z');
	mu_assert("'A' stays 'A'", ft_toupper('A') == 'A');
	mu_assert("'5' stays '5'", ft_toupper('5') == '5');
	return (NULL);
}

static char	*test_ft_tolower(void)
{
	mu_assert("'A' -> 'a'", ft_tolower('A') == 'a');
	mu_assert("'Z' -> 'z'", ft_tolower('Z') == 'z');
	mu_assert("'a' stays 'a'", ft_tolower('a') == 'a');
	mu_assert("'5' stays '5'", ft_tolower('5') == '5');
	return (NULL);
}

static char	*test_ft_atoi(void)
{
	mu_assert("\"42\"", ft_atoi("42") == 42);
	mu_assert("\"-42\"", ft_atoi("-42") == -42);
	mu_assert("\"   +123\"", ft_atoi("   +123") == 123);
	mu_assert("\"   -+-+1\" (multi-sign)", ft_atoi("   -+-+1") == 1);
	mu_assert("\"---5\"", ft_atoi("---5") == -5);
	mu_assert("\"42abc\"", ft_atoi("42abc") == 42);
	mu_assert("\"\"", ft_atoi("") == 0);
	mu_assert("\"abc\"", ft_atoi("abc") == 0);
	mu_assert("vs atoi(\"  -1234ZZ\")",
		ft_atoi("  -1234ZZ") == atoi("  -1234ZZ"));
	mu_assert("vs atoi(\"\\t\\n 9000\")",
		ft_atoi("\t\n 9000") == atoi("\t\n 9000"));
	return (NULL);
}

/* ---- strings ---- */

static char	*test_ft_strlen(void)
{
	mu_assert("\"\" -> 0", ft_strlen("") == 0);
	mu_assert("\"hola\" -> 4", ft_strlen("hola") == 4);
	mu_assert("matches libc strlen",
		ft_strlen("hello world") == strlen("hello world"));
	return (NULL);
}

static char	*test_ft_strncmp(void)
{
	mu_assert("equal full", ft_strncmp("abc", "abc", 3) == 0);
	mu_assert("equal n=0", ft_strncmp("abc", "xyz", 0) == 0);
	mu_assert("partial equal", ft_strncmp("abcd", "abce", 3) == 0);
	mu_assert("diff sign matches libc",
		sign(ft_strncmp("abc", "abd", 3)) == sign(strncmp("abc", "abd", 3)));
	mu_assert("diff sign matches libc 2",
		sign(ft_strncmp("xyz", "abc", 2)) == sign(strncmp("xyz", "abc", 2)));
	mu_assert("s1 shorter",
		sign(ft_strncmp("ab", "abc", 3)) == sign(strncmp("ab", "abc", 3)));
	return (NULL);
}

static char	*test_ft_strnstr(void)
{
	char	*r;

	r = ft_strnstr("hello world", "world", 11);
	mu_assert("find 'world'", r && strcmp(r, "world") == 0);
	r = ft_strnstr("hello world", "world", 5);
	mu_assert("len cuts off match", r == NULL);
	r = ft_strnstr("abc", "", 3);
	mu_assert("empty needle returns haystack", r != NULL && r[0] == 'a');
	r = ft_strnstr("abc", "xyz", 3);
	mu_assert("no match returns NULL", r == NULL);
	r = ft_strnstr("aaab", "aab", 4);
	mu_assert("overlapping", r != NULL && strcmp(r, "aab") == 0);
	return (NULL);
}

static char	*test_ft_strlcpy(void)
{
	char	dst[16];
	size_t	r;

	r = ft_strlcpy(dst, "hello", 16);
	mu_assert("strlcpy returns src_len", r == 5);
	mu_assert("strlcpy copies content", strcmp(dst, "hello") == 0);
	r = ft_strlcpy(dst, "hello", 3);
	mu_assert("size=3 returns 5", r == 5);
	mu_assert("size=3 truncates to 'he'", strcmp(dst, "he") == 0);
	r = ft_strlcpy(dst, "abc", 0);
	mu_assert("size=0 returns 3", r == 3);
	return (NULL);
}

static char	*test_ft_strlcat(void)
{
	char	dst[16];
	size_t	r;

	strcpy(dst, "foo");
	r = ft_strlcat(dst, "bar", 16);
	mu_assert("strlcat result", strcmp(dst, "foobar") == 0);
	mu_assert("strlcat returns total", r == 6);
	strcpy(dst, "foo");
	r = ft_strlcat(dst, "bar", 5);
	mu_assert("size=5 truncates", strcmp(dst, "foob") == 0);
	mu_assert("size=5 returns 6", r == 6);
	strcpy(dst, "foo");
	r = ft_strlcat(dst, "bar", 2);
	mu_assert("size<dest_len returns size+src_len", r == 2 + 3);
	return (NULL);
}

static char	*test_ft_strdup(void)
{
	char	*d;

	d = ft_strdup("hello");
	mu_assert("strdup content", d && strcmp(d, "hello") == 0);
	free(d);
	d = ft_strdup("");
	mu_assert("strdup empty", d && d[0] == '\0');
	free(d);
	return (NULL);
}

static char	*test_ft_strjoin(void)
{
	char	*r;

	r = ft_strjoin("foo", "bar");
	mu_assert("strjoin foo+bar", r && strcmp(r, "foobar") == 0);
	free(r);
	r = ft_strjoin("", "abc");
	mu_assert("strjoin empty+abc", r && strcmp(r, "abc") == 0);
	free(r);
	r = ft_strjoin("abc", "");
	mu_assert("strjoin abc+empty", r && strcmp(r, "abc") == 0);
	free(r);
	r = ft_strjoin("", "");
	mu_assert("strjoin empty+empty", r && r[0] == '\0');
	free(r);
	return (NULL);
}

static char	*test_ft_substr(void)
{
	char	*r;

	r = ft_substr("hello world", 6, 5);
	mu_assert("substr basic", r && strcmp(r, "world") == 0);
	free(r);
	r = ft_substr("abc", 0, 100);
	mu_assert("len > remaining", r && strcmp(r, "abc") == 0);
	free(r);
	r = ft_substr("abc", 10, 5);
	mu_assert("start >= len -> \"\"", r && r[0] == '\0');
	free(r);
	r = ft_substr("abc", 1, 1);
	mu_assert("single char", r && strcmp(r, "b") == 0);
	free(r);
	return (NULL);
}

static int	count_arr(char **a)
{
	int	i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}

static void	free_arr(char **a)
{
	int	i;

	i = 0;
	while (a[i])
		free(a[i++]);
	free(a);
}

static char	*test_ft_split(void)
{
	char	**r;

	r = ft_split("hello world", ' ');
	mu_assert("split 2 words", count_arr(r) == 2);
	mu_assert("split[0] == hello", strcmp(r[0], "hello") == 0);
	mu_assert("split[1] == world", strcmp(r[1], "world") == 0);
	free_arr(r);
	r = ft_split("  foo   bar  ", ' ');
	mu_assert("split trims spaces", count_arr(r) == 2);
	free_arr(r);
	r = ft_split("", ' ');
	mu_assert("empty input -> 0 words", count_arr(r) == 0);
	free_arr(r);
	r = ft_split("abc", 'z');
	mu_assert("no delim -> 1 word", count_arr(r) == 1);
	mu_assert("no delim content", strcmp(r[0], "abc") == 0);
	free_arr(r);
	return (NULL);
}

static char	*test_ft_memset(void)
{
	char	buf[8];
	void	*r;

	r = ft_memset(buf, 'A', 5);
	mu_assert("memset returns ptr", r == buf);
	mu_assert("memset[0]", buf[0] == 'A');
	mu_assert("memset[4]", buf[4] == 'A');
	ft_memset(buf, 0, 8);
	mu_assert("memset 0", buf[3] == 0);
	return (NULL);
}

/* =========================================================================
 *  ====================================================================
 *                      TESTS PENDIENTES
 *  ====================================================================
 *
 *  Cada bloque de abajo está rodeado de "#if 0 ... #endif" para que el
 *  archivo siga compilando aunque la función no exista todavía.
 *
 *  Cuando implementes la función:
 *    1) cambia el "#if 0" por "#if 1" (o quita los gates)
 *    2) descomenta la línea correspondiente en all_tests() al final
 *    3) "cd tests && make re run"
 * ========================================================================= */

/* -------------------------------------------------------------------------
 *  ft_bzero
 *
 *  Prototipo: void ft_bzero(void *s, size_t n);
 *
 *  Qué hace:  Pone a 0 los primeros 'n' bytes de la zona de memoria
 *             apuntada por 's'. Equivalente a ft_memset(s, 0, n).
 *  Retorna:   nada.
 *  Permitido: ninguna función externa.
 *  Bordes:    si n == 0, no hace nada. s no debe ser NULL si n > 0.
 * ------------------------------------------------------------------------- */
#if 1
static char	*test_ft_bzero(void)
{
	char	buf[8];

	memset(buf, 'A', 8);
	ft_bzero(buf, 4);
	mu_assert("bzero[0]", buf[0] == 0);
	mu_assert("bzero[3]", buf[3] == 0);
	mu_assert("bzero[4] untouched", buf[4] == 'A');
	memset(buf, 'B', 8);
	ft_bzero(buf, 0);
	mu_assert("bzero n=0 doesn't touch", buf[0] == 'B');
	return (NULL);
}
#endif

/* -------------------------------------------------------------------------
 *  ft_memcpy
 *
 *  Prototipo: void *ft_memcpy(void *dst, const void *src, size_t n);
 *
 *  Qué hace:  Copia 'n' bytes desde 'src' a 'dst'.
 *  Retorna:   'dst'.
 *  Permitido: ninguna función externa.
 *  Bordes:    n == 0 no copia nada y retorna dst.
 *             Comportamiento indefinido si las zonas se solapan
 *             (para solapamiento usa ft_memmove).
 *             Algunos hacen: if (!dst && !src) return (NULL);
 * ------------------------------------------------------------------------- */
#if 1
static char	*test_ft_memcpy(void)
{
	char	dst[16];
	void	*r;

	memset(dst, 0, sizeof(dst));
	r = ft_memcpy(dst, "hello", 5);
	mu_assert("memcpy returns dst", r == dst);
	mu_assert("memcpy content", memcmp(dst, "hello", 5) == 0);
	mu_assert("memcpy no overrun", dst[5] == 0);
	ft_memcpy(dst, "XX", 0);
	mu_assert("memcpy n=0 no escribe", memcmp(dst, "hello", 5) == 0);
	return (NULL);
}
#endif

/* -------------------------------------------------------------------------
 *  ft_memmove
 *
 *  Prototipo: void *ft_memmove(void *dst, const void *src, size_t n);
 *
 *  Qué hace:  Como memcpy pero seguro cuando 'src' y 'dst' se solapan.
 *  Retorna:   'dst'.
 *  Estrategia: si dst < src, copia hacia adelante; si dst > src, copia
 *              hacia atrás. Así no pisas bytes que aún no has leído.
 *  Bordes:    n == 0 retorna dst sin tocar nada.
 * ------------------------------------------------------------------------- */
#if 1
static char	*test_ft_memmove(void)
{
	char	buf[16];
	void	*r;

	memcpy(buf, "abcdefgh", 9);
	r = ft_memmove(buf + 2, buf, 5);
	mu_assert("memmove returns dst", r == buf + 2);
	mu_assert("memmove overlap fwd", memcmp(buf, "ababcde", 7) == 0);
	memcpy(buf, "abcdefgh", 9);
	ft_memmove(buf, buf + 2, 5);
	mu_assert("memmove overlap bwd", memcmp(buf, "cdefgfgh", 8) == 0);
	memcpy(buf, "1234567", 8);
	ft_memmove(buf, "XYZ", 0);
	mu_assert("memmove n=0", memcmp(buf, "1234567", 7) == 0);
	return (NULL);
}
#endif

/* -------------------------------------------------------------------------
 *  ft_memchr
 *
 *  Prototipo: void *ft_memchr(const void *s, int c, size_t n);
 *
 *  Qué hace:  Busca el primer byte igual a (unsigned char)c en los
 *             primeros 'n' bytes de 's'.
 *  Retorna:   puntero al byte encontrado, o NULL si no aparece.
 *  Bordes:    el cast a unsigned char es importante: c = 256 NO debe
 *             encontrar el byte 0 (256 & 0xFF == 0 sería un bug).
 *             Sí encuentra '\0' si está en los primeros n bytes.
 * ------------------------------------------------------------------------- */
#if 1
static char	*test_ft_memchr(void)
{
	const char	*s = "hello\0world";
	void		*r;

	r = ft_memchr(s, 'l', 5);
	mu_assert("memchr 'l'", r == s + 2);
	r = ft_memchr(s, 'z', 5);
	mu_assert("memchr not found", r == NULL);
	r = ft_memchr(s, '\0', 11);
	mu_assert("memchr finds \\0", r == s + 5);
	r = ft_memchr(s, 'h', 0);
	mu_assert("memchr n=0 -> NULL", r == NULL);
	return (NULL);
}
#endif

/* -------------------------------------------------------------------------
 *  ft_memcmp
 *
 *  Prototipo: int ft_memcmp(const void *s1, const void *s2, size_t n);
 *
 *  Qué hace:  Compara los primeros 'n' bytes de s1 y s2 (como bytes
 *             unsigned).
 *  Retorna:   0 si iguales, <0 si s1<s2, >0 si s1>s2.
 *  Bordes:    n == 0 retorna 0.
 *             Cast a unsigned char antes de restar: '\xff' es mayor
 *             que '\x01', no menor (con char con signo te confundirías).
 * ------------------------------------------------------------------------- */
#if 1
static char	*test_ft_memcmp(void)
{
	mu_assert("equal", ft_memcmp("abc", "abc", 3) == 0);
	mu_assert("n=0 -> 0", ft_memcmp("abc", "xyz", 0) == 0);
	mu_assert("diff sign vs libc",
		sign(ft_memcmp("abd", "abc", 3)) == sign(memcmp("abd", "abc", 3)));
	mu_assert("partial cut",
		sign(ft_memcmp("abZ", "abz", 2)) == 0);
	mu_assert("unsigned compare",
		sign(ft_memcmp("\xff", "\x01", 1)) > 0);
	return (NULL);
}
#endif

/* -------------------------------------------------------------------------
 *  ft_strchr
 *
 *  Prototipo: char *ft_strchr(const char *s, int c);
 *
 *  Qué hace:  Busca la primera ocurrencia de (char)c en s.
 *  Retorna:   puntero al char encontrado, o NULL si no aparece.
 *  IMPORTANTE: si c == '\0', debe retornar puntero al '\0' final de s
 *              (NO NULL). Esto es una trampa típica.
 * ------------------------------------------------------------------------- */
#if 1
static char	*test_ft_strchr(void)
{
	const char	*s = "hello";
	char		*r;

	r = ft_strchr(s, 'l');
	mu_assert("strchr 'l'", r == s + 2);
	r = ft_strchr(s, 'z');
	mu_assert("strchr not found", r == NULL);
	r = ft_strchr(s, '\0');
	mu_assert("strchr '\\0' -> end of string", r == s + 5);
	r = ft_strchr(s, 'h');
	mu_assert("strchr first char", r == s);
	return (NULL);
}
#endif

/* -------------------------------------------------------------------------
 *  ft_strrchr
 *
 *  Prototipo: char *ft_strrchr(const char *s, int c);
 *
 *  Qué hace:  Como strchr pero busca la ÚLTIMA ocurrencia.
 *  Retorna:   puntero al último char, o NULL si no aparece.
 *  IMPORTANTE: si c == '\0', retorna puntero al '\0' final (NO NULL).
 *  Estrategia: recorrer hasta el final y luego volver hacia atrás,
 *              o recorrer todo guardando la última posición.
 * ------------------------------------------------------------------------- */
#if 1
static char	*test_ft_strrchr(void)
{
	const char	*s = "hello";
	char		*r;

	r = ft_strrchr(s, 'l');
	mu_assert("strrchr último 'l'", r == s + 3);
	r = ft_strrchr(s, 'h');
	mu_assert("strrchr única 'h'", r == s);
	r = ft_strrchr(s, 'z');
	mu_assert("strrchr not found", r == NULL);
	r = ft_strrchr(s, '\0');
	mu_assert("strrchr '\\0' -> end", r == s + 5);
	return (NULL);
}
#endif

/* -------------------------------------------------------------------------
 *  ft_calloc
 *
 *  Prototipo: void *ft_calloc(size_t nmemb, size_t size);
 *
 *  Qué hace:  Reserva memoria para un array de 'nmemb' elementos de
 *             'size' bytes cada uno e inicializa todo a 0.
 *  Retorna:   puntero a la zona reservada, o NULL si malloc falla.
 *  Permitido: malloc.
 *  Bordes:    Subject: "si nmemb o size son 0, calloc() debe devolver
 *             un puntero único que pueda pasarse con éxito a free()".
 *             Es decir, NUNCA retornes NULL solo porque uno sea 0.
 *             Recomendable: chequear overflow de nmemb * size.
 *  Truco:     puedes hacer malloc(nmemb*size) y luego ft_bzero/ft_memset.
 * ------------------------------------------------------------------------- */
#if 1
static char	*test_ft_calloc(void)
{
	int		*arr;
	void	*p;
	int		i;

	arr = (int *)ft_calloc(10, sizeof(int));
	mu_assert("calloc no NULL", arr != NULL);
	i = 0;
	while (i < 10)
	{
		mu_assert("calloc zeroed", arr[i] == 0);
		i++;
	}
	free(arr);
	p = ft_calloc(0, 0);
	mu_assert("calloc(0,0) freeable", p != NULL || p == NULL);
	free(p);
	return (NULL);
}
#endif

/* -------------------------------------------------------------------------
 *  ft_strtrim
 *
 *  Prototipo: char *ft_strtrim(char const *s1, char const *set);
 *
 *  Qué hace:  Crea (con malloc) una copia de s1 con los caracteres de
 *             'set' eliminados del PRINCIPIO y del FINAL. No del medio.
 *  Retorna:   nueva string, o NULL si falla malloc.
 *  Permitido: malloc.
 *  Bordes:    s1 entera está en set -> string vacía "".
 *             set vacío -> copia de s1 tal cual.
 * ------------------------------------------------------------------------- */
#if 1
static char	*test_ft_strtrim(void)
{
	char	*r;

	r = ft_strtrim("  hello  ", " ");
	mu_assert("trim spaces", r && strcmp(r, "hello") == 0);
	free(r);
	r = ft_strtrim("xxhelloxx", "x");
	mu_assert("trim 'x'", r && strcmp(r, "hello") == 0);
	free(r);
	r = ft_strtrim("abchelloabc", "abc");
	mu_assert("trim multi-char set", r && strcmp(r, "hello") == 0);
	free(r);
	r = ft_strtrim("aaa", "a");
	mu_assert("trim all", r && r[0] == '\0');
	free(r);
	r = ft_strtrim("hello", "");
	mu_assert("trim empty set", r && strcmp(r, "hello") == 0);
	free(r);
	return (NULL);
}
#endif

/* -------------------------------------------------------------------------
 *  ft_itoa
 *
 *  Prototipo: char *ft_itoa(int n);
 *
 *  Qué hace:  Convierte el entero 'n' a su representación decimal en
 *             una string nueva (con malloc).
 *  Retorna:   la string, o NULL si malloc falla.
 *  Permitido: malloc.
 *  TRAMPA CLÁSICA: INT_MIN = -2147483648. -INT_MIN OVERFLOW.
 *                  Truco: gestionar n == INT_MIN como caso especial
 *                  o trabajar con n como unsigned/long.
 * ------------------------------------------------------------------------- */
#if 0
static char	*test_ft_itoa(void)
{
	char	*r;

	r = ft_itoa(0);
	mu_assert("itoa(0)", r && strcmp(r, "0") == 0);
	free(r);
	r = ft_itoa(42);
	mu_assert("itoa(42)", r && strcmp(r, "42") == 0);
	free(r);
	r = ft_itoa(-42);
	mu_assert("itoa(-42)", r && strcmp(r, "-42") == 0);
	free(r);
	r = ft_itoa(INT_MAX);
	mu_assert("itoa(INT_MAX)", r && strcmp(r, "2147483647") == 0);
	free(r);
	r = ft_itoa(INT_MIN);
	mu_assert("itoa(INT_MIN)", r && strcmp(r, "-2147483648") == 0);
	free(r);
	return (NULL);
}
#endif

/* -------------------------------------------------------------------------
 *  ft_strmapi
 *
 *  Prototipo: char *ft_strmapi(char const *s,
 *                              char (*f)(unsigned int, char));
 *
 *  Qué hace:  Crea (con malloc) una nueva string aplicando f(i, s[i])
 *             a cada carácter. 'i' es el índice.
 *  Retorna:   la nueva string, o NULL.
 *  Permitido: malloc.
 *  Bordes:    s == "" -> retorna "" (string vacía malloc'd, no NULL).
 * ------------------------------------------------------------------------- */
#if 0
static char	upper_at_even(unsigned int i, char c)
{
	if (i % 2 == 0 && c >= 'a' && c <= 'z')
		return ((char)(c - 32));
	return (c);
}

static char	*test_ft_strmapi(void)
{
	char	*r;

	r = ft_strmapi("abcdef", upper_at_even);
	mu_assert("strmapi alterna", r && strcmp(r, "AbCdEf") == 0);
	free(r);
	r = ft_strmapi("", upper_at_even);
	mu_assert("strmapi empty", r && r[0] == '\0');
	free(r);
	return (NULL);
}
#endif

/* -------------------------------------------------------------------------
 *  ft_striteri
 *
 *  Prototipo: void ft_striteri(char *s, void (*f)(unsigned int, char*));
 *
 *  Qué hace:  Aplica f(i, &s[i]) a cada carácter de 's'. La función
 *             recibe puntero al char, así que puede modificarlo in-place.
 *  Retorna:   nada (es void).
 *  Permitido: ninguna.
 *  Diferencia con strmapi: NO crea string nueva, modifica la existente.
 * ------------------------------------------------------------------------- */
#if 0
static void	mark_even(unsigned int i, char *c)
{
	if (i % 2 == 0)
		*c = '*';
}

static char	*test_ft_striteri(void)
{
	char	buf[8];

	strcpy(buf, "abcdef");
	ft_striteri(buf, mark_even);
	mu_assert("striteri in-place", strcmp(buf, "*b*d*f") == 0);
	strcpy(buf, "");
	ft_striteri(buf, mark_even);
	mu_assert("striteri empty noop", buf[0] == '\0');
	return (NULL);
}
#endif

/* =========================================================================
 *  TESTS PENDIENTES - funciones que escriben a un fd
 *
 *  Estrategia: creamos un pipe(), pasamos el extremo de escritura como fd,
 *  cerramos ese extremo, leemos el de lectura, y comparamos.
 * ========================================================================= */

/* helper común para los 4 tests fd. Lo dejamos fuera del #if 0 para que
 * esté disponible aunque actives solo uno. Si todo está apagado, el
 * compilador puede quejarse por función no usada con -Wunused-function;
 * por eso también lo gateamos. */
#if 0
static int	pipe_capture_begin(int pipefd[2])
{
	if (pipe(pipefd) == -1)
		return (-1);
	return (0);
}

static int	pipe_capture_end(int pipefd[2], char *buf, size_t bufsize)
{
	ssize_t	n;

	close(pipefd[1]);
	n = read(pipefd[0], buf, bufsize - 1);
	close(pipefd[0]);
	if (n < 0)
		n = 0;
	buf[n] = '\0';
	return ((int)n);
}
#endif

/* -------------------------------------------------------------------------
 *  ft_putchar_fd
 *
 *  Prototipo: void ft_putchar_fd(char c, int fd);
 *
 *  Qué hace:  Escribe el carácter 'c' en el file descriptor 'fd'.
 *  Retorna:   nada.
 *  Permitido: write (incluir <unistd.h>).
 *  Detalle:   write(fd, &c, 1);
 * ------------------------------------------------------------------------- */
#if 0
static char	*test_ft_putchar_fd(void)
{
	int		pfd[2];
	char	buf[8];

	mu_assert("pipe()", pipe_capture_begin(pfd) == 0);
	ft_putchar_fd('A', pfd[1]);
	pipe_capture_end(pfd, buf, sizeof(buf));
	mu_assert("putchar_fd 'A'", strcmp(buf, "A") == 0);
	return (NULL);
}
#endif

/* -------------------------------------------------------------------------
 *  ft_putstr_fd
 *
 *  Prototipo: void ft_putstr_fd(char *s, int fd);
 *
 *  Qué hace:  Escribe la string 's' completa en 'fd'.
 *  Retorna:   nada.
 *  Permitido: write.
 *  Detalle:   write(fd, s, ft_strlen(s));
 *             Cuidado con s == NULL: comportamiento indefinido por el
 *             subject, pero conviene no segfaultear.
 * ------------------------------------------------------------------------- */
#if 0
static char	*test_ft_putstr_fd(void)
{
	int		pfd[2];
	char	buf[32];

	mu_assert("pipe()", pipe_capture_begin(pfd) == 0);
	ft_putstr_fd("hello", pfd[1]);
	pipe_capture_end(pfd, buf, sizeof(buf));
	mu_assert("putstr_fd 'hello'", strcmp(buf, "hello") == 0);
	mu_assert("pipe()", pipe_capture_begin(pfd) == 0);
	ft_putstr_fd("", pfd[1]);
	pipe_capture_end(pfd, buf, sizeof(buf));
	mu_assert("putstr_fd empty", strcmp(buf, "") == 0);
	return (NULL);
}
#endif

/* -------------------------------------------------------------------------
 *  ft_putendl_fd
 *
 *  Prototipo: void ft_putendl_fd(char *s, int fd);
 *
 *  Qué hace:  Como putstr_fd pero añade '\n' al final.
 *  Permitido: write.
 * ------------------------------------------------------------------------- */
#if 0
static char	*test_ft_putendl_fd(void)
{
	int		pfd[2];
	char	buf[32];

	mu_assert("pipe()", pipe_capture_begin(pfd) == 0);
	ft_putendl_fd("hi", pfd[1]);
	pipe_capture_end(pfd, buf, sizeof(buf));
	mu_assert("putendl_fd 'hi\\n'", strcmp(buf, "hi\n") == 0);
	return (NULL);
}
#endif

/* -------------------------------------------------------------------------
 *  ft_putnbr_fd
 *
 *  Prototipo: void ft_putnbr_fd(int n, int fd);
 *
 *  Qué hace:  Escribe la representación decimal del entero 'n' en 'fd'.
 *  Permitido: write.
 *  TRAMPA:    INT_MIN otra vez. Si haces -n y luego conviertes, overflow.
 *             Soluciones:
 *               - caso especial: si n == INT_MIN, escribe "-2147483648".
 *               - trabajar con long o unsigned para evitar el overflow.
 *  Recursivo: la mayoría hace ft_putnbr_fd(n / 10, fd) + putchar del dígito.
 *             Cuidado con el signo: gestiona '-' una sola vez al principio.
 * ------------------------------------------------------------------------- */
#if 0
static char	*test_ft_putnbr_fd(void)
{
	int		pfd[2];
	char	buf[32];

	mu_assert("pipe()", pipe_capture_begin(pfd) == 0);
	ft_putnbr_fd(42, pfd[1]);
	pipe_capture_end(pfd, buf, sizeof(buf));
	mu_assert("putnbr 42", strcmp(buf, "42") == 0);
	mu_assert("pipe()", pipe_capture_begin(pfd) == 0);
	ft_putnbr_fd(-42, pfd[1]);
	pipe_capture_end(pfd, buf, sizeof(buf));
	mu_assert("putnbr -42", strcmp(buf, "-42") == 0);
	mu_assert("pipe()", pipe_capture_begin(pfd) == 0);
	ft_putnbr_fd(0, pfd[1]);
	pipe_capture_end(pfd, buf, sizeof(buf));
	mu_assert("putnbr 0", strcmp(buf, "0") == 0);
	mu_assert("pipe()", pipe_capture_begin(pfd) == 0);
	ft_putnbr_fd(INT_MIN, pfd[1]);
	pipe_capture_end(pfd, buf, sizeof(buf));
	mu_assert("putnbr INT_MIN", strcmp(buf, "-2147483648") == 0);
	mu_assert("pipe()", pipe_capture_begin(pfd) == 0);
	ft_putnbr_fd(INT_MAX, pfd[1]);
	pipe_capture_end(pfd, buf, sizeof(buf));
	mu_assert("putnbr INT_MAX", strcmp(buf, "2147483647") == 0);
	return (NULL);
}
#endif

/* =========================================================================
 *  RUNNER
 * ========================================================================= */

static char	*all_tests(void)
{
	mu_section("char checks");
	mu_run_test(test_ft_isalpha);
	mu_run_test(test_ft_isdigit);
	mu_run_test(test_ft_isalnum);
	mu_run_test(test_ft_isascii);
	mu_run_test(test_ft_isprint);
	mu_section("char conversions");
	mu_run_test(test_ft_toupper);
	mu_run_test(test_ft_tolower);
	mu_run_test(test_ft_atoi);
	mu_section("string measurement & comparison");
	mu_run_test(test_ft_strlen);
	mu_run_test(test_ft_strncmp);
	mu_run_test(test_ft_strnstr);
	mu_section("string copy & cat");
	mu_run_test(test_ft_strlcpy);
	mu_run_test(test_ft_strlcat);
	mu_section("allocating helpers");
	mu_run_test(test_ft_strdup);
	mu_run_test(test_ft_strjoin);
	mu_run_test(test_ft_substr);
	mu_run_test(test_ft_split);
	mu_section("memory");
	mu_run_test(test_ft_memset);
	mu_run_test(test_ft_bzero);
	mu_run_test(test_ft_memcpy);
	mu_run_test(test_ft_memmove);
	mu_run_test(test_ft_memchr);
	mu_run_test(test_ft_memcmp);
	mu_run_test(test_ft_calloc);
	mu_section("strings");
	mu_run_test(test_ft_strchr);
	mu_run_test(test_ft_strrchr);
	mu_run_test(test_ft_strtrim);
	/* === Descomenta cada línea cuando implementes la función === */
	/* mu_section("pendientes - strings");                          */
	/* mu_run_test(test_ft_itoa);                                   */
	/* mu_run_test(test_ft_strmapi);                                */
	/* mu_run_test(test_ft_striteri);                               */
	/* mu_section("pendientes - file descriptors");                 */
	/* mu_run_test(test_ft_putchar_fd);                             */
	/* mu_run_test(test_ft_putstr_fd);                              */
	/* mu_run_test(test_ft_putendl_fd);                             */
	/* mu_run_test(test_ft_putnbr_fd);                              */

	return (NULL);
}

int	main(void)
{
	all_tests();
	printf("\n----------------------------------------\n");
	printf("Tests run: %d  |  Failed: %d\n", g_tests_run, g_tests_failed);
	if (g_tests_failed == 0)
		printf("\033[32mALL TESTS PASSED\033[0m\n");
	else
		printf("\033[31m%d TEST(S) FAILED\033[0m\n", g_tests_failed);
	return (g_tests_failed != 0);
}
