##
## EPITECH PROJECT, 2020
## nothing
## File description:
## nothing
##

SRC 	=	-C src/*.cpp

UTFLAGS =       -l criterion --coverage

NAME	=	nanotekspice

CFLAGS	=	-W -Wall -Wextra

LIB	=	-L lib/my/

INCLUDE	=	-I include/

all:	$(NAME)

$(NAME):
	g++ $(CFLAGS) -o $(NAME) $(SRC) $(INCLUDE)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_TEST)
	rm -f *.gcno
	rm -f *.gcda
	rm -f *.out
path:
	LD_LIBRARY_PATH=./:$LD_LIBRARY_PATH
	export LD_LIBRARY_PATH=./:$LD_LIBRARY_PATH

tri-all:
	mv *.h include/
	mv *.c src
tri-c:
	mv *.c src/
auteur:
	echo $(USER) > auteur

re:     fclean all
## n'affiche pas les commandes
.SILENT:

## ne compare pas les fichiers
.PHONY:

##export xLDFLAGS
##	
