#include "printf_tester.h"
#include <signal.h>

int	g_test_no;

void sig_handler_c(int signum)
{
	printf(BYEL"%d: SIGSEG\n" CRESET, g_test_no);
	exit(0);
}

void	c_test(void)
{
	char *buffer1;
	char *buffer2;
	int	n1;
	int	n2;
	int	ret1;
	int	ret2;
	int	fd1;
	int	fd2;
	int	i;

	printf(CYN"%%c\n");

//////// TEST 1 /////////

	buffer1 = NULL;
	buffer2 = NULL;
	i = 0;
	g_test_no++;
	signal(SIGSEGV, sig_handler_c);
	delay(SPEED);
	freopen("expected_output.txt", "w", stdout);
	ret1 = printf("%c", 42);
	freopen ("/dev/tty", "a", stdout);

	freopen("user_output.txt", "w", stdout);
	ret2 = ft_printf("%c", 42);
	freopen ("/dev/tty", "a", stdout);

	fd1 = open("expected_output.txt", O_RDWR);
	fd2 = open("user_output.txt", O_RDWR);
	if (buffer1 == NULL)
		buffer1 = malloc(10001);
	if (buffer2 == NULL)
		buffer2 = malloc(10001);

	n1 = read(fd1, buffer1, 10000);
	n2 = read(fd2, buffer2, 10000);

	if (strncmp(buffer1, buffer2, n1) == 0)
		i++;
	if (ret1 == ret2)
		i++;
	if (i == 2)
		printf(BGRN"1: OK  " CRESET);
	if (i != 2)
		printf(BRED"1: ERR  " CRESET);


	free(buffer1);
	free(buffer2);


//////// TEST 2 /////////


	g_test_no++;
	signal(SIGSEGV, sig_handler_c);
	i = 0;
	delay(SPEED);
	freopen("expected_output.txt", "w", stdout);
	ret1 = printf("char is: %c", '\t');
	freopen ("/dev/tty", "a", stdout);

	freopen("user_output.txt", "w", stdout);
	ret2 = ft_printf("char is: %c", '\t');
	freopen ("/dev/tty", "a", stdout);

	buffer1 = malloc(10000);
	buffer2 = malloc(10000);

	n1 = read(fd1, buffer1, 10000);
	n2 = read(fd2, buffer2, 10000);

	if (strncmp(buffer1, buffer2, n1) == 0)
		i++;
	if (ret1 == ret2)
		i++;
	if (i == 2)
		printf(BGRN"2: OK  " CRESET);
	if (i != 2)
		printf(BRED"2: ERR  " CRESET);

	free(buffer1);
	free(buffer2);


//////// TEST 3 /////////


	g_test_no++;
	signal(SIGSEGV, sig_handler_c);
	i = 0;
	delay(SPEED);
	freopen("expected_output.txt", "w", stdout);
	ret1 = printf("%c%c%c%c", 126, 202, 48, 49);
	freopen ("/dev/tty", "a", stdout);

	freopen("user_output.txt", "w", stdout);
	ret2 = ft_printf("%c%c%c%c", 126, 202, 48, 49);
	freopen ("/dev/tty", "a", stdout);

	buffer1 = malloc(10000);
	buffer2 = malloc(10000);

	n1 = read(fd1, buffer1, 10000);
	n2 = read(fd2, buffer2, 10000);

	if (strncmp(buffer1, buffer2, n1) == 0)
		i++;
	if (ret1 == ret2)
		i++;
	if (i == 2)
		printf(BGRN"3: OK\n" CRESET);
	if (i != 2)
		printf(BRED"3: ERR\n" CRESET);
	exit(0);


//////// TEST 4 /////////


	g_test_no++;
	signal(SIGSEGV, sig_handler_c);
	i = 0;
	delay(SPEED);
	freopen("expected_output.txt", "w", stdout);
	ret1 = printf("  %s %s ", "what", "");
	freopen ("/dev/tty", "a", stdout);

	freopen("user_output.txt", "w", stdout);
	ret2 = ft_printf("  %s %s ", "what", "");
	freopen ("/dev/tty", "a", stdout);

	buffer1 = malloc(10000);
	buffer2 = malloc(10000);

	n1 = read(fd1, buffer1, 10000);
	n2 = read(fd2, buffer2, 10000);

	if (strncmp(buffer1, buffer2, n1) == 0)
		i++;
	if (ret1 == ret2)
		i++;
	if (i == 2)
		printf(BGRN"4: OK  " CRESET);
	if (i != 2)
		printf(BRED"4: ERR  " CRESET);
	free(buffer1);
	free(buffer2);

//////// TEST 5 /////////


	g_test_no++;
	signal(SIGSEGV, sig_handler_c);
	i = 0;
	delay(SPEED);
	freopen("expected_output.txt", "w", stdout);
	ret1 = printf("Why is life so %s", "fun");
	freopen ("/dev/tty", "a", stdout);

	freopen("user_output.txt", "w", stdout);
	ret2 = ft_printf("Why is life so %s", "fun");
	freopen ("/dev/tty", "a", stdout);

	fd1 = open("expected_output.txt", O_RDWR);
	fd2 = open("user_output.txt", O_RDWR);
	buffer1 = malloc(10000);
	buffer2 = malloc(10000);

	n1 = read(fd1, buffer1, 10000);
	n2 = read(fd2, buffer2, 10000);

	if (strncmp(buffer1, buffer2, n1) == 0)
		i++;
	if (ret1 == ret2)
		i++;
	if (i == 2)
		printf(BGRN"5: OK  " CRESET);
	if (i != 2)
		printf(BRED"5: ERR  " CRESET);
	free(buffer1);
	free(buffer2);

	exit(0); 
}
