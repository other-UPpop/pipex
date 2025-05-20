/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 05:00:19 by rohta             #+#    #+#             */
/*   Updated: 2024/11/20 16:07:12 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>

# ifndef PRINTFF_NULL
#  define PRINTF_NULL -1
# endif

# ifndef STDOUT_FD
#  define STDOUT_FD 1
# endif

# ifndef NOT_SPEC
#  define NOT_SPEC -1
# endif

# ifndef FLAGS
#  define FLAGS "-+ 0#"
# endif

# ifndef DESIMALS
#  define DESIMALS "0123456789"
# endif

# ifndef LOW_HEX
#  define LOW_HEX "0123456789abcdef"
# endif

# ifndef UP_HEX
#  define UP_HEX "0123456789ABCDEF"
# endif

//typedef struct s_list
//{
//	void					*content;
//	struct s_list			*next;
//}	l_list;

typedef struct s_flags
{
	bool	flag_minus;
	bool	flag_plus;
	bool	flag_space;
	bool	flag_zero;
	bool	flag_hashtag;
}	t_flags;

typedef struct s_params
{
	t_flags	*flags;
	ssize_t	*width;
	ssize_t	*precision;
	char	*converted;
	char	specifier;
	bool	dot;
}	t_params;

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *buf, int ch, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
long	ft_long_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);

char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(const char *s, const char *set);
char	**ft_split(const char *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(const char *s, char ((*f)(unsigned int, char)));
void	ft_striteri(char *s, void ((*f)(unsigned int, char *)));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

//t_list	*ft_lstnew(void *content);
//void	ft_lstadd_front(t_list **lst, t_list *new_node);
//int		ft_lstsize(t_list *lst);
//t_list	*ft_lstlast(t_list *lst);
//void	ft_lstadd_back(t_list **lst, t_list *new_node);
//void	ft_lstdelone(t_list *lst, void (*del)(void *));
//void	ft_lstclear(t_list **lst, void (*del)(void *));
//void	ft_lstiter(t_list *lst, void (*f)(void *));
//t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

char	*get_next_line(int fd);
char	*get_next_line_bonus(int fd);
int		ft_printf(const char *format, ...);
char	*ft_printf_check(t_params *params, char *format, va_list args);
void	ft_init_params(t_params *params);
char	*ft_apply_character(int arg);
char	*ft_apply_string(char *arg);
char	*ft_apply_pointer(size_t arg);
char	*ft_apply_desimals(long long arg, size_t base_len, char *base);
char	*ft_apply_hex(unsigned long long arg, size_t base_len,
			char *base);
size_t	ft_write_number(t_params *params);
size_t	ft_write_unsigned(t_params *params);
size_t	ft_write_hex(t_params *params);
ssize_t	ft_write_string(t_params *params);
size_t	ft_write_pointer(t_params *params);
int		ft_zero_check(t_params *params);
size_t	ft_write_prec(t_params *params, size_t put_prec,
			size_t *print_len, size_t conv_len);
size_t	ft_write_width(t_params *params, size_t put_prec,
			size_t conv_len, size_t *print_len);
void	ft_conv_prec(t_params *params, ssize_t conv_len,
			size_t *put_prec, size_t *print_len);
void	ft_prec_dot(t_params *params, size_t *print_len,
			size_t *put_prec, int number);
void	ft_minus_tmp(t_params *params, size_t *conv_len);

#endif
