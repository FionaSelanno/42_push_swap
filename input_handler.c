/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:03:46 by fiselann          #+#    #+#             */
/*   Updated: 2022/05/03 10:55:56 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi(char *str)
{
	unsigned long long numb;
	int	i;
	int	neg;

	i = 0;
	numb = 0;
	neg = 1;
	if (str[i] == '-')
	{
		neg = -neg;
		i++;
	}
	while(str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_exit();
		if(str[i] >= '0' && str[i] <= '9')
		{
			numb = (numb * 10) + str[i] - 48;
			if(check_limits(numb, neg) == -1)
				ft_exit();
			i++;
		}
	}
	return (neg * numb);
}

