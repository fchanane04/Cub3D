/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorUtils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 06:13:57 by fchanane          #+#    #+#             */
/*   Updated: 2023/04/04 23:11:56 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int	encode_color(int t, int r, int g, int b)
{
	int	encoded_color;

	encoded_color = t << 24 | r << 16 | g << 8 | b;
	return (encoded_color);
}

void	assign_correct_color(char dir, int color, int *ceiling, int *floor)
{
	if (dir == 'F')
		*floor = color;
	if (dir == 'C')
		*ceiling = color;
}

int	valid_splitter_count(char *content)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (content[i])
	{
		if (content[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		return (0);
	return (1);
}
