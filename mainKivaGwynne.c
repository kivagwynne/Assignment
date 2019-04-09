#include <stdio.h>

//ROTATION CIPHER tings

//Function prototypes





int main() {

    
    //user interface and scanning etc
    
    printf("ROTATION CIPHER\n\n");
    printf("a. Encrypt Text\nb. Decrypt Text\n\nEnter Selection: ");
    char selection; //stores the choice
    scanf("%c", &selection);
    printf("Selection [%c]: ", selection);
    
    
    
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
            
            
            FILE *input; 
            FILE *output;
            input=fopen("input.txt", "r"); //reads the file
            output=fopen("output.txt", "w"); //writes the file
            while(feof(input)==0) { //??????????? week 7 lecture
                
                char c; //the character being read
                fscanf(input, "%c", &c); //reads character, puts in c
                
                if((c>=97) && (c<=122)) { //if characters are lowercase
                    c=c-32; //subract 32, making it the equivalent uppercase letter in ASCII
                }
                if((c+key)>90) { //if the encrypted ascii character goes past the uppercase letters
                    c=(c+key)-26; //makes any letters that drop off the end loop back to the front
                } else if ((c>=65) && (c<=90)) { //if it is an uppercase letter, it will encrypt
                    c=c+key; //encryption!!
                }
                
                printf("%c", c); //prints each character to the console
                fprintf(output, "%c", c); //prints each charcter to an output file
            }
            
            
            break;
       
        default:
            
            printf("\n\nError. Run again.\n\n");
            
            break;
            
    }
    

return 0;
}



//FUNCTION DEFINITIONS






/*PSEUDOCODE
 *
 * Encryption:
 
 Initialise a string and a counter variable (and a case variable later for UI)
 key variable
 at first, hardcode in the letters (scan later)
 scan in a key
 take the string and add the key to each element (i) through a for loop
 do this loop whilst the count is 0 to whatever the length of the string is
 i.e. for each iteration, the ith element will have the key added
 print
 
 
 
 
 
 *
 */
