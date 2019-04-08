#include <stdio.h>

//ROTATION CIPHER tings


int main() {
    
    //user interface and scanning etc
    
    printf("ROTATION CIPHER\n\n");
    
    char string[5000]; //string of length 5000 bytes
    int key; //the integer that determines how far letters are shifted
    
    printf("Enter encryption key between 0 and 26: ");
    scanf("%d", &key);
    
    if((key>26) || (key<0)) {  //if any other integer is used, display error
        //WHAT IF YOU ENTER A LETTER???
        printf("\nr u stupid? enter a key between 0 and 25 spastic: ");
        scanf("%d", &key);
    }
   
    
    printf("\nEnter a string: ");
    scanf("%s", string); //scans in a string
    
    
    //FUNCTION below - MAKE IT A FUNCTION AND CALL IT - describe the function w/comment above description
    
    int index; //iteration count/index
    for(index=0; (index<500 && string[index]!='\0'); index++) { //goes through all elements
        
        if((string[index]>=97) && (string[index]<=122)) { //if characters are lowercase
            string[index]=string[index]-32; //subract 32, making it the equivalent uppercase letter in ASCII
        }
        
        //how to include space???
        
        if((string[index]+key)>90) { //if the encrypted ascii character goes past the uppercase letters
            string[index]=(string[index]+key)-26; //makes any letters that drop off the end loop back to the front
            
        } else if ((string[index]>=65) && (string[index]<=90)) { //if it is an uppercase letter, it will encrypt
            string[index]=string[index]+key;
        }
        
    }
    
    printf("\nEncrypted string: %s\n\n", string);

}






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
