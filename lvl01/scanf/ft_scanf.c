/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:20:50 by babyf             #+#    #+#             */
/*   Updated: 2025/12/02 17:55:52 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
it only scans through strings (s), integers (d) and characters (c)
The fgetc() function obtains the next input character (if present) from the stream 
pointed at by stream, or the next character pushed back on the stream via ungetc(3).
*/

#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

/* skip spaces */
int match_space(FILE *f)
{
    int	input;
	
	input = fgetc(f);
	while (input != EOF && isspace(input))
		input = fgetc(f);
	if (input == EOF)
		return (EOF);
	ungetc(input, f);
	return (1);
}

/* verify one specific character */
int match_char(FILE *f, char c)
{
	int	input;

	input = fgetc(f);
	if (input == EOF)
		return (-1);
	ungetc(input, f);
	if (input == c)
		return (1);
	return (-1);
}

/* scan one character (%c) */
int scan_char(FILE *f, va_list ap)
{
	int	input;
	char	*cp; /* char paramenter */
	
	input = fgetc(f);
	if (input == EOF)
		return (-1);
	cp = va_arg(ap, char *);
	*cp = input;
	return (1);
}

/* scan one integer (%d) */
int scan_int(FILE *f, va_list ap)
{
	int	input;
	int	sign;
	int	*ip;
	int	value;

	sign = 1;
	value = 0;
	ip = va_arg(ap, int *);
	input = fgetc(f);
	if (input == '-' || input == '+')
	{
		if (input == '-')
			sign = -1;
		input = fgetc(f);
	}
	while (1)
	{
		if (!isdigit(input))
		{
			ungetc(input, f);
			break;
		}
		value = value * 10 + (input - '0');
		input = fgetc(f);
	}
	*ip = sign * value;
	return (1);
}

/* scan one string (%s) */
int scan_string(FILE *f, va_list ap)
{
    int		input;
	char	*sp;
	int 	i;

	i = 0;
	sp = va_arg(ap, char *);
	while (1)
	{
		input = fgetc(f);
		if (input == EOF)
			return (EOF);
		if (isspace(input))
		{
			ungetc(input, f);
			break ;
		}
		sp[i] = input;
		i++;
	}
	return (1);
}

/* handle conversions */
int	match_conv(FILE *f, const char **format, va_list ap)
{
	switch (**format)
	{
		case 'c':
			return scan_char(f, ap);
		case 'd':
			match_space(f);
			return scan_int(f, ap);
		case 's':
			match_space(f);
			return scan_string(f, ap);
		case '\0':
			return -1;
		default:
			return -1;
	}
}

/* main scanf function */
int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
	int nconv = 0;
	int c = fgetc(f);

	if (c == EOF)
		return EOF;
	ungetc(c, f);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (match_conv(f, &format, ap) == -1)
				break;
			else
				nconv++;
		}
		else if (isspace(*format))
		{
			if (match_space(f) == -1)
				break;
		}
		else if (match_char(f, *format) == -1)
			break;
		format++;
	}
	
	if (ferror(f))
		return EOF;
	return nconv;
}

/* final function */
int ft_scanf(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	int ret = ft_vfscanf(stdin, format, ap);
	va_end (ap);
	return (ret);
}

int main(void)
{
	int		num;
	char	c;
	char	n[10];

	ft_scanf("%s", &n);
	printf("User said: %s\n", n);
	return (1);
}
