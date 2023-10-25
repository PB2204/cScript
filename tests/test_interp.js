// Include the interpreter module
const interpreter = require('../js_code/interpreter');

// Example tokens (replace with the actual output from the lexer)
const TokenType = interpreter.TokenType; // Access TokenType from the interpreter module
const tokens = [
    { type: TokenType.KEYWORD, value: 'let' },
    { type: TokenType.IDENTIFIER, value: 'x' },
    { type: TokenType.OPERATOR, value: '=' },
    { type: TokenType.NUMBER, value: '42' },
    { type: TokenType.KEYWORD, value: 'print' },
    { type: TokenType.IDENTIFIER, value: 'x' },
    { type: TokenType.EOF, value: '' },
];

interpreter.interpret(tokens);
