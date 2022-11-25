/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:00:27 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/25 20:06:46 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define LIBFT

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_norm
{
	int	a;
	int	i;
	int	c;
	int	d;
}	t_norm;

typedef struct s_norm2
{
	int		b;
	int		i;
	int		c;
	char	*s;
}	t_norm2;

typedef struct s_norm_putnbr_base
{
	int					i;
	unsigned long long	a;
	char				*final;
}	t_norm_putnbr_base;

typedef struct s_norm_x
{
	unsigned int	b;
	char			*s;
	int				c;
	int				i;
}	t_norm_x;

int		ft_printf(const char *s, ...);
int		count_n_arg(const char *s);
int		count_n_txt(const char *s);
int		check_error_arg1(const char *s);
int		check_exist(char c);
char	*arg_char(const char *s, int n_arg);
int		choose_type(va_list arg, char c, int *a);
int		choose_c(va_list arg, int *a);
int		choose_s(va_list arg, int *a);
int		choose_p(va_list arg, int *a);
int		choose_d(va_list arg, int *a);
int		choose_u(va_list arg, int *a);
int		choose_x(va_list arg, int *a);
int		choose_xmaj(va_list arg, int *a);
int		choose_for_100(int *a);
size_t	ft_print_table_table(char **final);
char	**return_final(const char *s, va_list arg, char **final);
char	**other_for_100(char *s, char **final, int a, int c);
int		len_int(int a);
int		len_unsigned_int(unsigned int a);
char	*ft_itoa_u(unsigned int n);
char	*ft_putnbr_base(unsigned long long nbr, char *base);
void	free_final(char **final);
char	*ft_itoa(int n);
size_t	ft_strlen(char *s);
void	ft_putstr_fd(char *s, int fd);
int		ft_putnbr(int n, int *a);
char	*ft_itoa(int n);

#endif
