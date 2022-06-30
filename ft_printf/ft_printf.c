#include "./libft/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_printf(const char *format, ...)
{
	char	*cp;
	int		i;
	va_list ap;
	int		ret;

	ret = 0;
	i = -1;
	cp = ft_strdup((char *)format);
	va_start(ap, format);
	while (cp[++i])
	{
		ret++;
		if (cp[i] == '%')
		{
			i++;
			ret++;
			if (cp[i] == 's')
			{
//				ft_putstr("je suis passer par s\n");
				ft_putstr(va_arg(ap, char *));
				ret += ft_strlen(va_arg(ap, char *));
				ft_putnbr(ret);
			}
			else if (cp[i] == 'c')
			{
//				ft_putstr("je suis passer par c\n");
				ft_putchar(va_arg(ap, int));
			}
			else if (cp[i] == 'd')
			{
//				ft_putstr("je suis passer par d");
				ft_putnbr(va_arg(ap, int));
			}
			else if (cp[i] == '%')
			{
				ft_putchar('%');
			}
//			printf("i == %d et %c%c\n", i, cp[i - 1], cp[i]);
		}
		if (cp[i + 1] && cp[i -1] != '%')
			ft_putchar(cp[i]);
	}
	ft_putchar('\n');
	va_end(ap);
	return ret;
}

int		main()
{
	int ret;
	
	ret = ft_printf("hello world %s %c %d %%", "mina-san", '!', 42);
	ft_printf("ret = %d\n", ret);
	return 0;
}
