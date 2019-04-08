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
                printf("\nBETWEEN 0 AND 25: ");
                scanf("%d", &key); //WHAT IF YOU ENTER A LETTER???
            }
            
            char eString[5000];  //string of length 5000 bytes - this is currently hardcoded
            printf("\nEnter text: ");
            scanf("%s", eString); //scans in a string - currently set aside because can't scan spaces //how to include space???
            
            int eIndex; //iteration count/index
            //char eString[5000]="hello there";//this is the hardcode
            for(eIndex=0; (eIndex<500 && eString[eIndex]!='\0'); eIndex++) { //goes through all elements
                
                if((eString[eIndex]>=97) && (eString[eIndex]<=122)) { //if characters are lowercase
                    eString[eIndex]=eString[eIndex]-32; //subract 32, making it the equivalent uppercase letter in ASCII
                }
                if((eString[eIndex]+key)>90) { //if the encrypted ascii character goes past the uppercase letters
                    eString[eIndex]=(eString[eIndex]+key)-26; //makes any letters that drop off the end loop back to the front
                } else if ((eString[eIndex]>=65) && (eString[eIndex]<=90)) { //if it is an uppercase letter, it will encrypt
                    eString[eIndex]=eString[eIndex]+key;
                }
            }
            
            printf("\nEncrypted text: %s\n\n", eString);
            
            break;
       
        case 'b':
            
            printf("Decryption\n\n");
            printf("Enter decryption key between 0 and 25: ");
            scanf("%d", &key);
            
            while ((key>25) || (key<0)) {  //if any other integer is used, display error
                //WHAT IF YOU ENTER A LETTER???
                printf("\nBETWEEN 0 AND 25: ");
                scanf("%d", &key);
            }
            
            char dString[5000];  //string of length 5000 bytes - this is currently hardcoded
            printf("\nEnter text: ");
            scanf("%s", dString); //scans in a string - currently set aside because can't scan spaces //how to include space???
            
            
            //FUNCTION below - MAKE IT A FUNCTION AND CALL IT - describe the function w/comment above description
            
            int dIndex; //iteration count/index
            //char dString[5000]={'h', 'e', 'l', 'l', 'o', ' ', 't', 'h', 'e', 'r', 'e', '\0'}; //this is the hardcode
            for(dIndex=0; (dIndex<500 && dString[dIndex]!='\0'); dIndex++) { //goes through all elements
                
                if((dString[dIndex]>=97) && (dString[dIndex]<=122)) { //if characters are lowercase
                    dString[dIndex]=dString[dIndex]-32; //subract 32, making it the equivalent uppercase letter in ASCII
                }
                if((dString[dIndex]+key)>90) { //if the encrypted ascii character goes past the uppercase letters
                    dString[dIndex]=(dString[dIndex]+key)-26; //makes any letters that drop off the end loop back to the front
                } else if ((dString[dIndex]>=65) && (dString[dIndex]<=90)) { //if it is an uppercase letter, it will encrypt
                    dString[dIndex]=dString[dIndex]-key;
                }
                
            }
            
            printf("\nDecrypted text: %s\n\n", dString);
            
            break;
            
        default:
            
            printf("\n\nError. Run again.\n\n");
            
            
            
    }
    


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
