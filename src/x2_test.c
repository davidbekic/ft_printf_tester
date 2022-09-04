#include "../includes/printf_tester.h"

int	g_test_no;

void sig_handler4_X(int signum)
{
	printf(BYEL"%d: ABORT\n" CRESET, g_test_no);
	exit(0);
}

void sig_handler3_X(int signum)
{
	printf(BYEL"%d: SIGSEG\n" CRESET, g_test_no);
	exit(0);
}

void	x2_testit(int n);

void	x2_testitmix();


void	x2_test(void)
{

	printf(UCYN"category X\n"CRESET);
	x2_testit(1);
	x2_testit(-1);
	x2_testit(0);
	x2_testit(INT_MAX);
	x2_testit(INT_MIN);
	x2_testit((int) NULL);
	x2_testit(UINT_MAX);
	x2_testit(-00001);
	x2_testit(0000002);
	x2_testit(0000002);
	x2_testit(0xab120b01);
	x2_testit(0xAB120b01);
	x2_testit(0xffffffff);
	x2_testit((int) "");
	x2_testit(0x00000000);
	x2_testit(00000000000);
	x2_testit(-0);
	x2_testitmix();
	printf("\n");
	exit(0);
}

void	x2_testit(int n)
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
	signal(SIGSEGV, sig_handler3_X);
	signal(SIGABRT, sig_handler4_X);
	i = 0;
	delay(SPEED);
	freopen("expected_output.txt", "w", stdout);
	ret1 = printf("number is: %x", n);
	freopen ("/dev/tty", "a", stdout);

	freopen("user_output.txt", "w", stdout);
	ret2 = ft_printf("number is: %x", n);
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

//	free(buffer1);
//	free(buffer2);
}



void	x2_testitmix()
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
	signal(SIGSEGV, sig_handler3_X);
	signal(SIGABRT, sig_handler4_X);
	i = 0;
	delay(SPEED);
	freopen("expected_output.txt", "w", stdout);
	ret1 = printf("number is: %X and %X or %X and perhaps %X%X%X", 500, INT_MAX, INT_MIN, 0x02ad12f7, UINT_MAX, 0);
	freopen ("/dev/tty", "a", stdout);

	freopen("user_output.txt", "w", stdout);
	ret2 = ft_printf("number is: %X and %X or %X and perhaps %X%X%X", 500, INT_MAX, INT_MIN, 0x02ad12f7, UINT_MAX, 0);
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
