/*
     Program that allows bank customers to
     manage their PIN (PIN Assignment 2016)
     Jack Darcy - C16357773
     28/10/2016
     Completed on Windows (Borland)
*/

#include <stdio.h>

int main()

{
    //declare integers
    int option;
    int kingPIN;
    int PIN;
    int correctPIN;
    int incorrectPIN;
    
    //assign values for integers
    option = 0;
    kingPIN = 0;
    PIN = 1234;
    correctPIN = 0;
    incorrectPIN = 0;
    
    //begin infinite do while(true) loop
    do
    
    {
        //create menu
        printf("\n \nOption 1: Enter PIN");
    
        printf("\nOption 2: Change PIN");
    
        printf("\nOption 3: How many times have I entered my PIN both correctly and incorrectly?");
    
        printf("\nOption 4: Exit program \n");

    
        //ask the user to enter an option
        printf("\nSelect an option \n");
        
        scanf("%d", &option);
        
        flushall();
        
        //begin if else
        if(option >= 5) //check for potential errors
        
        {
            printf("error, please enter a number between 1 and 4");
        }
            
        //case for opiton 1
        else if(option == 1)
            
        {
            //ask the user to enter their PIN, it should be 1234 to begin with
            printf("Please Enter your 4-digit PIN \n");
            
            scanf("%d", &kingPIN);
            
            flushall();
                
            //check for errors in the amount of digits in PIN
            if((kingPIN <= 9999) && (kingPIN >= 0001))
            
            {
                
                //check if PIN itself is correct or incorrect
                if(PIN == kingPIN)
                
                {
                    printf("PIN entered is correct \n");
                    
                    //increment counter for use in option 3
                    correctPIN++;
                }
            
                else
                    
                {
                    printf("Sorry, that PIN is incorrect");
                        
                    //increment counter for use in option 3
                    incorrectPIN++;
                }
                
            }
            
            else
            
            {
                printf("Sorry, that's an invalid PIN, please enter a 4-digit PIN \n");
                
                scanf("%d", &kingPIN);
                
                flushall();
                    
                //revert back to the beginning of option 1, this is the user's last chance to enter their PIN correctly
                if(PIN == kingPIN)
                
                {
                    printf("PIN entered is correct \n");
                    
                    correctPIN++;
                }
            
                else
                
                {
                    printf("Sorry, that PIN is incorrect");
                    
                    incorrectPIN++;
                }//end inner if else statement()
                    
            }//end outer if else statement()
                
        }// end case for option 1()
        
        //case for option 2
        else if(option == 2)
            
        {
            printf("Please enter your current PIN \n");
            
            scanf("%d", &kingPIN);
            
            flushall();
            
            
            
            //ask the user to enter the new PIN they want
            if(PIN == kingPIN)
            {
                printf("Please enter the PIN you wish to change to \n");
            
                scanf("%d", &kingPIN);
            
                flushall();
                
            //account for if they enter 1234 by mistake
                if(PIN == kingPIN)
                
                {
                    printf("This is already your PIN");
                }
            
                else
                
                {
                    /*
                                            ask the user to verify the PIN they want to change to while considering that
                                            a PIN with more than 4 digits won't be acccepted once it loops back to option 1
                                        */
                
                    printf("Please verify your new PIN \n");
               
                    printf("(Note that if you have entered a PIN with more than 4 digits, it will not be accepted once you select Option 1) \n");
                
                    scanf("%d", &PIN);
                
                    flushall();
                    
                    //verify the new PIN
                    if(kingPIN == PIN)
                    
                    {
                        //present the user's new PIN
                        printf("Your new PIN is %d \n \n", kingPIN);
                        
                        printf("To clarify, your new PIN is %d", PIN);
                    
                    }
                    
                    else
                            
                    {
                        //account for a potential error while allowing the user to start option 2 afresh
                        printf("Error, this does not match the previously entered PIN, start again by entering your original PIN \n");
                    
                        scanf("%d", &kingPIN);
                   
                        flushall();
                        
                    }//end inner if else statement()
                    
                }
                
            }//end outer if else statement()
                
        }//end case for option 2()
            
        //case for option 3
        else if(option == 3)
            
        {
            //consider the counter used in  option 1 and use both the correct and incorrect PIN variables to display this to the user
            printf("Your PIN was entered %d time(s) correctly and %d time(s) incorrectly", correctPIN, incorrectPIN);
            
        }//end case for option 3()

        //case for option 4
        else if(option == 4)
        
        {
            //display this message to the user, and verify that they want to leave the program by asking for their PIN again
            printf("The program will now end, please input your PIN once more to confirm your exit and press Enter twice \n");
            scanf("%d", &PIN);
            flushall();
                
            //account for potential errors
            if((PIN != 1234) || (PIN != kingPIN))
                
            {
                printf("Sorry that PIN is incorrect, try again \n");
                
                scanf("%d", &PIN);
                
                flushall();
            }//end inner if statement()
                
            //break the loop so the user can close the program indefinitely when option 4 is selected
            break;
        }//end case for option 4 ()
            
    }while(true); //end infinite do while(true) loop()
    
getchar();
return(0);
        
}//end main()
    
    