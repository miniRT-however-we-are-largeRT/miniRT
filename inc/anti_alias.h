#ifndef ANTI_ALIAS_H
# define ANTI_ALIAS_H

/* Anti-Aliasing 관련 함수 선언 */
double random_double(void);
double random_double_range(double min, double max);
double clamp(double x, double min, double max);
t_color3 average_color(t_color3 *colors, int sample_count);
t_color3 anti_aliasing_color(t_scene *scene, int i, int j, int samples_per_pixel);

#endif
