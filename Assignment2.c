/*
    Program that involves a security
    code that is encrypted (Security Code Assignment 2017)
    Jack Darcy - C16357773
    26/02/2017
    Completed on Windows 10 (Borland)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 4

//prototypes
int menu(void);
int code_enter(int[]);
int code_encryption(int[]);
int code_decrypt(int[]);
void attempts(int*, int*);
void encrypt_verification(int[], int[]);

//begin main
int main()
{
    //declare variables
    int decrypted_code[SIZE] = {1,2,3,4};
    int access_code[SIZE] = {4,5,2,3};
    int option;
    int counter = 0;
    int corr_att, inc_att = 0;
    
    //call menu function
    option = menu();
    
    //while loop to ensure the user enters a valid option
        switch(option)
        {
            //case for option 1
            case 1:
            {
                decrypted_code[SIZE] = code_enter(access_code);
                printf("Code entered successfully \n\n");
                menu();
                break;
            } //end option 1
            
            //case for option 2
            case 2:
            {
                if(counter != 0)
                {
                    printf("The code has already been encrypted \n");
                }
                    
                else    
                
                {
                    decrypted_code[SIZE] = code_encryption(access_code);
                    printf("The code has been encrypted \n\n");
                    counter++;
                }
                menu();
                break;
            } //end option 2
        
            //case for option 3
            case 3:
            {
                if(counter == 1)
                {
                    decrypted_code[SIZE] = code_decrypt(decrypted_code);
                    printf("Code has been decrypted \n\n");
                }
            
                else
                {
                    printf("This code hasn't been decrypted, please return to option 2 \n\n");
                }
                menu();
                break;
            } //end option 3
        
            //case for option 4
            case 4:
            {
                attempts(&corr_att, &inc_att);
                menu();
                break;
            } //end option 4
        
            //case for option 5
            case 5:
            {
                printf("Press Enter to end the program \n\n");
            } //end option 5
        
        } //end switch()
    
    getchar();
    return 0;
    
} //end main()

/* Implement menu
*/
int menu()
{
    int option;
    do
    {
        printf("\n\n Select one of the following options\n");
        printf("1. Enter code\n");
        printf("2. Encrypt new code\n");
        printf("3. Decrypt code\n");
        printf("4. How many times have I entered the code correctly and incorrectly?\n");
        printf("5. Exit program \n \n");
        scanf("%d", &option);
        flushall();
    }
    
    //ensure only the options available in the menu can be entered
    while((option < 1) || (option > 6));
    return(option);
}
/* Implement code_enter (option 1)
*/
int code_enter(int decrypted_code[])
{
    int i;
    
    printf("\n Please enter the access code as 4 separate numbers\n");
    
    for(i = 0; i < SIZE; i++)
    {
        scanf("%d", &decrypted_code[i]);
        flushall();
        
        //allow for if the user enters a number that isn't valid in the access code, i.e. over 10 or under 1
        if((decrypted_code[i] < 0) || (decrypted_code[i] > 9))
        {
            printf("ERROR: each number must be a single digit including 0, try again \n");
            scanf("%d", &decrypted_code[i]);
            flushall();
        }
        
    } //end for loop
    
    return(decrypted_code[SIZE]);
    
} //end code_enter (option 1)
    
    
/* Implement code_encrypt (option 2)
*/
int code_encryption(int user_code[])
{
    int i;
    int tmp1;
    
    //algorithm to encrypt
    for(i = 0; i < SIZE; i++);
    {
        user_code[i] = user_code[i] + 1;
        
        if(user_code[i] == -1)
        {
            user_code[i] = 9;
        }
    
    }
    
    //Swap 1st and 3rd numbers
    tmp1 = user_code[0];
    
    user_code[0] = user_code[2];
    
    user_code[2] = tmp1;
    
    
    //Swap 2nd and 4th numbers
    tmp1 = user_code[1];
    
    user_code[1] = user_code[3];
    
    user_code[3] = tmp1;
    
    for(i = 0; i < SIZE; i++);
    {
        printf("%d", user_code[i]);
    }
    
    return(user_code[SIZE]);
}


/* Implement code_decrypt (option 3)
*/
int code_decrypt(int user_code[])
{
    int i;
    int tmp1;
    
     //Algorithm to decrypt
    for (i = 0; i < SIZE; i++);
    {
        user_code[i] = user_code[i]--;
        
        if (user_code[i] == -1)
        {
            user_code[i] = 9;
        }
    }
    
    //swap 1st number and 3rd number
    tmp1 = user_code[0];
    
    user_code[0] = user_code[2];
    
    user_code[2] = tmp1;
    
    
    //swap 2nd number and 4th number
    tmp1 = user_code[1];
    
    user_code[1] = user_code[3];
    
    user_code[3] = tmp1;
    
    for(i = 0; i < SIZE; i++)
    {
        printf("%d", user_code[i]);
    }

    return (user_code[SIZE]);

}


/* Implement attempts (option 4)
*/
void attempts(int *correct, int *incorrect)
{
    printf("Correct attempts: %d \n", *correct);
    printf("Incorrect attempts: %d \n", *incorrect);
}

//option 5 is above in main where the program ends gracefully
