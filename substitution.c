#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//declare functions
bool key_valid(string key);

int main(int argc, string argv[])
{

    //check usage
    if (argc == 2) //if there are 2 command line arguments
    {
        //initialize a variable for the key
        string key = argv[1];

        //check if key is valid
        if (key_valid(key) == true)
        {
            //prompt user for input
            string plaintext = get_string("plaintext: ");

            //declare variable for the ciphertext, use plaintext to match length
            string ciphertext = plaintext;

            //declare array for the cipher
            int cipher[strlen(key)];

            //generate cipher by creating array of numbers which correspond to the alphabet position to shift each letter to
            for (int i = 0; i < strlen(key); i++)
            {
                cipher[i] = key[i] - 97; //using lowercase key, where a = 0
            }

            //for each character in plaintext
            for (int i = 0; i < strlen(plaintext); i++)
            {
                //if charcter is an uppercase letter
                if (plaintext[i] >= 65 && plaintext[i] <= 90)
                {
                    //get the letter's position in the alphabet and find its corresponding cipher letter in the cipher
                    ciphertext[i] = cipher[plaintext[i] - 65] + 65; //add 65 to return to uppercase
                }
                //if character is a lowercase letter
                else if (plaintext[i] >= 97 && plaintext[i] <= 122)
                {
                    //get the letter's position in the alphabet and find its corresponding cipher letter in the cipher
                    ciphertext[i] = cipher[plaintext[i] - 97] + 97; //add 97 to return to lowercase
                }
            }
            //print the generated cipher
            printf("ciphertext: %s\n", ciphertext);
        }
        else
        {
            return 1;
        }
    }
    else
    {
        //show user how substitution should be used
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

//function to check if key is valid and return lowercase key
bool key_valid(string key)
{
    //Set default return as true.
    bool check = true;

    //First check - is the key 26 characters long?
    if (strlen(key) == 26)
    {
        //Now check each character.
        for (int i = 0; i < strlen(key); i++)
        {
            //Second check - is the character alphabetical?
            if ((key[i] <= 90 && key[i] >= 65) || (key[i] >= 97 && key[i] <= 122))
            {
                //Make character lowercase for simplicity.
                key[i] = tolower(key[i]);

                //No need to check the first character.
                if (i > 0)
                {
                    //Third check - has the character been used before?
                    for (int j = 0; j < i; j++)
                    {
                        //If character has already been used, return message and false.
                        if (key[j] == key[i])
                        {
                            printf("Key must not contain any repeated characters.\n");
                            check = false;
                        }
                    }
                }
            }
            //If it is not alphabetical return message and false.
            else
            {
                printf("Key must only contain alphabetical characters.\n");
                check = false;
            }
        }
    }
    //If it is not 26 characters long return message and false.
    else
    {
        printf("Key must be 26 characters long.\n");
        check = false;
    }

    //Return a true or false.
    return check;
}





