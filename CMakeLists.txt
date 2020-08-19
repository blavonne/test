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
        ft_checker/checker.c
        ft_checker/srcs/reader.c
        ft_checker/srcs/bigint_base.c
        ft_checker/srcs/commander.c
        ft_checker/srcs/stack_handler.c
        ft_push_swap/srcs/timsort.c
        ft_push_swap/srcs/get_commands.c
        ft_push_swap/srcs/vector.c
        ft_push_swap/srcs/cleaner.c
        ft_push_swap/srcs/push_swap.c
        ft_push_swap/srcs/all_to_b.c
        ft_push_swap/srcs/middle_handler.c
        ft_push_swap/srcs/timsort_merge.c
        ft_push_swap/srcs/insertion_sort.c
        ft_push_swap/srcs/ft_is_slice.c
        ft_push_swap/srcs/check_order.c)
target_link_libraries(checker libft ftprintf)