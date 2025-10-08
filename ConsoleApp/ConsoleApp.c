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

#include <stdbool.h> // C99 introduced <stdbool.h> for bool, true, false. In C89, we use _Bool or integers.
#include <stddef.h>  // Required for NULL 
#include <string.h>  // For string manipulation functions like strcpy, strlen
#include <stdlib.h>  // For string conversion functions like atoi, atof 
#include <ctype.h>   // For character type functions like isdigit, isalpha 
#include <time.h>    // For all date and time functions 


// File Scope (Global) Variables
/*
 * This variable is declared outside of any function.
 * It is accessible from any function within this file.
 * It can also be accessed by other files using the 'extern' keyword.
 */
int global_variable = 100;

/*
 * A static global variable is also declared at file scope, but its visibility
 * is restricted to ONLY this file. It cannot be accessed from other files.
 */
static int file_static_variable = 200;


// Functions declarations (prototype)
/*
 * A function prototype tells the compiler about a function's name, return type,
 * and parameters before the function is actually defined. This allows you to
 * call a function before its definition appears in the code.
 */
void demoConsoleInOut(void);
void demoVariablesAndTypes(void);
void demoTypesCast(void);
void demoOperators(void);
void demoPointers(void);
void demoConstantPtr(void);
void demoControlFlowStructures(void);
void demoFunctions(void);
int addNumbers(int a, int b);
void passByValueExample(int num);
void passByReferenceExample(int* num_ptr);
void printWithConstParam(const int value);
long factorial(int n);
void demoFunctionPtr(void);
int add(int a, int b);
int subtract(int a, int b);
/* A function that takes a function pointer as an argument */
void performCalculation(int x, int y, int (*calculator_func)(int, int));
/* A function that returns a function pointer */
int (*getOperation(char op_char))(int, int);
void demoScopes(void);
void static_counter_function(void);
void demoFunctionDef(void);
int multiply(int a, int b);
int divide(int a, int b);
/*
 * Here, we define 'OperationFuncPtr' as a new name (alias) for the type:
 * "pointer to a function that takes two integers and returns an integer".
 * This makes the syntax for using function pointers much cleaner.
 */
typedef int (*OperationFuncPtr)(int, int);
/* A function that takes the typedef'd function pointer as a parameter */
void executeOperation(int x, int y, OperationFuncPtr operation);
void demoArrays(void);
void demoStrings(void);
/* This function will take the command-line parameters from main */
void demoMainCmdParams(int argc, char* argv[]);
void demoDateTime(void);



// Types and structures definitions



// Preprocessor macros



// MAIN

/*
 * int main()
 */

 /*
  * The 'main' function signature is changed to accept command-line parameters.
  * 
  * int main(int argc, char* argv[])
  *
  * int argc: "Argument Count". An integer that holds the number of arguments passed.
  *           It is always at least 1, because the program's name is the first argument.
  *
  * char *argv[]: "Argument Vector". An array of character pointers (an array of strings).
  *               Each string is one of the arguments passed to the program.
  */

