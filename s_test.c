#include "printf_tester.h"
#include <signal.h>

int	g_test_no;

void sig_handler(int signum)
{
	printf(BYEL"%d: SIGSEG\n" CRESET, g_test_no);
	exit(0);
}

void	s_test(void)
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

	printf(CYN"%%s\n"CRESET);

//////// TEST 1 /////////

	i = 0;
	g_test_no++;
	signal(SIGSEGV, sig_handler);
	delay(SPEED);
	freopen("expected_output.txt", "w", stdout);
	ret1 = printf("%s", "hey man");
	freopen ("/dev/tty", "a", stdout);

	freopen("user_output.txt", "w", stdout);
	ret2 = ft_printf("%s", "hey man");
	freopen ("/dev/tty", "a", stdout);

	fd1 = open("expected_output.txt", O_RDWR);
	fd2 = open("user_output.txt", O_RDWR);

	n1 = read(fd1, buffer1, 10000);
	n2 = read(fd2, buffer2, 10000);
	buffer1[n1] = 0;
	buffer2[n1] = 0;
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
	signal(SIGSEGV, sig_handler);
	i = 0;
	delay(SPEED);
	freopen("expected_output.txt", "w", stdout);
	ret1 = printf("string is: %s", "Wh&201sl;g.zxb<>*&@#_)*#@&\t\n");
	freopen ("/dev/tty", "a", stdout);

	freopen("user_output.txt", "w", stdout);
	ret2 = ft_printf("string is: %s", "Wh&201sl;g.zxb<>*&@#_)*#@&\t\n");
	freopen ("/dev/tty", "a", stdout);

	n1 = read(fd1, buffer1, 10000);
	n2 = read(fd2, buffer2, 10000);
	buffer1[n1] = 0;
	buffer2[n1] = 0;
	lseek(fd1, 0, SEEK_SET);
	lseek(fd2, 0, SEEK_SET);

	if (strncmp(buffer1, buffer2, n1) == 0)
		i++;
	if (ret1 == ret2)
		i++;
	if (i == 2)
		printf(BGRN"2: OK  " CRESET);
	if (i != 2)
		printf(BRED"2: ERR  " CRESET);


//////// TEST 3 /////////


	g_test_no++;
	signal(SIGSEGV, sig_handler);
	i = 0;
	delay(SPEED);
	freopen("expected_output.txt", "w", stdout);
	ret1 = printf("%s%s%s%s", "guay", "lol", "-12", "111111111111111111111111");
	freopen ("/dev/tty", "a", stdout);

	freopen("user_output.txt", "w", stdout);
	ret2 = ft_printf("%s%s%s%s", "guay", "lol", "-12", "111111111111111111111111");
	freopen ("/dev/tty", "a", stdout);

	n1 = read(fd1, buffer1, 10000);
	n2 = read(fd2, buffer2, 10000);
	buffer1[n1] = 0;
	buffer2[n1] = 0;
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
	signal(SIGSEGV, sig_handler);
	i = 0;
	delay(SPEED);
	freopen("expected_output.txt", "w", stdout);
	ret1 = printf("  %s %s ", "what", "");
	freopen ("/dev/tty", "a", stdout);

	freopen("user_output.txt", "w", stdout);
	ret2 = ft_printf("  %s %s ", "what", "");
	freopen ("/dev/tty", "a", stdout);

	n1 = read(fd1, buffer1, 10000);
	n2 = read(fd2, buffer2, 10000);
	buffer1[n1] = 0;
	buffer2[n1] = 0;
	lseek(fd1, 0, SEEK_SET);
	lseek(fd2, 0, SEEK_SET);

	if (strncmp(buffer1, buffer2, n1) == 0)
		i++;
	if (ret1 == ret2)
		i++;
	if (i == 2)
		printf(BGRN"4: OK  " CRESET);
	if (i != 2)
		printf(BRED"4: ERR  " CRESET);

//////// TEST 5 /////////


	g_test_no++;
	signal(SIGSEGV, sig_handler);
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

	n1 = read(fd1, buffer1, 10000);
	n2 = read(fd2, buffer2, 10000);
	buffer1[n1] = 0;
	buffer2[n1] = 0;
	lseek(fd1, 0, SEEK_SET);
	lseek(fd2, 0, SEEK_SET);

	if (strncmp(buffer1, buffer2, n1) == 0)
		i++;
	if (ret1 == ret2)
		i++;
	if (i == 2)
		printf(BGRN"5: OK  " CRESET);
	if (i != 2)
		printf(BRED"5: ERR  " CRESET);


