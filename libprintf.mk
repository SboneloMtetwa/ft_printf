# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libprintf.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smtetwa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/11 14:00:07 by smtetwa           #+#    #+#              #
#    Updated: 2018/08/19 11:36:16 by smtetwa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Base variables for ft_printf library
# Use with 'include /path/to/libprintf.mk'
# Make sure to define L_PRINTF with the path to ft_printf first

# Where our library is located
L_PRINTF		?= .

# What our library will be called
PRINTF_NAME	:= libftprintf.a

# Variables to link and compile with ft_printf
PRINTF_LNK	:= -L $(L_PRINTF) -l ftprintf
PRINTF_INC	:= -I $(L_PRINTF)/includes
PRINTF_LIB	:= $(L_PRINTF)/$(PRINTF_NAME)

# Variables to link and compile all libraries
ifndef LIB_LNK
LIB_LNK			:=
LIB_INC			:=
endif

LIB_LNK			+= $(PRINTF_LNK)
LIB_INC			+= $(PRINTF_INC)
