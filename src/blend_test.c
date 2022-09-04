#include "../includes/printf_tester.h"

int	g_test_no;

void sig_handler_blend(int signum)
{
	printf(BYEL"%d: ABORT\n" CRESET, g_test_no);
	exit(0);
}


void	blend_test(void)
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

	printf(UCYN"MIX MEGAPOL\n"CRESET);


//////// TEST 1 /////////


//	buffer1 = NULL;
//	buffer2 = NULL;
	g_test_no++;
	signal(SIGSEGV, sig_handler_blend);
	signal(SIGABRT, sig_handler_blend);
	i = 0;
	delay(SPEED);
	freopen("expected_output.txt", "w", stdout);
	ret1 = printf("number is: %x, isn't that %s, or what do you %p of this %d man. I dont know %u %%%i", UINT_MAX, "crazy", (void *) -25, -25, 25, 25);
	freopen ("/dev/tty", "a", stdout);

	freopen("user_output.txt", "w", stdout);
	ret2 = printf("number is: %x, isn't that %s, or what do you %p of this %d man. I dont know %u %%%i", UINT_MAX, "crazy", (void *) -25, -25, 25, 25);
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
		printf(BGRN"1: OK\n" CRESET);
	if (i != 2)
		printf(BRED"1: ERR\n" CRESET);


//	free(buffer1);
//	free(buffer2);
	exit(0);
}
