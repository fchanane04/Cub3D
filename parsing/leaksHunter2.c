/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaksHunter2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:07:38 by fchanane          #+#    #+#             */
/*   Updated: 2023/04/03 16:07:40 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	leaks_hunter(char ***table)
{
	char	**holder;
	int		i;

	holder = *table;
	i = 0;
	if (*table)
	{
		while (holder[i])
		{
			free(holder[i]);
			i++;
		}
		free(*table);
		*table = NULL;
	}
}
