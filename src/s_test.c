#include "../includes/printf_tester.h"

int	g_test_no;

void sig_handler(int signum)
{
	freopen ("/dev/tty", "a", stdout);
	printf(BYEL"%d: SIGSEG\n" CRESET, g_test_no);
	exit(0);
}
void timeout_handler(int signum)
{
	freopen ("/dev/tty", "a", stdout);
	printf(BRED"%d: TIMEOUT\n" CRESET, g_test_no);
	exit(0);
}

void	s_testit(char *s);

void	s_testitmix();

void	s_test(void)
{

	printf(UCYN"category s\n"CRESET);
	s_testit("wtf");
	s_testit("man");
	s_testit("whyyyy?");
	s_testit("");
	s_testit("how in the mother of 8u9pwgo");
	s_testit("/./vxb,xce9 rat83a4a9wtdfg dfo    dgpoijsdf;;goi");
	s_testit("eykafjallajokull");
	s_testit("hlynur");
	s_testit("svekkur idha hjallafjallafjokull");
	s_testit("42");
	s_testit("Здраво, ја сам Давид");
	s_testit("који курац јебе мацу твоје мајке");
	s_testit("collons");
	s_testit("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n\n\n\n\n\n\n\n\n");
	s_testit("什么他妈的是他妈的你妈妈的猫");
	s_testit("hijo de\n");
	s_testit("ta gueule");
	s_testit("ostia");
	s_testit("12345678924857082934573498257-324985-349026843-690834092572398570320849573409257802387520348570238570923457802394875023847509238475023874509823745908237458902374590872345897234098572349057238");
	s_testit("\\\\\\\\\\\\\\\\\\\\\\");
	s_testit("hjälp mig");
	s_testit(NULL);
	s_testitmix(NULL);
	printf("%c", 10);
	exit(0); 
}

void	s_testit(char *s)
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


	i = 0;
	g_test_no++;
	signal(SIGALRM, timeout_handler);
	alarm(TIME_OUT);
	signal(SIGSEGV, sig_handler);
	delay(SPEED);
	freopen("expected_output.txt", "w", stdout);
	ret1 = printf("string is: %s", s);
	freopen ("/dev/tty", "a", stdout);

	freopen("user_output.txt", "w", stdout);
	ret2 = ft_printf("string is: %s", s);
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
		printf(BGRN"%d: OK " CRESET, g_test_no);
	if (i != 2)
		printf(BRED"%d: ERR " CRESET, g_test_no);
//	printf("\nbuffer1: %s\nbuffer2: %s\n", buffer1, buffer2);
}

void	s_testitmix()
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


	i = 0;
	g_test_no++;
	signal(SIGSEGV, sig_handler);
	delay(SPEED);
	freopen("expected_output.txt", "w", stdout);
	ret1 = printf("string is: %s and also %s and also %s and perhaps even %s why %s%s%s or %s", NULL, "", "WHY", "  \t \n \v", "hahahajajajajaja", "		~~~~~		", "hjälp", "nećakinja");
	freopen ("/dev/tty", "a", stdout);

	freopen("user_output.txt", "w", stdout);
	ret2 = ft_printf("string is: %s and also %s and also %s and perhaps even %s why %s%s%s or %s", NULL, "", "WHY", "  \t \n \v", "hahahajajajajaja", "		~~~~~		", "hjälp", "nećakinja");
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
		printf(BGRN"%d: OK " CRESET, g_test_no);
	if (i != 2)
		printf(BRED"%d: ERR " CRESET, g_test_no);
//	printf("\nbuffer1: %s\nbuffer2: %s\n", buffer1, buffer2);
}
