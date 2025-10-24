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
