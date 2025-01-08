#include "../../inc/minirt.h"

double random_double(void)
{
    return rand() / (RAND_MAX + 1.0);
}

double random_double_range(double min, double max)
{
    return min + (max - min) * random_double();
}

double clamp(double x, double min, double max)
{
    if (x < min)
        return min;
    if (x > max)
        return max;
    return x;
}

t_color3 average_color(t_color3 *colors, int sample_count)
{
    t_color3 avg_color = color3(0, 0, 0);
    for (int i = 0; i < sample_count; i++)
    {
        avg_color = vadd(avg_color, colors[i]);
    }
    return vmult_f(1.0 / sample_count, avg_color);
}

t_color3 anti_aliasing_color(t_scene *scene, int i, int j, int samples_per_pixel)
{
    t_color3 pixel_color = color3(0, 0, 0);

    for (int s = 0; s < samples_per_pixel; s++)
    {
        double u = ((double)i + random_double()) / (scene->canvas.w - 1);
        double v = ((double)(scene->canvas.h - 1 - j) + random_double()) / (scene->canvas.h - 1);
        scene->ray = ray_primary(&scene->camera, u, v);
        pixel_color = vadd(pixel_color, ray_color(scene));
    }
    return vmult_f(1.0 / samples_per_pixel, pixel_color);  // 평균 색상 계산
}