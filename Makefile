#--------------------------------------//---------------------------------------
SRC_DIR	=	./sources
SRC		=	push_swap.c \
			check_args.c \
			moves_pri.c \
			moves_sec.c \
			sort_1.c \
			sort_2.c \
			sort_inv.c \
			utils.c \

OBJ_DIR	=	./builds
OBJ		=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))

INCD_DIR=	./includes
INCD	=	push_swap.h
#--------------------------------------//---------------------------------------
vpath %.c $(SRC_DIR)
vpath %.h $(INCD_DIR)

NAME	=	push_swap

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -rf

CC		=	clang
#--------------------------------------//---------------------------------------
all:			$(NAME)

$(NAME):		$(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo ""
	@echo "/ ************************************ \\"
	@echo "|           Push_Swap Criado           |"
	@echo "\\ ************************************ /"
	@echo ""

$(OBJ_DIR)/%.o:	%.c $(INCD)
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c -o $@ $(CFLAGS) -I $(INCD_DIR) $<
	@echo "  Criando .o de "$<
#--------------------------------------//---------------------------------------
clean:
	@$(RM) $(OBJ_DIR)
	@echo ""
	@echo "/ ************************************ \\"
	@echo "|         Arquivos .o Deletados        |"
	@echo "\\ ************************************ /"
	@echo ""

fclean:		clean
	@$(RM) $(NAME)
	@echo ""
	@echo "/ ************************************ \\"
	@echo "|           Push_Swap Deletada         |"
	@echo "\\ ************************************ /"
	@echo ""
#--------------------------------------//---------------------------------------

re:			fclean all

git:
	git add .
	git status
	git commit -m "$m"

.PHONY:		all clean fclean re git
