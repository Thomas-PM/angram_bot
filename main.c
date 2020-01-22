// main.c
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>



// Create the dictionary string
void create_dict(FILE *fp, char *dictionary);
// Check if it's in the dictionary
int in_dict(const char* word, const char* dict, size_t dict_size);





int main(void){
	FILE *fp;	


// Read dictionary file
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


    create_dict(fp, dict);


/* Check dictionary's creation
    char *buffer = (char *) malloc(50*sizeof(char));
    memcpy(buffer, &dict[20000], 50); 
    printf("%s\n", buffer);
*/

	fclose(fp);
    free(dict);

	exit(0);
}



// Create the dictionary string
void create_dict(FILE *fp, char *dictionary){
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    // Note: for the sake of simplicity and speed this function makes assumptions about 
    // the input dictionary file
	while ((read = getline(&line, &len, fp)) != -1) {
        if(srlen(line) > 1){
            for(int i = 0; i < strlen(line); i++){
                line[i] = tolower(line[i]);
            }
            line[strlen(line)-1] = ' '; 
            line[strlen(line)] = '\0'; 
            strcat(dictionary, line); 
        }
    }
    
	if(line){
		free(line);
    }

}

// -: a < b, 0: a = b, +: a > b
int word_compare(const char* a, const char* b){
    int comp = 0;
    int i = 0;
    for(i = 0; i < strlen(a); i++){
        if(b[i] = '\0'){
            // a is longer than b
            return 1;
        }

        comp = b[i] - a[i];    
        if(comp != 0){
            return comp;
        }
    }
    if(b[i] = '\0'){
        // a and b are the same
        return 0;
    }

    // b is longer than a
    return -1;

}

// Check if it's in the dictionary
int in_dict(const char* word, const char* dict, size_t dict_size){
    for(int i = 0; i < dict_size; i++){
    }
        

}



