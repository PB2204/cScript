// Include the parser module
const parser = require('../js_code/parser');

// Example tokens (replace with the actual output from the lexer)
const tokens = [
    { type: parser.TokenType.KEYWORD, value: 'let' },
    { type: parser.TokenType.IDENTIFIER, value: 'x' },
    { type: parser.TokenType.OPERATOR, value: '=' },
    { type: parser.TokenType.NUMBER, value: '42' },
    { type: parser.TokenType.KEYWORD, value: 'print' },
    { type: parser.TokenType.IDENTIFIER, value: 'x' },
    { type: parser.TokenType.EOF, value: '' },
];

// Call the parse function from the parser module
parser.parse(tokens);
