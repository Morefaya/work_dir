/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:27:44 by jcazako           #+#    #+#             */
/*   Updated: 2016/11/23 16:01:22 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BASE_HEX_A "0123456789abcdef"
# define BASE_HEX_B "0123456789ABCDEF"
# define BASE_OCT "01234567"
# define BASE_10 "0123456789"
# define MAX_INT 2147483647
# define MIN_INT -2147483648

# include <string.h>
# include "get_next_line.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_dlist
{
	void		*content;
	size_t		content_size;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}			t_dlist;

typedef struct		s_tree
{
	void			*content;
	size_t			content_size;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

void				ft_putchar(char a);
void				ft_putstr(const char *str);
void				ft_putnbr(int nbr);
void				ft_putchar_fd(char a, int fd);
void				ft_putstr_fd(const char *str, int fd);
void				ft_putnbr_fd(int nbr, int fd);
void				ft_putendl(const char *str);
void				ft_putendl_fd(const char *str, int fd);
size_t				ft_strlen(const char *str);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t n);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *s);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strdup(const char *str);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *str);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s1, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *str);
char				*ft_itoa(int a);
char				**ft_strsplit(char const *str, char a);
t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstdelone(t_list **alist, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alist, void (*del)(void *, size_t));

void				ft_lstadd(t_list **alist, t_list *new_lst);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *list, t_list *(*f)(t_list *elem));

int					ft_chisdigit(char a);
int					ft_check_charset(char a, const char *str);
int					ft_nextch_pos(const char *str);
int					ft_lastch_pos(const char *str);
int					ft_pow(int nbr, int pow);
int					ft_size_base(int nbr, int base);
int					ft_sqrt(int nb);
void				ft_putstr_left(char *str, int width);
void				ft_putstr_right(char *str, int width);
void				ft_putendstr(char *str, char a);
int					ft_getnbr(const char *str);
int					ft_strisnum(const char *str);
int					ft_select_charset(char ch, const char *charset);
char				**ft_strstr_split(const char *str, char *charset);
void				ft_lstadd_back(t_list *lst, t_list *n_lst);
int					ft_wordnb(char *str);
int					ft_strlen_str(char *str);
char				*ft_clean(char *str);
int					ft_lstcount(t_list *lst);
char				*ft_strinsert(char *str, char *insert, size_t pos);
int					ft_abs(int a);
t_list				*ft_lstcpy(t_list *lst, size_t content_size);
void				ft_lstrotate(t_list **lst);
void				ft_lstrev_rotate(t_list **lst);
void				ft_lstswap(t_list **lst);
void				ft_lstpush(t_list **lst_a, t_list **lst_b);
void				ft_lsttrans(t_list **lst, int range);
t_tree				*ft_trnew(const void *content, size_t content_size);
void				ft_trdelone(t_tree **atr, void (*del)(void*, size_t));
void				ft_trdel(t_tree **atr, void (*del)(void*, size_t));
void				ft_lstdel_addr(t_list **lst, t_list *addr, \
		void(*del)(void*, size_t));
void				ft_lstdel_range(t_list **lst, int range, \
		void(del)(void*, size_t));
void				ft_lstadd_range(t_list **lst, t_list *nouvo, int range);
void				ft_lstrev(t_list **lst);
int					ft_maxint(const char *str);
t_dlist			*ft_dlstnew(const void *content, size_t size);
void			ft_dlstadd_back(t_dlist *dlst, t_dlist *new_link);
void			ft_dlstadd_fow(t_dlist **dlst, t_dlist *new_link);
void				ft_dlstdel_range(t_dlist **dlst, int range, \
		void(*del)(void*, size_t));
void				ft_dlstdel_addr(t_dlist **dlst, t_dlist *addr, \
		void(*del)(void*, size_t));
void			ft_dlstdelone(t_dlist **adlst, void(*del)(void*, size_t));
void			ft_dlstdel(t_dlist **adlst, void(*del)(void*, size_t));
void			ft_dlstadd_range(t_dlist **lst, t_dlist *new_l, int range);
int			ft_dlstcount(t_dlist *dlst);
void				ft_dlstdel_range(t_dlist **lst, int range, \
		void(*del)(void*, size_t));
int			ft_dlstcount_next(t_dlist *dlst);
int			ft_dlstcount_prev(t_dlist *dlst);

#endif
