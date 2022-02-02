#include "minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

int handle_mouse(int keycode, void *param)
{
    printf("the keycode is: %d\n", keycode);
    return (0);
}

int handle_key(int keycode, void *param)
{
    printf("the keycode is: %d\n", keycode);
    if (keycode == 65307)
        exit(1);
    return (0);
}

int main()
{
    void    *mlx;
    void    *window;

    mlx = mlx_init();
    if (!mlx)
        return (0);
    window = mlx_new_window(mlx, 400, 400, "First Window!");
    mlx_mouse_hook(window, handle_mouse, 0);
    mlx_key_hook(window, handle_key, 0);
    mlx_loop(mlx);
}