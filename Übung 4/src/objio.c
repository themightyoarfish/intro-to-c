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
   int vertexbufSize = 30;
   int indexbufSize = 30;
   *vertexBuffer = malloc(vertexbufSize * sizeof(float));
   *indexBuffer = malloc(indexbufSize * sizeof(int));

   FILE *model_file = fopen(file, "r");
   if (model_file == NULL || *vertexBuffer == NULL || *indexBuffer == NULL) {
      set_null(vertexBuffer, indexBuffer, vertexCount, faceCount);
      return;
   }

   char vertex_format[] = "v %f %f %f";
   char face_format[] = "f %3d %3d %3d";
   char line_read[50];
   int i = 0, j = 0, line = 0;

   /* Loop over lines of file */
   float a,b,c;
   int d,e,f;
   while (fgets(line_read,50,model_file) != NULL)
   {

         line++;
#ifdef DEBUG
      printf("Current line read: %d: %s",line,line_read);
#endif
      /* Grow arrays if needed */
      if(i > vertexbufSize - 3){
         *vertexBuffer = realloc(*vertexBuffer, vertexbufSize * 2);
         vertexbufSize *= 2;
         if (*vertexBuffer == NULL) 
         {
            fprintf(stderr, "Error. call to realloc failed (vertexBuffer).\n");
            set_null(vertexBuffer, indexBuffer, vertexCount, faceCount);
            return;
         }
         printf("Reallocated vertexBuffer. new size %d\n",vertexbufSize);
#ifdef DEBUG
#endif
      }
      if(j > indexbufSize - 3){
         *indexBuffer = realloc(*indexBuffer, indexbufSize * 2);
         indexbufSize *= 2;
         if (*indexBuffer == NULL) 
         {
            fprintf(stderr, "Error. call to realloc failed (indexBuffer).\n");
            set_null(vertexBuffer, indexBuffer, vertexCount, faceCount);
            return;
         }
         printf("Reallocated indexBuffer. new size %d\n",indexbufSize);
#ifdef DEBUG
#endif
      }
      switch (line_read[0])
      {
         case '\n':
         case '#': break;
         case 'v': sscanf(line_read, vertex_format, &a,&b,&c);
                  (*vertexBuffer)[i] = a;
                  (*vertexBuffer)[i+1] = b;
                  (*vertexBuffer)[i+2] = c;
#ifdef DEBUG
                   printf("Vertex parsed: (%f,%f,%f)\n",(*vertexBuffer)[i],(*vertexBuffer)[i+1],(*vertexBuffer)[i+2]);
#endif
                   i += 3;
                   break;
         case 'f': sscanf(line_read, face_format, &d,&e,&f);
                  (*indexBuffer)[j] = d;
                  (*indexBuffer)[j+1] = e;
                  (*indexBuffer)[j+2] = f;
#ifdef DEBUG
                   printf("Vertex parsed: (%d,%d,%d)\n",(*indexBuffer)[j],(*indexBuffer)[j+1],(*indexBuffer)[j+2]);
#endif
                   j += 3;
                   break;
         default: fprintf(stderr, "Error. No valid .obj file.\nError at line %d: %s\n",line,line_read);
                  set_null(vertexBuffer, indexBuffer, vertexCount, faceCount);
                  return;
      }
#ifdef DEBUG
      printf("Current number of parsed vertices: %d\n",i/3);
      printf("Current number of parsed faces: %d\n",j/3);
#endif
   }
   *vertexCount = i/3;
   *faceCount = j/3;
   *vertexBuffer = realloc(*vertexBuffer, *vertexCount);
   *indexBuffer = realloc(*indexBuffer, *faceCount);
   printf("Done with sizes %d, %d\n",i/3,j/3);
   printf("End of function.\n");
}
void freeObj(float **vertexBuffer, int **indexBuffer)
{
   free(*vertexBuffer);
   free(*indexBuffer);
}
