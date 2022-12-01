#include <stdio.h>

#include "aoc-util.h"

#define DATA_FILE "data.txt"

int main(void)
{
	char **lines;
	int count;
	int i;

	lines = load_file_lines(DATA_FILE, 101, &count);

	if (lines == NULL)
	{
		printf("error: %s\n", strerror(count));
		return 1;
	}

	for (i = 0; i < count; i++)
		printf("%s\n", lines[i]);
    printf("Line count: %d\n", count);

	free_string_array(lines, count);

	return 0;
}