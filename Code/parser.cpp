#include <iostream>

#include "lexicalAnalyzer.cpp"

//creating an object
LexicalAnalyzer undObj;

std::stringstream s;
void identifier(std::string buffer, int lineNumber);
void op(std::string buffer, int lineNumber);
void terminator(std::string buffer, int lineNumber);
void keyword(std::string buffer, int lineNumber);
void str(std::string buffer, int lineNumber);
void number(std::string buffer, int lineNumber);
void comments(std::string buffer, int lineNumber);
void headerfile(std::string buffer, int lineNumber);
void parenthesis(std::string buffer, int lineNumber);
void parenthesisOpen(std::string buffer, int lineNumber);
void parenthesisClose(std::string buffer, int lineNumber);
void brackets(std::string buffer, int lineNumber);
void bracketsOpen(std::string buffer, int lineNumber);
void bracketsClose(std::string buffer, int lineNumber);

int main() {
    int lineNumber = 0;
    std::string sourcefile = "input.un";
    std::string line;
    std::ifstream file(sourcefile);
    if (!file) {
        std::cout << "Error is opening " << sourcefile << std::endl;
    }
    do {
        lineNumber++;
        s = stringstream(line);
        std::string buffer;
        s >> buffer;
        if (buffer[0] == '"') {
            std::string temp;
            while (buffer[buffer.size() - 1] != '"') {
                s >> temp;
                buffer = buffer + ' ' + temp;
            }
        } else if (undObj.isKeyword(buffer, lineNumber)) {
            keyword(buffer, lineNumber);
        } else if (undObj.isIdentifier(buffer, lineNumber)) {
            identifier(buffer, lineNumber);
        } else if (undObj.isComment(buffer, lineNumber)) {
            comments(buffer, lineNumber);
        } else if (undObj.isHeaderFile(buffer, lineNumber)) {
            headerfile(buffer, lineNumber);
        } else if (undObj.isParenthesis(buffer, lineNumber)) {
            parenthesis(buffer, lineNumber);
        } else if (undObj.isOpenParenthesis(buffer, lineNumber)) {
            parenthesisOpen(buffer, lineNumber);
        } else if (undObj.isCloseParenthesis(buffer, lineNumber)) {
            parenthesisClose(buffer, lineNumber);
        } else if (undObj.isBracket(buffer, lineNumber)) {
            brackets(buffer, lineNumber);
        } else if (undObj.isOpenBracket(buffer, lineNumber)) {
            bracketsOpen(buffer, lineNumber);
        } else if (undObj.isCloseBracket(buffer, lineNumber)) {
            bracketsClose(buffer, lineNumber);
        } else {
            std::cout << "Error at line " << lineNumber << std::endl;
            std::cout << buffer << endl;
        }

    } while (getline(file, line));
}
void keyword(std::string buffer, int lineNumber) {
    s >> buffer;
    if (buffer[0] == '"') {
        std::string temp;
        while (buffer[buffer.size() - 1] != '"') {
            s >> temp;
            buffer = buffer + ' ' + temp;
        }
    }
    if (undObj.isCharStr(buffer, lineNumber)) {
        str(buffer, lineNumber);
    } else if (undObj.isNum(buffer, lineNumber)) {
        number(buffer, lineNumber);
    } else if (undObj.isIdentifier(buffer, lineNumber)) {
        identifier(buffer, lineNumber);
    } else if (undObj.isTerminator(buffer, lineNumber)) {
        terminator(buffer, lineNumber);
    } else {
        std::cout << "Error at line " << lineNumber << std::endl;
        std::cout << buffer << endl;
    }
}
void str(std::string buffer, int lineNumber) {
    s >> buffer;
    if (buffer[0] == '"') {
        std::string temp;
        while (buffer[buffer.size() - 1] != '"') {
            s >> temp;
            buffer = buffer + ' ' + temp;
        }
    }
    if (undObj.isOperator(buffer, lineNumber)) {
        op(buffer, lineNumber);
    } else if (undObj.isTerminator(buffer, lineNumber)) {
        terminator(buffer, lineNumber);
    } else {
        std::cout << "Error at line " << lineNumber << std::endl;
        std::cout << buffer << endl;
    }
}
void number(std::string buffer, int lineNumber) {
    s >> buffer;
    if (buffer[0] == '"') {
        std::string temp;
        while (buffer[buffer.size() - 1] != '"') {
            s >> temp;
            buffer = buffer + ' ' + temp;
        }
    }
    if (undObj.isOperator(buffer, lineNumber)) {
        op(buffer, lineNumber);
    } else if (undObj.isTerminator(buffer, lineNumber)) {
        terminator(buffer, lineNumber);
    } else {
        std::cout << "Error at line " << lineNumber << std::endl;
        std::cout << buffer << std::endl;
    }
}
void identifier(std::string buffer, int lineNumber) {
    s >> buffer;
    if (buffer[0] == '"') {
        std::string temp;
        while (buffer[buffer.size() - 1] != '"') {
            s >> temp;
            buffer = buffer + ' ' + temp;
        }
    }
    if (undObj.isOperator(buffer, lineNumber)) {
        op(buffer, lineNumber);
    } else if (undObj.isTerminator(buffer, lineNumber)) {
        terminator(buffer, lineNumber);
    } else {
        std::cout << "Error at line " << lineNumber << std::endl;
        std::cout << buffer << endl;
    }
}
void op(std::string buffer, int lineNumber) {
    s >> buffer;
    if (buffer[0] == '"') {
        std::string temp;
        while (buffer[buffer.size() - 1] != '"') {
            s >> temp;
            buffer = buffer + ' ' + temp;
        }
    }
    if (undObj.isNum(buffer, lineNumber)) {
        number(buffer, lineNumber);
    } else if (undObj.isCharStr(buffer, lineNumber)) {
        str(buffer, lineNumber);
    } else if (undObj.isIdentifier(buffer, lineNumber)) {
        identifier(buffer, lineNumber);
    } else {
        std::cout << "Error at line " << lineNumber << std::endl;
        std::cout << buffer << endl;
    }
}
void comments(std::string buffer, int lineNumber) {
    s >> buffer;
    if (buffer[0] == '"') {
        std::string temp;
        while (buffer[buffer.size() - 1] != '"') {
            s >> temp;
            buffer = buffer + ' ' + temp;
        }
    }
    if (undObj.isComment(buffer, lineNumber)) {
        comments(buffer, lineNumber);
    } else {
        std::cout << "Error at line " << lineNumber << std::endl;
        std::cout << buffer << endl;
    }
}
void headerfile(std::string buffer, int lineNumber) {
    s >> buffer;
    if (buffer[0] == '"') {
        std::string temp;
        while (buffer[buffer.size() - 1] != '"') {
            s >> temp;
            buffer = buffer + ' ' + temp;
        }
    }
    if (undObj.isHeaderFile(buffer, lineNumber)) {
        headerfile(buffer, lineNumber);
    } else {
        std::cout << "Error at line " << lineNumber << std::endl;
        std::cout << buffer << endl;
    }
}
void parenthesis(std::string buffer, int lineNumber) {
    s >> buffer;
    if (buffer[0] == '"') {
        std::string temp;
        while (buffer[buffer.size() - 1] != '"') {
            s >> temp;
            buffer = buffer + ' ' + temp;
        }
    }
    if (undObj.isParenthesis(buffer, lineNumber)) {
        parenthesis(buffer, lineNumber);
    } else {
        std::cout << "Error at line " << lineNumber << std::endl;
        std::cout << buffer << endl;
    }
}
void parenthesisOpen(std::string buffer, int lineNumber) {
    s >> buffer;
    if (buffer[0] == '"') {
        std::string temp;
        while (buffer[buffer.size() - 1] != '"') {
            s >> temp;
            buffer = buffer + ' ' + temp;
        }
    }
    if (undObj.isOpenParenthesis(buffer, lineNumber)) {
        parenthesisOpen(buffer, lineNumber);
    } else {
        std::cout << "Error at line " << lineNumber << std::endl;
        std::cout << buffer << endl;
    }
}
void parenthesisClose(std::string buffer, int lineNumber) {
    s >> buffer;
    if (buffer[0] == '"') {
        std::string temp;
        while (buffer[buffer.size() - 1] != '"') {
            s >> temp;
            buffer = buffer + ' ' + temp;
        }
    }
    if (undObj.isCloseParenthesis(buffer, lineNumber)) {
        parenthesisClose(buffer, lineNumber);
    } else {
        std::cout << "Error at line " << lineNumber << std::endl;
        std::cout << buffer << endl;
    }
}
void brackets(std::string buffer, int lineNumber) {
    s >> buffer;
    if (buffer[0] == '"') {
        std::string temp;
        while (buffer[buffer.size() - 1] != '"') {
            s >> temp;
            buffer = buffer + ' ' + temp;
        }
    }
    if (undObj.isBracket(buffer, lineNumber)) {
        brackets(buffer, lineNumber);
    } else {
        std::cout << "Error at line " << lineNumber << std::endl;
        std::cout << buffer << endl;
    }
}
void bracketsOpen(std::string buffer, int lineNumber) {
    s >> buffer;
    if (buffer[0] == '"') {
        std::string temp;
        while (buffer[buffer.size() - 1] != '"') {
            s >> temp;
            buffer = buffer + ' ' + temp;
        }
    }
    if (undObj.isOpenBracket(buffer, lineNumber)) {
        bracketsOpen(buffer, lineNumber);
    } else {
        std::cout << "Error at line " << lineNumber << std::endl;
        std::cout << buffer << endl;
    }
}

void bracketsClose(std::string buffer, int lineNumber) {
    s >> buffer;
    if (buffer[0] == '"') {
        std::string temp;
        while (buffer[buffer.size() - 1] != '"') {
            s >> temp;
            buffer = buffer + ' ' + temp;
        }
    }
    if (undObj.isCloseBracket(buffer, lineNumber)) {
        bracketsClose(buffer, lineNumber);
    } else {
        std::cout << "Error at line " << lineNumber << std::endl;
        std::cout << buffer << endl;
    }
}

void terminator(std::string buffer, int lineNumber) {
    std::cout << "Syntax ACCEPTED at line " << lineNumber << " " << std::endl;
}