//////// TEST 6 /////////


	g_test_no++;
	signal(SIGSEGV, sig_handler);
	i = 0;
	delay(SPEED);
	freopen("expected_output.txt", "w", stdout);
	ret1 = printf("%s", "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
	freopen ("/dev/tty", "a", stdout);

	freopen("user_output.txt", "w", stdout);
	ret2 = ft_printf("%s", "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
	freopen ("/dev/tty", "a", stdout);

	fd1 = open("expected_output.txt", O_RDWR);
	fd2 = open("user_output.txt", O_RDWR);

	n1 = read(fd1, buffer1, 10000);
	n2 = read(fd2, buffer2, 10000);
	buffer1[n1] = 0;
	buffer2[n1] = 0;
	lseek(fd1, 0, SEEK_SET);
	lseek(fd2, 0, SEEK_SET);

	if (strncmp(buffer1, buffer2, n1) == 0)
		i++;
	if (ret1 == ret2)
		i++;
	if (i == 2)
		printf(BGRN"6: OK  " CRESET);
	if (i != 2)
		printf(BRED"6: ERR  " CRESET);

//////// TEST 7 /////////


	g_test_no++;
	signal(SIGSEGV, sig_handler);
	i = 0;
	delay(SPEED);
	freopen("expected_output.txt", "w", stdout);
	ret1 = printf("Why is life so %s", "!@#@$%(*™£ºª¢º™–•¡™£–º¡ª™£¡§™£∞¡¶§£¢");
	freopen ("/dev/tty", "a", stdout);

	freopen("user_output.txt", "w", stdout);
	ret2 = ft_printf("Why is life so %s", "!@#@$%(*™£ºª¢º™–•¡™£–º¡ª™£¡§™£∞¡¶§£¢");
	freopen ("/dev/tty", "a", stdout);

	fd1 = open("expected_output.txt", O_RDWR);
	fd2 = open("user_output.txt", O_RDWR);

	n1 = read(fd1, buffer1, 10000);
	n2 = read(fd2, buffer2, 10000);
	buffer1[n1] = 0;
	buffer2[n1] = 0;
	lseek(fd1, 0, SEEK_SET);
	lseek(fd2, 0, SEEK_SET);

	if (strncmp(buffer1, buffer2, n1) == 0)
		i++;
	if (ret1 == ret2)
		i++;
	if (i == 2)
		printf(BGRN"7: OK  " CRESET);
	if (i != 2)
		printf(BRED"7: ERR  " CRESET);


//////// TEST 8 /////////


	g_test_no++;
	signal(SIGSEGV, sig_handler);
	i = 0;
	delay(SPEED);
	freopen("expected_output.txt", "w", stdout);
	ret1 = printf("Why is life so %s", "ha•ha•ha•");
	freopen ("/dev/tty", "a", stdout);

	freopen("user_output.txt", "w", stdout);
	ret2 = ft_printf("Why is life so %s", "ha•ha•ha•");
	freopen ("/dev/tty", "a", stdout);

	fd1 = open("expected_output.txt", O_RDWR);
	fd2 = open("user_output.txt", O_RDWR);


	n1 = read(fd1, buffer1, 10000);
	n2 = read(fd2, buffer2, 10000);
	buffer1[n1] = 0;
	buffer2[n1] = 0;
	lseek(fd1, 0, SEEK_SET);
	lseek(fd2, 0, SEEK_SET);

	if (strncmp(buffer1, buffer2, n1) == 0)
		i++;
	if (ret1 == ret2)
		i++;
	if (i == 2)
		printf(BGRN"8: OK  " CRESET);
	if (i != 2)
		printf(BRED"8: ERR  " CRESET);


//////// TEST 9 /////////



	g_test_no++;
	signal(SIGSEGV, sig_handler);
	i = 0;
//	char *rubbish;
	delay(SPEED);
	freopen("/dev/null", "a", stdout);
	setbuf(stdout, buffer1);
	ret1 = printf("Why is life so %s", "ha•ha•ha•");
	freopen ("/dev/tty", "a", stdout);

	freopen("/dev/null", "a", stdout);
	setbuf(stdout, buffer2);
	ret2 = ft_printf("Why is life so %s", "ha•ha•ha•");
	freopen ("/dev/tty", "a", stdout);
	
	n1 = read(fd1, buffer1, 10000);
	n2 = read(fd2, buffer2, 10000);
	buffer1[n1] = 0;
	buffer2[n1] = 0;
	lseek(fd1, 0, SEEK_SET);
	lseek(fd2, 0, SEEK_SET);
	if (strncmp(buffer1, buffer2, strlen(buffer1) + strlen(buffer2)) == 0)
		i++;
	if (ret1 == ret2)
		i++;
	if (i == 2)
		printf(BGRN"9: OK\n" CRESET);
	if (i != 2)
		printf(BRED"9: ERR\n" CRESET);
	check_leaks();
	exit(0); 
}
