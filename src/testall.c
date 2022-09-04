#include "../includes/printf_tester.h"

int	main(void)
{
	char	test[20];
	int		i;
	int		pid;
	int		status;
	int		ret;

	i = 0;
			printf("\n");
			delay(SPEED);
			printf(CYNHB"                          "CRESET);
			delay(SPEED);
			printf(MAGHB"                          "CRESET);
			delay(SPEED);
			printf("\n");
			delay(SPEED);
			printf(MAGHB"                          "CRESET);
			delay(SPEED);
			printf(CYNHB"                          "CRESET);
			delay(SPEED);
			printf("\n");
			delay(SPEED);
			printf(MAGHB"   "CRESET);
			delay(SPEED);
			printf("                                              ");
			delay(SPEED);
			printf(CYNHB"   "CRESET);
			printf("\n");
			printf(CYNHB"   "CRESET);
			printf(BCYN"   DBEKIC'S "CRESET);
			printf(BHMAG"FT_PRINTF "CRESET);
			delay(SPEED);
			printf(BCYN"MANDATORY PART TESTER   "CRESET);
			printf(CYNHB"   "CRESET);
			printf("\n");
			printf(CYNHB"   "CRESET);
			printf("                                              ");
			delay(SPEED);
			printf(CYNHB"   "CRESET);
			delay(SPEED);
			printf("\n");
			delay(SPEED);
			printf(CYNHB"                          "CRESET);
			delay(SPEED);
			printf(CYNHB"                          "CRESET);
			delay(SPEED);
			printf("\n");
			delay(SPEED);
			printf(MAGHB"                          "CRESET);
			delay(SPEED);
			printf(MAGHB"                          "CRESET);
			delay(SPEED);

	printf("\n\n\n");
	printf(BHMAG"AVAILABLE TESTS:\n"CRESET);
	printf(WHT"- all\n- d\n- u\n- c\n- s\n- %%\n- x\n- X\n- ptr\n- mix\n"CRESET);

	printf(BHMAG"\nWhich part do you want to test?: "CRESET);
	scanf("%s", test);

	if (strncmp(test, "d", 5) == 0)
	{
		pid = fork();
		if (pid != 0)
			wait(&status);
		else
			d_test();
	}
	else if (strncmp(test, "x", 5) == 0)
	{
		pid = fork();
		if (pid != 0)
			wait(&status);
		else
			x_test();
	}
	else if (strncmp(test, "p", 5) == 0)
	{
		pid = fork();
		if (pid != 0)
			wait(&status);
		else
			p_test();
	}
	else if (strncmp(test, "c", 5) == 0)
	{
		pid = fork();
		if (pid != 0)
			wait(&status);
		else
			c_test();
	}
	else if (strncmp(test, "i", 5) == 0)
	{
		pid = fork();
		if (pid != 0)
			wait(&status);
		else
			i_test();
	}
	else if (strncmp(test, "u", 5) == 0)
	{
		pid = fork();
		if (pid != 0)
			wait(&status);
		else
			u_test();
	}
	else if (strncmp(test, "all", 5) == 0)
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
		pid = fork();
		if (pid != 0)
			wait(0);
		else
			s_test();
	}
	else if (strncmp(test, "X", 5) == 0)
	{
		pid = fork();
		if (pid != 0)
			wait(0);
		else
			x2_test();
	}
	else if (strncmp(test, "%", 5) == 0)
	{
		pid = fork();
		if (pid != 0)
			wait(0);
		else
			percent_test();
	}
	else if (strncmp(test, "mix", 5) == 0)
	{
		pid = fork();
		if (pid != 0)
			wait(0);
		else
			blend_test();
	}
	else 
		printf(BRED"BAD INPUT\n"CRESET);




}
