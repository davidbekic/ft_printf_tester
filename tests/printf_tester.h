#ifndef PRINTF_TESTER_H
# define PRINTF_TESTER_H
# define SPEED 60
# define BUFFER_SIZE 6000
#include "../libft.h"
#include "ANSI-color-codes.h"
#include <stdio.h>
#include <limits.h>
#include <stdio.h>
#include <wchar.h>
#include <unistd.h>
#include <locale.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <fcntl.h>

void	d_test(void);
void	delay(int milliseconds);
void	s_test(void);
void	i_test(void);
void	u_test(void);
void	percent_test(void);
void 	delay(int milliseconds);
void	check_leaks();
void	sig_handler2(int signum);
#endif
