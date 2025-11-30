/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:20:50 by babyf             #+#    #+#             */
/*   Updated: 2025/11/30 16:38:45 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* it only scans through strings (s), integers (d) and characters (c)
The fgetc() function obtains the next input character (if present) from the stream 
pointed at by stream, or the next character pushed back on the stream via ungetc(3).

*/

#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

/* skip spaces */
int match_space(FILE *f)
{
    int	ch;
	
	ch = fgetc(f);
	if (ch == EOF && ferror(f))
		return (-1);
	while (ch != EOF)
	{
		if (isspace(ch))
		{
			ungetc(ch, f);
			break ;
		}
		ch = fgetc(f);
	}
	if (ferror(f))
		return (-1);
    return (1);
}

/* verify one specific character */
int match_char(FILE *f, char c)
{
	int	ch;

	ch = fgetc(f);
	if (ch == c)
		return (1);
	if (ch != EOF)
		ungetc(ch, f);
	return (-1);
}

/* scan one character (%c) */
int scan_char(FILE *f, va_list ap)
{
	int		ch;
	char	*cp; /* char paramenter */
	
	ch = fgetc(f);
	cp = va_arg(ap, char*);
	if (ch == EOF)
		return (-1);
	*cp = (char)ch;
	return (1);
}

/* scan one integer (%d) */
int scan_int(FILE *f, va_list ap)
{
	int	ch;
	int	sign;
	int	value;
	int	*ip; /* int parameter */
	int count;

	sign = 1;
	value = 0;
	count = 0;
	ch = fgetc(f);
	ip = va_arg(ap, int *);
	if (ch == EOF)
		return (-1);
	/* skip the spaces */
	if (isspace(ch))
		ch = fgetc(f);
	/* handle sign */
	if (ch == '-')
	{
		sign = -1;
		ch = fgetc(f);
	}
	else if (ch == '+')
	{
		ch = fgetc(f);
	}
	/* check that the first character is a digit */
	if (!isdigit(ch))
	{
		ungetc(ch, f);
		return (-1);
	}
	/* read the digits and make the number */
	while (isdigit(ch))
	{
		value = value * 10 + (ch - '0');
		count++;
		ch = fgetc(f);
	}
	if (ch != EOF)
		ungetc(ch, f);
	if (count == 0)
		return (-1);
	*ip = value * sign;
	return (1);
}

/* scan one string (%s) */
int scan_string(FILE *f, va_list ap)
{
    int		ch;
	char	*sp; /* string parameter */
	int		i; 

	i = 0;
	ch = 0;
	sp = va_arg(ap, char *);
	while (ch != EOF && isspace(ch))
		ch = fgetc(f);
	if (ch == EOF)
		return (-1);
	do 
	{
		sp[i] = ch;
		i++;
		ch = fgetc(f);
	} while (ch != EOF && !isspace(ch));
	sp[i] = '\0';
	if (ch != EOF)
		ch = ungetc(ch, f);
	if (i == 0)
		return (-1);
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
    char str[100];
    char c;

    // Leer: número, espacio, string, espacio, carácter
    int converted = ft_scanf("%d %s %c", &x, str, &c);
    
    printf("Convertidos: %d\n", converted);
    printf("Número: %d, String: %s, Carácter: %c\n", x, str, c);
    
    return 0;
}

/* 
conversion with string: no output with printf user 
conversion with char: ok
conversion of numbers: random memory address that nobody asked for
*/