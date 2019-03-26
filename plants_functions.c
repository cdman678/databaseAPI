/* Functions to interact with database 'plants'*/

#include "databaseAPI.h"

/****/
//Establishing SQL variables 
MYSQL *conn;    //Saving the connection
MYSQL_RES *res; //Result of query variable
MYSQL_ROW row;  //Used for reading rows in a table

//Establishing 'log in' credentials  
char *server = "localhost";
char *user = "ubuntu";
char *password = "cornisgood";
char *database = "plants";
/****/

//Currently this function returns the description of a given plantName (this could be switched to plantID
void description(char plantName[20]) {
 
   //creating 'connection' object
   conn = mysql_init(NULL);
 
   // Check Connect to database before executing command
   if (!mysql_real_connect(conn, server,user, password, database, 0, NULL, 0)) {
      //executes upon error
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }
 
   //Creating query string to pass to mySQL
   char query_temp[1000] = "SELECT p.name, d.description FROM masterPlants p, description d WHERE p.plantID = d.plantID AND p.name =\"";
   char temp[10] = "\";";
   strcat(query_temp, plantName);
   strcat(query_temp, temp); 
 
   const char (*query)[1000] = &query_temp;
 
   // send SQL query
   if (mysql_query(conn, *query)){
      //executes upon error
      //fprintf(stderr, "%s\n", mysql_error(conn));
      printf("exit(1)\n");
      exit(1);
   }
  
   //saving the result
   res = mysql_use_result(conn);
   
   //finding how many fields are in the result from the above query
   int num_fields = mysql_num_fields(res);

   //prints the result of the query
   while ((row = mysql_fetch_row(res))) { 
      for(int i = 0; i < num_fields; i++){ 
          printf("%s ", row[i] ? row[i] : "NULL"); 
      } 
          printf("\n"); 
   }

   // close connection to server
   mysql_free_result(res);
   mysql_close(conn);
}

