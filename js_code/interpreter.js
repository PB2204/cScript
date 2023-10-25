// Token types
const TokenType = {
    IDENTIFIER: 'IDENTIFIER',
    NUMBER: 'NUMBER',
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

// Symbol table for variables
const symbolTable = {};

// Interpreter function
function interpret(tokens) {
    let i = 0;
    while (i < tokens.length) {
        // Check for 'let' keyword
        if (tokens[i].type === TokenType.KEYWORD && tokens[i].value === 'let') {
            // Variable declaration
            i++;
            if (tokens[i].type === TokenType.IDENTIFIER) {
                const variableName = tokens[i].value;
                i++;
                if (tokens[i].type === TokenType.OPERATOR && tokens[i].value === '=') {
                    i++;
                    // Evaluate the expression and store the result in the variable
                    if (tokens[i].type === TokenType.NUMBER) {
                        const value = parseFloat(tokens[i].value);
                        symbolTable[variableName] = value;
                    } else {
                        console.log(`Error: Expected a number after '='`);
                        return;
                    }
                }
            }
        } else if (tokens[i].type === TokenType.KEYWORD && tokens[i].value === 'print') {
            // Print statement
            i++;
            if (tokens[i].type === TokenType.IDENTIFIER) {
                const variableName = tokens[i].value;
                if (symbolTable[variableName] !== undefined) {
                    console.log(`Print: ${variableName} = ${symbolTable[variableName]}`);
                } else {
                    console.log(`Error: Variable ${variableName} not defined`);
                    return;
                }
            }
        }
        i++;
    }
}

// Example tokens (replace with the actual output from the lexer)
const tokens = [
    { type: TokenType.KEYWORD, value: 'let' },
    { type: TokenType.IDENTIFIER, value: 'x' },
    { type: TokenType.OPERATOR, value: '=' },
    { type: TokenType.NUMBER, value: '42' },
    { type: TokenType.KEYWORD, value: 'print' },
    { type: TokenType.IDENTIFIER, value: 'x' },
    { type: TokenType.EOF, value: '' },
];

interpret(tokens);
