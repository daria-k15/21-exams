#include "rectangle.h"

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

int check_pos(float x, float y, float input_x, float input_y, float w, float h){
    if (x < input_x || x > input_x + w || y < input_y || y > input_y +h)
        return (0);
    else if (x - input_x < 1.0 || (input_x + w) - x < 1.0 
        || y - input_y < 1.0 || (input_y + h) - y < 1.0)
        return (1);
    return (2);
}

int main(int argc, char **argv){
    FILE *file;

    int map_w;
    int map_h;
    char map_c;
    char *back;

    char r;
    float input_x;
    float input_y;
    float w;
    float h;
    char ch;

    if (argc != 2)
        return (ft_error("Error: argument\n"));
    file = fopen(argv[1], "r");
    if (!file)
        return(ft_error("Error: Operation file corrupted\n"));
    if (fscanf(file, "%d %d %c\n", &map_w, &map_h, &map_c) != 3)
        return(ft_error("Error: Operation file corrupted\n"));
    if (!(map_w > 0 && map_w <= 300) && (map_h > 0 && map_h <= 300)){
        return(ft_error("Error: Operation file corrupted\n"));}
    back = (char *)malloc(sizeof(char) * map_w * map_h);
    if (!back)
        return (1);
    memset(back, map_c, map_w * map_h);
    int scan;
    int x;
    int y;
    int pos;
    while ((scan = fscanf(file, "%c %f %f %f %f %c\n", &r, &input_x, &input_y, &w, &h, &ch)) == 6){
        if (!(w > 0) || !(h > 0) || !(r == 'r' || r == 'R'))
            break ;
        y = -1;
        while (++y < map_h){
            x = -1;
            while (++x < map_w){
               pos = check_pos((float)x, (float)y, input_x, input_y, w, h);
               if (pos == 1 || (pos == 2 && r == 'R'))
                    back[y*map_w + x] = ch;
                }
            }
        }  

    if (scan != -1){
        free(back);
        return(ft_error("Error: Operation file corrupted\n"));
    }
    y = -1;
    while (++y < map_h){
        write(1, back + y * map_w, map_w);
        write(1, "\n", 1);
    }
    free(back);
    fclose(file);
    return(0);
}