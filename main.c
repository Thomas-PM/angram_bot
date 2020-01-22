// main.c
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int contains(const char* in){
    int i = 0; 
    while(in[i] != 0){
        if(in[i] == '\''){
            return 1;
        }
        i++;
    }
    return 0;
}


int main(void){
	FILE *fp;	
	FILE *fpout;	
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    printf("char %c\n", '\'');

	if ((fp = fopen("dict_in.txt","r")) == NULL){
	   printf("Error opening file");
	   // Program exits if the file pointer returns NULL.
	   exit(1);
	}
	if ((fpout = fopen("dict.txt","w")) == NULL){
	   printf("Error opening file");
	   // Program exits if the file pointer returns NULL.
	   exit(1);
	}

	while ((read = getline(&line, &len, fp)) != -1) {
        if(!contains(line)){
            printf("%s", line);
            fprintf(fpout, "%s", line);
        }
        
    }


	fclose(fp);
	fclose(fpout);
	if(line){
		free(line);
    }

	exit(0);
}
