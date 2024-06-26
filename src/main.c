#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//Esto se hace para no tener que usar mlx_pixel_put ya que es muy lento

typedef struct s_data {
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_data;

typedef struct s_vars{
    void *mlx;
    void *win;
} t_vars;

//Función que imitará mlx_pixel_put

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;
    
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void draw_rect(t_data *img, int b, int h, int x, int y, int color)
{
    int base = 0;
    int altura = 0;
    while (base < b)
    {
        my_mlx_pixel_put(img, x + base, y, color);
        my_mlx_pixel_put(img, x + base, y + h, color);
        base++;
    }
    while (altura < h)
    {
        my_mlx_pixel_put(img, x, y + altura, color);
        my_mlx_pixel_put(img, x + b, y + altura, color);
        altura++;
    }
}

void draw_area_rect(t_data *img, int b, int h, int x, int y , int color)
{
    int base = 0;
    int altura = 0;
    while (altura <  h)
    {
        base = 0;
        while (base < b)
        {
            my_mlx_pixel_put(img, x + base, y + altura, color);
            base++;
        }
        altura++;
    }
}

void draw_arcoiris_rect(t_data *img, int b, int h, int x, int y)
{
    int color = 0xFF0000;
    draw_area_rect(img, b, h/7, x, y, color);
    color = 0xFF7C00;
    y += h/7;
    draw_area_rect(img, b, h/7, x, y, color);
    y += h/7;
    color = 0xFFCB00;
    draw_area_rect(img, b, h/7, x, y, color);
    y += h/7;
    color = 0x11EE65;
    draw_area_rect(img, b, h/7, x, y, color);
    y += h/7;
    color = 0x00F6FF;
    draw_area_rect(img, b, h/7, x, y, color);
    y += h/7;
    color = 0x5364EC;
    draw_area_rect(img, b, h/7, x, y, color);
    y += h/7;
    color = 0xCF6DD2;
    draw_area_rect(img, b, h/7, x, y, color);
}

void my_mlx_line_put(t_data *img, int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx, sy, err, e2;

// Se determina la dirección de los incrementods en las coordenadas 'x' y 'y'
    if (x0 < x1) {
        sx = 1;
    } else {
        sx = -1;
    }

    if (y0 < y1) {
        sy = 1;
    } else {
        sy = -1;
    }
// Diferencia entre las diferencias en las coordenads 'x' y 'y'
    err = dx - dy;

    while (x0 != x1 || y0 != y1) {
        my_mlx_pixel_put(img, x0, y0, color);
// Se actualiza la posición actual 'x0' 'y0' basándose en el valor de 'err' y se recalcula este
// Traza una linea usando el algoritmo de Bresenham
        e2 = err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}


void print_triangle(t_data *img, int l, int x, int y, int color)
{
    int lado = 0;
    while (lado < l)
    {
        my_mlx_pixel_put(img, x + lado, y + l, color);
        my_mlx_pixel_put(img, x + (lado / 2), (y + l) - lado, color);
        my_mlx_pixel_put(img, (x + (l / 2)) + (lado / 2), y + lado, color);
/*         if (lado % 2 == 0)
        {
            my_mlx_pixel_put(img, x + (lado / 2), y - lado, color);
        } */
        lado++;
    }
}

void print_circle(t_data *img, int r, int xc, int yc, int color)
{
    int x = r;
    int y = 0;
    int err = 0;

    while (x >= y) {
        my_mlx_pixel_put(img, xc - y, yc + x, color);
        my_mlx_pixel_put(img, xc + y, yc + x, color);
        my_mlx_pixel_put(img, xc + x, yc + y, color);
        my_mlx_pixel_put(img, xc - x, yc + y, color);
        my_mlx_pixel_put(img, xc - x, yc - y, color);
        my_mlx_pixel_put(img, xc - y, yc - x, color);
        my_mlx_pixel_put(img, xc + y, yc - x, color);
        my_mlx_pixel_put(img, xc + x, yc - y, color);
        if (err <= 0) 
        {
            y += 1;
            err += 2*y + 1;
        }
        if (err > 0) 
        {
            x -= 1;
            err -= 2*x + 1;
        }
    }

}

/*
* add_shade is a function that accepts a double (distance) and a int (color) as arguments,
* 0 will add no shading to the color, whilst 1 will make the color completely dark.
* 0.5 will dim it halfway, and .25 a quarter way. You get the point.
*/
int add_shade (double distance, int color)
{
    int t, r, g, b;
    t = (color >> 24) & 0xFF;
    r = (color >> 16) & 0xFF;
    g = (color >> 8) & 0xFF;
    b = color & 0xFF;
    t -= t*distance;
    r -= r*distance;
    g -= g*distance;
    b -= b*distance;
    return(t << 24 | r << 16 | g << 8 | b);
}

/*
* get_oppositees una función que acepta un int (color) como argumento y 
* que invertirá el color en consecuencia.
*/
int get_opposite(int color)
{
    int t, r, g, b;
    t = (color >> 24) & 0xFF;
    r = (color >> 16) & 0xFF;
    g = (color >> 8) & 0xFF;
    b = color & 0xFF;
    r = 255 - r;
    g = 255 - g;
    b = 255 - b;
    return(t << 24 | r << 16 | g << 8 | b);
}


void ft_close(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    exit(0);
}

int print_keycode(int keycode, t_vars *vars)
{
    if (keycode == 65307)
        ft_close(vars);
    if (vars)
        printf("%d\n", keycode);
    return (0);
}
/* int mouse_moved(int x, int y, t_vars *vars)
{
    if (vars)
        printf("Mouse position: x=%d, y=%d\n", x, y);
    return (0);
} */

int mouse_enter(void *param)
{
    if (!param)
        printf("Hello!\n");
    return (0);
}

int mouse_leave(void *param)
{
    if (!param)
        printf("Bye!\n");
    return (0);
}

int close_window(t_vars *vars)
{
    if (vars)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        exit(0);
    }
    return (0);
}

int main()
{
    t_vars vars;
    t_data img;

    vars.mlx = mlx_init(); // Inicializar la conexión con el servidor X11
    vars.win = mlx_new_window(vars.mlx, 500, 500, "My window ");
    img.img = mlx_new_image(vars.mlx, 500, 500); // Crear una ventana de 500x500

    /*
    ** Despues de crear una imagen, podemos llamar 'mlx_get_data_addr'.
    ** Esto inicializaría la imagen con la dirección *actual*
    */

    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    //Color as 0xTTRRGGBB
    draw_rect(&img, 100, 50, 0, 0, 0xFFFFFF);
    print_triangle(&img, 50, 110, 1, 0x0000FF00);
    draw_arcoiris_rect(&img, 150, 75, 10, 400);
    my_mlx_line_put(&img, 10, 400, 160, 475, 0x191919);
    print_circle(&img, 100, 250, 250, 0xFFFFFF);
    mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
    mlx_hook(vars.win, 2, 1L<<0, print_keycode, &vars);
    mlx_hook(vars.win, 7, 1L<<4, mouse_enter, NULL);
    mlx_hook(vars.win, 8, 1L<<5, mouse_leave, NULL);
    mlx_hook(vars.win, 17, 0, close_window, &vars);
    //mlx_hook(vars.win, 6, 1L<<6, mouse_moved, &vars);
    mlx_loop(vars.mlx);
    return 0;
}
