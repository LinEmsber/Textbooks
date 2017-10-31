/* Count the occurrence of a substring. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv)
{
        int count = 0;
        char * ptr;

        if (argc < 3){
                printf("Please enter two strings.\n");
        }

        printf("argv[1]: %s, string length: %zu\n", argv[1], strlen(argv[1]));
        printf("argv[2]: %s, string length: %zu\n", argv[2], strlen(argv[2]));

        ptr = argv[1];

        // do{
        //         ptr = strstr(ptr, argv[2]);
        //         if (ptr != NULL){
        //                 printf("%s\n", ptr);
        //                 count++;
        //                 ptr++;
        //         }
        // } while(ptr != NULL);

        while(ptr != NULL){
                ptr = strstr(ptr, argv[2]);
                if (ptr != NULL){
                        printf("%s\n", ptr);
                        count++;
                        ptr++;
                }
        }
        
        if (count == 0){
                printf("argv[2] is not a substring of argv[1].\n");
        }
        else{
                printf("argv[2] occurs %d times in argv[1].\n", count);
        }


        return EXIT_SUCCESS;
}
