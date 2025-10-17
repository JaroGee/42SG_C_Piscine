#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	main(void)
{
	printf("%d\n", ft_strncmp("abc", "abd", 2));  // 0
	printf("%d\n", ft_strncmp("abc", "abd", 3));  // negative
	printf("%d\n", ft_strncmp("ab",  "abc", 5));  // negative (s1 hits '\0')
	printf("%d\n", ft_strncmp("abc", "ab",  5));  // positive (s2 hits '\0')
	printf("%d\n", ft_strncmp("abc", "abc", 0));  // 0
	return (0);
}
