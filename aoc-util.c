#include "aoc-util.h"

char **load_file_lines(char *filename, int buf_len, int *count);
void free_string_array(char **array, int count);



char **load_file_lines(char *filename, int buf_len, int *count)
{
	FILE *fp;
	char **array;
	char *string;
	char *buffer;
	int line_count = 0;
	int array_size = 100;

	fp = fopen(filename, "r");

	if (fp == NULL)
	{
		*count = errno;
		return NULL;
	}

	buffer = malloc(buf_len * sizeof(char));

	if (buffer == NULL)
	{
		*count = errno;
		fclose(fp);
		return NULL;
	}

	array = malloc(array_size * sizeof(char*));

	if (array == NULL)
	{
		*count = errno;
		fclose(fp);
		free(buffer);
		return NULL;
	}

	while (fgets(buffer, buf_len, fp) != NULL)
	{
		if (line_count == array_size)
		{
			char **newptr;

			array_size += 100;

			newptr = realloc(array, array_size * sizeof(char*));

			if (newptr == NULL)
			{
				*count = errno;
				fclose(fp);
				free(buffer);
				free_string_array(array, line_count);
				return NULL;				
			}

			array = newptr;
		}

		/* discard overflow */
		if (strchr(buffer, '\n') == NULL)
		{
			char discard;

			while ((discard = fgetc(fp)) != '\n' && discard != EOF);
		}
		
		buffer[strcspn(buffer, "\n")] = '\0';

		string = malloc(strlen(buffer) + 1);
		strcpy(string, buffer);

		array[line_count] = string;

		line_count++;
	}

	fclose(fp);
	free(buffer);

	*count = line_count;

	return array;
}

void free_string_array(char **array, int count)
{
	int i;

	for (i = 0; i < count; i++)
		free(array[i]);

	free(array);
}