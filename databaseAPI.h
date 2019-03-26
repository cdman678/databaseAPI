//databaseAPI.h file
#ifndef _databaseAPI_h
#define _databaseAPI_h

#include <mysql.h>  //interacting with mySQL
#include <stdio.h>  //input output
#include <string.h> //using strings

//Returns the name and description given a plant name - currently just prints
void description(char plantName[20]);

#endif
