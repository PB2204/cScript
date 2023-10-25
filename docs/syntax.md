# cScript Language Syntax

This document provides an overview of the syntax and language constructs in cScript, a programming language that combines elements of C and JavaScript.

## Table of Contents

1. [Variables](#variables)
2. [Data Types](#data-types)
3. [Statements](#statements)
   - [Variable Declaration](#variable-declaration)
   - [Print Statement](#print-statement)

## Variables

In cScript, variables are used to store and manipulate data. Variable names are case-sensitive and can consist of letters, numbers, and underscores.

Example:

```cscript
let x = 42;
let message = "Hello, World!";
```

## Data Types

cScript supports the following data types:

- **Numbers**: Numeric data can be integers or floating-point values.

```cscript
let count = 10;
let price = 19.99;
```

- **Strings**: Text data can be represented using double or single quotes.

```cscript
let message = "Hello, cScript!";
let title = 'My Program';
```

## Statements

### Variable Declaration

Variables in cScript are declared using the `let` keyword, followed by the variable name and an optional initialization value.

Syntax:

```cscript
let variableName = initialValue;
```

Example:

```cscript
let x = 42;
let message = "Hello, World!";
```

### Print Statement

The `print` statement is used to display values to the console.

Syntax:

```cscript
print(expression);
```

Example:

```cscript
let message = "Hello, cScript!";
print(message);
```