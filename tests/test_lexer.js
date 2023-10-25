// Include the lexer module
const { lexer } = require('../js_code/lexer');


const input = 'let x = 42; print(x);';

const tokens = lexer(input);
console.log(tokens);
