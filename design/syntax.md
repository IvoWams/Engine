# Basic structure

This defines the structure of a file:
```
<file> ::= <header> <declarations>
<header> ::= ?
<declarations> ::= { <declaration> }
<declaration> ::= <function-declaration>
<declaration> ::= <class-declaration>
```

# lexigraphic
```
<empty> = 
<bracket-open> ::= "("
<bracket-close> ::= ")"
<accolade-open> ::= "{"
<accolade-close> ::= "}"
<array-open> ::= "["
<array-close> ::= "]"
<basic-type> ::= [a-zA-Z0-9\-_]
<basic-name> ::= [a-zA-Z0-9\-_]
<basic-number> ::= [0-9\-,.]
<list-separator> ::= ","
<statement-separator> ::= ";"
<string-separator> ::= "\""	// A singe doublequote
<string-content> ::= { ^" }	// A list of anything except doublequote
<equals> ::= "="
```

# basics
## Function declaration
```
returnType functionName (parameterType parameterName)
returnType functionName (parameterType parameterName = parameterDefaultValue)
```

```
<return-type> ::= <basic-type>
<function-name> ::= <basic-name>

<parameter-type> ::= <basic-type>
<parameter-name> ::= <basic-name>
<parameter-default-value> ::= <variable-scalar-value>
```

In conclusion:
```
<function-declaration> ::= <return-type> <function-name> <parameter-declaration>
<parameter-declaration> ::= <bracket-open> <parameter-declaration-list> <bracket-close>
<parameter-declaration-list> ::= <parameter-declaration> { <list-separator> <parameter-declaration> }
<parameter-declaration> ::= <parameter-type> <parameter-name>
<parameter-declaration> ::= <parameter-type> <parameter-name> <equals> <variable-scalar-value>
<variable-scalar-value> ::= <variable-
```

## Variable declaration
```
variableType variableName = variableValue
variableType variableName = expression
```

```
<variable-type> ::= <declaration-type>
<variable-name> ::= <basic-name>
<variable-value> ::= <declaration-value>

<declaration-type> ::= <declaration-type-void>
<declaration-type> ::= <declaration-type-boolean>
<declaration-type> ::= <declaration-type-string>
<declaration-type> ::= <declaration-type-number>
<declaration-type> ::= <declaration-type-array>
<declaration-type> ::= <declaration-type-class>

<declaration-type-void> ::= "void"
<declaration-type-boolean> ::= "bool"
<declaration-type-string> ::= "string"
<declaration-type-number> ::= "number"
<declaration-type-array> ::= "array"
<declaration-type-class> ::= <basic-type>

<declaration-value> ::= <declaration-value-boolean>
<declaration-value> ::= <declaration-value-string>
<declaration-value> ::= <declaration-value-number>
<declaration-value> ::= <declaration-value-array>
<declaration-value> ::= <declaration-value-class>
<declaration-value> ::= <declaration-value-variable>
```

## Variable assignment
```
variableName = variableValue
variableName = expression
```

<declare-value-boolean> ::= "true"
<declare-value-boolean> ::= "false"
<declare-value-string> ::= <string-separator> <string-content> <string-separator>
<declare-value-number> ::= <basic-number>
<declare-value-array> ::= <array-open> <array-list> <array-close>

<array-list> ::= <array-entry> { <list-separator> <array-entry> }
<array-entry> ::= <declaration-value>
<array-entry> ::= <variable>

# function decaration

String someKindOfFunction(int number1, int number2)
{
	return number1 + number2;
}

<function-declaration> ::= <return-type> <function-name> <parameter-list> <function-content>
<return-type> ::= <basic-type>
<function-name> ::= <basic-name>

<declaration-parameter-list> ::= <bracket-open> <bracket-close>
<declaration-parameter-list> ::= <bracket-open> <declaration-parameters> <bracker-close>
<declaration-parameters> ::= <declaration-parameter>  { <list-separator> <declaration-parameter> } 
<declaration-parameter> ::= <parameter-type> <parameter-name>

<parameter-type> ::= <basic-type>
<parameter-name> ::= <basic-name>

<function-content> ::= <accolade-open> <statements> <accolade-close>

# main program declaration

<statements> ::= { <statement> <statement-separator> }
<statement> ::= <assignment>
<statement> ::= <return> | <if> | <switch> | <while> | ...

#assignemnts

<assignemnt> ::= [ <variable-type> ] <variable> "=" <expression>
<variable-type> ::= <basic-type>
<variable> ::= <basic-name>

<expression> ::= "new" <class-declaration>
<expression> ::= <scalar>
<expression> ::= <variable-name>



<expression> ::= <variable-name>
<expression> ::= <invoke-function>
<expression> ::= <operator> <variable-name>
<expression> ::= <variable-name> <operator> <variable-name>

<invoke-function> ::= <function-name> <invoke-parameter-list>

<invoke-parameter-list> ::= <bracket-open> <bracket-close>
<invoke-parameter-list> ::= <bracket-open> <invoke-parameters> <bracket-close>
<invoke-parameters> ::= <invoke-parameter> { <list-separator> <invoke-parameter> }
<invoke-parameter> ::= <scalar>
<invoke-parameter> ::= <variable>


assignment: x = 5;


# Basic C type declarations

variable = <bool> | <number> | <string> | <object> | <expression>
bool = "true" | "false" | <expression>
number = [0-9.-]+

expression = <expression> "&&" <expression>
expression = <expression> "||" <expression>
expression = <variable> "==" <variable>
expression = <variable> "<" <variable>
expression = <variable> "<=" <variable>
expression = <variable> ">" <variable>
expression = <variable> ">=" <variable>



object = new class(variables);
object.property = variable
object.method = function

parameter = <type> <name> [ "=" <value> ]
parameterlist = [] | <parameter> { "," <parameter> }

"function" <name> "(" { <type> <name> ["=" <initialvalue>] [","] } ")"
	"{" {expressions} "}"
	
	