int main(int argc, char* argv[])
{
    // Windows console support UTF-8 and Cyrillic
    //SetConsoleCP(CP_UTF8);
    //SetConsoleOutputCP(CP_UTF8);
    //setlocale(LC_ALL, ""); // Localization setup

    printf("Hello World!\n");

    printf("\nUncomment a demo function if you don't see anything.\n");

    // Uncomment a demo function
    
    //demoConsoleInOut();
    //demoVariablesAndTypes();
    //demoTypesCast();
    //demoOperators();
    //demoPointers();
    //demoConstantPtr();
    //demoControlFlowStructures();
    //demoFunctions();
    //demoFunctionPtr();
    
    //demoScopes();
    //printf("\nAfter demoScopes finished, global_variable is now: %d\n", global_variable);
    
    //demoFunctionDef();
    //demoArrays();
    //demoStrings();
    
    printf("\nProgram started with %d arguments\n", argc);
    if (argc > 1) {
        printf("Command line arguments:\n");
        int i;
        for (i = 0; i < argc; i++) {
            printf("  argv[%d]: %s\n", i, argv[i]);
        }
        printf("\n");
    }
    //demoMainCmdParams(argc, argv);

    demoDateTime();


    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


// Function definitions (implementation)
/*
 * Function Definition is the full implementation of the function
 * int addNumbers(int a, int b)
 * 'int' is the return type
 * 'a' and 'b' are the parameters
 * 'return' statement sends a value back to the caller
 */


/*
 * Demonstrates console input and output operations.
 */
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


/*
 * Demonstrates variable declaration, basic data types, and their sizes.
 */
void demoVariablesAndTypes(void)
{
    /* C89 requires all variables to be declared at the start of a block */
    char grade;

    short temperature;
    int population;
    long national_debt;
    /* 'long long' was officially added in C99, but is widely supported by C89 compilers as an extension. */
    long long world_population;

    unsigned char age;
    unsigned int distance_to_sun;

    float pi_approx;
    double pi_precise;
    long double pi_extended;

    /* _Bool is the underlying type for bool from <stdbool.h> (C99) */
    bool is_active;

    printf("\n--- DEMO: Variables and Basic Data Types ---\n");
    printf("Note: The exact size of data types can vary between systems (e.g., 32-bit vs 64-bit).\n");

    /* --- Character Type --- */
    printf("\nSection: Character Type (char)\n");
    grade = 'A';
    printf("  Variable 'grade' (char): '%c'\n", grade);
    printf("  A char is a small integer. '%c' as a number is: %d\n", grade, grade);
    printf("  Size of char: %zu byte(s)\n", sizeof(char));

    /* --- Integer Types (Signed) --- */
    printf("\nSection: Integer Types (short, int, long)\n");
    temperature = -5;
    population = 1350000;
    national_debt = 23000000000L;    /* 'L' suffix is for long constants */
    world_population = 7800000000LL; /* 'LL' suffix is for long long constants */

    printf("  Variable 'temperature' (short): %hd\n", temperature);
    printf("  Size of short: %zu byte(s)\n", sizeof(short));

    printf("  Variable 'population' (int): %d\n", population);
    printf("  Size of int: %zu byte(s)\n", sizeof(int));

    printf("  Variable 'national_debt' (long): %ld\n", national_debt);
    printf("  Size of long: %zu byte(s)\n", sizeof(long));

    printf("  Variable 'world_population' (long long): %lld (Note: C99 standard)\n", world_population);
    printf("  Size of long long: %zu byte(s)\n", sizeof(long long));

    /* --- Unsigned Integer Types --- */
    printf("\nSection: Unsigned Integer Types\n");
    age = 255; /* An unsigned char can hold values from 0 to 255 */
    distance_to_sun = 150000000U; /* 'U' suffix for unsigned */
    printf("  Unsigned types cannot be negative and have a larger positive range.\n");
    printf("  Variable 'age' (unsigned char): %u\n", age);
    printf("  Size of unsigned char: %zu byte(s)\n", sizeof(unsigned char));
    printf("  Variable 'distance_to_sun' (unsigned int): %u\n", distance_to_sun);
    printf("  Size of unsigned int: %zu byte(s)\n", sizeof(unsigned int));

    /* --- Floating-Point Types --- */
    printf("\nSection: Floating-Point Types (float, double, long double)\n");
    pi_approx = 3.14159f;        /* 'f' suffix for float */
    pi_precise = 3.1415926535;
    pi_extended = 3.141592653589793238L; /* 'L' suffix for long double */

    printf("  Variable 'pi_approx' (float): %f\n", pi_approx);
    printf("  Size of float: %zu byte(s)\n", sizeof(float));

    printf("  Variable 'pi_precise' (double): %.10f\n", pi_precise);
    printf("  Size of double: %zu byte(s)\n", sizeof(double));

    printf("  Variable 'pi_extended' (long double): %.18Lf\n", pi_extended);
    printf("  Size of long double: %zu byte(s)\n", sizeof(long double));

    /* --- Boolean Type (C99) --- */
    printf("\nSection: Boolean Type (bool - C99 Standard)\n");
    is_active = true; /* Can be 'true' or 'false' */
    printf("  C89 has no built-in boolean. C99 introduced <stdbool.h>.\n");
    printf("  Often, integers are used (0 for false, non-zero for true).\n");
    printf("  Variable 'is_active' (bool): %d (1=true, 0=false)\n", is_active);
    printf("  Size of bool: %zu byte(s)\n", sizeof(bool));

    /* --- Void Type --- */
    printf("\nSection: Void Type\n");
    printf("  The 'void' type has three main uses:\n");
    printf("  1. To specify a function returns no value (e.g., void my_func()).\n");
    printf("  2. To specify a function takes no arguments (e.g., int main(void)).\n");
    printf("  3. As a generic pointer (void*), covered in the pointers demo.\n");
    printf("  You cannot declare a variable of type void.\n");
}


/*
 * Demonstrates implicit and explicit type casting.
 */
void demoTypesCast(void)
{
    /* C89 requires all variables to be declared at the start of a block */
    int integer_val;
    double double_val;

    int numerator, denominator;
    double result_double;
    int result_int;

    int large_int;
    char small_char;

    printf("\n--- DEMO: Type Casting ---\n");

    /* --- Implicit Type Conversion (Coercion) --- */
    printf("\nSection: Implicit Type Conversion\n");
    printf("The compiler automatically converts types when it's safe (promotion).\n");

    integer_val = 10;
    double_val = integer_val; /* Implicitly converted from int to double */
    printf("  int 10 assigned to a double becomes: %f\n", double_val);

    printf("Data loss can occur with implicit narrowing conversions.\n");
    double_val = 9.99;
    integer_val = double_val; /* Implicitly converted, fractional part is lost */
    printf("  double 9.99 assigned to an int becomes: %d (fraction is truncated)\n", integer_val);

    /* --- Explicit Type Conversion (Casting) --- */
    printf("\nSection: Explicit Type Conversion (Casting)\n");
    printf("We use the (new_type) syntax to force a conversion.\n");

    /* Example 1: The most common use case - integer division */
    printf("\n  Example 1: Forcing Floating-Point Division\n");
    numerator = 10;
    denominator = 4;

    /* Without casting, the result is an integer because both operands are integers */
    result_int = numerator / denominator;
    printf("    10 / 4 (integer division) = %d\n", result_int);

    /* By casting one of the operands to double, we force floating-point division */
    result_double = (double)numerator / denominator;
    printf("    (double)10 / 4 (floating-point division) = %f\n", result_double);

    /* Example 2: Casting a float/double to an integer */
    printf("\n  Example 2: Casting a Double to an Integer\n");
    double_val = 42.85;
    /* The cast explicitly tells the compiler we want to truncate the value */
    integer_val = (int)double_val;
    printf("    (int)42.85 results in: %d (value is truncated, not rounded)\n", integer_val);

    /* Example 3: Casting a larger integer type to a smaller one */
    printf("\n  Example 3: Casting an Integer to a Char\n");
    large_int = 321; /* Binary: 0001 0100 0001 */
    /* A char can only hold 1 byte (8 bits). The higher bits of the int are discarded. */
    small_char = (char)large_int; /* Keeps only the lower 8 bits: 0100 0001 */

    printf("    int 321 cast to a char.\n");
    printf("    The resulting character is '%c'\n", small_char);
    printf("    Its integer value is %d (which is ASCII for 'A')\n", small_char);

    /* Example 4: A note on casting pointers */
    printf("\n  Example 4: A Note on Pointers\n");
    printf("    Type casting is also crucial when working with generic pointers (void*).\n");
    printf("    This allows a pointer to point to any data type.\n");
    printf("    This topic will be explored in the pointers demo.\n");
}


/*
 * Demonstrates the various operators available in C.
 */
void demoOperators(void)
{
    /* C89 requires all variables to be declared at the start of a block */
    int a, b;
    int logic_true, logic_false;
    unsigned char p, q; /* Use unsigned for bitwise ops to avoid sign-related issues */
    int z;
    int i;
    int max_val;

    printf("\n--- DEMO: Operators in C ---\n");

    a = 10;
    b = 4;

    /* --- Arithmetic Operators --- */
    printf("\nSection: Arithmetic Operators (a=%d, b=%d)\n", a, b);
    printf("  Addition (a + b)         = %d\n", a + b);
    printf("  Subtraction (a - b)      = %d\n", a - b);
    printf("  Multiplication (a * b)   = %d\n", a * b);
    printf("  Division (a / b)         = %d (Note: Integer division truncates)\n", a / b);
    printf("  Modulus (a %% b)          = %d (Remainder of the division)\n", a % b);

    /* --- Relational Operators --- */
    printf("\nSection: Relational Operators (a=%d, b=%d)\n");
    printf("  Relational operators return 1 for true and 0 for false.\n");
    printf("  Is Equal (a == b)        = %d\n", a == b);
    printf("  Is Not Equal (a != b)    = %d\n", a != b);
    printf("  Greater Than (a > b)     = %d\n", a > b);
    printf("  Less Than (a < b)        = %d\n", a < b);
    printf("  Greater or Equal (a >= b) = %d\n", a >= b);
    printf("  Less or Equal (a <= b)   = %d\n", a <= b);

    /* --- Logical Operators --- */
    logic_true = 1;  /* In C, any non-zero value is considered true */
    logic_false = 0; /* Zero is considered false */
    printf("\nSection: Logical Operators (true=%d, false=%d)\n", logic_true, logic_false);
    printf("  Logical AND (true && false) = %d\n", logic_true && logic_false);
    printf("  Logical OR (true || false)  = %d\n", logic_true || logic_false);
    printf("  Logical NOT (!true)         = %d\n", !logic_true);

    /* --- Bitwise Operators --- */
    p = 5; /* Binary: 00000101 */
    q = 9; /* Binary: 00001001 */
    printf("\nSection: Bitwise Operators (p=5, q=9)\n");
    printf("  Bitwise AND (p & q)      = %d (Binary: 00000001)\n", p & q);
    printf("  Bitwise OR (p | q)       = %d (Binary: 00001101)\n", p | q);
    printf("  Bitwise XOR (p ^ q)      = %d (Binary: 00001100)\n", p ^ q);
    printf("  Bitwise NOT (~p)         = %d (Flips all bits)\n", ~p);
    printf("  Left Shift (p << 1)      = %d (Binary: 00001010)\n", p << 1);
    printf("  Right Shift (p >> 1)     = %d (Binary: 00000010)\n", p >> 1);

    /* --- Assignment Operators --- */
    z = 100;
    printf("\nSection: Assignment Operators (z starts at 100)\n");
    printf("  Initial z                  = %d\n", z);
    z += 10; /* Equivalent to z = z + 10 */
    printf("  z += 10 (Add and assign)   = %d\n", z);
    z -= 20; /* Equivalent to z = z - 20 */
    printf("  z -= 20 (Sub and assign)   = %d\n", z);
    z *= 3;  /* Equivalent to z = z * 3 */
    printf("  z *= 3  (Mul and assign)   = %d\n", z);
    z /= 5;  /* Equivalent to z = z / 5 */
    printf("  z /= 5  (Div and assign)   = %d\n", z);

    /* --- Increment/Decrement Operators --- */
    i = 5;
    printf("\nSection: Increment/Decrement Operators (i starts at 5)\n");
    /* Post-increment: The value of 'i' is used first, then it is incremented. */
    printf("  Post-increment (i++): Value used is %d, then i becomes %d.\n", i++, i);

    /* Pre-increment: The value of 'i' is incremented first, then it is used. */
    printf("  Pre-increment (++i): Value is incremented to %d, then used.\n", ++i);

    /* Post-decrement: The value of 'i' is used first, then it is decremented. */
    printf("  Post-decrement (i--): Value used is %d, then i becomes %d.\n", i--, i);

    /* Pre-decrement: The value of 'i' is decremented first, then it is used. */
    printf("  Pre-decrement (--i): Value is decremented to %d, then used.\n", --i);
}


/*
 * Demonstrates the fundamental concepts of pointers in C.
 */
void demoPointers(void)
{
    /* C89 requires all variables to be declared at the start of a block */
    int var;
    int* ptr; /* ptr is a 'pointer to an integer' */
    int** ptr_to_ptr; /* A pointer to a pointer to an integer */

    int arr[5] = { 100, 200, 300, 400, 500 };
    int* arr_ptr_start;
    int* arr_ptr_middle;
    int i;

    void* generic_ptr;
    float float_var;

    printf("\n--- DEMO: Pointers in C ---\n");

    /* --- Pointer Definition, Address-of Operator (&), and Assignment --- */
    printf("\nSection: Pointer Definition and Assignment\n");
    var = 42;
    ptr = &var; /* The '&' operator gets the memory address of 'var' */

    printf("  A pointer is a variable that stores a memory address.\n");
    printf("  Value of 'var': %d\n", var);
    /* Use %p format specifier to print addresses. Cast to (void*) for portability. */
    printf("  Address of 'var' (&var): %p\n", (void*)&var);
    printf("  Value of 'ptr' (the address it stores): %p\n", (void*)ptr);

    /* --- Dereference Operator (*) --- */
    printf("\nSection: Getting the Value at an Address (Dereferencing)\n");
    printf("  The '*' operator (dereference) retrieves the value at the stored address.\n");
    printf("  Value at the address stored in 'ptr' (*ptr): %d\n", *ptr);

    printf("  We can also modify the original variable's value through the pointer.\n");
    *ptr = 99; /* Change the value at the memory location pointed to by ptr */
    printf("  After '*ptr = 99;', the value of 'var' is now: %d\n", var);

    /* --- Address of a Pointer (Pointer to Pointer) --- */
    printf("\nSection: Address of a Pointer\n");
    ptr_to_ptr = &ptr;
    printf("  A pointer is also a variable, so it has its own memory address.\n");
    printf("  Address of 'ptr' (&ptr): %p\n", (void*)&ptr);
    printf("  Value of 'ptr_to_ptr': %p\n", (void*)ptr_to_ptr);
    printf("  Value at 'ptr_to_ptr' (*ptr_to_ptr): %p (This is the address of 'var')\n", (void*)*ptr_to_ptr);
    printf("  Value at the final address (**ptr_to_ptr): %d (This is the value of 'var')\n", **ptr_to_ptr);

    /* --- Pointer Arithmetic --- */
    printf("\nSection: Pointer Arithmetic\n");
    printf("  Pointer arithmetic is scaled by the size of the data type it points to.\n");
    arr_ptr_start = arr; /* An array name decays to a pointer to its first element */

    for (i = 0; i < 5; i++)
    {
        /* *(arr_ptr_start + i) is equivalent to arr[i] */
        printf("  Element %d: Address=%p, Value=%d\n", i,
            (void*)(arr_ptr_start + i), *(arr_ptr_start + i));
    }
    printf("  Note: The address increases by %zu bytes each time (the size of an int).\n", sizeof(int));

    /* --- Pointer Comparison --- */
    printf("\nSection: Pointer Comparison\n");
    arr_ptr_start = &arr[0];
    arr_ptr_middle = &arr[2];

    printf("  Pointers can be compared, which is useful with arrays.\n");
    if (arr_ptr_start < arr_ptr_middle)
    {
        printf("  The address of arr[0] (%p) is less than the address of arr[2] (%p).\n",
            (void*)arr_ptr_start, (void*)arr_ptr_middle);
    }

    /* A crucial safety check is comparing a pointer to NULL */
    ptr = NULL; /* NULL is a special value for a pointer that points to nothing */
    if (ptr == NULL)
    {
        printf("  The pointer 'ptr' is currently a NULL pointer.\n");
    }

    /* --- Void Pointers and Type Casting --- */
    printf("\nSection: Void Pointers (Generic Pointers)\n");
    printf("  A 'void*' can point to any data type but cannot be dereferenced directly.\n");

    /* Pointing to an integer */
    generic_ptr = &var;
    printf("  Void pointer now holds address of 'var': %p\n", generic_ptr);
    /* To get the value, we must cast it back to the correct pointer type first */
    printf("  Value via cast: %d\n", *((int*)generic_ptr));

    /* Pointing to a float */
    float_var = 3.14f;
    generic_ptr = &float_var;
    printf("  Void pointer now holds address of 'float_var': %p\n", generic_ptr);
    printf("  Value via cast: %.2f\n", *((float*)generic_ptr));
}


/*
 * Demonstrates the use of the 'const' keyword with pointers.
 */
void demoConstantPtr(void)
{
    /* C89 requires all variables to be declared at the start of a block */
    int val1, val2;
    const int immutable_val = 100;

    /* Case 1: Pointer to a constant integer */
    const int* ptr_to_const;

    /* Case 2: Constant pointer to an integer. Must be initialized at declaration. */
    int* const const_ptr = &val1;

    /* Case 3: Constant pointer to a constant integer. Must be initialized. */
    const int* const const_ptr_to_const = &val1;

    printf("\n--- DEMO: Pointers and Constants ---\n");

    val1 = 10;
    val2 = 20;

    /* --- Basic Constant Variable --- */
    printf("\nSection: Basic Constant Variable\n");
    printf("  A 'const' variable cannot be changed after initialization.\n");
    printf("  Value of 'immutable_val': %d\n", immutable_val);
    /* immutable_val = 200; // COMPILER ERROR: Cannot assign to a read-only variable. */

    /* --- Case 1: Pointer to a Constant --- */
    /* Read 'const int*' as "a pointer to an integer that is constant". */
    printf("\nSection: Pointer to a Constant (const int*)\n");
    printf("  Rule: The VALUE pointed to cannot be changed through this pointer.\n");

    ptr_to_const = &val1;
    printf("  Pointer 'ptr_to_const' now points to 'val1'.\n");
    printf("  Value read via pointer: %d\n", *ptr_to_const);

    /* This is NOT allowed. You cannot change the data it points to. */
    /* *ptr_to_const = 30; // COMPILER ERROR: Assignment of read-only location. */
    printf("  Attempting to change the value via '*ptr_to_const = 30;' would cause a compiler error.\n");

    /* This IS allowed. The pointer itself can be changed to point elsewhere. */
    ptr_to_const = &val2;
    printf("  The pointer itself can be changed. It now points to 'val2'.\n");
    printf("  New value read via pointer: %d\n", *ptr_to_const);

    /* It can also point to a true constant variable. */
    ptr_to_const = &immutable_val;
    printf("  It can also point to a 'const int' variable. Value: %d\n", *ptr_to_const);

    /* --- Case 2: Constant Pointer --- */
    /* Read 'int* const' as "a constant pointer to an integer". */
    printf("\nSection: Constant Pointer (int* const)\n");
    printf("  Rule: The POINTER itself cannot be changed to point to a different address.\n");

    printf("  'const_ptr' was initialized to point to 'val1'. Value: %d\n", *const_ptr);

    /* This IS allowed. The data it points to can be modified. */
    *const_ptr = 50;
    printf("  The value it points to can be changed. 'val1' is now: %d\n", val1);

    /* This is NOT allowed. The pointer cannot be reassigned. */
    /* const_ptr = &val2; // COMPILER ERROR: Assignment of read-only variable 'const_ptr'. */
    printf("  Attempting to change the pointer 'const_ptr = &val2;' would cause a compiler error.\n");

    /* --- Case 3: Constant Pointer to a Constant --- */
    /* Read 'const int* const' as "a constant pointer to an integer that is constant". */
    printf("\nSection: Constant Pointer to a Constant (const int* const)\n");
    printf("  Rule: NEITHER the pointer NOR the value it points to can be changed.\n");

    printf("  'const_ptr_to_const' points to 'val1'. Value read: %d\n", *const_ptr_to_const);

    /* Neither of these operations are allowed. */
    /* *const_ptr_to_const = 60; // COMPILER ERROR! */
    /* const_ptr_to_const = &val2; // COMPILER ERROR! */
    printf("  This is the most restrictive type. It is read-only in every way.\n");
}


/*
 * Demonstrates conditional statements and loops in C.
 */
void demoControlFlowStructures(void)
{
    /* C89 requires all variables to be declared at the start of a block */
    int number;
    int items_read;
    int a, b, max_val;
    int i;
    int countdown;
    int do_while_counter;

    printf("\n--- DEMO: Control Flow Structures ---\n");

    printf("Please enter an integer number: ");
    items_read = scanf("%d", &number);

    /* Always check the return value of scanf to handle bad input */
    if (items_read != 1) {
        printf("Invalid input. Exiting demo.\n");
        return; /* Exit the function */
    }

    /* --- If, Else If, Else Statements --- */
    printf("\nSection: If / Else If / Else\n");
    if (number > 0)
    {
        printf("  The number %d is positive.\n", number);
    }
    else if (number < 0)
    {
        printf("  The number %d is negative.\n", number);
    }
    else
    {
        printf("  The number is exactly zero.\n", number);
    }

    /* --- Switch Statement --- */
    printf("\nSection: Switch Statement\n");
    printf("  Checking the number %d against a few cases:\n", number);
    switch (number)
    {
    case 0:
        printf("    Case 0: The number is zero.\n");
        break; /* 'break' exits the switch block */
    case 1:
        printf("    Case 1: The number is one.\n");
        break;
    case 7:
        printf("    Case 7: The number is seven.\n");
        break;
    case 2:
    case 3:
    case 5:
        printf("    Case 2, 3, or 5: The number is a small prime.\n");
        /* Note the 'fall-through' from case 2 and 3 to this line */
        break;
    default:
        /* This block runs if no other case matches */
        printf("    Default: The number is not 0, 1, 2, 3, 5, or 7.\n");
        break;
    }

    /* --- Ternary Operator (?:) --- */
    printf("\nSection: Ternary Operator\n");
    a = 15;
    b = 8;
    /* A compact way to write a simple if-else statement */
    max_val = (a > b) ? a : b;
    printf("  The maximum of %d and %d is: %d\n", a, b, max_val);

    /* --- For Loop --- */
    printf("\nSection: For Loop\n");
    printf("  Counting from 1 to 5: ");
    for (i = 1; i <= 5; i++)
    {
        printf("%d ", i);
    }
    printf("\n");

    /* --- While Loop --- */
    printf("\nSection: While Loop\n");
    printf("  Countdown from 5 to 1: ");
    countdown = 5;
    while (countdown > 0)
    {
        printf("%d ", countdown);
        countdown--; /* Decrement the counter */
    }
    printf("\n");

    /* --- Do-While Loop --- */
    printf("\nSection: Do-While Loop\n");
    printf("  This loop's body always executes at least once.\n");
    do_while_counter = 10;
    do
    {
        printf("    Inside do-while loop. Counter value: %d\n", do_while_counter);
        do_while_counter++;
    } while (do_while_counter < 5); /* Condition is false, but loop ran once */
    printf("    Loop finished.\n");

    /* --- Break and Continue --- */
    printf("\nSection: Break and Continue\n");
    printf("  Looping from 1 to 10. Skipping 4, breaking at 8.\n  ");
    for (i = 1; i <= 10; i++)
    {
        if (i == 4)
        {
            /* 'continue' skips the rest of this iteration and starts the next one */
            continue;
        }
        if (i == 8)
        {
            /* 'break' exits the loop entirely */
            break;
        }
        printf("%d ", i);
    }
    printf("\n");
}


/*
 * Demonstrates function definition, calling, parameters, and return values.
 */
void demoFunctions(void)
{
    /* C89 requires all variables to be declared at the start of a block */
    int sum;
    int original_value;
    long fact_result;

    printf("\n--- DEMO: Functions in C ---\n");

    /* --- Function Call and Return Result --- */
    printf("\nSection: Function Call and Return Value\n");
    /*
     * Here, we 'call' the addNumbers function.
     * The values 5 and 3 are 'arguments' passed to the function.
     * The function 'returns' a value which is stored in the 'sum' variable.
     */
    sum = addNumbers(5, 3);
    printf("  The result of addNumbers(5, 3) is: %d\n", sum);

    /* --- Pass By Value --- */
    printf("\nSection: Pass By Value\n");
    original_value = 10;
    printf("  Before calling passByValueExample, original_value = %d\n", original_value);
    passByValueExample(original_value); /* A copy of original_value is passed */
    printf("  After calling passByValueExample, original_value is still = %d\n", original_value);
    printf("  Conclusion: The function could not change the original variable.\n");

    /* --- Pointers as Parameters (Pass By Reference) --- */
    printf("\nSection: Pointers as Parameters (Pass By Reference)\n");
    original_value = 20;
    printf("  Before calling passByReferenceExample, original_value = %d\n", original_value);
    passByReferenceExample(&original_value); /* The memory address is passed */
    printf("  After calling passByReferenceExample, original_value is now = %d\n", original_value);
    printf("  Conclusion: By passing a pointer, the function can change the original variable.\n");

    /* --- Constant Parameters --- */
    printf("\nSection: Constant Parameters\n");
    printf("  Using 'const' for a parameter tells the compiler the function should not modify it.\n");
    printWithConstParam(99);
    printf("  This is a contract that improves code safety and readability.\n");

    /* --- Recursive Functions --- */
    printf("\nSection: Recursive Functions\n");
    /* A recursive function is one that calls itself to solve a problem. */
    fact_result = factorial(5);
    printf("  The result of factorial(5) is: %ld\n", fact_result);
    printf("  (Calculation: 5 * 4 * 3 * 2 * 1)\n");
}

/*
 * This is a simple implementation of a function.
 */
int addNumbers(int a, int b)
{
    return a + b;
}

/*
 * This function receives a copy of the argument.
 * Any changes to 'num' here only affect the local copy.
 */
void passByValueExample(int num)
{
    num = 100; /* This only changes the copy inside this function */
    printf("    -> Inside function, the local copy 'num' is changed to %d\n", num);
}

/*
 * This function receives a pointer (a memory address).
 * By dereferencing the pointer, it can modify the original variable.
 */
void passByReferenceExample(int* num_ptr)
{
    *num_ptr = 200; /* This changes the value at the original memory address */
    printf("    -> Inside function, the value at the address is changed to %d\n", *num_ptr);
}

/*
 * The 'const' keyword ensures that 'value' cannot be changed inside this function.
 * For example, the line 'value = 0;' would cause a compiler error.
 */
void printWithConstParam(const int value)
{
    printf("  The constant value received by the function is: %d\n", value);
}

/*
 * Calculates the factorial of a number using recursion.
 * The function calls itself with a smaller value until it reaches the base case.
 */
long factorial(int n)
{
    /* Base case: The condition that stops the recursion */
    if (n <= 1)
    {
        return 1;
    }
    /* Recursive step: The function calls itself */
    else
    {
        return n * factorial(n - 1);
    }
}


/*
 * Demonstrates declaring, assigning, and using function pointers.
 */
void demoFunctionPtr(void)
{
    /*
     * Declaration of a function pointer.
     * Syntax: return_type (*pointer_name)(parameter_types);
     * This declares 'operation_ptr' as a pointer to a function that
     * takes two integers as arguments and returns an integer.
     */
    int (*operation_ptr)(int, int);
    int result;

    printf("\n--- DEMO: Function Pointers ---\n");

    /* --- Basic Declaration and Usage --- */
    printf("\nSection: Basic Function Pointer Usage\n");

    /* Assign the address of the 'add' function to the pointer. */
    /* The '&' is optional but makes the intent clear. */
    operation_ptr = &add;

    /* Call the function through the pointer. */
    /* The explicit dereference '(*operation_ptr)' is the classic way. */
    result = (*operation_ptr)(10, 5);
    printf("  Calling via (*operation_ptr)(10, 5) where ptr points to 'add': %d\n", result);

    /* Re-assign the pointer to a different, compatible function. */
    operation_ptr = &subtract;

    /* You can also call it implicitly, which is more common in modern code. */
    result = operation_ptr(10, 5);
    printf("  Calling via operation_ptr(10, 5) where ptr points to 'subtract': %d\n", result);

    /* --- Passing a Function Pointer as an Argument --- */
    printf("\nSection: Passing a Function Pointer to Another Function\n");
    printf("  This allows for creating flexible, reusable code (e.g., callbacks).\n");

    /* Pass the 'add' function itself as an argument. */
    performCalculation(20, 8, add);

    /* Pass the 'subtract' function as an argument. */
    performCalculation(20, 8, subtract);

    /* --- Returning a Function Pointer from a Function --- */
    printf("\nSection: Returning a Function Pointer from Another Function\n");

    /* Get a pointer to the appropriate function based on the character. */
    operation_ptr = getOperation('+');

    /* Always check if the returned pointer is valid before using it. */
    if (operation_ptr != NULL)
    {
        result = operation_ptr(100, 25);
        printf("  The function for '+' returned a pointer. Result: %d\n", result);
    }

    operation_ptr = getOperation('-');
    if (operation_ptr != NULL)
    {
        result = operation_ptr(100, 25);
        printf("  The function for '-' returned a pointer. Result: %d\n", result);
    }

    /* Test the case where an invalid operator is provided. */
    operation_ptr = getOperation('/');
    if (operation_ptr == NULL)
    {
        printf("  The function for '/' returned NULL as expected.\n");
    }
}

/* 
* Helper functions for the demoFunctionPtr() demo 
*/
int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

/*
 * This function accepts a function pointer 'calculator_func' as its third argument.
 * It then uses this pointer to perform the actual calculation.
 */
void performCalculation(int x, int y, int (*calculator_func)(int, int))
{
    int result = calculator_func(x, y);
    printf("    -> performCalculation result is: %d\n", result);
}

/*
 * This function's return type is a pointer to a function: int (*)(int, int).
 * Based on the 'op_char' argument, it returns a pointer to the 'add' or 'subtract'
 * function, or NULL if the operator is not recognized.
 */
int (*getOperation(char op_char))(int, int)
{
    switch (op_char)
    {
    case '+':
        return &add;
    case '-':
        return &subtract;
    default:
        return NULL; /* Return NULL for unsupported operations */
    }
}


/*
 * Demonstrates different variable scopes in C.
 */
void demoScopes(void)
{
    /* --- Block Scope (Local) Variable --- */
    /*
     * This variable is declared inside a function block.
     * It only exists and is only accessible within this function.
     */
    int local_variable = 10;

    printf("\n--- DEMO: Variable Scopes ---\n");

    printf("\nSection: Block Scope (Local) vs. File Scope (Global)\n");
    printf("  Inside demoScopes, 'local_variable' = %d\n", local_variable);
    printf("  Inside demoScopes, 'global_variable' = %d\n", global_variable);
    printf("  Inside demoScopes, 'file_static_variable' = %d\n", file_static_variable);

    /* We can modify the global variable from within a function */
    global_variable = 101;
    printf("  Modified 'global_variable' to: %d\n", global_variable);

    /* --- Inner Block Scope and Shadowing --- */
    printf("\nSection: Inner Block Scope and Shadowing\n");
    {
        /*
         * This is a NEW variable that only exists inside these curly braces.
         * It "shadows" the outer local_variable, meaning that within this block,
         * the name 'local_variable' refers to this new variable.
         */
        int local_variable = 20;
        int inner_block_var = 30;
        printf("    -> Inside inner block, a new 'local_variable' = %d (shadowing)\n", local_variable);
        printf("    -> Inside inner block, 'inner_block_var' = %d\n", inner_block_var);
    }
    /* The variable 'inner_block_var' no longer exists here. */
    /* The shadowed 'local_variable' is gone, and the original is visible again. */
    printf("  Outside inner block, original 'local_variable' = %d\n", local_variable);

    /* --- Static Local Variables --- */
    printf("\nSection: Static Local Variables\n");
    printf("  A static local variable is initialized only once and retains its value\n");
    printf("  between function calls, but is only visible inside its function.\n");
    static_counter_function();
    static_counter_function();
    static_counter_function();

    /* --- External Objects ('extern') --- */
    printf("\nSection: External Objects ('extern')\n");
    printf("  The 'extern' keyword is a promise to the compiler that a global\n");
    printf("  variable exists, but is defined in another source file.\n");

    /*
     * This line DECLARES another_global_var, but does not DEFINE it (allocate memory).
     * It tells the compiler to trust that the linker will find it in another file.
     */
    extern int another_global_var;

    /*
     * If you were to uncomment the line below and compile this single file,
     * you would get a LINKER ERROR because 'another_global_var' is never defined.
     * To make it work, you would need another .c file with 'int another_global_var = 500;'
     * at the global scope.
     */
     /* printf("  Value from another file: %d\n", another_global_var); */
    printf("  Using an unresolved 'extern' variable would cause a LINKER ERROR.\n");
}


/*
 * This function demonstrates a static local variable.
 */
void static_counter_function(void)
{
    /*
     * 'static_counter' is created and initialized to 0 only the first time
     * this function is called. On subsequent calls, the variable persists
     * and retains its previous value.
     */
    static int static_counter = 0;
    static_counter++;
    printf("    -> Counter function call. 'static_counter' is now: %d\n", static_counter);
}


/*
 * Demonstrates using typedef to simplify function pointer syntax.
 */
void demoFunctionDef(void)
{
    /* C89 requires all variables to be declared at the start of a block */

    /* The "old way" without typedef */
    int (*raw_func_ptr)(int, int);

    /* The "new way" using our typedef alias */
    OperationFuncPtr aliased_func_ptr;

    int result;

    printf("\n--- DEMO: Function Types and Typedef ---\n");

    /* --- Comparing Declaration Syntax --- */
    printf("\nSection: Comparing Declaration Syntax\n");
    printf("  The 'raw' syntax for a function pointer is complex and hard to read:\n");
    printf("    int (*raw_func_ptr)(int, int);\n");

    printf("  Using 'typedef', the declaration becomes simple and clear:\n");
    printf("    typedef int (*OperationFuncPtr)(int, int);\n");
    printf("    OperationFuncPtr aliased_func_ptr;\n");

    /* --- Assigning and Using the Typedef'd Pointer --- */
    printf("\nSection: Using the Typedef'd Pointer\n");

    /* Assignment is the same for both */
    raw_func_ptr = &multiply;
    aliased_func_ptr = &multiply;

    result = aliased_func_ptr(10, 5);
    printf("  Calling function via aliased pointer: 10 * 5 = %d\n", result);

    aliased_func_ptr = &divide;
    result = aliased_func_ptr(10, 5);
    printf("  Calling function via aliased pointer: 10 / 5 = %d\n", result);

    /* --- Using Typedef for Function Parameters --- */
    printf("\nSection: Using Typedef for Function Parameters\n");
    printf("  Using the alias makes function prototypes much easier to understand.\n");
    printf("  Compare:\n");
    printf("    void func(int, int, int (*op)(int, int)); // Hard to read\n");
    printf("    void func(int, int, OperationFuncPtr op); // Easy to read\n");

    printf("  Executing 'multiply' via the executeOperation function:\n");
    executeOperation(20, 4, multiply);

    printf("  Executing 'divide' via the executeOperation function:\n");
    executeOperation(20, 4, divide);
}

/* 
 * Helper functions for the demoFunctionDef() demo
 */
int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    /* Basic check to avoid division by zero */
    if (b != 0)
    {
        return a / b;
    }
    return 0;
}

