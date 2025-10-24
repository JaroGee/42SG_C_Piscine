#!/bin/sh
set -e
mkdir -p ex00 ex01 ex02 ex03 ex04 ex05 ex06 ex07 ex08 ex09 ex10 ex11 ex12 tests

# ft_list.h (tabs preserved)
cat > ft_list.h <<'EOF'
#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

/* ex00 */ t_list	*ft_create_elem(void *data);
/* ex01 */ void		ft_list_push_front(t_list **begin_list, void *data);
/* ex02 */ int		ft_list_size(t_list *begin_list);
/* ex03 */ t_list	*ft_list_last(t_list *begin_list);
/* ex04 */ void		ft_list_push_back(t_list **begin_list, void *data);
/* ex05 */ t_list	*ft_list_push_strs(int size, char **strs);
/* ex06 */ void		ft_list_clear(t_list *begin_list, void (*free_fct)(void *));
/* ex07 */ t_list	*ft_list_at(t_list *begin_list, unsigned int nbr);
/* ex08 */ void		ft_list_reverse(t_list **begin_list);
/* ex09 */ void		ft_list_foreach(t_list *begin_list, void (*f)(void *));
/* ex10 */ void		ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
					void *data_ref, int (*cmp)());
/* ex11 */ t_list	*ft_list_find(t_list *begin_list, void *data_ref,
					int (*cmp)());
/* ex12 */ void		ft_list_remove_if(t_list **begin_list, void *data_ref,
					int (*cmp)(), void (*free_fct)(void *));
#endif
EOF

# ex00
cat > ex00/ft_create_elem.c <<'EOF'
#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->data = data;
	node->next = 0;
	return (node);
}
EOF

# ex01
cat > ex01/ft_list_push_front.c <<'EOF'
#include "ft_list.h"

t_list	*ft_create_elem(void *data);

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*node;

	if (!begin_list)
		return ;
	node = ft_create_elem(data);
	if (!node)
		return ;
	node->next = *begin_list;
	*begin_list = node;
}
EOF

# ex02
cat > ex02/ft_list_size.c <<'EOF'
#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	n;

	n = 0;
	while (begin_list)
	{
		n++;
		begin_list = begin_list->next;
	}
	return (n);
}
EOF

# ex03
cat > ex03/ft_list_last.c <<'EOF'
#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	if (!begin_list)
		return (0);
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
}
EOF

# ex04
cat > ex04/ft_list_push_back.c <<'EOF'
#include "ft_list.h"

t_list	*ft_create_elem(void *data);

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*node;
	t_list	*last;

	if (!begin_list)
		return ;
	node = ft_create_elem(data);
	if (!node)
		return ;
	if (!*begin_list)
	{
		*begin_list = node;
		return ;
	}
	last = *begin_list;
	while (last->next)
		last = last->next;
	last->next = node;
}
EOF

# ex05
cat > ex05/ft_list_push_strs.c <<'EOF'
#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data);

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*begin;
	int		i;

	begin = 0;
	i = 0;
	while (i < size)
	{
		ft_list_push_front(&begin, strs[i]);
		i++;
	}
	return (begin);
}
EOF

# ex06
cat > ex06/ft_list_clear.c <<'EOF'
#include <stdlib.h>
#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*next;

	while (begin_list)
	{
		next = begin_list->next;
		if (free_fct)
			free_fct(begin_list->data);
		free(begin_list);
		begin_list = next;
	}
}
EOF

# ex07
cat > ex07/ft_list_at.c <<'EOF'
#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	while (begin_list && nbr > 0)
	{
		begin_list = begin_list->next;
		nbr--;
	}
	return (begin_list);
}
EOF

# ex08
cat > ex08/ft_list_reverse.c <<'EOF'
#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*prev;
	t_list	*cur;
	t_list	*next;

	if (!begin_list)
		return ;
	prev = 0;
	cur = *begin_list;
	while (cur)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*begin_list = prev;
}
EOF

# ex09
cat > ex09/ft_list_foreach.c <<'EOF'
#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list)
	{
		f(begin_list->data);
		begin_list = begin_list->next;
	}
}
EOF

