#include "objio.h"

int checkFile(char* file, int* vertexCount, int* indexCount)
{
    /* File handle to obj file */
    FILE *f;
    
    /* Buffer to read a line from file */
    char read_buffer[BUFFERSIZE];
    
    /* Sub string buffer */
    char* sub_string;

    /* Open .obj file */
    f = fopen(file, "r");
    if(f != NULL)
    {
        while(fgets(read_buffer, BUFFERSIZE, f))
        {
            sub_string = strtok(read_buffer, " ");

            /* Increase vertex and index count if a line starts with a valid flag */
            if(strncmp(sub_string,"v",1) == 0)
            {
                (*vertexCount)++;
            }
            else if(strncmp(sub_string,"f",1) == 0)
            {
                (*indexCount)++;
            }
        }
    }
    else
    {
        /* Indicate a parse error */
        fclose(f);
        *vertexCount = 0;
        *indexCount  = 0;
        return 0;
    }
    
    /* Close file and return success */
    fclose(f);
    return 1;
}


void loadObj(
             char* file,
             float** vertexBuffer,
             int** indexBuffer,
             int* vertexCount,
             int* faceCount)
{
    /* Counter variables to determine number of vertices and faces */
    *vertexCount    = 0;
    *faceCount      = 0;
    
    /* File handle to read obj data */
    FILE *f;
    
    /* Error flag to indicate is an error was determined during reading */
    int error = 0;
    
    /* String to represent a line in the obj file */
    char read_buffer[BUFFERSIZE];
    
    /* Pointer to sub strings of the read line in file needed for parsing*/
    char* sub_string;
    char* sub_string_x;
    char* sub_string_y;
    char* sub_string_z;
    
    /* Pointer to the actual vertex and index arrays */
    float* vertexPointer;
    int*   facePointer;

    
    /* Try to get a file handle to the given file name. Open for reading */
    f = fopen(file, "r");

    /*if file is open*/
    if(f != NULL)
    {
        /*  Counter number of faces and vertices in file */
        if(checkFile(file, vertexCount, faceCount) == 1)
        {
            /* Allocate memory */
            *vertexBuffer = (float*) calloc(*vertexCount * 3, sizeof(float));
            *indexBuffer =  (int*)   calloc(*faceCount  * 3, sizeof(int));
            
            /* Check for errors */
            if(!(*vertexBuffer && *indexBuffer))
            {
                *faceCount = 0;
                *vertexCount = 0;
                perror("Could not allocate memory for buffers!\n");
            }
            
            /* Get pointer to vertex array */
            vertexPointer = *vertexBuffer;
            
            /* Get pointer to face array */
            facePointer   = *indexBuffer;
            
            /* Read file line wise */
            while(fgets(read_buffer, BUFFERSIZE, f))
            {
                /* Take first character from string to check abainst known keyword */
                sub_string = strtok(read_buffer, " ");
                
                /* If a vertex is found... */
                if(strncmp(sub_string,"v",1) == 0)
                {
                    /* Split into coordinate sub strings */
                    sub_string_x = strtok(NULL, " \t");
                    sub_string_y = strtok(NULL, " \t");
                    sub_string_z = strtok(NULL, " \t");
                
                    /* Check for parsing errors */
                    if(sub_string_x != NULL &&
                       sub_string_y != NULL &&
                       sub_string_z != NULL)
                    {
                        /* Convert sub strings to float values */
                        *vertexPointer++ = atof(sub_string_x);
                        *vertexPointer++ = atof(sub_string_y);
                        *vertexPointer++ = atof(sub_string_z);
                    }
                    else
                    {
                        error = 1;
                        break;
                    }
                }
                else if(strncmp(sub_string,"f",1) == 0)
                {
                    /* Same as above for indices. Just converting to int */
                    sub_string_x = strtok(NULL, " \t");
                    sub_string_y = strtok(NULL, " \t");
                    sub_string_z = strtok(NULL, " \t");
                    if(sub_string_x != NULL &&
                       sub_string_y != NULL &&
                       sub_string_z != NULL)
                    {
                        /* Shift numbering in obj file to array conform indexing */
                        *facePointer++ = atoi(sub_string_x) - 1;
                        *facePointer++ = atoi(sub_string_y) - 1;
                        *facePointer++ = atoi(sub_string_z) - 1;
                    } 
                    else
                    {
                        error = 1;
                        break;
                    }
                    
                }
            }
        }
        else
        {
            error = 1;
        }
    }
    /* Could not open file for reading */
    else
    {
        error = 1;
    }

    /* Close file */
    fclose(f);

    /* Set all values to NULL if an error occurred during file parsing */
    if(error)
    {
        *faceCount = 0;
        *vertexCount = 0;
        perror("Could not parse file!\n");
        freeObj(vertexBuffer, indexBuffer);
    }
}

void freeObj(float** vertexBuffer, int** indexBuffer)
{
    if(*vertexBuffer && *indexBuffer)
    {
        free(*vertexBuffer);
        free(*indexBuffer);
    }
}