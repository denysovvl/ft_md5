#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


char	*dectobin(int n)
{
	int i = 7;
	char *buf;

	buf = (char *)malloc(sizeof(char) * 9);
	ft_memset(buf, '0', 8);
	buf[8] = '\0';
	while (n > 0)
	{
		buf[i] = (n % 2) + '0';
		n = n / 2;
		i--; 
	}
	return (buf);
}

void	printbase(int num)
{
	char c;

	c = num + 65; // A-Z
	if (num > 25)
		c = num + 71;
	if (num > 51)
		c = num - 4;
	ft_printf("%c", c);
}

int		bintodec(char *str)
{
	int i;
	int num;
	int sum;

	num = 1;
	sum = 0;
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (str[i] == '1')
			sum += num;
		num *= 2;
		i--;
	}
	return (sum);
}

char	*join(char *av, int len)
{
	int		i = -1;
	char *buf;
	char *tmp;
	char *input;

	input = ft_strnew(0);
	while (++i < len)
	{
		buf = dectobin(av[i]);
		tmp = input;
		if (!(input = ft_strjoin(input, buf)))
			return (NULL);
		free(buf);
		ft_strdel(&tmp);
	}
	return (input);
}

void	padding(char *str, int len, int ptr)
{
	char *tmp;
	char *sub;
	int pad;

	pad = 0;
	while (len != 6)
	{
		tmp = str;
		if (!(str = ft_strjoin(str, "00")))
			return ;
		printf("TEMP = %s\n", tmp);
		printf("STR  = %s\n", str);
		ft_strdel(&tmp);
		printf("TEMP = %s\n", tmp);
		len += 2;
		pad += 1;
	}
	sub = ft_strsub(str, ptr, 6);
	printbase(bintodec(sub));
	free(sub);
	while (pad--)
		ft_printf("=");
}

void	strdelim(char *str, int len)
{
	int ptr;
	int n;
	char *sub;
	char *tmp;

	ptr = 0;
	while (len >= 6)
	{
		tmp = str;
		sub = ft_strsub(str, ptr, 6);
		n = bintodec(sub);
		printbase(n);
		free(sub);
		ptr += 6;
		len -= 6;
	}
	printf("\nlen = %d\n", len);
	if (len)
		padding(str, len, ptr);
	ft_printf("\n");
}

void		base64(t_flags *flag, int ac, char **av)
{
	if (!flag || !ac)
		return ;
	int len = strlen(av[2]);
	char *input;

	input = join(av[2], len);
	strdelim(input, strlen(input));

	//system("leaks ft_ssl");
	free(input);
}

int 	main(int ac, char **av)
{
	if (ac < 2)
		return 0;
	base64(av[1]);
}












