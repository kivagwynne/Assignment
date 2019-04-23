//CIPHER ASSIGNEMT ENGG1003

//K&R style indentation

#include <stdio.h>

//HIGH LEVEL OPERATION OF THE PROGRAM DESCRIPTION

/*
 *  This program encrypts and decrypts english text using both a rotation
 *  cipher and substitution cipher, with a known key. The program also decrypts
 *  rotation cipher text with an unknown key, according to letter frequency
 *  analysis (can also decrypt using every possible key). The user interface
 *  allows the user to choose between the different encryptions and decryptions
 *  by printing the options and scanning the user input. The input text is
 *  taken from an input file, and the resulting text is printed to the console
 *  and an output file
 */

//FUNCTION PROTOTYPES

char rEncrypt(char rE, int key); //rotation encryption function declaration
char rDecrypt(char rD, int key); //rotation decryption function declaration
char sEncrypt(char sE); //substitution encryption function declaration
char sDecrypt(char sD); //substitution decryption function declaration
char rKDecrypt(char rKD, int rKey); //rotation decryption without key function declaration

//MAIN FUNCTION

int main()
{

//USER INTERFACE (UI)
    
    printf("CIPHER SELECTION MENU\n\n");
    printf("a. Rotation Encryption\n"); //each function of the program can be  
    printf("b. Rotation Decryption\n"); //selected, and is printed to the console
    printf("c. Substitution Encryption\n");
    printf("d. Substitution Decryption\n");
    printf("e. Rotation Decryption with Unknown Key via Frequency Analysis\n");
    printf("f. Rotation Decryption Using All Possible Keys\n");
    printf("\nEnter Selection: "); //prompts the user to enter the desired selection
    char selection; //variable to store the selection of the user
    scanf("%c", &selection); //scans the selection entered by the user, stores in 'selection'
    printf("Selection [%c]: ", selection); //prints selection for user friendliness
    
//FILES
    
    FILE *input; //pointer to file 'input' for input text
    FILE *output; //pointer to file 'output' for output text
    
//CIPHERS
    
    switch(selection) { //switch case, which 'jumps' to the function selected by the user
            
        case 'a':
            printf("Rotation Encryption\n\n"); //for clear UI
            int key; //determines how far letters are shifted (the key)
            printf("Enter encryption key between 0 and 26: "); //prompts user to enter key
            scanf("%d", &key); //scans the user input and stores it in 'key'
            while ((key>26) || (key<0)) { //while the key is not within range 0-26, for robustness?
                printf("Enter encryption key between 0 and 26: "); //repeats if input is incorrect
                scanf("%d", &key); //scans the user input and stores it in 'key'
            }
            printf("\nEncrypted Text:\n\n"); //UI
            input=fopen("input.txt", "r"); //opens 'input' file for reading
            output=fopen("output.txt", "w"); //opens 'output' file for writing
            char string1[10000]; //string to store the text from file
            int i1=0; //string element counter
            fscanf(input, " %[^\n]s", string1); //scans file and puts in  string, until new line reached
            while(string1[i1]!='\0') { //reads string until nulled, performs the operation below for each character
                char c; //variable for the character being read
                c=string1[i1]; //makes c the ith element of the string (i.e. the ith character)
                c=rEncrypt(c, key); //function call, encrypts each character as they are scanned according to the function
                printf("%c", c); //prints each character to the console
                fprintf(output, "%c", c); //prints each character to the output file
                i1++; //increment to move to the next element of the text string
            }
            printf("\n\n");
            break;
            
        case 'b':
            printf("Rotation Decryption\n\n"); //for clear UI
            printf("Enter decryption key between 0 and 26: "); //how far letters have been shifted in cipher text
            scanf("%d", &key); //int key already declared in case a - user input scanned and stored in 'key'
            while ((key>26) || (key<0)) { //while the key is not within range 0-26
                printf("Enter decryption key between 0 and 26: "); //repeats the prompt if input is incorrect
                scanf("%d", &key); //scans the user input and stores it in 'key'
            }
            printf("\nDecrypted Text:\n\n"); //UI
            input=fopen("input.txt", "r"); //opens 'input' file for reading
            output=fopen("output.txt", "w"); //opens 'output' file for writing
            char string2[10000]; //string to store the text from file
            int i2=0; //string element counter
            fscanf(input, " %[^\n]s", string2); //scans file and puts in  string, until new line reached
            while(string2[i2]!='\0') { //reads string until nulled, performs the operation below for each character
                char c; //variable for the character being read
                c=string2[i2]; //makes c the ith element of the string (i.e. the ith character)
                c=rDecrypt(c, key); //function call, decrypts each character as they are scanned according to the function
                printf("%c", c); //prints each character to the console
                fprintf(output, "%c", c); //prints each character to the output file
                i2++; //increment to move to the next element of the text string
            }
            printf("\n\n");
            break;
        
        case 'c':
            printf("Substitution Encryption\n\n"); //for clear UI
            printf("The key is: MNBVCXZASDFGHJKLPOIUYTREWQ\n\n"); //the substitution letters (26 letters) - printed for UI
            printf("Encrypted Text:\n\n"); //UI
            input=fopen("input.txt", "r"); //opens 'input' file for reading
            output=fopen("output.txt", "w"); //opens 'output' file for writing
            char string3[10000]; //string to store the text from file
            int i3=0; //string element counter
            fscanf(input, " %[^\n]s", string3); //scans file and puts in  string, until new line reached
            while(string3[i3]!='\0') { //reads string until nulled, performs the operation below for each character
                char c; //variable for the character being read
                c=string3[i3]; //makes c the ith element of the string (i.e. the ith character)
                c=sEncrypt(c); //function call, encrypts each character as they are scanned according to the function
                printf("%c", c); //prints each character to the console
                fprintf(output, "%c", c); //prints each character to the output file
                i3++; //increment to move to the next element of the text string
            }
            printf("\n\n");
            break;
            
        case 'd':
            printf("Substitution Decryption\n\n"); //for clear UI
            printf("The key is: MNBVCXZASDFGHJKLPOIUYTREWQ\n\n"); //the substitution letters (26 letters) - printed for UI
            printf("Decrypted Text:\n\n"); //UI
            input=fopen("input.txt", "r"); //opens 'input' file for reading
            output=fopen("output.txt", "w"); //opens 'output' file for writing
            char string4[10000]; //string to store the text from file
            int i4=0; //string element counter
            fscanf(input, " %[^\n]s", string4); //scans file and puts in  string, until new line reached
            while(string4[i4]!='\0') { //reads string until nulled, performs the operation below for each character
                char c; //variable for the character being read
                c=string4[i4]; //makes c the ith element of the string (i.e. the ith character)
                c=sDecrypt(c); //function call, decrypts each character as they are scanned according to the function
                printf("%c", c); //prints each character to the console
                fprintf(output, "%c", c); //prints each character to the output file
                i4++; //increment to move to the next element of the text string
            }
            printf("\n\n");
            break;
            
        case 'e':
            printf("Rotation Decryption with Unknown Key via Frequency Analysis"); //UI
            printf("\n\nDecrypted Text (assuming the most frequent letters in the English language to be E, T, A, O and I):\n\n"); //UI
            input=fopen("input.txt", "r"); //opens 'input' file for reading
            output=fopen("output.txt", "w"); //opens 'output' file for writing
            char a, b, cc, d, e, f, g, h, ii, j, k, l, m; //variables to store the frequency of each letter in cipher text
            char n, o, p, q, r, s, t, u, v, w, x, y, z;
            a=0; b=0; cc=0; d=0; e=0; f=0; g=0; h=0; ii=0; j=0; k=0; l=0; m=0; //initialise to 0 before frequency analysis, which will then increment
            n=0; o=0; p=0; q=0; r=0; s=0; t=0; u=0; v=0; w=0; x=0; y=0; z=0;
            while(!feof(input)) { //before the end of the file
                char cK; //variable to store the character when scanned
                fscanf(input, "%c", &cK); //scans each character in the input file text, puts in cK for switch case
                switch(cK) { //switch case for cK - increments the variable for the given letter of the alphabet
                    case 'A': a++; break; //case for each letter
                    case 'B': b++; break;
                    case 'C': cc++; break; //cc and ii used because c and i are already used
                    case 'D': d++; break;
                    case 'E': e++; break;
                    case 'F': f++; break;
                    case 'G': g++; break;
                    case 'H': h++; break;
                    case 'I': ii++; break;
                    case 'J': j++; break;
                    case 'K': k++; break;
                    case 'L': l++; break;
                    case 'M': m++; break;
                    case 'N': n++; break;
                    case 'O': o++; break;
                    case 'P': p++; break;
                    case 'Q': q++; break;
                    case 'R': r++; break;
                    case 'S': s++; break;
                    case 'T': t++; break;
                    case 'U': u++; break;
                    case 'V': v++; break;
                    case 'W': w++; break;
                    case 'X': x++; break;
                    case 'Y': y++; break;
                    case 'Z': z++; break;
                    default: break;
                }
            }
            int data[27]={a, b, cc, d, e, f, g, h, ii, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z}; //string for each value of letter frequency
            int max=-1000000; //stores the letter of highest frequency - set to a negative number to ensure the max value replaces it
            int maxIndex=0; //variable to store the element of the string with the highest value (frequency)
            int i; //string element variable
            float sum; //variable to store the sum of total letters in the text
            sum=a+b+cc+d+e+f+g+h+ii+j+k+l+m+n+o+p+q+r+s+t+u+v+w+x+y+z; //adds the frequency of each letter to get total sum
            for(i=0; i<=26; i++) { //runs through each letter frequency value for the alphabet
                if(data[i]>max) { //when the frequency value is larger than any previous values
                    max=data[i]; //the new largest value replaces the old value
                    maxIndex=65+i; //the index becomes the element of the string, plus 65 to correspond to an ASCII character
                }
            }
            input=fopen("input.txt", "r"); //opens input for reading
            output=fopen("output.txt", "w"); //opens output for writing
            char string5[10000]; //string to store text from file
            int aaE=0, eeE=0, iiE=0, ooE=0, ttE=0; //variables to store the frequency of E, T, A, I, O (most common letters)
            float sumCommonE; //variable to store sum of the 5 most common letters
            int i5=0; //string element counter
            char c; //character being read
            int rKey; //stores key
            rKey=maxIndex-69+26; //gets index for most frequent letter, giving a key that shifts letter to E (and shifts all by same amount)
            if(rKey>26)
                rKey=rKey-26; //wraps key back around if it goes past 26
            fscanf(input, " %[^\n]s", string5); //scans file and puts in  string, until new line reached
            while(string5[i5]!='\0') { //reads string until nulled, performs the operation below for each character
                c=string5[i5]; //makes c the ith element of the string (i.e. the ith character)
                c=rKDecrypt(c, rKey); //function call, decrypts each character as they are scanned according to the function
                if(c=='A') //after decryption, the frequency of the most common letters are remembered by incrementing the variables
                    aaE++;
                if(c=='E')
                    eeE++;
                if(c=='I')
                    iiE++;
                if(c=='O')
                    ooE++;
                if(c=='T')
                    ttE++;
                printf("%c", c); //prints to console
                fprintf(output, "%c", c); //prints to output file
                i5++; //moves to the next element of the text string
            }
            sumCommonE=aaE+eeE+iiE+ooE+ttE; //adds frequencies of common letters
            //printf("\n\n%f\n\n", sumCommonE);
            float ratioE; //
            ratioE=sumCommonE/sum; //variable stores the ratio of the sum of 5 most common letters to the total sum
            if(ratioE>0.36) { //when the text is decrypted correctly, is is highly likely that the common letters make up over 36% of total letters
                printf("\n\n");
                break; //when the ratio is over 0.36, it will break after (hopefully) printing the decrypted text.
                //the longer the cipher text, the more likely it will be decrypted correctly
            }
                //THE PROCESS ABOVE IS REPEATED FOR T, A, I and O.
            
            printf("\n\n");
            i5=0;
            input=fopen("input.txt", "r");
            output=fopen("output.txt", "w");
            int aaT=0, eeT=0, iiT=0, ooT=0, ttT=0;
            float sumCommonT;
            rKey=maxIndex-84+26; //for T as most common
            if(rKey>26)
                rKey=rKey-26;
            fscanf(input, " %[^\n]s", string5);
            while(string5[i5]!='\0') {
                c=string5[i5];
                c=rKDecrypt(c, rKey);
                if(c=='A')
                    aaT++;
                if(c=='E')
                    eeT++;
                if(c=='I')
                    iiT++;
                if(c=='O')
                    ooT++;
                if(c=='T')
                    ttT++;
                printf("%c", c);
                fprintf(output, "%c", c);
                i5++;
            }
            sumCommonT=aaT+eeT+iiT+ooT+ttT;
            float ratioT;
            ratioT=sumCommonT/sum;
            if(ratioT>0.36) {
                printf("\n\n");
                break;
            }
            printf("\n\n");
            i5=0;
            input=fopen("input.txt", "r");
            output=fopen("output.txt", "w");
            int aaA=0, eeA=0, iiA=0, ooA=0, ttA=0;
            float sumCommonA;
            rKey=maxIndex-65+26; //for A as most common
            if(rKey>26)
                rKey=rKey-26;
            fscanf(input, " %[^\n]s", string5);
            while(string5[i5]!='\0') {
                c=string5[i5];
                c=rKDecrypt(c, rKey);
                if(c=='A')
                    aaA++;
                if(c=='E')
                    eeA++;
                if(c=='I')
                    iiA++;
                if(c=='O')
                    ooA++;
                if(c=='T')
                    ttA++;
                printf("%c", c);
                fprintf(output, "%c", c);
                i5++;
            }
            sumCommonA=aaA+eeA+iiA+ooA+ttA;
            //printf("\n\n%f\n\n", sumCommonA);
            float ratioA;
            ratioA=sumCommonA/sum;
            if(ratioA>0.36) {
                printf("\n\n");
                break;
            }
            printf("\n\n");
            i5=0;
            input=fopen("input.txt", "r");
            output=fopen("output.txt", "w");
            int aaO=0, eeO=0, iiO=0, ooO=0, ttO=0;
            float sumCommonO;
            rKey=maxIndex-79+26; //for O as most common
            if(rKey>26)
                rKey=rKey-26;
            fscanf(input, " %[^\n]s", string5);
            while(string5[i5]!='\0') {
                c=string5[i5];
                c=rKDecrypt(c, rKey);
                if(c=='A')
                    aaO++;
                if(c=='E')
                    eeO++;
                if(c=='I')
                    iiO++;
                if(c=='O')
                    ooO++;
                if(c=='T')
                    ttO++;
                printf("%c", c);
                fprintf(output, "%c", c);
                i5++;
            }
            sumCommonO=aaO+eeO+iiO+ooO+ttO;
            float ratioO;
            ratioO=sumCommonO/sum;
            if(ratioO>0.36) {
                printf("\n\n");
                break;
            }
            printf("\n\n");
            i5=0;
            input=fopen("input.txt", "r");
            output=fopen("output.txt", "w");
            int aaI=0, eeI=0, iiI=0, ooI=0, ttI=0;
            float sumCommonI;
            rKey=maxIndex-73+26; //for I as most common
            if(rKey>26)
                rKey=rKey-26;
            fscanf(input, " %[^\n]s", string5);
            while(string5[i5]!='\0') {
                c=string5[i5];
                c=rKDecrypt(c, rKey);
                if(c=='A')
                    aaI++;
                if(c=='E')
                    eeI++;
                if(c=='I')
                    iiI++;
                if(c=='O')
                    ooI++;
                if(c=='T')
                    ttI++;
                printf("%c", c);
                fprintf(output, "%c", c);
                i5++;
            }
            sumCommonI=aaI+eeI+iiI+ooI+ttI;
            float ratioI;
            ratioI=sumCommonI/sum;
            if(ratioI>0.36) {
                printf("\n\n");
                break;
            }
            printf("\n\n");
            printf("If the decrypted text does not appear, run the program again choosing option [f].\n\n");
            break;
            
        case 'f':
            printf("Rotation Decryption Using All Possible Keys"); //UI
            printf("\n\nDecrypted Text:\n\n"); //UI
            for(int rKey=0; rKey<26; rKey++) { //loop tests every possible rotation key from 0 to 25
                input=fopen("input.txt", "r"); //opens 'input' file for reading
                output=fopen("output.txt", "w"); //opens 'output' file for writing
                char string5[10000]; //string to store the text from file
                int i5=0; //string element counter
                char c; //variable for the character being read
                fscanf(input, " %[^\n]s", string5); //scans file and puts in  string, until new line reached
                    while(string5[i5]!='\0') { //reads string until nulled, performs the operation below for each character
                        c=string5[i5]; //makes c the ith element of the string (i.e. the ith character)
                        c=rKDecrypt(c, rKey); //function call, decrypts each character as they are scanned according to the function
                        printf("%c", c); //prints text to console
                        fprintf(output, "%c", c); //prints text to output file
                        i5++; //increment to move to the next element of the text string
                    }
                    printf("\n\n"); //prints every possible decryption on a new line
            }
            printf("\n");
            break;
        
        default:
            
            printf("\n\nError. Run again.\n\n"); //for UI
            break;
    }
    
    return 0;
}


