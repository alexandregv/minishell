/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:36:31 by aguiot--          #+#    #+#             */
/*   Updated: 2020/11/29 19:59:16 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include "structs.h"
# include "get_next_line.h"

void		ft_putchar_fd(char c, int fd);
void		ft_putchar(char c);
void		ft_putchar_fd_tty(char c, int fd);
void		ft_putchar_tty(char c);
void		ft_putstr_fd(const char *s, int fd);
void		ft_putstr_fd_tty(const char *s, int fd);
void		ft_putstr(const char *s);
void		ft_putstr_tty(const char *s);
void		ft_putnbr_fd(int n, int fd);
void		ft_putnbr_fd_tty(int n, int fd);
void		ft_putnbr(int n);
void		ft_putnbr_tty(int n);
size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strncpy(char *dst, const char *src, size_t len);
char		*ft_strdup(const char *s1);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strncat(char *s1, const char *s2, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_isupper(int c);
int			ft_islower(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isprint(int c);
int			ft_isascii(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
void		ft_strclr(char *s);
void		ft_putendl_fd(const char *s, int fd);
void		ft_putendl(const char *s);
void		ft_putendl_fd_tty(const char *s, int fd);
void		ft_putendl_tty(const char *s);
int			ft_strequ(const char *s1, const char *s2);
int			ft_strnequ(const char *s1, const char *s2, size_t n);
char		*ft_strstr(const char *hay, const char *needle);
char		*ft_strnstr(const char *hay, const char *needle, size_t n);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);
char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
char		*ft_strsub(const char *s, unsigned int start, size_t len);
char		*ft_strjoin(const char *s1, const char *s2);
int			ft_isspace(int c);
int			ft_isblank(int c);
int			ft_iscntrl(int c);
int			ft_isgraph(int c);
int			ft_isxdigit(int c);
int			ft_str_is_alpha(const char *s);
int			ft_str_is_lowercase(const char *s);
int			ft_str_is_uppercase(const char *s);
int			ft_str_is_numeric(const char *s);
int			ft_str_is_printable(const char *s);
char		*ft_strupcase(char *s);
char		*ft_strlowcase(char *s);
char		*ft_strcasestr(const char *haystack, const char *needle);
int			ft_strcasecmp(const char *s1, const char *s2);
char		*ft_strndup(const char *s1, size_t n);
char		*ft_strtrim(const char *s);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmap(const char *s, char (*f)(char));
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int			ft_atoi(const char *s);
void		*ft_memcpy(void *dst, void const *src, size_t n);
void		*ft_memchr(void const *s, int c, size_t n);
int			ft_memcmp(void const *s1, void const *s2, size_t n);
void		*ft_memmove(void *dst, void const *src, size_t len);
void		*ft_memccpy(void *dst, void const *src, int c, size_t n);
char		**ft_strsplit(const char *s, char c);
char		*ft_itoa(int n);
t_list		*ft_lstnew(void const *content, size_t content_size);
void		ft_lstadd(t_list **alst, t_list *new);
void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void		ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void		ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int			ft_str_skip_to(char **str, const char c);
int			ft_str_skip_while(char **str, int (*f)(int));
int			ft_str_skip_charset(char **str, const char *charset);
int			ft_str_copy_to(char **dst, char *src, char c);
char		*ft_strnjoin(const char *s1, const char *s2, size_t n);
void		ft_die(char *msg, int status);
int			get_next_line(const int fd, char **line);
int			*ft_int_tab(int size);
size_t		*ft_sizet_tab(int size);
char		*ft_strjoinfree(char *s1, char *s2, size_t len);
char		**ft_split(char *str, int delim);
char		**ft_sort_table(char **table, size_t size);
void		ft_print_word_table(char **words);
void		ft_free_word_table(char **words);
char		**ft_splitu(char *str, char *charset);

t_list		*ft_list_new(const void *content, size_t content_size);
t_dlist		*ft_dlist_new(const void *content, size_t content_size, int copy);
t_list		*ft_list_push_front(t_list **head, t_list *new);
t_dlist		*ft_dlist_push_front(t_dlist **head, t_dlist *new);
t_list		*ft_list_push_at(t_list **head, t_list *node, size_t index);
t_dlist		*ft_dlist_push_at(t_dlist **head, t_dlist *node, size_t index);
t_list		*ft_list_push_back(t_list **node, t_list *new);
t_dlist		*ft_dlist_push_back(t_dlist **node, t_dlist *new);
t_list		*ft_list_pop_front(t_list **head);
t_dlist		*ft_dlist_pop_front(t_dlist **head);
t_list		*ft_list_pop_at(t_list **head, size_t index);
t_dlist		*ft_dlist_pop_at(t_dlist **head, size_t index);
t_list		*ft_list_pop_back(t_list **node);
t_dlist		*ft_dlist_pop_back(t_dlist **node);
t_list		*ft_list_get_at(t_list *head, size_t index);
t_dlist		*ft_dlist_get_at(t_dlist *head, size_t index);
ssize_t		ft_list_get_index(t_list *head, t_list *node);
ssize_t		ft_dlist_get_index(t_dlist *head, t_dlist *node);
size_t		ft_list_size(t_list *head);
size_t		ft_dlist_size(t_dlist *head);
void		ft_list_del_node(t_list **node, void (*del)(void*, size_t));
void		ft_dlist_del_node(t_dlist **node, void (*del)(void *, size_t));
void		ft_list_del(t_list **list, void (*del)(void *, size_t));
void		ft_dlist_del(t_dlist **list, void (*del)(void *, size_t));
void		ft_list_del_at(t_list **head, void (*del)(void*, size_t),
			size_t index);
void		ft_dlist_del_at(t_dlist **head, void (*del)(void *, size_t),
			size_t index);
void		ft_list_iter(t_list *head, void (*f)(t_list *node));
void		ft_dlist_iter(t_dlist *head, void (*f)(t_dlist *elem), int rev);
void		ft_list_rev(t_list **head);
void		ft_dlist_rev(t_dlist **head);
t_list		*ft_list_last(t_list *head);
t_dlist		*ft_dlist_last(t_dlist *head);
t_dlist		*ft_dlist_first(t_dlist *head);
t_list		*ft_list_msort(t_list *head, int (*cmp)(t_list *, t_list *));
t_dlist		*ft_dlist_msort(t_dlist *head, int (*cmp)(t_dlist *, t_dlist *));
t_list		*ft_list_map(t_list *head, t_list *(*f)(t_list *node));
t_dlist		*ft_dlist_map(t_dlist *head, t_dlist *(*f)(t_dlist *node));
t_dlist		*ft_dlist_mapi(t_dlist *head, t_dlist *(*f)(int, t_dlist *), int i);

char		*ft_strjoin3(const char *s1, const char *s2, const char *s3);
char		*ft_strjoin4(const char *s1, const char *s2, const char *s3,
			const char *s4);
char		*ft_join_table(char **words, char *sep);
char		*ft_strreplace(char *str, char *needle, char *stack);
char		*ft_epur_str(char *str);

#endif
