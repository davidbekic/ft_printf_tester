#include "../includes/printf_tester.h"

int	g_test_no;

void sig_handler5(int signum)
{
	printf(BYEL"%d: SIGSEG\n" CRESET, g_test_no);
	exit(0);
}

void	p_testit(void *n);

void	p_testitmix();

void	p_test(void)
{
	printf(UCYN"category p\n"CRESET);
	p_testit((void *) -22);
	p_testit((void *) LONG_MIN);
	p_testit((void *) LONG_MAX);
	p_testit((void *) LONG_MAX + 42020);
	p_testit((void *) -1);
	p_testit((void *) UINT_MAX);
	p_testit((void *) INT_MAX);
	p_testit((void *) INT_MIN);
	p_testit((void *) 5);
	p_testit((void *) 0000001215);
	p_testit(NULL);
	p_testitmix();
	printf("\n");
	exit(0);
}

void	p_testit(void *n)
{
	char buffer1[BUFFER_SIZE];
	char buffer2[BUFFER_SIZE];
	int	n1;
	int	n2;
	int	ret1;
	int	ret2;
	int	fd1;
	int	fd2;
	int	i;



	g_test_no++;
	signal(SIGSEGV, sig_handler5);
	i = 0;
	delay(SPEED);
	freopen("expected_output.txt", "w", stdout);
	ret1 = printf("number is: %p\n", (void *) -512599);
	freopen ("/dev/tty", "a", stdout);

	freopen("user_output.txt", "w", stdout);
	ret2 = ft_printf("number is: %p\n", (void *) -512599);
	freopen ("/dev/tty", "a", stdout);

	fd1 = open("expected_output.txt", O_RDWR);
	fd2 = open("user_output.txt", O_RDWR);

	n1 = read(fd1, buffer1, BUFFER_SIZE);
	n2 = read(fd2, buffer2, BUFFER_SIZE);
	buffer1[n1] = 0;
	buffer2[n2] = 0;
	lseek(fd1, 0, SEEK_SET);
	lseek(fd2, 0, SEEK_SET);

	if (strncmp(buffer1, buffer2, n1) == 0)
		i++;
	if (ret1 == ret2)
		i++;
	if (i == 2)
		printf(BGRN"%d: OK " CRESET, g_test_no);
	if (i != 2)
		printf(BRED"%d: ERR " CRESET, g_test_no);

}

void	p_testitmix()
{
	char buffer1[BUFFER_SIZE];
	char buffer2[BUFFER_SIZE];
	int	n1;
	int	n2;
	int	ret1;
	int	ret2;
	int	fd1;
	int	fd2;
	int	i;



	g_test_no++;
	signal(SIGSEGV, sig_handler5);
	i = 0;
	delay(SPEED);
	freopen("expected_output.txt", "w", stdout);
	ret1 = printf("number is: %p or is it perhaps %p or %p and %p or even %p why not %p and %p\n", (void *) -512599, (void *) INT_MAX, (void *) INT_MIN, (void *) LONG_MAX, (void *) LONG_MAX + 42001, (void *) LONG_MIN, (void *) 0);
	freopen ("/dev/tty", "a", stdout);

	freopen("user_output.txt", "w", stdout);
	ret2 = ft_printf("number is: %p or is it perhaps %p or %p and %p or even %p why not %p and %p\n", (void *) -512599, (void *) INT_MAX, (void *) INT_MIN, (void *) LONG_MAX, (void *) LONG_MAX + 42001, (void *) LONG_MIN, (void *) 0);
	freopen ("/dev/tty", "a", stdout);

	fd1 = open("expected_output.txt", O_RDWR);
	fd2 = open("user_output.txt", O_RDWR);

	n1 = read(fd1, buffer1, BUFFER_SIZE);
	n2 = read(fd2, buffer2, BUFFER_SIZE);
	buffer1[n1] = 0;
	buffer2[n2] = 0;
	lseek(fd1, 0, SEEK_SET);
	lseek(fd2, 0, SEEK_SET);

	if (strncmp(buffer1, buffer2, n1) == 0)
		i++;
	if (ret1 == ret2)
		i++;
	if (i == 2)
		printf(BGRN"%d: OK " CRESET, g_test_no);
	if (i != 2)
		printf(BRED"%d: ERR " CRESET, g_test_no);

//	printf("\nbuffer1: %s\nbuffer2: %s\n", buffer1, buffer2);
}
