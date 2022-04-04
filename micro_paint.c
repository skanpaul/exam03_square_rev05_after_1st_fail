
#include "micro_paint.h"
// ----------------------------------------------------------------------------
t_square	s;
t_zone		z;
char		*map;

// ----------------------------------------------------------------------------
int ft_strlen(char *str)
{
	int i;

	while (str[i] != '\0')
		i++;
	
	return i;
}

// ----------------------------------------------------------------------------
int message_error(FILE *ptr_file, int err_type)
{
	if (err_type == ERR_ARG)
	{
		write(1, MSG_ERR_ARG, ft_strlen(MSG_ERR_ARG));
		if(ptr_file)
			fclose(ptr_file);
		return(ERROR);
	}
	else if (err_type == ERR_FILE_CRPT)
	{
		write(1, MSG_ERR_FILE_CRPT, ft_strlen(MSG_ERR_FILE_CRPT));
		if(ptr_file)
			fclose(ptr_file);
		return(ERROR);
	}
	else // if (err_type == ERR_END_OF_FILE)
	{
		for (int y = 0; y < z.h; y++)
		{
			write(1, &map[y * z.w], z.w);
			write(1, "\n", 1);
		}
		if(ptr_file)
			fclose(ptr_file);
		return ERR_END_OF_FILE;
	}
}

// ----------------------------------------------------------------------------
int pixel_status(float x, float y, t_square *s)
{
	if (x < s->x || x > (s->x + s->w) || y < s->y || y > (s->y + s->h))
		return PXL_OUTSIDE;
	else if (x - s->x < 1 || (s->x + s->w) - x < 1 || y - s->y < 1 || (s->y + s->h) - y < 1)
		return PXL_ON_EDGE;
	return PXL_INSIDE;
}

// ----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	FILE *ptr_file;
	int res;
	int in_out_on;

	ptr_file = NULL;
	
	
	if (argc != 2)
		return (message_error(ptr_file, ERR_ARG));

	if ((ptr_file = fopen(argv[1], "r")) == NULL)
		return (message_error(ptr_file, ERR_FILE_CRPT));

	if ((fscanf(ptr_file, "%d %d %c", &z.w, &z.w, &z.bg)) != 3)
		return (message_error(ptr_file, ERR_FILE_CRPT));

	if (z.w <= 0 || z.w > 300 || z.h <= 0 || z.h > 300)
		return (message_error(ptr_file, ERR_FILE_CRPT));

	z.total = z.w * z.h;
	map = malloc (z.total * sizeof(char));
	memset(map, z.bg, z.total);

	while(1)
	{
		res = fscanf(ptr_file, "%c %f %f %f %f %c\n", &s.type, &s.x, &s.y, &s.w, &s.h, &s.c	);
		if(res == -1)
			return(message_error(ptr_file, ERR_END_OF_FILE));
		else if (res != 6 || s.w <= 0 || s.h <= 0 || (s.type != 'r' && s.type != 'R'))
			return (message_error(ptr_file, ERR_FILE_CRPT));

		for (int x = 0;)




	}
}
// ----------------------------------------------------------------------------