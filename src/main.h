/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 19:41:05 by dromanic          #+#    #+#             */
/*   Updated: 2018/10/12 20:59:25 by dromanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# define WIN_WIDTH 1024
# define WIN_HEIGHT 768
# define WIN_NAME "wolf3d by dromanic (@Dentair)"
# define DEFAULT_MENU_COLOR 0x0f9100FF
# define DEF_FONT "fonts/ARIAL.TTF"
#define FRAME_LIMIT 80
#define mapWidth 24
#define mapHeight 24
#define texWidth 64
#define texHeight 64
#define textureCount 8
#include <stdbool.h>

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <string.h>

//# include "../library/frameworks/SDL2.framework/Headers/extern.h"
//# include <SDL2/SDL.h>
//#include "../library/frameworks/SDL2_ttf.framework/Versions/A/Headers/SDL_ttf.h"
//#include "../library/frameworks/SDL2_image.framework/Versions/A/Headers/SDL_image.h"
//# include <SDL2/SDL.h>
//# include <SDL2_ttf/SDL_ttf.h>
# include "../library/frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
# include "../library/frameworks/SDL2_image.framework/Headers/SDL_image.h"
# include "../library/frameworks/SDL2_mixer.framework/Headers/SDL_mixer.h"
# include "../library/libft/libft.h"

typedef struct	s_uint32_point
{
	Uint32		x;
	Uint32		y;
}				t_uint32_pt;

typedef struct	s_sint32_point
{
	Sint32		x;
	Sint32		y;
}				t_sint32_pt;


typedef struct	s_double_pt
{
	double		x;
	double		y;
}				t_double_pt;

typedef struct	s_sprite
{
	SDL_Surface *image;
	SDL_Rect	rect;
	Uint32		width;
	Uint32		height;
}				t_sprite;

typedef struct	s_line
{
	double	height;
	double	start;
	double	end;
	double	perp_wall_dist;
}				t_line;

typedef struct	s_ray
{
	unsigned char	less_dist:1;
	unsigned char	hit:1;
	float			x;
	t_double_pt		dist;
	t_double_pt		delta_dist;
	t_double_pt		dir;
	t_sint32_pt		pt;

}				t_ray;

typedef struct	s_text
{
	int			messageWidth;
	int			messageHeight;
	SDL_Color	messageColor;
	SDL_Rect	rect;
}				t_txt;

enum			e_colors
{
	RED = 0xFF0000,
	GREEN = 0x00FF00,
	BLUE = 0x0000FF,
	WHITE = 0xFFFFFF,
	YELLOW = 0xFFFF00
};

enum			e_keys_code
{
	NUM_1 = 83, ONE = 18,
	NUM_2 = 84, TWO = 19,
	NUM_3 = 85, THREE = 20,
	NUM_4 = 86, FOUR = 21,
	NUM_5 = 87, FIVE = 23,
	NUM_6 = 88, SIX = 22,
	NUM_7 = 89, SEVEN = 26,
	NUM_8 = 91, EIGHT = 28, MINUS = 27,
	NUM_9 = 92, NINE = 25, PLUS = 24,
	NUM_0 = 82, ZERO = 29, NUM_MINUS = 78,
	NUM_DIV = 75, NUM_MUL = 67, NUM_PLUS = 69,
	MOUSE_SCROLL_UP = 4, MOUSE_LBT = 1,
	MOUSE_SCROLL_DOWN = 5, MOUSE_RBT = 2,
	Q = 12, W = 13, E = 14, R = 15, T = 17, Y = 16, U = 32,
	A = 0, S = 1, D = 2, F = 3, G = 5, H = 4, J = 38,
	Z = 6, X = 7, C = 8, V = 9, B = 11, N = 45, M = 46,
	ENTER = 36, ESC = 53,
	ARROW_UP = 126, ARROW_DOWN = 125,
	ARROW_LEFT = 123, ARROW_RIGHT = 124,
	HOME = 115, PAGE_UP = 116,
	END = 119, PAGE_DOWN = 121
};

typedef struct	s_environment
{
	bool			game_over;
	int				state_arr_length;
	const Uint8		*state;
	float			fps;
	double			moveSpeed;
	double			rotateSpeed;
	double			frameTime;
	double			camera_x;
	Uint32			framesTimesindex;
	Uint32			getticks;
	Uint32			frameTimeLast;
	Uint32			frameCount;
	Uint32			current_tick;
	Uint32			framesTimes[FRAME_LIMIT];
	Uint32 			buffer[WIN_HEIGHT][WIN_WIDTH];// y-coordinate first because it works per scanline
	Uint32			previous_tick;
	Sint32			side;//was a NS or a EW wall hit?
	Sint32			hit;
	Sint32			img_buff[WIN_HEIGHT][WIN_WIDTH];
	Sint32			texture[textureCount][texWidth * texHeight];
	t_double_pt		pos;
	t_double_pt		direction;
	t_sint32_pt		step;
//	t_sint32_pt		map_pt;
	t_double_pt		plane;
//vector			sdl_texture[8];
	SDL_Texture		*sdl_texture;
	SDL_DisplayMode	display_param;
	SDL_Event		event;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*mainTexture;
	SDL_Surface		*surface;

}				t_env;

t_env			*init_env();
int				display_interface(t_env *env);
void			event_handler(t_env *env, Sint32 [mapWidth][mapHeight]);
Sint32 			chose_color(Sint32 switch_num, Sint32 side);
void			verLine(t_env *env, int x, int start, int end, int color);
void			clear_img_buff(t_env *env);
//int			*init_img_buff(int width, int height);
void			frame_limit(Uint32 current_tick, Uint32 previous_tick);
void			quit_program(t_env *env);
void			raycasting(t_env *env, Sint32 worldMap[mapWidth][mapHeight], double x);
void			generate_texture(t_env *env);
void			get_time_ticks(t_env *env);
void			swap_px(t_env *env, size_t texSize);
#endif