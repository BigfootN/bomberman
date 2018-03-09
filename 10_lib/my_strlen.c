#include "headers.h"

size_t	my_strlen(const char *s)
{
	const char	*lstr;

	lstr = s;
	while (*s != '\0')
		s++;
	return (s - lstr);
}