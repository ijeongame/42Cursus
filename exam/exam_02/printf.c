#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct s_set
{
	va_list ap;
	int	i;
	int ret;
	int width;
	int precision;
	int dot;
	int precision_parsing;
	int arglen;
}				t_set;

void	reset_set(t_set *set)
{
	set->width = 0;
	set->precision = 0;
	set->dot = 0;
	set->precision_parsing = 0;
	set->arglen = 0;
	return ;
}
int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_atoi(char *str, t_set *set)
{
	int res;

	while (str[set->i] >= '0' && str[set->i] <= '9')
	{
		res = res * 10 + str[set->i] - '0';
		set->i++;
	}
	set->i--;
	return (res);
}

void is_conv(char c)
{
	return (c == 's' || c == 'x' || c == 'd')
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr_l(char *str, int len)
{
	write(1, ste, len);
}


int ft_intlen_base(intmax_t num, char *base)
{
	int len;
	int base_len;

	len = 1;
	base_len = ft_strlen(base);
	if (num < 0)
		num = -num;
	while (num >= base_len)
	{
		num /= base_len;
		len++;
	}
	return (len);
}

void ft_putnbr_base(intmax_t num, char *base)
{
	int base_len;

	base_len = ft_strlen(base);
	if (num < 0)
		num -= num;
	if (num >= base_len)
		ft_putnbr_base(num / base_len, base);
	ft_putchar(base[num % base_len]);
}

void print_space(t_set *set, int len)
{
	int i;

	i = 0;
	if (len < 0)
		return ;
	while (i < len)
	{
		ft_putchar(' ');
		i++;
	}
	set->ret += len;
}

void print_zero(t_set *set, int len)
{
	int i;

	i = 0;
	if (len < 0)
		return ;
	while (i < len)
	{
		ft_putchar('0');
		i++;
	}
	set->ret += len;
}

void convert_str(t_set *set)
{
	char *str;

	str = va_arg(set->ap, char *);
	if (!str)
		str = "(null)"
	set->arglen = ft_strlen(str);
	if (set->dot && set->precision < set->arglen)
		set->arglen = set->precision;
	print_spaces(set, set->width - set->arglen);
	ft_putstr_l(str, set->arglen);
	set->ret += set->arglen;
}

void convert_int(t_set *set)
{
	intmax_t num;
	int		zero;

	num = va_arg(set->ap, int);
	zero = 0;
	set->arglen = ft_intlen_base(num, "0123456789");
	if (num == 0)
		set->arglen = 0;
	if (set->dot && set->precision > set->arglen)
		zero = set->precision - set->arglen;
	if (num < 0)
		set->arglen += 1;
	print_spaces(set, set->width - (zero + set->arglen));
	if (num < 0)
		ft_putchar('-');
	print_zero(set, zero);
	if (set->dot && num == 0)
		return ;
	ft_putnbr_base(num, "0123456789");
	set->ret += set->arglen;
}

void convert_hex(t_set *set)
{
	intmax_t num;
	int zero;

	zero = 0;
	num = va_arg(set->ap, unsigned int);
	set->arglen = ft_intlen_base(num, "0123456789abcdef");
	if (set->dot && set->precision > set->arglen)
	   	zero = set->precision - set->arglen;
	print_spaces(set, set->width - (zero + set->arglen));
	print_zero(setm zero);
	if (set->dot && set->precision == 0 && num == 0)
		return ;
	ft_putnbr_base(num, "0123456789abcdef");
	set->ret += set->arglen;
}

void parse(t_set *set, char *str)
{
	set->i++;
	reset_set(set);
	while (!is_conv(str[set->i]))
	{
		if (str[set->i] >= '0' && str[set->i] <= '9')
		{
			if (set->precision_parsing)
				set->precision = ft_atoi(set, str);
			else
				set->width = ft_atoi(set, str);
		}
		set->precision_parising = 0;
		if (str[set->i] == '.')
		{
			set->dot = 1;
			set->precision_parsion = 1;
		}
		set->i++;
	}
	str[set->i] == 's' ? convert_str(set) : 0;
	str[set->i] == 'd' ? convert_int(set) : 0;
	str[set->i] == 'x' ? convert_int(set) : 0;
}

int ft_printf(char *str, ...)
{
	t_set set;

	set.i = 0;
	set.ret = 0;
	va_start(set.ap, str);
	while (str[set.i])
	{
		if (str[set.i] == '%')
			parse(&set, (char *)str);
		else
		{
			ft_putchar(str[set.i]);
			set.ret++;
		}
	}
	va_end(set.ap);
	return (set.ret);
}
