/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <kkuvalis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 11:22:51 by kkuvalis          #+#    #+#             */
/*   Updated: 2019/05/08 11:22:54 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char		*ft_parser(int fd, ssize_t x)
{
	char	*str;
	char	*str2;
	char	*str3;
	char	*allstr;

	MALLOCHECK(allstr = ft_strnew(1));
	MALLOCHECK(str = ft_strnew(100));
	while ((x = read(fd, str, 100)) > 0)
	{
		MALLOCHECK(str2 = ft_strncpy(ft_strnew((size_t)x), str, (size_t)x));
		str3 = allstr;
		MALLOCHECK(allstr = ft_strjoin(str3, str2));
		free(str2);
		free(str3);
	}
	free(str);
	return (allstr);
}

char		*ft_preparser(char *file)
{
	ssize_t	x;
	char	*buff[1];
	char	*map;
	int		fd;

	x = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0 || read(fd, buff, 0) < 0)
	{
		ft_putstr("Invalid map: ");
		ft_putstr(file);
		ft_putchar('\n');
		exit(0);
	}
	map = ft_parser(fd, x);
	close(fd);
	return (map);
}
