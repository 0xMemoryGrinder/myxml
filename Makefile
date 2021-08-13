##
## EPITECH PROJECT, 2020
## Makefile for matchstick project
## File description:
## compilation control
##

SRC	=	src/myxml_path.c \
		src/myxml_attr_values_set.c \
		src/myxml_attr_values_extract.c\
		src/myxml_child_data_extract.c\
		src/myxml_child_extract.c\
		src/myxml_doc_load.c\
		src/myxml_doc_write.c\
		src/myxml_filepath.c\
		src/myxml_getnbr.c\
		src/myxml_getnbr_f.c\
		src/myxml_list.c\
		src/myxml_node.c\
		src/myxml_node_parse.c\
		src/myxml_strcmp.c\
		src/myxml_strdup.c\
		src/myxml_tag_check_write.c

NAME = libmyxml.a

OBJ	=	$(SRC:.c=.o)

CPPFLAGS	+=	-I ./include -I ../my/include

CFLAGS		+=	-Wall -Wextra

LDFLAGS	+=	-L ../my -lmy

RM	=	rm -f

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	make -C ../my
	ar -rcT $(NAME) ../my/libmy.a $(OBJ)
	# ar -rcT $(NAME) $(OBJ) $(LDFLAGS)

clean	:
	$(RM) $(OBJ)

fclean	:	clean
	$(RM) $(NAME)

re	: fclean all

.PHONY	:	all clean fclean re