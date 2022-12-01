#ifndef aoc_utils
#define aoc_utils

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

char **load_file_lines(char *filename, int buf_len, int *count);
void free_string_array(char **array, int count);


#endif // aoc_utils