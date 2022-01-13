#include <ctype.h>
#include<stdio.h>
#include<cs50.h>
#include<string.h>

// Protype
void encrypt(char argv[], string plaintext);

int main(int argc, string argv[])
{
	//error! if command line arguments are not equal to 2
	if (argc != 2)
	{
		printf("Usage: ./substitution (key)\n");
		return 1;
	}
	
	int alphas = 0, total_char = 0;
	int i,m;
	
	char argv1_copy[26];
	
	//convert all alphabets to uppercase to get rid of "case senstive" issues later
	for (i = 0; i < 26; i++)
	{
		argv[1][i] = toupper(argv[1][i]);
	}
	
	//copy all characters of argv[1] to argv1_copy[26]
	for (i = 0; i < 26; i++)
	{
		argv1_copy[i] = argv[1][i];
	}
	
	//count alphabets and total chars
	for (i = 0; i < strlen(argv[1]); i++)
	{
		if (isalpha(argv[1][i]))
		{
			alphas++;
		}
		total_char++;
	}
	
	//error! if total chars are not equal to 26
	if (total_char != 26)
	{
		printf("Key must contain 26 alphabets!\n");
		return 1;
	}
	
	//error! if no. of counted alphabets are less than total characters in the string
	if (alphas < strlen(argv[1]))
	{
		printf("Key must contain only alphabets!\n");
		return 1;
	}
	
	// Loop for checking whether the letters repeat or not
	for(i = 0;i < 26;i++)
	{
		// Count the repeated letters
		int repLetter = 0;
		
		for (m = 0; m < 26; m++)
		{
			if (argv1_copy[i] == argv[1][m])
			{
				repLetter++;
				
				if (repLetter == 2)
				{
					//error! if an alphabet repeats more than once
					//(ignoring case bcz all are in uppercase)
					printf("Alphabets in the key should not repeat!\n");
					return 1;
				}
			}
		}
	}
	
	//prompt user for plaintext
	string plaintext = get_string("Plaintext: ");
	
	//print cypher text 
	printf("ciphetext: ");
	encrypt(argv[1], plaintext);
}

//prints ciphertext when plaintext and key are passed as input
void encrypt(char argv[], string plaintext)
{
	// Arrays of alphabets in uppercase and lowercase
	string alphas_U[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	string alphas_L[] = {"abcdefghijklmnopqrstuvwxyz"};

	// Variables used in the loop upahead
	int i, j = 0;
	
	// Array of ciphertext's characters
	char ciphertext[strlen(plaintext)];
	
	// Loop over string length of plaintext
	// Encrypt
	for (i = 0; i < strlen(plaintext); i++)
	{
		
		int r = 0;
		
		if(isalpha(plaintext[i]))
		{
			// If plaintext is lowercase
			if (islower(plaintext[i]))
			{
				for (j = 0; alphas_L[0][j] < plaintext[i]; j++)
				{
					r++;
				}
				ciphertext[i] = tolower(argv[r]);
			}
			// If plaintext is uppercase
			else
			{
				for (j = 0; alphas_U[0][j] < plaintext[i]; j++)
				{
					r++;
				}
				ciphertext[i] = toupper(argv[r]);
			}
		}
		// For characters other than alphabets
		else
		{
			ciphertext[i] = plaintext[i];
		}

		// Print out the ith character of Ciphertext
		printf("%c",ciphertext[i]);
	}
}
