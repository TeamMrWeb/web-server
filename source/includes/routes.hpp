/**
 * @file routes.h
 * @brief Routes headers management file for the website server.
*/

#include <stdlib.h>
#include <string.h>

/**
 * Route structure for the website server.
 * @param key The route key.
 * @param value The route value.
 * @param left The left route.
 * @param right The right route.
 * @return The route structure.
*/
struct route 
{
    char* key;
    char* value;
    struct route *left, *right;  
};

struct route * InitiliazeRoute(char* key, char* value);