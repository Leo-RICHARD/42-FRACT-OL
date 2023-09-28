/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <lrichard@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:35:40 by lrichard          #+#    #+#             */
/*   Updated: 2021/10/02 20:42:01 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	write_image(t_img *frame, int file, int filesize)
{
	unsigned char	header[54];

	ft_bzero((char *)header, 54);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	header[2] = (unsigned char)(filesize);
	header[3] = (unsigned char)(filesize >> 8);
	header[4] = (unsigned char)(filesize >> 16);
	header[5] = (unsigned char)(filesize >> 24);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	header[18] = (unsigned char)(XRES);
	header[19] = (unsigned char)(XRES >> 8);
	header[20] = (unsigned char)(XRES >> 16);
	header[21] = (unsigned char)(XRES >> 24);
	header[22] = (unsigned char)(-YRES);
	header[23] = (unsigned char)(-YRES >> 8);
	header[24] = (unsigned char)(-YRES >> 16);
	header[25] = (unsigned char)(-YRES >> 24);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(32);
	if (write(file, header, 54) < 0 || \
		write(file, frame->addr, XRES * YRES * 4) < 0)
		return (0);
	return (1);
}

int	*get_name(char **name, int fd)
{
	static int	n = -1;

	n++;
	if (n >= 10000)
	{
		prints("too many screenshots in folder already\n");
		prints("rename or delete some\n");
		n = 0;
		return (NULL);
	}
	(*name)[13] = '0' + (n % 10);
	(*name)[12] = '0' + (n / 10 % 10);
	(*name)[11] = '0' + (n / 100 % 10);
	(*name)[10] = '0' + (n / 1000 % 10);
	fd = open(*name, O_RDONLY);
	if (fd != -1)
	{
		close(fd);
		return (get_name(name, 0));
	}
	return (&n);
}

void	take_screenshot(t_img *frame, char *name)
{
	int	fd;
	int	*n;
	int	filesize;

	n = get_name(&name, 0);
	if (!n)
		return ;
	filesize = 40 + 4 * XRES * YRES;
	fd = open(name, O_WRONLY | O_CREAT, 0666);
	if (fd == -1)
		return ;
	if (!write_image(frame, fd, filesize))
	{
		close(fd);
		unlink((const char *)name);
		(*n)--;
	}
	else
		close(fd);
	prints("screenshot taken\n");
}
