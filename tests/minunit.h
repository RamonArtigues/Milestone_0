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
*/
# define mu_assert(message, test) \
	do { if (!(test)) return ((char *)(message)); } while (0)

# define mu_run_test(test) \
	do { \
		char *_msg = test(); \
		g_tests_run++; \
		if (_msg) { \
			printf("  [\033[31mFAIL\033[0m] %-24s -> %s\n", #test, _msg); \
			g_tests_failed++; \
		} else { \
			printf("  [\033[32m OK \033[0m] %s\n", #test); \
		} \
	} while (0)

# define mu_section(name) printf("\n== %s ==\n", name)

#endif
