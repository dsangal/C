/**
 *
 * A password strength meter and a default password generator, 
 * as defined in the CS221 course website for Project 1.
 *
 */

// REMEMBER: WRITE COMMENTS IN YOUR CODE FOR FULL CREDIT

// including all necessary libraries
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h> 
#include <stdlib.h>
#include <ctype.h>

// boolean function to check if user is within the password
bool isContainUser(int userLength, int pwLength, const char* username, const char* password){

//initializing iterators
//initializing counter to keep track of consecutive characters
//firstLetterofUsername is equal to the first letter of user's username
    int k=0;
    int j=0;
    int foundLen = 0; 
    char firstLetterofUsername = *username;

    //iterate through the user
    for(int i=0; i< userLength; i++){

        //check if the letter in username is equal to letter in password 
        if (tolower(*(username+i)) == tolower(*(password+k))){

            //if the letters are same increment the counter 
            foundLen++;
            
			//increment password array to check for next element in the for loop */
            k++;
            //if the for loop has checked all the letter in username and all of them are matching, then foundLen length will be equal to userLength length. 
			
           // if (foundLen == userLength){
            //    break;
            //}
        }
        
		
		/* if the first letter in usernname and password is not matching then 
        try to find if first letter of username is matching with any letter of password
        Get the location of the matching letter in password array*/

         
        else{
        		foundLen=0;
            if (firstLetterofUsername == *(password +k)){
           		k++;
            		i--;
            		foundLen++;
            }else {

				//if the letter is found within the password array, move k to the next element to continue comparing
	            for (j=k; j < pwLength; j++){
	                if (*(username + i) == *(password + j)){
	                    foundLen++;
	                    k=j+1;
	                    break;
	                }
	            }
            }
        }
    }
	//if the counter is the same as the length of the username, 
	//the username was found within the password and the function will return false
    if (foundLen == userLength){
        return false;
    }
    return true;

}



bool isStrongPassword(const char * username, const char * password) {
	// Initialize iterator and multiple boolean conditions
	// Initializing username and password lengths
	// Initializing varible strLength to help check if a string exists
	int i = 0;
	int j = 0;
	int strLength = 0;
	int userLen = 0;
	int pwLen = 0;
	bool containsUpper = false;
	bool containsLower = false;
	bool containsNum = false;
	bool containsStr = false;
	bool ContainUser = false;

	//finding the length of of the username
	while(*(username + j) != '\0'){
		userLen++;
		j++;
	}

	// traverse the password array using password pointers until it hits null terminator
	// search for ASCII code for lower case, upper case, and digits
	while(*(password + i) != '\0')
	{
		if(*(password + i) >= 'A' && *(password + i) <= 'Z'){
			containsUpper = true;
		}
		if(*(password + i) >= 'a' &&  *(password + i) <= 'z'){
			containsLower = true;
		}
		//check if there is a string (4 consecutive characters)
		//every time a character comes up, increment strLength. However, it only continues to increment if the succeeding elements are also characters
		//Once the strLength is 4, the containsStr boolean is set to true
		if(strLength < 4){
			if((*(password + i) >= 'A' && *(password + i) <= 'Z') || (*(password + i) >= 'a' &&  *(password + i) <= 'z')){
				strLength++;
			}
			else{
				strLength = 0;
			}
		}
		else{
			containsStr = true;
		}

		if(*(password + i) >= '0' &&  *(password + i)<= '9'){
			containsNum = true;
		}
		pwLen++;
		i++;
	}

	
	//sending username, password, and their lengths to isContainUser to check if username is within the password 
    ContainUser = isContainUser(userLen,pwLen,username, password);

	//checking if all boolean conditions are satisfied
	//send true if conditions are indeed satisfied, false if not
	if(containsUpper && containsLower && containsNum && containsStr && ContainUser){
			return true;
	}
	else
	{
		return false;
	}
	
}

/** 
 * Example: isStrongDefaultPassword("vahab", "Taher3h") returns false
 */
