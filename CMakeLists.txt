cmake_minimum_required(VERSION 3.16)
project(checker C)

set(CMAKE_C_STANDARD 11)

include_directories(./ft_checker/includes)
include_directories(./libft)
include_directories(./printf/includes)
add_subdirectory(./libft)
add_subdirectory(./printf)
add_executable(checker
        ft_checker/includes/checker.h
        ft_checker/srcs/errors.c
        ft_checker/checker.c
        ft_checker/srcs/reader.c
        ft_checker/srcs/bigint_base.c
        ft_checker/srcs/commander.c
        ft_checker/srcs/stack_handler.c
        ft_push_swap/srcs/timesort.c
        ft_push_swap/srcs/get_commands.c)
target_link_libraries(checker libft ftprintf)