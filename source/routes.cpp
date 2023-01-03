/**
 * @file routes.c
 * @brief This file contains routes logic for the web server.
*/

#include "./includes/routes.hpp"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct route * InitiliazeRoute(char* key, char* value)
{
    struct route * tmp = (struct route *) malloc(sizeof(struct route));
    // TODO: Check if malloc failed.
}