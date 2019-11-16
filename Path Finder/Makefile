NAME = pathfinder
INC = ./inc/header.h
INCLIB = ./libmx/inc/libmx.h
HEADTMP = ./header.h ./libmx.h
SRC = ./main.c ./mx_isalpha.c ./mx_isdigit.c ./mx_printerr.c
SRCS = ./src/main.c ./src/mx_isalpha.c ./src/mx_isdigit.c ./src/mx_printerr.c
OBJ = ./main.o ./mx_isalpha.o ./mx_isdigit.o ./mx_printerr.o
OBJO = ./obj/main.o ./obj/mx_isalpha.o ./obj/mx_isdigit.o ./obj/mx_printerr.o
CFLGS = -std=c11 -Wall -Wextra -Wpedantic -Werror
all: install uninstall
install:
	@cd libmx && make -f Makefile install
	@cp $(INC) $(SRCS) .
	@cp $(INCLIB) . 
	@clang $(CFLGS) -c  $(SRC)
	@mkdir  obj
	@mv $(OBJ) ./obj
	@clang $(CFLGS) $(OBJO) libmx/libmx.a -o $(NAME)
uninstall:
	@cd libmx && make -f Makefile uninstall
	@rm -rf $(OBJO) $(SRC) $(HEADTMP)
	@rm -rf ./obj
	@rm -rf ./libmx/obj
clean: uninstall
	@cd libmx && make -f Makefile clean
	@rm -rf $(NAME)
reinstall: clean all