#include <stdio.h>
#include <stdlib.h>


char *readDynamicString()
{
    size_t bufferSize = 128;                                       
    char *inputString = (char *)malloc(bufferSize * sizeof(char)); 

    if (inputString == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }

    size_t bytesRead = 0;
    int ch;

    //The characters entered by the user will be saved in an array until hit Enter.
    while (1)
    {
        ch = getchar();

        if (ch == '\n' || ch == EOF)
        {
            inputString[bytesRead] = '\0'; 
            break;
        }

        inputString[bytesRead] = (char)ch;
        bytesRead++;

        //If the characters surpassed the initial buffersize, increase it by 128.
        if (bytesRead >= bufferSize - 1)
        {
            bufferSize += 128; 
            char *newString = (char *)realloc(inputString, bufferSize);

            if (newString == NULL)
            {
                fprintf(stderr, "Memory reallocation failed.\n");
                free(inputString);
                return NULL;
            }

            inputString = newString;
        }
    }

    return inputString;
}

int main()
{
    printf("Enter a string: ");
    char *userInput = readDynamicString();

    // Desallocate the memory
    if (userInput != NULL)
    {
        printf("You entered: %s\n", userInput);
        free(userInput); 
    }

    return 0;
}