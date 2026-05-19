/* minunit.h - tiny C unit testing framework */
/* Based on Jera Design's minunit (http://www.jera.com/techinfo/jtns/jtn002.html) */

#ifndef MINUNIT_H
# define MINUNIT_H

# include <stdio.h>

extern int	g_tests_run;
extern int	g_tests_failed;

/*
** Each test function returns NULL on success or a "char *" error message
** on failure. mu_assert short-circuits and returns the message immediately.
** En modo verbose, cada caso que pasa también imprime su mensaje.
*/
# define mu_assert(message, test) \
	do { \
		if (!(test)) \
			return ((char *)(message)); \
		printf("    \033[32m·\033[0m %s\n", (message)); \
	} while (0)

# define mu_run_test(test) \
	do { \
		char *_msg; \
		printf("\n  \033[1m%s\033[0m\n", #test); \
		_msg = test(); \
		g_tests_run++; \
		if (_msg) { \
			printf("    \033[31m✗ FAIL\033[0m: %s\n", _msg); \
			g_tests_failed++; \
		} else { \
			printf("    \033[32m✓ pass\033[0m\n"); \
		} \
	} while (0)

# define mu_section(name) printf("\n\033[1;34m== %s ==\033[0m\n", name)

#endif
