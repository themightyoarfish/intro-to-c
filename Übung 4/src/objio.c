#include <stdio.h>
#include <stdlib.h>

void set_null(float **vertexBuffer, int **indexBuffer, int *vertexCount, int *faceCount)
{
   *vertexBuffer = NULL;
   *indexBuffer = NULL;
   *vertexCount = 0;
   *faceCount = 0;
}

void loadObj(
      char* file,
      float** vertexBuffer,
      int** indexBuffer,
      int* vertexCount,
      int* faceCount)
{

   FILE *model_file = fopen(file, "r");
   if (model_file == NULL) {
      set_null(vertexBuffer, indexBuffer, vertexCount, faceCount);
      return;
   }

   char vertex_format[] = "v %f %f %f";
   char face_format[] = "f %d %d %d";
   char line_read[50];

   *vertexCount = *faceCount = 0;

   while (fgets(line_read, 50, model_file) != NULL)
   {
      switch(line_read[0])
      {
         case '\n':
         case '#': break;
         case 'f': (*faceCount)++; break;
         case 'v': (*vertexCount)++; break;
         default: /* invalid format */
                   set_null(vertexBuffer, indexBuffer, vertexCount, faceCount);
                   return;

      }
   }

   *vertexBuffer = malloc(*vertexCount * 3 * sizeof(float));
   *indexBuffer = malloc(*faceCount * 3 * sizeof(int));

   /* indices for both arrays */
   int i, j, line, error = 0;
   i = j = line = 0;

   rewind(model_file);
   while (!error && fgets(line_read,50,model_file) != NULL)
   {
      line++;
      printf("%d: %s\n",line,line_read);
      int read;
      switch (line_read[0])
      {
         case '\n':
         case '#': break;
         case 'v': read = sscanf(line_read, vertex_format, 
                         (*vertexBuffer)+i,
                         (*vertexBuffer)+i+1,
                         (*vertexBuffer)+i+2);
                   i += 3;
                   if(!read) error = 1;
                   break;
         case 'f': read = sscanf(line_read, face_format,
                         (*indexBuffer)+j,
                         (*indexBuffer)+j+1,
                         (*indexBuffer)+j+2);
                   j += 3;
                   if(!read) error = 1;
                   break;
         default: error = 1; break;
      }
   }
   if(error)
   {
      fprintf(stderr, "Error. No valid .obj file.\nError at line %d: %s\n",line,line_read);
      set_null(vertexBuffer, indexBuffer, vertexCount, faceCount);
      return;
   }
   fclose(model_file);
}

void freeObj(float **vertexBuffer, int **indexBuffer)
{
   free(*vertexBuffer);
   free(*indexBuffer);
}
