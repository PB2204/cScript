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

// Parser function
function parse(tokens) {
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
                        // Here you would typically handle variable assignment
                        // or store the value in an environment.
                        console.log(`Variable ${variableName} assigned the value: ${value}`);
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
                // Here you would typically handle printing the value of the variable.
                console.log(`Print: ${tokens[i].value}`);
            }
        }
        i++;
    }
}

// Export the TokenType and parse function
module.exports = {
    TokenType,
    parse,
};
