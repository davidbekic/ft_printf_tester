#include "../includes/printf_tester.h"

int	g_test_no;


void	d_testit(int n);

void	d_testitmix();

void	i_test(void)
{
	printf(UCYN"category i\n"CRESET);

	d_testit(24);
	d_testit(INT_MAX);
	d_testit(INT_MIN);
	d_testit(INT_MAX - 1);
	d_testit(INT_MIN + 1);
	d_testit(-250000);
	d_testit(250000);
	d_testit(42);
	d_testit(0);
	d_testit(-0);
	d_testit(-00003);
	d_testit(00000003);
	d_testit((int) NULL);
	d_testitmix();
	printf("\n");

	exit(0);
}
