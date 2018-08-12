SRC = srcs/main.c
SRC += srcs/syscall.c

NAME = ft_strace

OBJ = $(SRC:.c=.o)

LIB = libft/libft.a
FLAG = -Wall -Werror -Wextra
CG = \033[92m
CY =  \033[93m
CE = \033[0m
CB = \033[34m
INC = -I ./includes/

all: start lib $(NAME)

lib:
	-@make -C libft nohd

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(SRC) $(FLAG) $(INC) $(LIB);
	@echo "\033[K$(CY)[FT_STRACE] :$(CE) $(CG)Compiling ft_strace$(CE)";


start:
	@echo "\n";
	@echo "			$(CG)      :::::::::: :::::::::::           :::::::: ::::::::::: :::::::::      :::      ::::::::  ::::::::::   $(CE)";
	@echo "			$(CG)     :+:            :+:              :+:    :+:    :+:     :+:    :+:   :+: :+:   :+:    :+: :+:           $(CE)";
	@echo "			$(CG)    +:+            +:+              +:+           +:+     +:+    +:+  +:+   +:+  +:+        +:+            $(CE)";
	@echo "			$(CG)   :#::+::#       +#+              +#++:++#++    +#+     +#++:++#:  +#++:++#++: +#+        +#++:++#        $(CE)";
	@echo "			$(CG)  +#+            +#+                     +#+    +#+     +#+    +#+ +#+     +#+ +#+        +#+              $(CE)";
	@echo "			$(CG) #+#            #+#              #+#    #+#    #+#     #+#    #+# #+#     #+# #+#    #+# #+#               $(CE)";
	@echo "			$(CG)###            ###    ########## ########     ###     ###    ### ###     ###  ########  ##########         $(CE)";
	@echo "\n";

%.o: %.c
	@echo "\033[K$(CY)[FT_STRACE] :$(CE) $(CG)Compiling $<$(CE)";
	@gcc $(FLAG) -c $< -o $@ $(INC)

clean: start
	@echo "$(CY)[FT_STRACE] :$(CE) $(CG)Cleaning ft_strace objects$(CE)";
	-@make -C libft nohdclean;
	@/bin/rm -rf $(OBJ);

fclean: start clean
	@echo "\033[K$(CY)[FT_STRACE] :$(CE) $(CG)Cleaning binairies ...$(CE)";
	-@make -C libft nohdfclean;
	@/bin/rm -f $(NAME);

re: fclean all

.PHONY: all clean fclean re
