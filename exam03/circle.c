#include "circle.h"

int ft_strlen(char *str){
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

int ft_error(char *str){
    write(1, str, ft_strlen(str));
    return (1);
}

int main(int argc, char **argv)
{
    FILE *file;

    int map_w;
    int map_h;
    char map_c;
    char *back;

    char c;
    float input_x;
    float input_y;
    float rad;
    char ch;

    int x;
    int y;
    float dis;
    int scan;

    if (argc == 1)
        return(ft_error("Error: argument\n"));
    file = fopen(argv[1], "r");
    if (!file)
        return(ft_error("Error: Operation file corrupted 1 \n"));
    if (fscanf(file ,"%d %d %c\n", &map_w, &map_h, &map_c) != 3)
        return(ft_error("Error: Operation file corrupted 2\n"));
    if (!(map_w > 0 && map_w <= 300) && !(map_h > 0 && map_h <= 300))
        return(ft_error("Error: Operation file corrupted 3\n"));
    back = (char *)malloc(sizeof(char) * map_w*map_h);
    if (!back)
        return(ft_error("Error: Operation file corrupted 4\n"));
    memset(back, map_c, map_w * map_h);
    while ((scan = fscanf(file, "%c %f %f %f %c\n", &c, &input_x, &input_y, &rad, &ch)) == 5){
        if (!(rad > 0) || !(c == 'c' || c == 'C'))
            break ;
        y = -1;
        while (++y < map_h){
            x = -1;
            while (++x < map_w){
                dis = sqrtf(powf(x - input_x, 2.) + powf(y - input_y, 2));
                if (dis <= rad){
                    if (c == 'c'){
                        if (rad - dis < 1.0000000){
                            back[y * map_w + x] = ch;
                        }
                    }
                    else if (c == 'C')
                        back[y * map_w + x] = ch;
                }
            }
        }
    }
    if (scan != -1)
    {
        free (back);
        return(ft_error("Error: Operation file corrupted 5\n"));
    }
    y = -1;
    while (++y < map_h){
        write(1, back + y * map_w, map_w);
        write(1, "\n", 1);
    }
    free(back);
    fclose(file);
    return (0);
}