bool isStrongDefaultPassword(const char* username, const char* password) {
	//Same booleans, iterators , and length variables
	int i = 0;
	int j = 0;
	int strLength = 0;
	int userLen = 0;
	int pwLen = 0;
	bool containsUpper = false;
	bool containsLower = false;
	bool containsNum = false;
	bool containsStr = false;
	bool ContainUser = false;
	//this time including boolean to check if password is between 8 and 15 characters
	bool correctPwLen = false;

	while(*(username + j) != '\0'){
		userLen++;
		j++;
	}

	// traverse the password array using password pointers
	// search for ASCII code for lower case, upper case, and digits
	while(*(password + i) != '\0')
	{
		if(*(password + i) >= 'A' && *(password + i) <= 'Z'){
			containsUpper = true;
		}
		if(*(password + i) >= 'a' &&  *(password + i) <= 'z'){
			containsLower = true;
		}
		//check if there is a string (4 consecutive characters)
		//every time a character comes up, increment strLength. However, it only continues to increment if the succeeding elements are also characters
		//Once the strLength is 4, the containsStr boolean is set to true
		if(strLength < 4){
			if((*(password + i) >= 'A' && *(password + i) <= 'Z') || (*(password + i) >= 'a' &&  *(password + i) <= 'z')){
				strLength++;
			}
			else{
				strLength = 0;
			}
		}
		else{
			containsStr = true;
		}

		if(*(password + i) >= '0' &&  *(password + i)<= '9'){
			containsNum = true;
		}
		i++;
		pwLen++;
	}

	if(pwLen >= 8 && pwLen <= 15){
		correctPwLen = true;
	}

    ContainUser = isContainUser(userLen,pwLen,username, password);

	if(containsUpper && containsLower && containsNum && containsStr && ContainUser && correctPwLen){
		return true;
	}
	else
	{
		return false;
	}
}
/** 
 * This function may *not* call isStrongPassword(). 
 * This function must call isStrongDefaultPassword().
 */
void generateDefaultPassword(char* default_password, const char * username) {
	//initializing variables for length of password
	int len = 0;
	int count = 0;
	int revCount =0;
	bool validPassword = false;

	//finding length of password
	while(*default_password != '\0'){
		len++;
		default_password++;
	}

	//putting value of length in count and revCount
	//will use to traverse through password (front and back)
	count = len;
	revCount = len;

	//char array to include all numbers, lower case, and upper case letters
	const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	int passwordLen = sizeof(alphanum) - 1;
		//loop runs until random password is strong enough
			while(validPassword != true)
			{
				//taking random elements from alphanum[] to fill generated password
				while(len != 1){
					*default_password = alphanum[rand() % passwordLen];
					default_password++;
					len--;
				}
				//using revCount to point to first element again
					while(len <= revCount){
					default_password--;
					len++;
				}
				//sending password to be verified as strong
				validPassword = isStrongDefaultPassword(username, default_password);
			}
			

			
	printf("Generating default password...\n");
	printf("Generated default password:");
	
	//using count variable to print password elements
	while(count > 0){
		printf("%c", *default_password);
		default_password++;
		count--;
	}
/*
	while(*default_password != '\0'){
		printf("%c", *default_password);
		default_password--;
	}
*/
	printf("\n");

}

int main(void) 
{

	//initalize username & password char arrays
	char username[50];
	char password[50];
	char response;

	//setting seed of random number generator
	srand(time(0)); 
	
	//initialize boolean to determine if while loop should continue running
	//initialize second boolean to store the result of the function
	bool isPassWeak = false;
	bool result;  
	
	//asking user to enter username
	printf("Enter your username: ");
	scanf("%s", username);
	
	//randomly generating length for generated password
	int lower = 8, upper = 15;
	int defaultPasswordLen;
	defaultPasswordLen = (rand() % (upper - lower + 1)) + lower;

	char defaultPassword[defaultPasswordLen];

	//filling the generated password with zeros 
	for(int iterator = 0; iterator < defaultPasswordLen; iterator++){
		defaultPassword[iterator] = '0';
	}
	defaultPassword[defaultPasswordLen] = '\0';

	//sending the generated password to the generateDefaultPassword to be filled with random characters
	generateDefaultPassword(defaultPassword, username);

	//asking user if they would like to use the generated password
	printf("Would you like to use this password?(Y/N): ");
	scanf("%s", &response);
    
	//if yes, then they have successfully logged in
	if(response == 'Y'){
		printf("Log in successful.\n");
	}
	//if no, program asks they to input a strong password to replace it
	else
	{
		//while loop to continue asking for username and adequate password
		while(!isPassWeak){
			
			//asking and accepting password input 
			printf("Enter your password: ");
			scanf("%s", password);

			//find length of password using strlen and store it in int variable
			int stringLen = strlen(password);


			//checking if length of password is less than 8
			//if so, password is weak and boolean remains true
			if(stringLen < 8){
				printf("Your password is weak! Try again. \n");
				isPassWeak = false;
			}
			else {
				result = isStrongPassword(username, password);
				//if boolean is true, password is strong and loop terminates
				if (result){
					printf("Strong password!\n");
					isPassWeak = true;
				}
				//if false, password is weak and loop continues to run 
				//and ask the user for an adequate password
				else{
					printf("Your password is weak! Try again. \n");
					isPassWeak = false;
				}
			}
		}
	}
	
	return 0;
}

