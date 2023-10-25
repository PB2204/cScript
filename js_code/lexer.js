// Token types
const TokenType = {
    IDENTIFIER: 'IDENTIFIER',
    NUMBER: 'NUMBER',
    STRING: 'STRING',
    KEYWORD: 'KEYWORD',
    OPERATOR: 'OPERATOR',
    PUNCTUATION: 'PUNCTUATION',
    NEWLINE: 'NEWLINE',
    EOF: 'EOF',
};

// Token structure
class Token {
    constructor(type, value) {
        this.type = type;
        this.value = value;
    }
}

// Function to check if a string is a keyword
function isKeyword(str) {
    const keywords = ['let', 'print', 'for', 'if', 'else'];
    return keywords.includes(str);
}

// Lexer function
function lexer(input) {
    const tokens = [];
    let i = 0;

    while (i < input.length) {
        // Skip whitespace
        if (/\s/.test(input[i])) {
            i++;
            continue;
        }

        // Recognize numbers
        if (/[0-9]/.test(input[i])) {
            let j = i;
            while (/[0-9]/.test(input[j])) {
                j++;
            }
            tokens.push(new Token(TokenType.NUMBER, input.slice(i, j)));
            i = j;
        }

        // Recognize keywords and identifiers
        if (/[a-zA-Z_]/.test(input[i])) {
            let j = i;
            while (/[a-zA-Z0-9_]/.test(input[j])) {
                j++;
            }
            const tokenValue = input.slice(i, j);
            tokens.push(new Token(isKeyword(tokenValue) ? TokenType.KEYWORD : TokenType.IDENTIFIER, tokenValue));
            i = j;
        }

        // Recognize operators
        if (/[\+\-\*\/\=\&\|\<\>\!\%\^]/.test(input[i])) {
            tokens.push(new Token(TokenType.OPERATOR, input[i]));
            i++;
        }

        // Recognize punctuation
        if (/[\(\)\{\}\[\]\,\;\:\.]/.test(input[i])) {
            tokens.push(new Token(TokenType.PUNCTUATION, input[i]));
            i++;
        }

        // Recognize newline characters
        if (/\n/.test(input[i])) {
            tokens.push(new Token(TokenType.NEWLINE, '\n'));
            i++;
        }
    }

    // Add an end-of-file token
    tokens.push(new Token(TokenType.EOF, ''));

    return tokens;
}

module.exports = { TokenType, Token, lexer };

// Example input
const input = 'let x = 42; print(x);';

const tokens = lexer(input);
console.log(tokens);
