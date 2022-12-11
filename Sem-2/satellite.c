#include <stdio.h>
#include <string.h>

int main ()
{
    FILE * filepointer;
    char myfile[500];
    filepointer=fopen("Satellite_data.csv", "r");
    if (filepointer==NULL) {
        printf("File not found\n");
    }
    else {
        printf("The file is opened\n");
        while( fgets ( myfile, 500, filepointer ) != NULL )
        {
         
            // Print the myfile
            printf( "%s" , myfile ) ;
        }

         
         
        printf("Data successfully read\n");
        // Closing the file using fclose()
        fclose(filepointer) ;
        printf("The file is now closed.") ;
    }
    return 0;       
}
