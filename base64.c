#include "ft_base64.h"

char	*dectobin(unsigned int n)
{
	int i = 7;
	char *buf;

	buf = (char *)malloc(sizeof(char) * 9);
	ft_memset(buf, '0', 8);
	buf[8] = '\0';
	while (n > 0)
	{
		buf[i] = (n % 2) + '0';
		n = n >> 1;
		i--; 
	}
	return (buf);
}

char	*dectobindec(int n)
{
	int i = 5;
	int c;
	char *buf;

	c = n + 4;
	if (n == 43)
		c = n + 19;
	if (n == 47)
		c = n + 16;
	if (n > 64)
		c = n - 65;
	if (n > 96)
		c = n - 71;
	buf = (char *)malloc(sizeof(char) * 6);
	ft_memset(buf, '0', 6);
	buf[6] = '\0';
	while (c > 0)
	{
		buf[i] = (c % 2) + '0';
		c = c >> 1;
		i--; 
	}
	if (n == 32 || n == 10)
		buf[0] = '\0';
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
	if (num == 62)
		c = num - 19;
	if (num == 63)
		c = num - 16;
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
		num <<= 1;
		i--;
	}
	return (sum);
}

char	*join(unsigned char *av, int len, int mode)
{
	int		i = -1;
	char *buf;
	char *tmp;
	char *input;

	input = ft_strnew(0);
	while (++i < len)
	{
		if (!mode)
			buf = dectobin(av[i]);
		else
			buf = dectobindec(av[i]);
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
		ft_strdel(&tmp);
		len += 2;
		pad += 1;
	}
	sub = ft_strsub(str, ptr, 6);
	ft_strdel(&str);
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
	};
	if (len)
		padding(str, len, ptr);
	ft_printf("\n");
}

void	strdelimdec(char *str, int len)
{
	int ptr;
	int n;
	char *sub;
	char *tmp;

	ptr = 0;
	if (len % 8)
		exit(0); //error
	while (len > 0)
	{
		tmp = str;
		sub = ft_strsub(str, ptr, 8);
		n = bintodec(sub);
		ft_printf("%c", n);
		free(sub);
		ptr += 8;
		len -= 8;
	}
	ft_printf("\n");
}

void		base64(t_flags *flag, int ac, char **av)
{
	unsigned char *input;
	char *bin;
	int len;

	if (!flag || !ac)
		return ;
	len = ft_strlen(av[2]);
	input = (unsigned char *)malloc(len + 1);

	ft_memcpy(input, av[2], len);

	// bin = join(input, len, ENC);
	// strdelim(bin, ft_strlen(bin));

	bin = join(input, len, DEC);
	strdelimdec(bin, ft_strlen(bin));
}

//если символ с зашифрованом левый - exit()











