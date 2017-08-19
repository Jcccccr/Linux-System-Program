#include<stdio.h>
int main(int argc, char**argv)
{
	bool opt_r = false;
	bool opt_l = false;
	bool opt_s = false;
	char *src = NULL;
	char *dest = NULL;
	char c;
	while ((c = getopt(argc, argv, "rRls")) != -1)
	{
		switch (c)
		{
		case 'R':
		case 'r':
			opt_r = true;
			break;
		case 'l':
			opt_l = true;
			break;
		case 's':
			opt_s = true;
			break;
		}
	}
	if (optind >= argc - 1)
	{
		printf("quan shao zuocuo fu\n");
		exit(1);
	}
	src = argv[optind];
	dest = argv[optind + 1];
	if (opt_l)
	{
		if (isdir(src))
		{
			printf("mu lu bu neng chuang jian ying lian jie\n");
			exit(1);
		}
		if ((link(src, dest)) == 0)
			return 0;
		else
		{
			print("create ying lie jie shibai\n");
			exit(1);
		}
	}
	if (opt_s)
	{
		if (isdir(src))
		{
			printf("mu lu bu neng chuang jian fuhao lianjie\n");
			exit(1);
		}
		if ((symlink(src, dest)) == 0)
			return 0;
		else
		{
			printf("chuang jian liejie shibai\n");
			exit(1);
		}
	}
	return 0;
}