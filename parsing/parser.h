#ifndef CUB3D_PARSER_H
#define CUB3D_PARSER_H

void	ft_error(char *str);
int		count_of_symbols(char *str, char symbol);
bool	str_isdigit(char *str);

int		check_file(int argc, char *file);

void	init_map(t_map *data);
void 	init_player(t_main *data);

void	get_text_and_color(char *str, t_map *map);



#endif //CUB3D_PARSER_H
