/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:20:50 by babyf             #+#    #+#             */
/*   Updated: 2025/12/01 15:28:33 by babyf            ###   ########.fr       */
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
		return (-1);
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
	if (input == c)
		return (1);
	ungetc(input, f);
	return (1);
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
	int	count;
	int	value;
	int	*ip;

	sign = 1;
	value = 0;
	count = 0;
	input = fgetc(f);
	if (input == EOF)
		return (-1);
	if (input == '-' || input == '+')
	{
		if (input == '-')
			sign = -1;
		input = fgetc(f);
	}
	while (input != EOF && isspace(input))
	{
		value = value * 10 + (input - '0');
		count++;
		input = fgetc(f);
	}
	if (input != EOF)
		ungetc(input, f);
	if (count == 0)
		return (-1);
	ip = va_arg(ap, int *);
	*ip = value * sign;
	return (1);
}

/* scan one string (%s) */
int scan_string(FILE *f, va_list ap)
{
    int		input;
	char	*sp;
	int		i;

	sp = va_arg(ap, char *);
	i = 0;
	while (1)
	{
		input = fgetc(f);
		if (input == EOF)
			return (EOF);
		if (isspace(input))
		{
			
		}		
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
			if (match_conv(f, &format, ap) != 1)
				break;
			else
				nconv++;
		}
		else if (isspace(*format))
		{
			if (match_space(f) == -1)
				break;
		}
		else if (match_char(f, *format) != 1)
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
	int x;
    // char str[100];
    // char c;

    int converted = ft_scanf("%d", &x);
    
    printf("Converted: %d\n", converted);
    printf("Num: %d\n", x);
    
    return 0;
}

/* 
think the problem might be the main
*/