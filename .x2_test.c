#include "printf_tester.h"

int	g_test_no;

void sig_handler4(int signum)
{
	printf(BYEL"%d: ABORT\n" CRESET, g_test_no);
	exit(0);
}

void sig_handler3(int signum)
{
	printf(BYEL"%d: SIGSEG\n" CRESET, g_test_no);
	exit(0);
}

void	x_testit(int n);

void	x_testitmix();


void	x_test(void)
{

	printf(UCYN"category x\n"CRESET);
	x_testit(1);
	x_testit(-1);
	x_testit(0);
	x_testit(INT_MAX);
	x_testit(INT_MIN);
	x_testit((int) NULL);
	x_testit(UINT_MAX);
	x_testit(-00001);
	x_testit(0000002);
	x_testit(0000002);
	x_testit(0xab120b01);
	x_testit(0xAB120b01);
	x_testit(0xffffffff);
	x_testit((int) "");
	x_testit(0x00000000);
	x_testit(00000000000);
	x_testit(-0);
	x_testitmix();
	printf("\n");
	exit(0);
}

void	x_testit(int n)
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
	signal(SIGSEGV, sig_handler3);
	signal(SIGABRT, sig_handler4);
	i = 0;
	delay(SPEED);
	freopen("expected_output.txt", "w", stdout);
	ret1 = printf("number is: %x", 500);
	freopen ("/dev/tty", "a", stdout);

	freopen("user_output.txt", "w", stdout);
	ret2 = ft_printf("number is: %x", 500);
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



void	x_testitmix()
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
	signal(SIGSEGV, sig_handler3);
	signal(SIGABRT, sig_handler4);
	i = 0;
	delay(SPEED);
	freopen("expected_output.txt", "w", stdout);
	ret1 = printf("number is: %x and %x or %x and perhaps %x%x%x", 500, INT_MAX, INT_MIN, 0x02ad12f7, UINT_MAX, 0);
	freopen ("/dev/tty", "a", stdout);

	freopen("user_output.txt", "w", stdout);
	ret2 = ft_printf("number is: %x and %x or %x and perhaps %x%x%x", 500, INT_MAX, INT_MIN, 0x02ad12f7, UINT_MAX, 0);
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
