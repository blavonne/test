cmake_minimum_required(VERSION 3.16)
project(checker C)

set(CMAKE_C_STANDARD 11)

include_directories(./includes)
include_directories(./libft)
include_directories(./printf/includes)
add_subdirectory(./libft)
add_subdirectory(./printf)
add_executable(checker
        includes/push_swap.h
        ft_checker/srcs/reader.c
        ft_checker/srcs/bigint_base.c
        ft_checker/srcs/commander.c
        ft_checker/srcs/stack_handler.c
        ft_push_swap/srcs/timsort.c
        ft_push_swap/srcs/get_commands.c
        ft_push_swap/srcs/vector.c
        ft_push_swap/srcs/cleaner.c
        ft_push_swap/main.c
#        ft_checker/main.c
        ft_checker/srcs/checker.c
        ft_push_swap/srcs/all_to_b.c
        ft_push_swap/srcs/middle_handler.c
        ft_push_swap/srcs/timsort_merge.c
        ft_push_swap/srcs/insertion_sort.c
        ft_push_swap/srcs/ft_is_slice.c
        ft_push_swap/srcs/check_order.c
        ft_push_swap/srcs/all_to_a.c
        ft_push_swap/srcs/vector_arr.c ft_push_swap/srcs/main_struct.c ft_push_swap/srcs/ptr_to_top_b.c ft_push_swap/srcs/ptr_to_a.c ft_push_swap/srcs/optimize_way.c ft_push_swap/srcs/set_steps.c ft_checker/srcs/spliter.c ft_push_swap/srcs/sort_map.c)
target_link_libraries(checker libft ftprintf)