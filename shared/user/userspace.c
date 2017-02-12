/* ============================================
 * Author: Jacob Adkins
 * Description: simple c program that prints numbers 1-100000
 * into a file, recording executions time, then deletes the file.
 */

#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[])
{
        clock_t begin, end;
        double delta;
        char str[10];
        int i;
        begin = clock();
        
                FILE* fp = fopen("file", "w");
                for (i = 0; i < 100000; i++)
                {
                        sprintf(str, "%d\n", i);
                        fputs(str, fp);
                } 
                fclose(fp);
        
        end = clock(); 
        delta = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Time Spent: %f\n", delta);
        remove("file");
        return(0);
}
