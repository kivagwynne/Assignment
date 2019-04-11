//CIPHER ASSIGNEMT ENGG1003

#include <stdio.h>

//FUNCTION PROTOTYPES

char rEncrypt(char rE, int key); //rotation encryption function declaration
char rDecrypt(char rD, int key); //rotation decryption function declaration
char sEncrypt(char sE); //substitution encryption function declaration
char sDecrypt(char sD); //substitution decryption function declaration

//MAIN FUNCTION

int main() {

//USER INTERFACE
    
    printf("CIPHER\n\n");
    printf("a. Rotation Encryption\nb. Rotation Decryption\nc. Substitution Encryption\nd. Substitution Decryption\ne. Rotation Decryption with unknown key\n\nEnter Selection: ");
    char selection; //stores the choice
    scanf("%c", &selection);
    printf("Selection [%c]: ", selection);
    
//FILES
    
    FILE *input; //pointer to file 'input' for input text
    FILE *output; //pointer to file 'output' for output text
    
//CIPHERS
    
    switch(selection) {
            
        case 'a':
            
            printf("Rotation Encryption\n\n");
            int key;   //the integer that determines how far letters are shifted
            printf("Enter encryption key between 0 and 26: ");
            scanf("%d", &key);
            while ((key>26) || (key<0)) {
                printf("Enter encryption key between 0 and 26: ");
                scanf("%d", &key);
            }
            printf("\nEncrypted Text:\n\n"); //UI
            input=fopen("input.txt", "r"); //opens input file for reading
            output=fopen("output.txt", "w"); //opens output file for writing
            char string1[500]; //string to put the text from file
            int i1=0; //string iteration counter
            fscanf(input, " %[^\n]s", string1); //scans the file and puts it into a string, until newline(i.e. enter is pressed)
            while(string1[i1]!='\0') { //reads string before reaching the end of line
                char c; //the character being read
                c=string1[i1]; //makes c the ith element of the string(i.e. file)
                c=rEncrypt(c, key); //function call, encrypts each character as they are scanned according to the function (i.e. key)
                printf("%c", c); //prints each character to the console
                fprintf(output, "%c", c); //prints each character to an output file
                i1++;
            }
            printf("\n\n"); //makes it look good
            break;
            
        case 'b':
            
            printf("Rotation Decryption\n\n");
            printf("Enter decryption key between 0 and 26: ");
            scanf("%d", &key); //int key already declared in case a
            while ((key>26) || (key<0)) {
                printf("Enter decryption key between 0 and 26: ");
                scanf("%d", &key);
            }
            printf("\nDecrypted Text:\n\n");
            input=fopen("input.txt", "r");
            output=fopen("output.txt", "w");
            char string2[500];
            int i2=0;
            fscanf(input, " %[^\n]s", string2);
            while(string2[i2]!='\0') {
                char c;
                c=string2[i2];
                c=rDecrypt(c, key);
                printf("%c", c);
                fprintf(output, "%c", c);
                i2++;
            }
            printf("\n\n");
            break;
        
        case 'c':
            
            printf("Substitution Encryption\n\n");
            printf("The key is: MNBVCXZASDFGHJKLPOIUYTREWQ\n\n"); //to get user input, tell them to enter 26 uppercase letters
            printf("Encrypted Text:\n\n");
            input=fopen("input.txt", "r");
            output=fopen("output.txt", "w");
            char string3[500];
            int i3=0;
            fscanf(input, " %[^\n]s", string3);
            while(string3[i3]!='\0') {
                char c;
                c=string3[i3];
                c=sEncrypt(c);
                printf("%c", c);
                fprintf(output, "%c", c);
                i3++;
            }
            printf("\n\n");
            break;
            
        case 'd':
            
            printf("Substitution Decryption\n\n");
            printf("The key is: MNBVCXZASDFGHJKLPOIUYTREWQ\n\n"); //to get user input, tell them to enter 26 uppercase letters
            printf("Decrypted Text:\n\n");
            input=fopen("input.txt", "r");
            output=fopen("output.txt", "w");
            char string4[500];
            int i4=0;
            fscanf(input, " %[^\n]s", string4);
            while(string4[i4]!='\0') {
                char c;
                c=string4[i4];
                c=sDecrypt(c);
                printf("%c", c);
                fprintf(output, "%c", c);
                i4++;
            }
            printf("\n\n");
            break;
            
        default:
            
            printf("\n\nError. Run again.\n\n");
            
            break;
            
    }

    return 0;
}


/************************************************************************************************/
//FUNCTION DEFINITIONS
/************************************************************************************************/

//Rotation encryption function definition

    char rEncrypt(char rE, int key) {
        if((rE>=97) && (rE<=122)) { //if characters are lowercase according to ASCII value
            rE=rE-32; //subract 32, making it the equivalent uppercase letter in ASCII
        }
        if((rE+key)>90) { //if the encrypted ascii character goes past the uppercase letters
            rE=(rE+key)-26; //encrypts and makes any letters that drop off the end loop back to the front
        } else if((rE>=65) && (rE<=90)) { //if it is an uppercase letter, it will encrypt
            rE=rE+key; //encryption!!
        }
        return rE; //return the encrypted character to the main function
    }

/************************************************************************************************/

//Rotation decryption function definition

    char rDecrypt(char rD, int key) {
        if(((rD-key)<65) && (rD>=65) && (rD<=90)) { //if the encrypted letter (and not any other characters) goes below the uppercase letters
            rD=(rD-key)+26; //decrypts and makes any letters that drop off the front loop to the back
        } else if((rD>=65) && (rD<=90)) { //if it is an uppercase letter, it will decrypt
            rD=rD-key; //decryption!!
        }
        return rD;
    }

/************************************************************************************************/

//Substitution encrytion function definition - week 7 tuesday lecture - how to substitute letters (more of a simple way lol)

    char sEncrypt(char sE) {
        
        if((sE>=97) && (sE<=122)) { //if characters are lowercase according to ASCII value
            sE=sE-32; //subract 32, making it the equivalent uppercase letter in ASCII
        }
        char eString[26]="MNBVCXZASDFGHJKLPOIUYTREWQ"; //the substitution key
        char eAlphabet[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //the alphabet, to compare to the key
        int i=0; //iteration counter
        for(i=0; i<26; i++) {
            if(sE==eAlphabet[i]) { //when the character from file matches the character in the alphabet string
                //once they match, 'i' is 'remembered' - it respresents how many times it taks before they match
                sE=eString[i]; //if they match, the character becomes the corresponding 'i' element in the sub key
                break; //breaks once this has been achieved
            }
        }
        return sE; //return the encrypted character to the main function
       
    }

/************************************************************************************************/

//Substitution decryption function definition

    char sDecrypt(char sD) {
        
        char dString[26]="MNBVCXZASDFGHJKLPOIUYTREWQ"; //the substitution key
        char dAlphabet[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //the alphabet, to compare to the key
        int i=0; //iteration counter
        for(i=0; i<26; i++) {
            if(sD==dString[i]) { //when the character from file matches the character in the alphabet string
                //once they match, 'i' is 'remembered' - it respresents how many times it taks before they match
                sD=dAlphabet[i]; //if they match, the character becomes the corresponding 'i' element in the sub key
                break; //breaks once this has been achieved
            }
        }
        return sD; //return the decrypted character to the main function
    }

/************************************************************************************************/

//Rotation decryption without given key

    //test all of the keys, and test whether the (maybe 50%) words appear in the dictionary file (on the project sheet)
    //found in week 7 tues

/************************************************************************************************/