/*
 * The third parameter, 'operation', is of our aliased function pointer type.
 * This makes the function signature clean and self-documenting.
 */
void executeOperation(int x, int y, OperationFuncPtr operation)
{
    int result;

    /* Check if the passed pointer is valid before calling it */
    if (operation != NULL)
    {
        result = operation(x, y);
        printf("    -> Result from executeOperation: %d\n", result);
    }
    else
    {
        printf("    -> Error: A NULL function pointer was passed.\n");
    }
}


/*
 * Demonstrates the declaration, initialization, and usage of arrays in C.
 */
void demoArrays(void)
{
    /* C89 requires all variables to be declared at the start of a block */
    int numbers[5] = { 10, 20, 30, 40, 50 };
    int i, j;
    size_t num_elements;

    const char vowels[] = { 'A', 'E', 'I', 'O', 'U' };

    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    size_t num_rows;
    size_t num_cols;

    printf("\n--- DEMO: Arrays in C ---\n");

    /* --- One-Dimensional Array --- */
    printf("\nSection: One-Dimensional Array\n");

    printf("  Array 'numbers' has been declared and initialized.\n");

    /* Accessing elements */
    printf("  Accessing elements by index (0-based):\n");
    printf("    The first element, numbers[0], is: %d\n", numbers[0]);
    printf("    The third element, numbers[2], is: %d\n", numbers[2]);

    /* Modifying an element */
    numbers[0] = 11;
    printf("    After modification, numbers[0] is now: %d\n", numbers[0]);

    /* Iterating over the array */
    printf("  Iterating through all elements with a for loop:\n    ");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    /* --- Array Size and Element Count --- */
    printf("\nSection: Finding Array Size and Length\n");
    printf("  The total size of the 'numbers' array in memory is: %zu bytes\n", sizeof(numbers));
    printf("  The size of a single int element is: %zu bytes\n", sizeof(numbers[0]));

    /* This is the standard, portable way to calculate the number of elements in an array */
    num_elements = sizeof(numbers) / sizeof(numbers[0]);
    printf("  Therefore, the number of elements in the array is: %zu\n", num_elements);

    /* --- Constant Arrays --- */
    printf("\nSection: Constant Arrays\n");
    printf("  An array declared with 'const' cannot have its elements modified.\n");
    printf("  The elements of the 'vowels' array are: ");
    for (i = 0; i < 5; i++)
    {
        printf("%c ", vowels[i]);
    }
    printf("\n");
    /* vowels[0] = 'B'; // This line would cause a COMPILER ERROR. */
    printf("  Attempting to modify a const array element results in a compiler error.\n");

    /* --- Two-Dimensional Array (Matrix) --- */
    printf("\nSection: Two-Dimensional Array\n");
    printf("  A 2D array is an array of arrays, often visualized as a grid or matrix.\n");

    /* Accessing an element */
    printf("  Accessing an element at row 1, column 2: matrix[1][2] = %d\n", matrix[1][2]);

    /* Finding dimensions */
    num_rows = sizeof(matrix) / sizeof(matrix[0]);
    num_cols = sizeof(matrix[0]) / sizeof(matrix[0][0]);
    printf("  The matrix has %zu rows and %zu columns.\n", num_rows, num_cols);

    /* Iterating over the 2D array with nested loops */
    printf("  Printing the full matrix:\n");
    for (i = 0; i < num_rows; i++)
    {
        printf("    "); /* Indent for alignment */
        for (j = 0; j < num_cols; j++)
        {
            printf("%-4d", matrix[i][j]); /* Print with padding */
        }
        printf("\n");
    }
}


