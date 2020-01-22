// main.c
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



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


	while ((read = getline(&line, &len, fp)) != -1) {
        
        
    }


	fclose(fp);
	if(line){
		free(line);
    }

	exit(0);
}
