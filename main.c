// main.c
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>



int in_dict(const char* word, const char* dict, size_t dict_size){


}



int main(void){
	FILE *fp;	
	FILE *fpout;	
    char * line = NULL;
    size_t len = 0;
    ssize_t read;


	if ((fp = fopen("dict.txt","r")) == NULL){
	   printf("Error opening file");
	   // Program exits if the file pointer returns NULL.
	   exit(1);
	}

    fseek(fp, 0L, SEEK_END);
    int sz = ftell(fp);
    sz++;
    rewind(fp);
    char *dict = (char *) malloc(sz*sizeof(char));
    dict[0] = '\0';

	while ((read = getline(&line, &len, fp)) != -1) {
        line[strlen(line)-1] = ' '; 
        line[strlen(line)] = '\0'; 
        strcat(dict, line); 
    }

    char *buffer = (char *) malloc(50*sizeof(char));
    memcpy(buffer, dict, 50); 

    printf("%s\n", buffer);

	fclose(fp);
	if(line){
		free(line);
    }
    free(dict);
    free(buffer);

	exit(0);
}
