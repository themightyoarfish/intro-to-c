/**
 * @file plyio.c
 *
 * @author Henning Strüber
 */

#include "plyio.h"

void loadply(
		char* file, 
		float** vertexBuffer, 
		int** indexBuffer, 
		int* vertexCount, 
		int* faceCount)
{
	int header_read = 0;
	char line [100];	
	int v_count;
	int f_count; 
	
	float* v_buffer;
	float* v_buffer_begin;

	int* f_buffer; 
	int* f_buffer_begin;

	char* token;

	int i;

	FILE* ply_file = fopen(file, "r");

	if (ply_file == NULL) {
		vertexBuffer = 0;
		indexBuffer= 0;
		vertexCount = 0;
		faceCount =0;
		perror("File kann nicht geöffnet werden: ");
		return;	
	}

	/* Read Header */
	fgets(line, sizeof(line), ply_file);
	
	if (strcmp(line, "ply\n") != 0) {
		vertexBuffer = 0;
		indexBuffer= 0;
		vertexCount = 0;
		faceCount =0;
		perror("Keine ply Datei: ");
		return;
	}
	printf("Lese Header ... \n");

	while (!header_read) {
		fgets(line, sizeof(line), ply_file);
		token = strtok(line, " ");	

		/* End Header */
		if (strcmp(token, "end_header\n") == 0) {
			header_read = 1;
			break;
		}
		
		/* Parse element */ 
		if (strcmp(token, "element") == 0 ) {
			token = strtok(NULL, " ");

			/* Parse vertex */ 
			if (strcmp(token, "vertex") == 0 ) {
				token = strtok(NULL, " ");
				v_count = atoi(token);
				*vertexCount = atoi(token);

				*vertexBuffer = (float*) calloc(v_count * 3, sizeof(float));
				v_buffer_begin = *vertexBuffer;
				v_buffer = *vertexBuffer;
			}

			/* parse face */
			if (strcmp(token, "face") == 0 ) {
				token = strtok(NULL, " ");
				f_count = atoi(token);
				*faceCount = atoi(token);
					
				*indexBuffer = (int*) calloc(f_count * 3, sizeof(int));
				f_buffer_begin = *indexBuffer;
				f_buffer = *indexBuffer;
			}
		}
	}


	/* Write Vertices */
	for (i = 0; i < v_count; i++) {
		fgets(line, sizeof(line), ply_file);
		write_vertices_to_buffer(line, v_buffer);
		v_buffer+=3;
	}

	/* Write Index */
	for (i = 0; i < f_count; i++) {
		fgets(line, sizeof(line), ply_file);
		write_indices_to_buffer(line, f_buffer);
		f_buffer += 3;
	}

}

void freeply(
		float** vertexBuffer,
		int** indexBuffer,
		int* vertexCount,
		int* faceCount)
{
	free(*vertexBuffer);
	free(*indexBuffer);
}


void write_vertices_to_buffer(char* line, float* buffer)
{
	char* token;
	token = strtok(line, " ");
	*buffer++ = atof(token);
	token = strtok(NULL, " ");
	*buffer++ = atof(token);
	token = strtok(NULL, " ");
	*buffer++ = atof(token);
}

void write_indices_to_buffer(char* line, int* buffer)
{
	char* token;
	token = strtok(line, " ");
	token = strtok(NULL, " ");
	*buffer++ = atoi(token);
	token = strtok(NULL, " ");
	*buffer++ = atoi(token);
	token = strtok(NULL, " ");
	*buffer++ = atoi(token);
}


