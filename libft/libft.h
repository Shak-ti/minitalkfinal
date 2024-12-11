/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconiat <sconiat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 09:11:41 by sconiat           #+#    #+#             */
/*   Updated: 2024/09/23 10:57:42 by sconiat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t nitems, size_t size);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);

//printf

int		ft_printf(const char *str, ...)__attribute__((format(printf, 1, 2)));
int		ft_choice(const char *format, va_list args, int *cpt, int b);
void	ft_putnbr_hex(unsigned int nbr, int maj, int *cpt, int b);
void	ft_putnbr_u(unsigned int nbr, int *cpt, int b);
void	ft_putptr_hex(uintptr_t p, int *cpt);
void	ft_putchar(char c, int *cpt);
void	ft_putstr(char *s, int *cpt);
void	ft_putnbr(int n, int *cpt, int b);

#endif
