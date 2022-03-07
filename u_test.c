#include "printf_tester.h"

int	g_test_no;

void sig_handler_u(int signum)
{
	printf(BYEL"%d: SIGSEG\n" CRESET, g_test_no);
	exit(0);
}

void	u_testit(int n);

void	u_testitmix();

void	u_test(void)
{
	printf(UCYN"category u\n"CRESET);

	u_testit(24);
	u_testit(INT_MAX);
	u_testit(INT_MIN);
	u_testit(-25);
	u_testit(0);
	u_testit(1);
	u_testit(34059);
	u_testit(24);
	u_testit(-255);
	u_testit(UINT_MAX);
	u_testitmix();
	printf("\n");

	exit(0);
}

void	u_testit(int n)
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
	i = 0;
	delay(SPEED);
	freopen("expected_output.txt", "w", stdout);
	ret1 = printf("number is: %u", 24);
	freopen ("/dev/tty", "a", stdout);

	freopen("user_output.txt", "w", stdout);
	ret2 = ft_printf("number is: %u", 24);
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
		printf(BGRN"%d: OK  "CRESET, g_test_no);
	if (i != 2)
		printf(BRED"%d: ERR  "CRESET, g_test_no);
}

void	u_testitmix()
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
	i = 0;
	delay(SPEED);
	freopen("expected_output.txt", "w", stdout);
	ret1 = printf("number is: %u and %u and %u%u and %u %u %u %u as well as %u%u %u %u", 12, 14, UINT_MAX, -2222, 0, -1, INT_MIN, 600, (int) NULL, (INT_MIN + INT_MAX), -0000001, 00000012);
	freopen ("/dev/tty", "a", stdout);

	freopen("user_output.txt", "w", stdout);
	ret2 = ft_printf("number is: %u and %u and %u%u and %u %u %u %u as well as %u%u %u %u", 12, 14, UINT_MAX, -2222, 0, -1, INT_MIN, 600, (int) NULL, (INT_MIN + INT_MAX), -0000001, 00000012);
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
		printf(BGRN"%d: OK  "CRESET, g_test_no);
	if (i != 2)
		printf(BRED"%d: ERR  "CRESET, g_test_no);
}
