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
//		delay(2);
		i++;
	}

	printf("\n\n\n");
	printf(BHMAG"AVAILABLE TESTS:\n"CRESET);
	printf(BWHT"- all\n- d\n- u\n- c\n- s\n- %%\n"CRESET);

	printf(BHMAG"\nWhich part do you want to test?: "CRESET);
	scanf("%s", test);
	printf(BWHT"testing %s...\n"CRESET, test);

	if (strncmp(test, "d", 1) == 0)
	{
		pid = fork();
		if (pid != 0)
			wait(&status);
		else
			d_test();
	}
	if (strncmp(test, "i", 1) == 0)
		i_test();
	if (strncmp(test, "u", 1) == 0)
		u_test();
	if (strncmp(test, "all", 3) == 0)
	{
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
	}
	if (strncmp(test, "s", 1) == 0)
	{
		pid = fork();
		if (pid != 0)
			wait(0);
		else
			s_test();
	}
	if (strncmp(test, "%", 1) == 0)
		pid = fork();
		if (pid != 0)
			wait(0);
		else
			percent_test();




}
