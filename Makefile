NAME	= libftprintf.a
SRCDIR	= ./
OBJDIR	= ./
SRC		= $(SRCDIR)ft_atoi.c $(SRCDIR)ft_initialize.c $(SRCDIR)ft_itoa_base.c $(SRCDIR)ft_num_len.c $(SRCDIR)ft_parse_c.c $(SRCDIR)ft_parse_d.c $(SRCDIR)ft_parse_p.c $(SRCDIR)ft_parse_s.c $(SRCDIR)ft_parse_type.c $(SRCDIR)ft_parse_x_X.c $(SRCDIR)ft_parsing.c $(SRCDIR)ft_printf.c $(SRCDIR)ft_putnbr_fd.c $(SRCDIR)ft_strchr.c

OBJ		= $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRC))
CC		= gcc
CFLAGS	=  

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
