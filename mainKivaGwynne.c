//CIPHER ASSIGNEMT ENGG1003

#include <stdio.h>

//FUNCTION PROTOTYPES

char rEncrypt(char rE, int key); //rotation encryption function declaration
char rDecrypt(char rD, int key); //rotation decryption

//MAIN FUNCTION

int main() {

//USER INTERFACE
    
    printf("ROTATION CIPHER\n\n");
    printf("a. Encrypt Text\nb. Decrypt Text\n\nEnter Selection: ");
    char selection; //stores the choice
    scanf("%c", &selection);
    printf("Selection [%c]: ", selection);
    
//FILES
    
    FILE *input; //pointer to file 'input'
    FILE *output; //pointer to file 'input'
    
//CIPHERS
    
    switch(selection) {
            
        case 'a':
            
            printf("Encryption\n\n");
            int key;   //the integer that determines how far letters are shifted
            printf("Enter encryption key between 0 and 25: ");
            scanf("%d", &key);
            while ((key>25) || (key<0)) {
                printf("Enter encryption key between 0 and 25: ");
                scanf("%d", &key); //WHAT IF YOU ENTER A LETTER???
            }
            printf("\nEncrypted Text:\n\n"); //UI
            input=fopen("input.txt", "r"); //opens input file for reading
            output=fopen("output.txt", "w"); //opens output file for writing
            while(feof(input)==0) { //??????????? week 7 lecture
                char c; //the character being read
                fscanf(input, "%c", &c); //reads character, puts in c
                c=rEncrypt(c, key); //function call, encrypts each character as they are scanned according to the function
                printf("%c", c); //prints each character to the console
                fprintf(output, "%c", c); //prints each character to an output file
            }
            printf("\n\n"); //makes it look good
            break;
            
        case 'b':
            
            printf("Decryption\n\n");
            printf("Enter decryption key between 0 and 25: ");
            scanf("%d", &key);
            while ((key>25) || (key<0)) {
                printf("Enter decryption key between 0 and 25: ");
                scanf("%d", &key); //WHAT IF YOU ENTER A LETTER???
            }
            printf("\nDecrypted Text:\n\n");
            input=fopen("input.txt", "r");
            output=fopen("output.txt", "w");
            while(feof(input)==0) { //??????????? week 7 lecture
                char c;
                fscanf(input, "%c", &c);
                c=rDecrypt(c, key);
                printf("%c", c); //prints each character to the console
                fprintf(output, "%c", c); //prints each character to an output file
            }
            printf("\n\n");
            break;
        
        default:
            
            printf("\n\nError. Run again.\n\n");
            
            break;
            
    }

    return 0;
}



//FUNCTION DEFINITIONS

//Rotation encryption function definition
char rEncrypt(char rE, int key) {
    if((rE>=97) && (rE<=122)) { //if characters are lowercase according to ASCII value
        rE=rE-32; //subract 32, making it the equivalent uppercase letter in ASCII
    }
    if((rE+key)>90) { //if the encrypted ascii character goes past the uppercase letters
        rE=(rE+key)-26; //encrypts and makes any letters that drop off the end loop back to the front
    } else if ((rE>=65) && (rE<=90)) { //if it is an uppercase letter, it will encrypt
        rE=rE+key; //encryption!!
    }
    return rE; //return the encrypted character to the main function
}

//Rotation decryption function definition
char rDecrypt(char rD, int key) {
    if(((rD-key)<65) && (rD>=65) && (rD<=90)) { //if the encrypted letter (and not any other characters) goes below the uppercase letters
        rD=(rD-key)+26; //decrypts and makes any letters that drop off the front loop to the back
    } else if ((rD>=65) && (rD<=90)) { //if it is an uppercase letter, it will decrypt
        rD=rD-key; //decryption!!
    }
    return rD;
}

//Substitution encrytion function definition

//Substitution decryption function definition
