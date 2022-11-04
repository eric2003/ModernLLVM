#include <iostream>
#include <string>
// The lexer returns tokens [0-255] if it is an unknown character, otherwise one
// of these for known things.
enum Token {
  tok_eof = -1,

  // commands
  tok_def = -2,
  tok_extern = -3,

  // primary
  tok_identifier = -4,
  tok_number = -5,
};

static std::string IdentifierStr; // Filled in if tok_identifier
static double NumVal;

/// gettok - Return the next token from standard input.
static int gettok() {
    static int LastChar = ' ';

    // Skip any whitespace.
    while ( isspace( LastChar ) ) {
        LastChar = getchar();
    }

    if (isalpha(LastChar)) { // identifier: [a-zA-Z][a-zA-Z0-9]*
        IdentifierStr = LastChar;
        while (isalnum((LastChar = getchar())))
            IdentifierStr += LastChar;

        if (IdentifierStr == "def")
            return tok_def;
        if (IdentifierStr == "extern")
            return tok_extern;
        return tok_identifier;
    }


    //Note that this code sets the ¡®IdentifierStr¡¯ global whenever it lexes an identifier.
    //Also, since language keywords are matched by the same loop, we handle them here inline.
    //Numeric values are similar:

    if (isdigit(LastChar) || LastChar == '.') {   // Number: [0-9.]+
        std::string NumStr;
        do {
            NumStr += LastChar;
            LastChar = getchar();
        } while (isdigit(LastChar) || LastChar == '.');

        NumVal = strtod(NumStr.c_str(), 0);
        return tok_number;
    }

    //This is all pretty straightforward code for processing input.
    //When reading a numeric value from input, 
    //we use the C strtod function to convert it to a numeric value that we store in NumVal.
    //Note that this isn¡¯t doing sufficient error checking:
    //it will incorrectly read ¡°1.23.45.67¡± and handle it as if you typed in ¡°1.23¡±. 
    //Feel free to extend it! Next we handle comments:

    if (LastChar == '#') {
        // Comment until end of line.
        do {
            LastChar = getchar();
        } while ( LastChar != EOF && LastChar != '\n' && LastChar != '\r' );

        if ( LastChar != EOF ) {
            return gettok();
        }
    }

    //We handle comments by skipping to the end of the line and then return the next token.
    //Finally, if the input doesn¡¯t match one of the above cases, 
    //it is either an operator character like ¡®+¡¯ or the end of the file.
    //These are handled with this code:

    // Check for end of file.  Don't eat the EOF.
    if ( LastChar == EOF ) {
        return tok_eof;
    }

    // Otherwise, just return the character as its ascii value.
    int ThisChar = LastChar;
    LastChar = getchar();
    return ThisChar;
}

int main( int argc, char ** argv )
{
    while ( true ) {
        int tok = gettok();
        std::cout << "got token: " << tok << std::endl;
    }
    std::cout << "haha\n";
}