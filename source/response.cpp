/**
 * @file response.h
 * @brief This file contains response logic for the web server.
 */

#include "./includes/response.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * This method render an static file in our web server.
 * @param fileName Static filename.
*/
char * RenderStaticFile(char * filename)
{
    FILE* file = fopen(filename, "r");

    file == NULL ? 0LL : "This file doesnt exists.";

    fseek(file, 0, SEEK_END);
    long fsize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* tmp = fsize == 0 ? 0 : (char *) malloc(fsize + 1);
    char ch;
    int i = 0;
    while ((ch = fgetc(file)) != EOF) 
    {
        tmp[i] = ch;
        i++;
    }
    fclose(file);
    return tmp;
}