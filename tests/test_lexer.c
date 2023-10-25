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

// Function to print a token
void print_token(const Token *token)
{
    const char *type_str;
    switch (token->type)
    {
    case TOKEN_IDENTIFIER:
        type_str = "IDENTIFIER";
        break;
    case TOKEN_NUMBER:
        type_str = "NUMBER";
        break;
    case TOKEN_STRING:
        type_str = "STRING";
        break;
    case TOKEN_KEYWORD:
        type_str = "KEYWORD";
        break;
    case TOKEN_OPERATOR:
        type_str = "OPERATOR";
        break;
    case TOKEN_PUNCTUATION:
        type_str = "PUNCTUATION";
        break;
    case TOKEN_NEWLINE:
        type_str = "NEWLINE";
        break;
    case TOKEN_EOF:
        type_str = "EOF";
        break;
    }

    printf("Type: %s, Value: %s\n", type_str, token->value);
}

int main()
{
    const char *input = "let x = 42; print(x);";
    Token *tokens = lexer(input);

    int i = 0;
    while (tokens[i].type != TOKEN_EOF)
    {
        print_token(&tokens[i]);
        i++;
    }

    free(tokens);
    return 0;
}
