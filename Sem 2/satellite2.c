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
        fgets ( myfile, 500, filepointer );
         
        printf("Data successfully read\n");
        // Closing the file using fclose()
        fclose(filepointer) ;
        printf("The file is now closed.") ;

        printf("%s\n",myfile);
    }

    return 0;       
}
