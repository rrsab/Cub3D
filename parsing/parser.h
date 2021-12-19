#ifndef CUB3D_PARSER_H
#define CUB3D_PARSER_H

int		count_of_symbols(char *str, char symbol);
bool	str_isdigit(char *str);

int		check_file(int argc, char *file);
void	check_map_symbols(t_list *map_list);
void	check_map(t_map *map);

void	init_map(t_map *data);
void	map_creation(t_map *map);

void 	init_player(t_main *data);
void	find_player(t_player *player, t_map *map);

void	get_text_and_color(char *str, t_map *map);



#endif //CUB3D_PARSER_H
