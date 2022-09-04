#include "printf_tester.h"
#include <signal.h>

int	g_test_no;

void	c_testit(char c);

void	c_testitmix();

void sig_handler_c(int signum)
{
	printf(BYEL"%d: SIGSEG\n" CRESET, g_test_no);
	exit(0);
}

void	c_test(void)
{

	printf(UCYN"category c\n"CRESET);

	c_testit('c');
	c_testit('D');
	c_testit(42);
	c_testit(0);
	c_testit(12);
	c_testit(32);
	c_testit(99);
	c_testit(124);
	c_testit(127);
	c_testitmix();
	printf("\n");
	exit(0); 
}

void	c_testit(char c)
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


//////// INDIVIDUAL TESTS /////////

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
		printf(BGRN"%d: OK " CRESET, g_test_no);
	if (i != 2)
		printf(BRED"%d: ERR " CRESET, g_test_no);


	free(buffer1);
	free(buffer2);
}

//////// MIX TEST /////////

void	c_testitmix()
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



	buffer1 = NULL;
	buffer2 = NULL;
	i = 0;
	g_test_no++;
	signal(SIGSEGV, sig_handler_c);
	delay(SPEED);
	freopen("expected_output.txt", "w", stdout);
	ret1 = printf("%c%c%c what is up %c %c ", 42, 32, 50, 125, 127);
	freopen ("/dev/tty", "a", stdout);

	freopen("user_output.txt", "w", stdout);
	ret2 = ft_printf("%c%c%c what is up %c %c ", 42, 32, 50, 125, 127);
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
		printf(BGRN"%d: OK " CRESET, g_test_no);
	if (i != 2)
		printf(BRED"%d: ERR " CRESET, g_test_no);


	free(buffer1);
	free(buffer2);
}