# ex10
cat > ex10/ft_list_foreach_if.c <<'EOF'
#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
	void *data_ref, int (*cmp)())
{
	while (begin_list)
	{
		if (cmp(begin_list->data, data_ref) == 0)
			f(begin_list->data);
		begin_list = begin_list->next;
	}
}
EOF

# ex11
cat > ex11/ft_list_find.c <<'EOF'
#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	while (begin_list)
	{
		if (cmp(begin_list->data, data_ref) == 0)
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (0);
}
EOF

# ex12
cat > ex12/ft_list_remove_if.c <<'EOF'
#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
	int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*cur;
	t_list	*prev;
	t_list	*next;

	if (!begin_list)
		return ;
	prev = 0;
	cur = *begin_list;
	while (cur)
	{
		next = cur->next;
		if (cmp(cur->data, data_ref) == 0)
		{
			if (free_fct)
				free_fct(cur->data);
			if (prev)
				prev->next = next;
			else
				*begin_list = next;
			free(cur);
		}
		else
			prev = cur;
		cur = next;
	}
}
EOF

# optional tests
cat > tests/main.c <<'EOF'
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ft_list.h"

static void	print_str(void *p){ printf("%s\n", p ? (char*)p : "(null)"); }
static int	cmp_str(void *a, void *b){ return strcmp((char*)a,(char*)b); }
static void	free_str(void *p){ free(p); }

static char	*dup_cstr(const char *s)
{
	size_t n = 0; while (s[n]) n++;
	char *o = (char*)malloc(n + 1);
	if (!o) return 0;
	for (size_t i = 0; i <= n; i++) o[i] = s[i];
	return o;
}

static void	print_inline(t_list *lst)
{
	printf("[");
	while (lst)
	{
		printf("%s", (char*)lst->data);
		if (lst->next) printf(" -> ");
		lst = lst->next;
	}
	printf("]\n");
}

int	main(int ac, char **av)
{
	t_list *a = 0, *b = 0;
	if (ac > 1) a = ft_list_push_strs(ac - 1, av + 1);
	printf("a: "); print_inline(a);
	printf("size: %d\n", ft_list_size(a));
	if (ft_list_last(a)) printf("last: %s\n", (char*)ft_list_last(a)->data);

	ft_list_push_front(&a, "FRONT");
	ft_list_push_back(&a, "BACK");
	printf("after push: "); print_inline(a);

	printf("at(0)=%s\n", (char*)ft_list_at(a, 0)->data);
	if (ft_list_at(a, 3)) printf("at(3)=%s\n", (char*)ft_list_at(a, 3)->data);

	printf("foreach:\n"); ft_list_foreach(a, &print_str);
	printf("foreach_if == BACK:\n");
	ft_list_foreach_if(a, &print_str, "BACK", &cmp_str);

	b = ft_create_elem(dup_cstr("apple"));
	b->next = ft_create_elem(dup_cstr("banana"));
	b->next->next = ft_create_elem(dup_cstr("apple"));
	printf("b before: "); print_inline(b);
	ft_list_remove_if(&b, "apple", &cmp_str, &free_str);
	printf("b after:  "); print_inline(b);

	ft_list_reverse(&a);
	printf("a reversed: "); print_inline(a);

	ft_list_clear(a, 0);
	ft_list_clear(b, &free_str);
	return 0;
}
EOF

printf "Done. Build with:\n"
printf "cc -Wall -Wextra -Werror tests/main.c \\\n"
printf "  ex00/ft_create_elem.c ex01/ft_list_push_front.c ex02/ft_list_size.c \\\n"
printf "  ex03/ft_list_last.c ex04/ft_list_push_back.c ex05/ft_list_push_strs.c \\\n"
printf "  ex06/ft_list_clear.c ex07/ft_list_at.c ex08/ft_list_reverse.c \\\n"
printf "  ex09/ft_list_foreach.c ex10/ft_list_foreach_if.c ex11/ft_list_find.c \\\n"
printf "  ex12/ft_list_remove_if.c -o list_test\n"
