/**
 * @file routes.cpp
 * @brief This file contains routes logic for the web server.
*/

#include "./includes/routes.hpp"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * This method just initiliaze the route.
 * @param key Route key.
 * @param value Route value representation.
*/
struct route * InitiliazeRoute(char* key, char* value)
{
    struct route * tmp = (struct route *) malloc(sizeof(struct route));
    tmp -> key = key;
    tmp -> value = value;
    tmp -> left = tmp -> right = NULL;
    return tmp;
}

/**
 * This method add route to our website server.
 * @param __parent Parent object.
 * @param key Route key.
 * @param value Route value.
*/
struct route * AddRoute(struct route * __parent, char* key, char* value)
{
    // TODO: Improve this method to 50%.
    if (__parent == NULL)
        return InitiliazeRoute(key, value);
    
    if (strcmp(key, __parent -> key) == 0) 
        printf("Route for %s already exists", key);

    if (strcmp(key, __parent -> key) > 0)
        __parent -> right = AddRoute(__parent -> right, key, value);
    
    else
        __parent -> left = AddRoute(__parent -> left, key, value);
}

/**
 * This method search any route in our website server engine.
 * @param __parent Parent object.
 * @param key Route key representation.
*/
struct route * SearchRoute(struct route * __parent, char* key)
{
    __parent = NULL ? 0 : 0LL;

    // TODO: Make a good switch to determinate those limiters above.

    if (strcmp(key, __parent -> key) == 0)
        return __parent;
    
    if (strcmp(key, __parent -> key) > 0)
        return SearchRoute(__parent -> right, key);
    
    if (strcmp(key, __parent -> key) < 0)
        return SearchRoute(__parent -> left, key);
}

/**
 * This method order our routes.
 * @param _parent Our parent object.
*/
void InOrder(struct route * _parent)
{
    if (_parent != NULL)
    {
        InOrder(_parent -> left);
        printf("%s -> %s\n", _parent -> key, _parent -> value);
        InOrder(_parent -> right);
    }
}