/************************************************************************************************/
//FUNCTION DEFINITIONS
/************************************************************************************************/

//Rotation encryption
/*
 * The inputs of this function are the character being read and encrypted, and the key
 * that determines how far each letter shifted. Lowercase letters are converted to
 * uppercase by subracting 32 (ASCII), so that the output is only uppercase. If the
 * key addition results in an ASCII character over 90, 26 is subracted to go back to the
 * start (A) of the alphabet, otherwise the key simply shifts each letter a certain
 * integer down the alphabet. The encrypted character is then returned, and the rotation
 * encryption is achieved. Punctuation and numbers are returned unaltered.
 */

    char rEncrypt(char rE, int key) //encrypts rE using the key
    {
        if((rE>=97) && (rE<=122)) { //if characters are lowercase according to ASCII value
            rE=rE-32; //subract 32, making it the equivalent uppercase letter in ASCII
        }
        if((rE+key)>90) { //if the encrypted ascii character goes past the uppercase letters
            rE=(rE+key)-26; //encrypts and makes any letters that drop off the end loop back to the front
        } else if((rE>=65) && (rE<=90)) { //if it is an uppercase letter, it will encrypt
            rE=rE+key; //adds key to encrypt
        }
        return rE; //return the encrypted character to the main function
    }

/************************************************************************************************/

