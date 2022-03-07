#include "printf_tester.h"

int	g_test_no;

void sig_handler2(int signum)
{
	printf(BYEL"%d: SIGSEG\n" CRESET, g_test_no);
	exit(0);
}


void	d_test(void)
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


	printf(CYN"%%d\n");


//////// TEST 1 /////////

	g_test_no++;
	signal(SIGSEGV, sig_handler2);
	i = 0;
	delay(SPEED);
	freopen("expected_output.txt", "w", stdout);
	ret1 = printf("number is: %d", 24);
	freopen ("/dev/tty", "a", stdout);

	freopen("user_output.txt", "w", stdout);
	ret2 = ft_printf("number is: %d", 24);
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
		printf(BGRN"1: OK  " CRESET);
	if (i != 2)
		printf(BRED"1: ERR  " CRESET);



//////// TEST 2 /////////


	g_test_no++;
	signal(SIGSEGV, sig_handler2);
	i = 0;
	delay(SPEED);
	freopen("expected_output.txt", "w", stdout);
	ret1 = printf("number is: %d", -100);
	freopen ("/dev/tty", "a", stdout);

	freopen("user_output.txt", "w", stdout);
	ret2 = ft_printf("number is: %d", -100);
	freopen ("/dev/tty", "a", stdout);

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
		printf(BGRN"2: OK  "CRESET);
	if (i != 2)
		printf(BRED"2: ERR  "CRESET);



//////// TEST 3 /////////


	g_test_no++;
	signal(SIGSEGV, sig_handler2);
	i = 0;
	delay(SPEED);
	freopen("expected_output.txt", "w", stdout);
	ret1 = printf("number is: %d", INT_MAX);
	freopen ("/dev/tty", "a", stdout);

	freopen("user_output.txt", "w", stdout);
	ret2 = ft_printf("number is: %d", INT_MAX);
	freopen ("/dev/tty", "a", stdout);

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
		printf(BGRN"3: OK  " CRESET);
	if (i != 2)
		printf(BRED"3: ERR  " CRESET);

//////// TEST 4 /////////


	g_test_no++;
	signal(SIGSEGV, sig_handler2);
	i = 0;
	delay(SPEED);
	freopen("expected_output.txt", "w", stdout);
	ret1 = printf("number is: %d", INT_MAX - 1);
	freopen ("/dev/tty", "a", stdout);

	freopen("user_output.txt", "w", stdout);
	ret2 = ft_printf("number is: %d", INT_MAX - 1);
	freopen ("/dev/tty", "a", stdout);

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
		printf(BGRN"4: OK  " CRESET);
	if (i != 2)
		printf(BGRN"4: ERR  " CRESET);



//////// TEST 5 /////////


	g_test_no++;
	signal(SIGSEGV, sig_handler2);
	i = 0;
	delay(SPEED);
	freopen("expected_output.txt", "w", stdout);
	ret1 = printf("number is: %d", INT_MIN);
	freopen ("/dev/tty", "a", stdout);

	freopen("user_output.txt", "w", stdout);
	ret2 = ft_printf("number is: %d", INT_MIN);
	freopen ("/dev/tty", "a", stdout);

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
		printf(BGRN"5: OK  \n" CRESET);
	if (i != 2)
		printf(BRED"5: ERR  \n" CRESET);

	check_leaks();
	exit(0);
}
