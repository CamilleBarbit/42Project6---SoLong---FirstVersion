#include "minilibx/mlx.h"

int main()
{
    void    *mlx;
    void    *window;

    mlx = mlx_init();
    window = mlx_new_window(mlx, 400, 400, "First Window!");
    mlx_loop(mlx);

}