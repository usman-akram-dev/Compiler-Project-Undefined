#ifndef parser_h
#define parser_h#include "lexicalAnalyzer.cpp"

#include <bits/stdc++.h>

class parser {
    public:
        parser(string file) {
            std::ifstream sourceCode(file);
            std::String line;
            std::String buff;
            LexicalAnalyzer undObj;
            if (!sourceCode) {
                std::cout << "Error in reading Code.us\n";
            }
            int lineNum = 0;
            do {
                std::stringstream s(line);
                while (s >> buff) {
                    if (buff[0] == '"') {
                        std::string temp;
                        while (buff[buff.size() - 1] != '"') {
                            s >> temp;
                            buff = buff + ' ' + temp;
                        }
                    }
                    if (undObj.isKeyword(buff, lineNum)) {
                        if (!(s >> buff)) {
                            std::cout << "Error at line " << lineNum << " " << line << std::endl;
                            continue;
                        }

                        if (buff[0] == '"') {
                            std::string temp;
                            while (buff[buff.size() - 1] != '"') {
                                s >> temp;
                                buff = buff + ' ' + temp;
                            }
                        }

                        if (undObj.isNum(buff, lineNum)) {
                            continue;
                        } else if (undObj.isIdentifier(buff, lineNum)) {
                            continue;
                        } else if (undObj.isTerminator(buff, lineNum)) {
                            continue;
                        } else if (undObj.isCharStr(buff, lineNum)) {
                            continue;
                        } else {
                            std::cout << line << endl;
                            std::cout << "ERROR at line " << buff << " Excepted an identifier" << endl;
                        }
                    }

                    if (undObj.isNum(buff, lineNum)) {

                        if (!(s >> buff)) {
                            std::cout << "Error at line " << lineNum << " " << line << endl;
                        } else
                        if (undObj.isNum(buff, lineNum)) {
                            std::cout << "ERROR at line " << lineNum << " Excepted an operator" << endl;
                        } else if (undObj.isIdentifier(buff, lineNum)) {
                            std::cout << "ERROR at line " << lineNum << " Excepted an operator" << endl;
                        }
                        if (undObj.isOperator(buff, lineNum)) {
                            continue;
                        }
                        if (undObj.isTerminator(buff, lineNum)) {
                            continue;
                        }
                    }

                    if (undObj.isIdentifier(buff, lineNum)) {
                        if (!(s >> buff)) {
                            std::cout << "Error at line " << lineNum << " " << line << endl;
                            continue;
                        }
                        if (undObj.isOperator(buff, lineNum)) {
                            continue;
                        } else if (undObj.isTerminator(buff, lineNum)) {
                            continue;
                        } else if (undObj.isNumb(buff, lineNum)) {
                            std::cout << "ERROR at line " << lineNum << " Excepted an operator" << endl;
                        } else if (undObj.isIdentifier(buff, lineNum)) {
                            std::cout << "ERROR at line " << lineNum << " Excepted an operator" << endl;
                        }
                    }

                    if (undObj.isComment(buff, lineNum)) {
                        if (!(s >> buff)) {
                            std::cout << "Error at line " << lineNum << " " << line << endl;
                            continue;
                        }
                    }
                    if (undObj.isHeaderFile(buff, lineNum)) {
                        if (!(s >> buff)) {
                            std::cout << "Error at line " << lineNum << " " << line << endl;
                            continue;
                        }
                    }
                    if (undObj.isBracket(buff, lineNum)) {
                        if (!(s >> buff)) {
                            std::cout << "Error at line " << lineNum << " " << line << endl;
                            continue;
                        }
                    }
                    if (undObj.isOpenBracket(buff, lineNum)) {
                        if (!(s >> buff)) {
                            std::cout << "Error at line " << lineNum << " " << line << endl;
                            continue;
                        }
                    }
                    if (undObj.isCloseBracket(buff, lineNum)) {
                        if (!(s >> buff)) {
                            std::cout << "Error at line " << lineNum << " " << line << endl;
                            continue;
                        }
                    }
                    if (undObj.isParenthesis(buff, lineNum)) {
                        if (!(s >> buff)) {
                            std::cout << "Error at line " << lineNum << " " << line << endl;
                            continue;
                        }
                    }
                    if (undObj.isOpenParenthesis(buff, lineNum)) {
                        if (!(s >> buff)) {
                            std::cout << "Error at line " << lineNum << " " << line << endl;
                            continue;
                        }
                    }
                    if (undObj.isCloseParenthesis(buff, lineNum)) {
                        if (!(s >> buff)) {
                            std::cout << "Error at line " << lineNum << " " << line << endl;
                            continue;
                        }
                    }
                }
                lineNum++;
            } while (getline(sourceCode, line));
        }
};
