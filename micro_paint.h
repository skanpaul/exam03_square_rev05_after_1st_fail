#ifndef MICRO_PAINT_H
# define MICRO_PAINT_H
// -----------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
// -----------------------------------
#define	ERROR				1
// -----------------------------------
#define	ERR_END_OF_FILE		0
#define ERR_ARG				1
#define ERR_FILE_CRPT		2
// -----------------------------------
#define PXL_OUTSIDE		0
#define PXL_INSIDE		1
#define PXL_ON_EDGE		2
// -----------------------------------
#define MSG_ERR_ARG			"Error: argument\n"
#define MSG_ERR_FILE_CRPT	"Error: Operation file corrupted\n"
// -----------------------------------
typedef struct s_zone
{
	int w;
	int h;
	char bg;
	int total;
} t_zone;

typedef struct s_square
{
	char type;
	float x;
	float y;
	float w;
	float h;
	char  c;
} t_square;

// -----------------------------------
#endif