//CIPHER ASSIGNEMT ENGG1003 KIVA GWYNNE

#include <stdio.h>

//FUNCTION PROTOTYPES

char rEncrypt(char rE, int key); //rotation encryption function declaration
char rDecrypt(char rD, int key); //rotation decryption function declaration
char sEncrypt(char sE); //substitution encryption function declaration
char sDecrypt(char sD); //substitution decryption function declaration
char rKDecrypt(char rKD, int rKey); //rotation decryption without key function declaration

//MAIN FUNCTION

int main() {

//USER INTERFACE (UI)
    
    printf("CIPHER\n\n");
    printf("a. Rotation Encryption\n");
    printf("b. Rotation Decryption\n");
    printf("c. Substitution Encryption\n");
    printf("d. Substitution Decryption\n");
    printf("e. Rotation Decryption with Unknown Key via Frequency Analysis\n");
    printf("f. Rotation Decryption Using All Possible Keys\n");
    printf("\nEnter Selection: ");
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
            int key; //the integer that determines how far letters are shifted (remebered as a key)
            printf("Enter encryption key between 0 and 26: "); //prints to console to prompt user to enter desired rotation key within the range
            scanf("%d", &key); //scans the user input and stores it in 'key'
            while ((key>26) || (key<0)) { //while the key is not within range 0-26
                printf("Enter encryption key between 0 and 26: "); //repeats the prompt if input is incorrect
                scanf("%d", &key); //scans the user input and stores it in 'key'
            }
            printf("\nEncrypted Text:\n\n"); //UI
            input=fopen("input.txt", "r"); //opens 'input' file for reading
            output=fopen("output.txt", "w"); //opens 'output' file for writing
            char string1[1000]; //string to put the text from file
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
            char string2[1000];
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
            char string3[1000];
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
            char string4[1000];
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
            
        case 'e':
            
            printf("Rotation Decryption with Unknown Key via Frequency Analysis");
            printf("\n\nDecrypted Text:\n\n");
            printf("The decrypted texts below assume the most frequent letters in the English language to be E, T, A, O or I, repectively.\n");
            input=fopen("input.txt", "r");
            output=fopen("output.txt", "w");
            char a, b, cc, d, e, f, g, h, ii, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
            a=0; b=0; cc=0; d=0; e=0; f=0; g=0; h=0; ii=0; j=0; k=0; l=0; m=0; n=0; o=0; p=0; q=0; r=0; s=0; t=0; u=0; v=0; w=0; x=0; y=0; z=0;
            while(!feof(input)) {
                char cK;
                fscanf(input, "%c", &cK);
                if(cK=='A')
                    a++;
                if(cK=='B')
                    b++;
                if(cK=='C')
                    cc++;
                if(cK=='D')
                    d++;
                if(cK=='E')
                    e++;
                if(cK=='F')
                    f++;
                if(cK=='G')
                    g++;
                if(cK=='H')
                    h++;
                if(cK=='I')
                    ii++;
                if(cK=='J')
                    j++;
                if(cK=='K')
                    k++;
                if(cK=='L')
                    l++;
                if(cK=='M')
                    m++;
                if(cK=='N')
                    n++;
                if(cK=='O')
                    o++;
                if(cK=='P')
                    p++;
                if(cK=='Q')
                    q++;
                if(cK=='R')
                    r++;
                if(cK=='S')
                    s++;
                if(cK=='T')
                    t++;
                if(cK=='U')
                    u++;
                if(cK=='V')
                    v++;
                if(cK=='W')
                    w++;
                if(cK=='X')
                    x++;
                if(cK=='Y')
                    y++;
                if(cK=='Z')
                    z++;
            }
            printf("\n%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", a, b, cc, d, e, f, g, h, ii, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z);
            int data[27]={a, b, cc, d, e, f, g, h, ii, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z};
            int max=-1000000;
            int maxIndex=0;
            int printMaxIndex=0;
            int i;
            for(i=0; i<=26; i++) {
                if(data[i]>max) {
                    max=data[i];
                    printMaxIndex=i;
                    maxIndex=65+i;
                }
            }
            printf("The maximum value was %d, found at index %d\n\n", max, printMaxIndex);
            input=fopen("input.txt", "r");
            output=fopen("output.txt", "w");
            char string5[1000];
            int i5=0;
            char c;
            int rKey;
            rKey=maxIndex-69+26; //for E as most common
            if(rKey>26)
                rKey=rKey-26;
            fscanf(input, " %[^\n]s", string5);
            while(string5[i5]!='\0') {
                c=string5[i5];
                c=rKDecrypt(c, rKey);
                printf("%c", c);
                fprintf(output, "%c", c);
                i5++;
            }
            printf("\n\n");
            i5=0;
            input=fopen("input.txt", "r");
            output=fopen("output.txt", "w");
            rKey=maxIndex-84+26; //for T as most common
            if(rKey>26)
                rKey=rKey-26;
            fscanf(input, " %[^\n]s", string5);
            while(string5[i5]!='\0') {
                c=string5[i5];
                c=rKDecrypt(c, rKey);
                printf("%c", c);
                fprintf(output, "%c", c);
                i5++;
            }
            printf("\n\n");
            i5=0;
            input=fopen("input.txt", "r");
            output=fopen("output.txt", "w");
            rKey=maxIndex-65+26; //for A as most common
            if(rKey>26)
                rKey=rKey-26;
            fscanf(input, " %[^\n]s", string5);
            while(string5[i5]!='\0') {
                c=string5[i5];
                c=rKDecrypt(c, rKey);
                printf("%c", c);
                fprintf(output, "%c", c);
                i5++;
            }
            printf("\n\n");
            i5=0;
            input=fopen("input.txt", "r");
            output=fopen("output.txt", "w");
            rKey=maxIndex-79+26; //for O as most common
            if(rKey>26)
                rKey=rKey-26;
            fscanf(input, " %[^\n]s", string5);
            while(string5[i5]!='\0') {
                c=string5[i5];
                c=rKDecrypt(c, rKey);
                printf("%c", c);
                fprintf(output, "%c", c);
                i5++;
            }
            printf("\n\n");
            i5=0;
            input=fopen("input.txt", "r");
            output=fopen("output.txt", "w");
            rKey=maxIndex-73+26; //for I as most common
            if(rKey>26)
                rKey=rKey-26;
            fscanf(input, " %[^\n]s", string5);
            while(string5[i5]!='\0') {
                c=string5[i5];
                c=rKDecrypt(c, rKey);
                printf("%c", c);
                fprintf(output, "%c", c);
                i5++;
            }
            printf("\n\n");
            printf("If the decrypted text does not appear, run the program again choosing option [f].\n\n");
            break;
            
        case 'f':
           
            printf("Rotation Decryption Using All Possible Keys");
            printf("\n\nDecrypted Text:\n\n");
            for(int rKey=0; rKey<26; rKey++) { //runs every possible rotation key
                input=fopen("input.txt", "r");
                output=fopen("output.txt", "w");
                char string5[1000];
                int i5=0;
                char c;
                fscanf(input, " %[^\n]s", string5);
                    while(string5[i5]!='\0') {
                        c=string5[i5];
                        c=rKDecrypt(c, rKey);
                        printf("%c", c);
                        fprintf(output, "%c", c);
                        i5++;
                    }
                    printf("\n"); //prints every possible decryption on a new line
            }
            printf("\n");
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

//Substitution encrytion function definition

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

    char rKDecrypt(char rKD, int rKey) {
        
        if(((rKD-rKey)<65) && (rKD>=65) && (rKD<=90)) { //if the encrypted letter (and not any other characters) goes below the uppercase letters
            rKD=(rKD-rKey)+26; //decrypts and makes any letters that drop off the front loop to the back
        } else if((rKD>=65) && (rKD<=90)) { //if it is an uppercase letter, it will decrypt
            rKD=rKD-rKey; //decryption!!
        }
       
        return rKD;
    }

/************************************************************************************************/
