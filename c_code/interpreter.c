#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Token types
typedef enum
{
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_STRING,
    TOKEN_KEYWORD,
    TOKEN_OPERATOR,
    TOKEN_PUNCTUATION,
    TOKEN_NEWLINE,
    TOKEN_EOF
} TokenType;

// Token structure
typedef struct
{
    TokenType type;
    char value[100];
} Token;

// Symbol table for variables
typedef struct
{
    char name[100];
    double value;
} Symbol;

// Array to store variables
Symbol symbol_table[100];
int symbol_count = 0;

// Function to get the value of a variable by name
double get_variable_value(const char *name)
{
    for (int i = 0; i < symbol_count; i++)
    {
        if (strcmp(symbol_table[i].name, name) == 0)
        {
            return symbol_table[i].value;
        }
    }
    return 0; // Return 0 if variable not found (you may want to handle this differently)
}

// Function to set the value of a variable by name
void set_variable_value(const char *name, double value)
{
    for (int i = 0; i < symbol_count; i++)
    {
        if (strcmp(symbol_table[i].name, name) == 0)
        {
            symbol_table[i].value = value;
            return;
        }
    }

    // If the variable doesn't exist, add it to the symbol table
    if (symbol_count < 100)
    {
        strcpy(symbol_table[symbol_count].name, name);
        symbol_table[symbol_count].value = value;
        symbol_count++;
    }
    else
    {
        printf("Error: Symbol table full\n");
        exit(1);
    }
}

// Interpreter function
void interpret(Token *tokens)
{
    int i = 0;
    while (tokens[i].type != TOKEN_EOF)
    {
        if (tokens[i].type == TOKEN_KEYWORD && strcmp(tokens[i].value, "let") == 0)
        {
            // Variable declaration
            i++;
            if (tokens[i].type == TOKEN_IDENTIFIER)
            {
                char variable_name[100];
                strcpy(variable_name, tokens[i].value);
                i++;
                if (tokens[i].type == TOKEN_OPERATOR && strcmp(tokens[i].value, "=") == 0)
                {
                    i++;
                    // Evaluate the expression and store the result in the variable
                    double value = atof(tokens[i].value);
                    set_variable_value(variable_name, value);
                }
            }
        }
        else if (tokens[i].type == TOKEN_KEYWORD && strcmp(tokens[i].value, "print") == 0)
        {
            // Print statement
            i++;
            if (tokens[i].type == TOKEN_IDENTIFIER)
            {
                double value = get_variable_value(tokens[i].value);
                printf("%f\n", value);
            }
        }

        i++;
    }
}

int main()
{
    // Example tokens (replace with the actual output from the lexer)
    Token tokens[] = {
        {TOKEN_KEYWORD, "let"},
        {TOKEN_IDENTIFIER, "x"},
        {TOKEN_OPERATOR, "="},
        {TOKEN_NUMBER, "42"},
        {TOKEN_KEYWORD, "print"},
        {TOKEN_IDENTIFIER, "x"},
        {TOKEN_EOF, ""}};

    interpret(tokens);

    return 0;
}
