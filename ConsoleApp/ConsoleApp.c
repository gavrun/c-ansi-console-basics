// ConsoleApp.c : This file contains the 'main' function. Program execution begins and ends there.
//
//
// NOTE: Visual Studio does not provide a built-in "Console App (C)" template.
// 
// Create a "Console App (C++)" or "Empty Project", then:
//   1. Add a source file with the .c extension
//   2. Set project to "Compile As C Code (/TC)"
//   3. Set project to "Legacy MSVC (C89 or ANSI C)"
//
// This project uses ANSI C (C89/C90) with elements compatible with C99.
// For input/output in C use <stdio.h>.
//
// Save a source file with character encoding UTF-8 with BOM for Cyrillic support


#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
//#include <windows.h> // Windows console support UTF-8 and Cyrillic
#include <string.h>


// Functions declarations (prototype)
void demoConsoleInOut(void);


// Types and structures definitions



// Preprocessor macros



// MAIN

int main()
{
    // Windows console support UTF-8 and Cyrillic
    //SetConsoleCP(CP_UTF8);
    //SetConsoleOutputCP(CP_UTF8);
    //setlocale(LC_ALL, ""); // Localization setup

    printf("Hello World!\n");

    printf("\nUncomment a demo function if you don't see anything.\n");

    // Uncomment a demo function
    demoConsoleInOut();


    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


// Function definitions (implementation)


void demoConsoleInOut(void) 
{
    /* Declare all variables at the beginning of the block (C89 standard) */
    int inputChar;
    char name[50];
    int age;
    float weight;
    int itemsRead;
    char* newline;

    printf("\n--- DEMO: Console Input/Output ---\n");

    /* --- Standard Streams --- */
    /*
     * In C, there are three standard streams:
     * 1. stdin:  Standard Input (usually the keyboard)
     * 2. stdout: Standard Output (usually the console screen)
     * 3. stderr: Standard Error (usually the console screen, for error messages)
     * All functions below use these streams implicitly.
     */
    printf("\nSection: Standard Streams\n");
    fprintf(stdout, "This message is printed to standard output.\n");
    fprintf(stderr, "This is an example of an error message.\n");


    /* --- Character I/O --- */
    printf("\nSection: Character I/O (getchar, putchar)\n");
    printf("Please enter a single character: ");
    inputChar = getchar(); /* Read one character from stdin */

    printf("You entered: '");
    putchar(inputChar); /* Print one character to stdout */
    printf("'\n");

    /*
     * IMPORTANT: When you press Enter, you input the character AND a newline ('\n').
     * The character is read by getchar(), but the newline remains in the input buffer.
     * We must clear the buffer to prevent issues with the next input operation.
     */
    while (getchar() != '\n')
    {
        /* Keep reading and discarding characters until newline is found */
    }


    /* --- String I/O --- */
    printf("\nSection: String I/O (fgets, puts)\n");
    /*
     * The puts() function prints a string to the console and adds a newline at the end.
     */
    puts("The puts() function is simple for displaying strings.");

    /*
     * For reading strings, fgets() is the safe and recommended function.
     * NEVER use gets(), as it can cause buffer overflows and is a major security risk.
     *
     * fgets() reads a line of text from a stream (stdin) into a buffer (name).
     * It stops when it reads a newline, reaches the end-of-file, or the buffer size limit is met.
     */
    printf("Please enter your full name: ");
    fgets(name, sizeof(name), stdin); /* Read a line of text safely */

    /*
     * fgets() includes the newline character ('\n') in the string if it fits.
     * Let's remove it for cleaner output.
     */
    newline = strchr(name, '\n');
    if (newline)
    {
        *newline = '\0'; /* Replace newline with null terminator */
    }

    printf("Hello, %s!\n", name);


    /* --- Formatted I/O --- */
    printf("\nSection: Formatted I/O (scanf, printf)\n");
    /*
     * printf() can format and print various data types.
     * %d for int, %f for float/double, %s for string, %c for char.
     */
    printf("Example of formatted output: Name=%s, Age=%d, Pi=%.2f\n", "Alex", 30, 3.14159);

    /*
     * scanf() reads formatted input from the console.
     * It requires the memory address of the variables to store the data, so we use the '&' operator.
     * It's important to check the return value of scanf(), which is the number of items successfully read.
     */
    printf("Enter your age and weight (e.g., 25 70.5): ");
    itemsRead = scanf("%d %f", &age, &weight);

    if (itemsRead == 2)
    {
        printf("Successfully read 2 items.\n");
        printf("Your age: %d\n", age);
        printf("Your weight: %.1f\n", weight);
    }
    else
    {
        printf("Error: Invalid input.\n");
    }
}










