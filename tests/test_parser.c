#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Parser function
void parse(Token *tokens)
{
    int i = 0;
    while (tokens[i].type != TOKEN_EOF)
    {
        // Check for 'let' keyword
        if (tokens[i].type == TOKEN_KEYWORD && strcmp(tokens[i].value, "let") == 0)
        {
            // Expect an identifier
            i++;
            if (tokens[i].type == TOKEN_IDENTIFIER)
            {
                printf("Declaration: %s\n", tokens[i].value);
            }
            else
            {
                printf("Error: Expected an identifier after 'let'\n");
                return;
            }
        }

        // Check for 'print' keyword
        else if (tokens[i].type == TOKEN_KEYWORD && strcmp(tokens[i].value, "print") == 0)
        {
            // Expect an expression
            i++;
            if (tokens[i].type == TOKEN_IDENTIFIER || tokens[i].type == TOKEN_NUMBER)
            {
                printf("Print: %s\n", tokens[i].value);
            }
            else
            {
                printf("Error: Expected an identifier or number after 'print'\n");
                return;
            }
        }

        // Move to the next token
        i++;
    }
}

int main()
{
    Token tokens[] = {
        {TOKEN_KEYWORD, "let"},
        {TOKEN_IDENTIFIER, "x"},
        {TOKEN_OPERATOR, "="},
        {TOKEN_NUMBER, "42"},
        {TOKEN_PUNCTUATION, ";"},
        {TOKEN_KEYWORD, "print"},
        {TOKEN_IDENTIFIER, "x"},
        {TOKEN_PUNCTUATION, ";"},
        {TOKEN_EOF, ""}};

    parse(tokens);

    return 0;
}
