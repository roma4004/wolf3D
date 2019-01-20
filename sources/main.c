/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 17:13:08 by dromanic          #+#    #+#             */
/*   Updated: 2019/01/20 21:58:04 by dromanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			quit_program(t_env *env)
{
	if (!env)
		return ;
	//need clear env
	if (env->screen)
		SDL_DestroyTexture(env->screen);
	env->screen = NULL;
	if (env->renderer)
		SDL_DestroyRenderer(env->renderer);
	env->renderer = NULL;
	if (env->window)
		SDL_DestroyWindow(env->window);
	env->window = NULL;
	if (env->surface)
		SDL_FreeSurface(env->surface);
	env->surface = NULL;
	if (env->music)
		Mix_CloseAudio();
	env->music = NULL;
	show_errors(env);
	SDL_Quit();
}

static void		clear_img_buff(t_env *env)
{
	Uint32	y;
	Uint32	x;

	if (!env)
		return ;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
			env->buff[y][x++] = 0x0;
		y++;
	}
}

static int		prepare_render(t_env *env, t_fps *fps)
{
	fps->pre_tick = fps->cur_tick;
	fps->cur_tick = SDL_GetTicks();
	fps->frame_time = (fps->cur_tick - fps->pre_tick) / 1000.0f;
	fps->value = (u_char)(1.0 / fps->frame_time);
	env->cam.move_speed = fps->frame_time * 3;
	env->cam.rotate_speed = fps->frame_time * 2;
	if ((fps->frame_limit_second) > fps->cur_tick - fps->pre_tick)
		SDL_Delay(fps->frame_limit_second - (fps->cur_tick - fps->pre_tick));
	event_handler(env, &env->cam, &env->flags);
	clear_img_buff(env);
	return (1);
}

void			game_loop(t_env *env, int threads)
{
	int			id;
	t_pth_dt	data[threads];
	pthread_t	threads_arr[threads];

	if (!env)
		return ;
	while (!env->flags.is_game_over && prepare_render(env, &env->fps))
	{
		id = -1;
		while (++id < threads)
		{
			data[id].env = env;
			data[id].offset = id;
			pthread_create(&threads_arr[id], NULL, multi_raycasting, &data[id]);
		}
		id = -1;
		while (++id < threads)
			pthread_join(threads_arr[id], NULL);
		SDL_UpdateTexture(env->screen, NULL, env->buff, WIN_WIDTH << 2);
		SDL_RenderCopy(env->renderer, env->screen, NULL, NULL);
		if (SHOW_FPS)
			render_interface(env, &env->fps, &env->txt);
		SDL_RenderPresent(env->renderer);
	}
}

int				main(int argc, char **argv)
{
	t_env *env;

	env = NULL;
	if (argc == 2)
	{
		if ((env = init_env()) && parse_map(argv[1], env)
		&& !Mix_PlayMusic(env->music, 1))
			game_loop(env, env->threads);
	}
	else
		ft_putstr("Usage: ./wolf3d map.wmp\n");
	if (env)
		quit_program(env);
	return (0);
}
