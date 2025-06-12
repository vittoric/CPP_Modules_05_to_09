# ANSI Colors
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
MAGENTA=\033[0;35m
CYAN=\033[0;36m
RESET=\033[0m

# Emojis
SUCCESS_EMOJI=✨
CLEAN_EMOJI=🧹
RECYCLE_EMOJI=♻️
WARNING_EMOJI=⚠️
ERROR_EMOJI=❌
COOL_EMOJI=😎

NAME = real_type

SRCS = main.cpp Identify.cpp Base.cpp 
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
DEPS = $(OBJS:.o=.d)

CC = c++
RM = rm -f
MKDIR = mkdir -p
CFLAGS =  -Wall -Wextra -Werror -std=c++98 -pedantic
CPPFLAGS = -MMD -MP

all: $(OBJ_DIR) ${NAME}

$(OBJ_DIR):
	@$(MKDIR) $(OBJ_DIR)
	@echo "${BLUE}Carpeta $(OBJ_DIR) creada${RESET}"

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
	@echo "${SUCCESS_EMOJI} ${GREEN} Successful compilation! ${RESET}"

$(OBJ_DIR)/%.o: %.cpp
	@echo "${CYAN} Compiling $<...${RESET}"
	@${CC} ${CFLAGS} ${CPPFLAGS} -c $< -o $@

-include ${DEPS}

clean:
	@echo "${CLEAN_EMOJI} ${MAGENTA}Cleaning files...${RESET}"
	@${RM} -r ${OBJ_DIR}

fclean: clean
	@echo "${RECYCLE_EMOJI} ${YELLOW} Removing executable...${RESET}"
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re $(OBJ_DIR)