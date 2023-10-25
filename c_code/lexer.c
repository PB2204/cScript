#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_SIZE 100

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
    char value[MAX_TOKEN_SIZE];
} Token;

// Function to check if a string is a keyword
int is_keyword(const char *str)
{
    const char *keywords[] = {"let", "print", "for", "if", "else"};
    int num_keywords = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < num_keywords; i++)
    {
        if (strcmp(keywords[i], str) == 0)
        {
            return 1;
        }
    }
    return 0;
}

// Lexer function
Token *lexer(const char *input)
{
    Token *tokens = malloc(sizeof(Token) * MAX_TOKEN_SIZE);
    int token_count = 0;

    const char *ptr = input;
    while (*ptr)
    {
        // Skip whitespace
        if (isspace(*ptr))
        {
            ptr++;
            continue;
        }

        // Recognize numbers
        if (isdigit(*ptr))
        {
            tokens[token_count].type = TOKEN_NUMBER;
            int i = 0;
            while (isdigit(ptr[i]))
            {
                tokens[token_count].value[i] = ptr[i];
                i++;
            }
            tokens[token_count].value[i] = '\0';
            token_count++;
            ptr += i;
        }
        // Recognize keywords
        else if (isalpha(*ptr))
        {
            int i = 0;
            while (isalnum(ptr[i]))
            {
                tokens[token_count].value[i] = ptr[i];
                i++;
            }
            tokens[token_count].value[i] = '\0';

            if (is_keyword(tokens[token_count].value))
            {
                tokens[token_count].type = TOKEN_KEYWORD;
            }
            else
            {
                tokens[token_count].type = TOKEN_IDENTIFIER;
            }

            token_count++;
            ptr += i;
        }
        // Handle other cases (operators, punctuation, etc.)
        else
        {
            // You would add more code to recognize operators and other constructs here.
            // For this simple example, we'll just skip the character.
            ptr++;
        }
    }

    // Add an end-of-file token
    tokens[token_count].type = TOKEN_EOF;

    return tokens;
}

int main()
{
    const char *input = "let x = 42; print(x);";
    Token *tokens = lexer(input);

    int i = 0;
    while (tokens[i].type != TOKEN_EOF)
    {
        printf("Token: %s\n", tokens[i].value);
        i++;
    }

    free(tokens);
    return 0;
}