//Rotation decryption
/*
 * The inputs of this function are the character being read and decrypted, and the key
 * that returns the letters back to the original english. If the key subtraction results
 * in an ASCII character below 65, 26 is added to go to the end (Z) of the alphabet,
 * otherwise the key simply shifts each letter a certain integer down the alphabet.
 * The decrypted character is then returned, and the rotation decryption is achieved.
 * Punctuation and numbers are returned unaltered.
 */

    char rDecrypt(char rD, int key) //decrypts rD using the key
    {
        if(((rD-key)<65) && (rD>=65) && (rD<=90)) { //if the encrypted letter (and not any other characters) goes below the uppercase letters
            rD=(rD-key)+26; //decrypts and makes any letters that drop off the front loop to the back
        } else if((rD>=65) && (rD<=90)) { //if it is an uppercase letter, it will decrypt
            rD=rD-key; //key subracted for decryption
        }
        return rD; //return the decrypted character to the main function
    }

/************************************************************************************************/

//Substitution encrytion
/*
 * The input of this function is the character being read and encrypted. Lowercase letters
 * are converted to uppercase by subracting 32 (ASCII), so that the output is only uppercase.
 * A string containing 26 letters is created for substitution, and a string of the alphabet
 * is created. Each letter is read, and when it matches the letter in the alphabet string,
 * it is replaced with the corresponding letter in the substitution string. The encrypted
 * character is then returned, and the substitution encryption is achieved. Punctuation
 * and numbers are returned unaltered.
 */

    char sEncrypt(char sE) //encrypts sE
    {
        if((sE>=97) && (sE<=122)) { //if characters are lowercase according to ASCII value
            sE=sE-32; //subract 32, making it the equivalent uppercase letter in ASCII
        }
        char eString[26]="MNBVCXZASDFGHJKLPOIUYTREWQ"; //the substitution key
        char eAlphabet[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //the alphabet, to compare to the key
        int i=0; //iteration counter
        for(i=0; i<26; i++) {
            if(sE==eAlphabet[i]) { //when the character from file matches the character in the alphabet string
                //once they match, 'i' is 'remembered' - it respresents how many times it takes before they match
                sE=eString[i]; //if they match, the character becomes the corresponding 'i' element in the sub key
                break; //breaks once this has been achieved
            }
        }
        return sE; //return the encrypted character to the main function
       
    }

/************************************************************************************************/

//Substitution decryption
/*
 * The input of this function is the character being read and decrypted.
 * A string containing 26 letters is created for substitution, and a string of the alphabet
 * is created. Each letter is read, and when it matches the letter in the substitution string,
 * it is replaced with the corresponding letter in the alphabet string. The decrypted
 * character is then returned, and the substitution decryption is achieved. Punctuation
 * and numbers are returned unaltered.
 */

    char sDecrypt(char sD) //decrypts sD
    {
        char dString[26]="MNBVCXZASDFGHJKLPOIUYTREWQ"; //the substitution key
        char dAlphabet[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //the alphabet, to compare to the key
        int i=0; //iteration counter
        for(i=0; i<26; i++) {
            if(sD==dString[i]) { //when the character from file matches the character in the substitution string
                //once they match, 'i' is 'remembered' - it respresents how many times it takes before they match
                sD=dAlphabet[i]; //if they match, the character becomes the corresponding 'i' element in the alphabet key
                break; //breaks once this has been achieved
            }
        }
        return sD; //return the decrypted character to the main function
    }

/************************************************************************************************/

//Rotation decryption (for unknown key)
/*
 * The inputs of this function are the character being read and decrypted, and the key
 * that returns the letters back to the original english. If the key subtraction results
 * in an ASCII character below 65, 26 is added to go to the end (Z) of the alphabet,
 * otherwise the key simply shifts each letter a certain integer down the alphabet.
 * The decrypted character is then returned, and the rotation decryption is achieved.
 * Punctuation and numbers are returned unaltered.
 */

    char rKDecrypt(char rKD, int rKey) //decrypts rKD using rKey
    {
        if(((rKD-rKey)<65) && (rKD>=65) && (rKD<=90)) { //if the encrypted letter (and not any other characters) goes below the uppercase letters
            rKD=(rKD-rKey)+26; //decrypts and makes any letters that drop off the front loop to the back
        } else if((rKD>=65) && (rKD<=90)) { //if it is an uppercase letter, it will decrypt
            rKD=rKD-rKey; //key subtracted for decryption
        }
        return rKD; //return the decrypted character to the main function
    }

/************************************************************************************************/