/*
 * Demonstrates string handling in C.
 */
void demoStrings(void)
{
    /* C89 requires all variables to be declared at the start of a block */
    char str1[] = "Hello"; /* Size is determined by compiler (5 chars + 1 null terminator) */
    char str2[20] = "World"; /* Explicitly sized buffer */
    char buffer[50];
    int cmp_result;

    char num_str_int[] = "12345";
    char num_str_float[] = "3.14";
    int int_val;
    double float_val;

    char result_str[50];
    int my_number = 42;

    char test_str[] = "Data 123 Go!";
    int i;
    char c;

    printf("\n--- DEMO: Strings in C ---\n");

    /* --- Strings as Character Arrays --- */
    printf("\nSection: Strings as Character Arrays\n");
    printf("  In C, a string is an array of characters ending with a null terminator ('\\0').\n");
    printf("  String 1: \"%s\"\n", str1);
    printf("  Size in memory (sizeof): %zu bytes (includes the '\\0')\n", sizeof(str1));
    printf("  Length (strlen): %zu characters (does NOT include the '\\0')\n", strlen(str1));

    /* --- String Operations (<string.h>) --- */
    printf("\nSection: Common String Operations\n");
    /* strcpy: copies a string into a buffer. DANGEROUS if source is larger than destination! */
    strcpy(buffer, str1);
    printf("  After strcpy(buffer, str1), buffer is: \"%s\"\n", buffer);

    /* strcat: concatenates (appends) a string to another. Also DANGEROUS! */
    strcat(buffer, " ");
    strcat(buffer, str2);
    printf("  After strcat, buffer is: \"%s\"\n", buffer);

    /* --- String Comparison (<string.h>) --- */
    printf("\nSection: String Comparison (strcmp)\n");
    printf("  strcmp compares strings lexicographically (alphabetical order).\n");
    cmp_result = strcmp("Apple", "Banana");
    printf("  strcmp(\"Apple\", \"Banana\") returns: %d (a negative value)\n", cmp_result);
    cmp_result = strcmp("Banana", "Apple");
    printf("  strcmp(\"Banana\", \"Apple\") returns: %d (a positive value)\n", cmp_result);
    cmp_result = strcmp("Apple", "Apple");
    printf("  strcmp(\"Apple\", \"Apple\") returns: %d (zero for equal strings)\n", cmp_result);

    /* --- String to Number Conversion (<stdlib.h>) --- */
    printf("\nSection: Converting Strings to Numbers\n");
    int_val = atoi(num_str_int); /* ASCII to Integer */
    float_val = atof(num_str_float); /* ASCII to Float/Double */
    printf("  String \"%s\" converted to integer: %d\n", num_str_int, int_val);
    printf("  String \"%s\" converted to double: %f\n", num_str_float, float_val);
    printf("  We can now perform math: %d * 2 = %d\n", int_val, int_val * 2);

    /* --- Number to String Conversion (sprintf) --- */
    printf("\nSection: Converting Numbers to Strings\n");
    /* sprintf works like printf, but "prints" its output into a string buffer. */
    sprintf(result_str, "The magic number is %d.", my_number);
    printf("  The newly created string is: \"%s\"\n", result_str);

    /* --- Character Checks (<ctype.h>) --- */
    printf("\nSection: Character Type Checking\n");
    printf("  Analyzing the string: \"%s\"\n", test_str);
    for (i = 0; test_str[i] != '\0'; i++)
    {
        c = test_str[i];
        printf("    '%c' is: ", c);
        if (isalpha(c)) printf("alpha, ");
        if (isdigit(c)) printf("digit, ");
        if (isspace(c)) printf("space, ");
        if (isupper(c)) printf("uppercase, ");
        if (islower(c)) printf("lowercase, ");
        printf("to_upper: %c, to_lower: %c\n", toupper(c), tolower(c));
    }
}


