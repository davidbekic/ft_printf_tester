#include "printf_tester.h"
#include "../libft.h"

void	i_test(void)
{
	char buffer1[100];
	char buffer2[100];
	int	ret1;
	int	ret2;
	int	i;

	printf(CYN"%%i");

//////// TEST 1 /////////

	i = 0;
	delay(300);
	freopen("/dev/null", "a", stdout);
	setbuf(stdout, buffer1);
	ret1 = ft_printf("number is: %i", 24);
	freopen ("/dev/tty", "a", stdout);

	freopen("/dev/null", "a", stdout);
	setbuf(stdout, buffer2);
	ret2 = ft_printf("number is: %i", 24);
	freopen ("/dev/tty", "a", stdout);
	
	if (strncmp(buffer1, buffer2, strlen(buffer1) + strlen(buffer2)))
		i++;
	if (ret1 == ret2)
		i++;
	if (i == 2)
		printf(BGRN"\n1: OK  " CRESET);
	if (i != 2)
		printf(BRED"\n1: ERR  " CRESET);



//////// TEST 2 /////////

	i = 0;
	delay(300);
	freopen("/dev/null", "a", stdout);
	setbuf(stdout, buffer1);
	ret1 = ft_printf("number is: %i", -100);
	freopen ("/dev/tty", "a", stdout);

	freopen("/dev/null", "a", stdout);
	setbuf(stdout, buffer2);
	ret2 = ft_printf("number is: %i", -100);
	freopen ("/dev/tty", "a", stdout);
	
	if (strncmp(buffer1, buffer2, strlen(buffer1) + strlen(buffer2)))
		i++;
	if (ret1 == ret2)
		i++;
	if (i == 2)
		printf(BGRN"2: OK  " CRESET);
	if (i != 2)
		printf(BRED"2: ERR  " CRESET);



//////// TEST 3 /////////

	delay(300);
	i = 0;
	freopen("/dev/null", "a", stdout);
	setbuf(stdout, buffer1);
	ret1 = ft_printf("number is: %i", INT_MAX);
	freopen ("/dev/tty", "a", stdout);

	freopen("/dev/null", "a", stdout);
	setbuf(stdout, buffer2);
	ret2 = ft_printf("number is: %i", INT_MAX);
	freopen ("/dev/tty", "a", stdout);
	
	if (strncmp(buffer1, buffer2, strlen(buffer1) + strlen(buffer2)))
		i++;
	if (ret1 == ret2)
		i++;
	if (i == 2)
		printf(BGRN"3: OK  " CRESET);
	if (i != 2)
		printf(BRED"3: ERR  " CRESET);


//////// TEST 4 /////////

	i = 0;
	delay(300);
	freopen("/dev/null", "a", stdout);
	setbuf(stdout, buffer1);
	ret1 = ft_printf("number is: %i", LONG_MAX);
	freopen ("/dev/tty", "a", stdout);

	freopen("/dev/null", "a", stdout);
	setbuf(stdout, buffer2);
	ret2 = ft_printf("number is: %i", LONG_MAX);
	freopen ("/dev/tty", "a", stdout);
	
	if (strncmp(buffer1, buffer2, strlen(buffer1) + strlen(buffer2)))
		i++;
	if (ret1 == ret2)
		i++;
	if (i == 2)
		printf(BGRN"4: OK  " CRESET);
	if (i != 2)
		printf(BRED"4: ERR  " CRESET);



//////// TEST 5 /////////

	i = 0;
	delay(100);
	freopen("/dev/null", "a", stdout);
	setbuf(stdout, buffer1);
	ret1 = ft_printf("number is: %i", INT_MIN);
	freopen ("/dev/tty", "a", stdout);

	freopen("/dev/null", "a", stdout);
	setbuf(stdout, buffer2);
	ret2 = ft_printf("number is: %i", INT_MIN);
	freopen ("/dev/tty", "a", stdout);
	
	if (strncmp(buffer1, buffer2, strlen(buffer1) + strlen(buffer2)))
		i++;
	if (ret1 == ret2)
		i++;
	if (i == 2)
		printf(BGRN"5: OK\n" CRESET);
	if (i != 2)
		printf(BRED"5: ERR\n" CRESET);

	exit(0);

}
