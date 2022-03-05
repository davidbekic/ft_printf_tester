#include "printf_tester.h"
#include <signal.h>


int	main(void)
{
	char	test[20];
	int		i;
	int		pid;
	int		status;
	int		ret;

	i = 0;
	while (i < 200)
	{
		if (i % 1 == 0 && i != 99 && i != 101 && i != 100)
			printf(CYNHB"  "CRESET);
		if (i % 2 == 0 && i != 99 && i != 101 && i != 100)
			printf(MAGHB"  "CRESET);
		if (i == 20 || i == 40 || i == 60 || i == 80 || i == 100 || i == 120 || i == 140 || i == 160 || i == 180)
			printf("\n");
		if (i == 99)
			printf(MAGHB"\n------------------------------------------------------------------\n"CRESET);
		if (i == 100)
		{
			printf(BCYN"¡DBEKIC'S "CRESET);
			printf(BHMAG"FT_PRINTF "CRESET);
			printf(BCYN"MANDATORY PART TESTER!\n"CRESET);
		}
		if (i == 101)
			printf(BMAG"\n------------------------------------------------------------------\n");
		delay(SPEED / 10);
		i++;
	}

	printf("\n\n\n");
	printf(BHMAG"AVAILABLE TESTS:\n"CRESET);
	printf(WHT"- all\n- d\n- u\n- c\n- s\n- %%\n- x\n- X\n- ptr\n- mix\n"CRESET);

	printf(BHMAG"\nWhich part do you want to test?: "CRESET);
	scanf("%s", test);

	if (strncmp(test, "d", 5) == 0)
	{
	printf(BWHT"testing %s...\n"CRESET, test);
		pid = fork();
		if (pid != 0)
			wait(&status);
		else
			d_test();
	}
	else if (strncmp(test, "x", 5) == 0)
	{
	printf(BWHT"testing %s...\n"CRESET, test);
		pid = fork();
		if (pid != 0)
			wait(&status);
		else
			x_test();
	}
	else if (strncmp(test, "p", 5) == 0)
	{
	printf(BWHT"testing %s...\n"CRESET, test);
		pid = fork();
		if (pid != 0)
			wait(&status);
		else
			p_test();
	}
	else if (strncmp(test, "c", 5) == 0)
	{
	printf(BWHT"testing %s...\n"CRESET, test);
		pid = fork();
		if (pid != 0)
			wait(&status);
		else
			c_test();
	}
	else if (strncmp(test, "i", 5) == 0)
	{
	printf(BWHT"testing %s...\n"CRESET, test);
		pid = fork();
		if (pid != 0)
			wait(&status);
		else
			i_test();
	}
	else if (strncmp(test, "u", 5) == 0)
	{
	printf(BWHT"testing %s...\n"CRESET, test);
		pid = fork();
		if (pid != 0)
			wait(&status);
		else
			u_test();
	}
	else if (strncmp(test, "all", 5) == 0)
	{
	printf(BWHT"testing %s...\n"CRESET, test);
		pid = fork();
		if (pid != 0)
			wait(&status);
		else
			d_test();
		pid = fork();
		if (pid != 0)
			wait(&status);
		else	
			s_test();
		pid = fork();
		if (pid != 0)
			wait(&status);
		else	
			c_test();
		pid = fork();
		if (pid != 0)
			wait(&status);
		else
			i_test();
		pid = fork();
		if (pid != 0)
			wait(&status);
		else
			u_test();
		pid = fork();
		if (pid != 0)
			wait(&status);
		else
			percent_test();
		pid = fork();
		if (pid != 0)
			wait(&status);
		else
			x_test();
		pid = fork();
		if (pid != 0)
			wait(&status);
		else
			x2_test();
		pid = fork();
		if (pid != 0)
			wait(&status);
		else
			p_test();
		pid = fork();
		if (pid != 0)
			wait(&status);
		else
			blend_test();
	}
	else if (strncmp(test, "s", 5) == 0)
	{
		printf(BWHT"testing %s...\n"CRESET, test);
		pid = fork();
		if (pid != 0)
			wait(0);
		else
			s_test();
	}
	else if (strncmp(test, "%", 5) == 0)
	{
		printf(BWHT"testing %s...\n"CRESET, test);
		pid = fork();
		if (pid != 0)
			wait(0);
		else
			percent_test();
	}
	else 
		printf(BRED"BAD INPUT\n"CRESET);




}