/*
 * Demonstrates how to access and use command-line parameters.
 */
void demoMainCmdParams(int argc, char* argv[])
{
    int i;

    printf("\n--- DEMO: Main Function Command-Line Parameters ---\n");

    /* --- How to Run This Demo --- */
    printf("\n  IMPORTANT: To see this demo work, you must run the compiled .exe\n");
    printf("  file from a command prompt (like cmd.exe or PowerShell) and provide arguments.\n\n");
    printf("  For example, after compiling, navigate to the executable's directory and run:\n");
    printf("  > ConsoleApp.exe first_arg 123 \"An argument with spaces\"\n\n");
    printf("  You can also configure 'Command Arguments' in your IDE's project debug settings.\n");

    /* --- Analyzing argc and argv --- */
    printf("\nSection: Analyzing argc and argv\n");

    /* Print the number of arguments found */
    printf("  Argument count (argc): %d\n", argc);

    /* Check if any arguments were provided besides the program name */
    if (argc == 1)
    {
        printf("  No additional command-line arguments were provided.\n");
    }
    else
    {
        printf("  The following arguments were provided:\n");
    }

    /* Loop through the argv array and print each argument string */
    for (i = 0; i < argc; i++)
    {
        /*
         * argv[0] is always the name of the program itself.
         * argv[1] is the first actual argument.
         * ...and so on.
         */
        printf("    argv[%d]: %s\n", i, argv[i]);
    }
}


