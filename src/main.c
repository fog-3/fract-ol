#include "../minilibx-linux/mlx.h"

int main()
{
    void *mlx_ptr;
    void *win_ptr;

    mlx_ptr = mlx_init(); // Inicializar la conexión con el servidor X11
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "My Window"); // Crear una ventana de 500x500

    mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF); // Dibujar un píxel blanco en (250,250)

    mlx_loop(mlx_ptr); // Bucle principal para mantener la ventana abierta

    return 0;
}
