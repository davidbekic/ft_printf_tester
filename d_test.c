#include "printf_tester.h"

int	g_test_no;

void sig_handler2(int signum)
{
	printf(BYEL"%d: SIGSEG\n" CRESET, g_test_no);
	exit(0);
}

void	d_testit(int n);

void	d_testitmix();

void	d_test(void)
{
	printf(UCYN"category d\n"CRESET);

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

void	d_testit(int n)
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
	signal(SIGSEGV, sig_handler2);
	signal(SIGABRT, sig_handler2);
	i = 0;
	delay(SPEED);
	freopen("expected_output.txt", "w", stdout);
	ret1 = printf("number is: %d", n);
	freopen ("/dev/tty", "a", stdout);

	freopen("user_output.txt", "w", stdout);
	ret2 = ft_printf("number is: %d", n);
	freopen ("/dev/tty", "a", stdout);

	fd1 = open("expected_output.txt", O_RDWR);
	fd2 = open("user_output.txt", O_RDWR);

	int lol = (int) malloc(10);
	lol = 2;
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
		printf(BGRN"%d: OK "CRESET, g_test_no);
	if (i != 2)
		printf(BRED"%d: ERR "CRESET, g_test_no);
	//printf("buffer1: %s\nbuffer2: %s\n", buffer1, buffer2);
}

void	d_testitmix()
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
	signal(SIGSEGV, sig_handler2);
	signal(SIGABRT, sig_handler2);
	i = 0;
	delay(SPEED);
	freopen("expected_output.txt", "w", stdout);
	ret1 = printf("number is: %d and %d and %d%d and %d %d %d %d as well as %d%d %d %d", 12, 14, INT_MAX, -2222, 0, -1, INT_MIN, 600, (int) NULL, (INT_MIN + INT_MAX), -0000001, 00000012);
	freopen ("/dev/tty", "a", stdout);

	freopen("user_output.txt", "w", stdout);
	ret2 = ft_printf("number is: %d and %d and %d%d and %d %d %d %d as well as %d%d %d %d", 12, 14, INT_MAX, -2222, 0, -1, INT_MIN, 600, (int) NULL, (INT_MIN + INT_MAX), -0000001, 00000012);
	freopen ("/dev/tty", "a", stdout);

	fd1 = open("expected_output.txt", O_RDWR);
	fd2 = open("user_output.txt", O_RDWR);

	int lol = (int) malloc(10);
	lol = 2;
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
		printf(BGRN"%d: OK "CRESET, g_test_no);
	if (i != 2)
		printf(BRED"%d: ERR "CRESET, g_test_no);
//	printf("buffer1: %s\nbuffer2: %s\n", buffer1, buffer2);
}
