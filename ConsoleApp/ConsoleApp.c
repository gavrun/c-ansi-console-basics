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
#include <stdbool.h> //C99 introduced <stdbool.h> for bool, true, false. In C89, we use _Bool or integers.
#include <stddef.h> // Required for NULL 


// Functions declarations (prototype)
void demoConsoleInOut(void);
void demoVariablesAndTypes(void);
void demoTypesCast(void);
void demoOperators(void);
void demoPointers(void);
void demoConstantPtr(void);


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
    //demoConsoleInOut();
    //demoVariablesAndTypes();
    //demoTypesCast();
    //demoOperators();
    //demoPointers();
    demoConstantPtr();


    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


// Function definitions (implementation)


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

















