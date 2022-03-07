#ifndef PRINTF_TESTER_H
# define PRINTF_TESTER_H
# define SPEED 50
# define BUFFER_SIZE 6000
# define TIME_OUT 3
#include "ANSI-color-codes.h"
#include <stdlib.h>
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
#include <signal.h>

void	d_test(void);
void	d_testit(int n);
void	x2_test(void);
int		ft_printf(const char *format, ...);
void	blend_test(void);
void	p_test(void);
void	x_test(void);
void	delay(int milliseconds);
void	s_test(void);
void	c_test(void);
void	i_test(void);
void	u_test(void);
void	percent_test(void);
void 	delay(int milliseconds);
void	check_leaks();
void	sig_handler2(int signum);
#endif
