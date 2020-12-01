/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 15:57:09 by eprusako          #+#    #+#             */
/*   Updated: 2020/12/01 12:33:39 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 1000
# define FD_MAX 4096

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <fcntl.h>

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					get_next_line(const int fd, char **line);
int					ft_abs(int a, int b);
int					ft_mod(int a);
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putnbr(int nb);
size_t				ft_strlen(const char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t num);
char				*ft_strchr(const char *s, int ch);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little, size_t n);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
int					ft_isalpha(int c);
int					ft_isdigit(int a);
int					ft_isalnum(int a);
int					ft_isascii(int a);
int					ft_isprint(int a);
int					ft_toupper(int a);
int					ft_tolower(int a);
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
char				*ft_itoa_base(uintmax_t num, int base, int change);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *ptr, int x, size_t len);
void				*ft_memcpy(void *dest, const void *src, size_t len);
void				*ft_memccpy(void *dest, const void *src, int c, size_t len);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memchr(const void *str, int ch, size_t len);
int					ft_memcmp(const void *ptr1, const void *ptr2, size_t len);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strncat(char *dst, const char *src, int len);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				**ft_strsplit(char const *s, char c);
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);
void				ft_memdel(void **ap);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strcharjoin(int c, const char *s);
char				*ft_strjfree(char const *s1, char const *s2, int l, int r);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strtrim(char const *s);
void				ft_putendl(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_isupper(int a);
int					ft_islower(int a);
int					ft_lst_len(t_list *content);
void				ft_lstpushbach(t_list **head, t_list *new);
t_list				*ft_lstfindnode(t_list *content, void *value);
#endif
