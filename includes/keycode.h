#ifndef KEYCODE_H
# define KEYCODE_H

# ifdef DARWIN
# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define MOUSE_LEFT_BUTTON		1
# define MOUSE_RIGHT_BUTTON		2
# define MOUSE_SCROLL_BUTTON	3
# define MOUSE_SCROLL_UP		4
# define MOUSE_SCROLL_DOWN		5

# define ARROW_UP				126
# define ARROW_DOWN				125
# define ARROW_LEFT				123
# define ARROW_RIGHT			124

# define NUM_PAD_0				82
# define NUM_PAD_1				83
# define NUM_PAD_2				84
# define NUM_PAD_3				85
# define NUM_PAD_4				86
# define NUM_PAD_5				87
# define NUM_PAD_6				88
# define NUM_PAD_7				89
# define NUM_PAD_8				91
# define NUM_PAD_9				92
# define NUM_PAD_PLUS			69
# define NUM_PAD_MINUS			78

# define MAIN_PAD_W				13
# define MAIN_PAD_D				2
# define MAIN_PAD_S				1
# define MAIN_PAD_A				0
# define MAIN_PAD_B				11
# define MAIN_PAD_V				9
# define MAIN_PAD_0				29
# define MAIN_PAD_1				18
# define MAIN_PAD_2				19
# define MAIN_PAD_3				20
# define MAIN_PAD_4				21
# define MAIN_PAD_5				23
# define MAIN_PAD_6				22
# define MAIN_PAD_7				26
# define MAIN_PAD_8				28
# define MAIN_PAD_9				25
# define MAIN_PAD_ESC			53
# define MAIN_PAD_PLUS			24
# define MAIN_PAD_MINUS			27
# define MAIN_PAD_SPACE			49
# define MAIN_PAD_LESS			43
# define MAIN_PAD_MORE			47
# define MAIN_PAD_ENTER			36
# define MAIN_PAD_DELETE		117
# define MAIN_PAD_R_SHIFT		258

# else
#  define ARROW_UP 65364
#  define ARROW_DOWN 65362
#  define ARROW_LEFT 65361
#  define ARROW_RIGHT 65363
#  define MAIN_PAD_PLUS 61
#  define MAIN_PAD_MINUS 45
#  define MAIN_PAD_Z 6
#  define MAIN_PAD_X 7
#  define MAIN_PAD_W 119
#  define MAIN_PAD_S 115
#  define MAIN_PAD_A 97
#  define MAIN_PAD_D 100
#  define MAIN_PAD_Q 113
#  define MAIN_PAD_E 101
#  define MAIN_PAD_ESC 65307
#  define MOUSE_UP 0
#  define MOUSE_DOWN 4
#  define MOUSE_LEFT 1
#  define MOUSE_RIGHT 2
#  define MOUSE_MIDDLE 3
#  define DIVIZOR_MINUS 44
#  define DIVIZOR_PLUS 46
#  define I 105
#  define P 112
# endif

#endif