/*
 * Demonstrates working with dates and times in C.
 */
void demoDateTime(void)
{
    /* C89 requires all variables to be declared at the start of a block */
    time_t current_time_raw;
    struct tm* time_info;
    char buffer[80];
    time_t start_time, end_time;
    double elapsed_seconds;
    long i;

    printf("\n--- DEMO: Date and Time Operations ---\n");

    /* --- Getting the Current Time (time_t) --- */
    printf("\nSection: Getting the Current Time\n");
    /*
     * The time() function returns the current calendar time as a time_t object.
     * time_t is an arithmetic type representing the number of seconds elapsed
     * since the "Epoch" (00:00:00 UTC, January 1, 1970).
     */
    time(&current_time_raw);
    printf("  Raw time_t value (seconds since Epoch): %ld\n", (long)current_time_raw);


    /* --- Converting time_t to a Readable Format (struct tm) --- */
    printf("\nSection: Converting to a Human-Readable Structure\n");
    /*
     * The localtime() function converts a time_t value to a tm structure,
     * which breaks down the time into its components (year, month, day, etc.).
     * Note: localtime() returns a pointer to a static, internal buffer that
     * can be overwritten by subsequent calls.
     */
    time_info = localtime(&current_time_raw);
    printf("  The time_t value has been converted to a 'struct tm'.\n");

    /* --- Formatting Time as a String --- */
    printf("\nSection: Formatting Time as a String\n");
    /* Method 1: asctime() - Simple but fixed format */
    printf("  Using asctime() for a standard format: %s", asctime(time_info));

    /* Method 2: strftime() - Flexible and powerful */
    /*
     * strftime() formats the time according to provided format codes.
     * %Y = Year with century (e.g., 2023)
     * %m = Month as a number (01-12)
     * %d = Day of the month (01-31)
     * %H = Hour (00-23), %M = Minute (00-59), %S = Second (00-60)
     */
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", time_info);
    printf("  Using strftime() for a custom format: %s\n", buffer);

    /* --- Accessing Individual Time Components --- */
    printf("\nSection: Accessing Individual Time Components\n");
    /*
     * IMPORTANT: Note the offsets required for year and month.
     * tm_year is the number of years since 1900.
     * tm_mon is the month, from 0 (January) to 11 (December).
     */
    printf("  Year: %d\n", time_info->tm_year + 1900);
    printf("  Month: %d\n", time_info->tm_mon + 1);
    printf("  Day: %d\n", time_info->tm_mday);
    printf("  Time: %02d:%02d:%02d\n", time_info->tm_hour, time_info->tm_min, time_info->tm_sec);

    /* --- Calculating Time Differences --- */
    printf("\nSection: Calculating Elapsed Time\n");
    printf("  Performing a task to measure elapsed time...\n");

    start_time = time(NULL);

    /* Simulate some work by running a long loop */
    for (i = 0; i < 2000000000; i++) {
        /* This loop just consumes CPU time */
    }

    end_time = time(NULL);

    /* The difftime() function safely calculates the difference in seconds */
    elapsed_seconds = difftime(end_time, start_time);
    printf("  Task finished. Elapsed time: %.2f seconds\n", elapsed_seconds);
}










