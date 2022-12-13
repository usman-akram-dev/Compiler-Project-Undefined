#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

class LexicalAnalyzer {
   public:
     int flag;
      //constructor
      LexicalAnalyzer() {
           int flag = 0;
      }

   bool isKeyword(string buff, int lineNum) {
      if (buff == "globlPrnt" | buff == "in" | buff == "out" | buff == "Yes" | buff == "No" | buff == "charStr" | buff == "console" | buff == "store" | buff == "check" | buff == "ifNot" | buff == "checkAgain" | buff == "untilSatisfied" | buff == "isValid") {
         return true;
      }
      return false;
   }

   bool isHeaderFile(string buff, int lineNum) {
      bool first = false;
      int stringBegin, stringEnd, i = 0;

      for (i = 0; i < buff.length(); i++) {

         if (buff[i] == '.') {
            stringBegin = i;
            break;
         }
      }

      for (int j = i + 1; j < buff.length(); j++) {

         if (buff[j] == 'h') {
            stringBegin = j;
            return true;

         }
      }
      return false;
   }

   bool isNum(string buff, int lineNum) {

      for (int i = 0; i < buff.length(); i++) {
         if (buff[i] >= '0' && buff[i] <= '9')
            continue;
         else
            return false;
      }

      return true;
   }

   bool isComment(string buff, int lineNum) {

      bool first = false;
      int stringBegin, stringEnd, i = 0;

      for (i = 0; i < buff.length(); i++) {

         if (buff[i] == '#') {
            stringBegin = i;
            break;
         }
      }
      for (int j = i + 1; j < buff.length(); j++) {

         if (buff[j] == '#') {
            stringBegin = j;
            return true;

         }
      }
      return false;
   }

   bool isCharStr(string buff, int lineNum) {

      bool first = false;
      int stringBegin, stringEnd, i = 0;

      for (i = 0; i < buff.length(); i++) {

         if (buff[i] == '"') {
            stringBegin = i;
            break;
         }
      }
      for (int j = i + 1; j < buff.length(); j++) {

         if (buff[j] == '"') {
            stringBegin = j;
            return true;

         }
      }
      return false;
   }

   bool isOperator(string buff, int lineNum) {
      if (buff == "+" | buff == "++" | buff == "-" | buff == "--" | buff == "/" | buff == "*" | buff == "%" || buff == "=" || buff == "==" || buff == "<" || buff == ">" || buff == "=<" || buff == "=>" || buff == "!=") {
         return true;
      }
      return false;
   }

   bool isTerminator(string buff, int lineNum) {
      for (int i = 0; i < buff.length(); i++) {
         if (buff[i] == ';')
            return true;
      }
      return false;
   }

   bool isParenthesis(string buff, int lineNum) {
      bool first = false;
      int stringBegin, stringEnd, i = 0;

      for (i = 0; i < buff.length(); i++) {

         if (buff[i] == '(') {
            stringBegin = i;
            break;
         }
      }
      for (int j = i + 1; j < buff.length(); j++) {

         if (buff[j] == ')') {
            stringBegin = j;
            return true;

         }
      }
      return false;
   }
   bool isOpenParenthesis(string buff, int lineNum) {
      for (int i = 0; i < buff.length(); i++) {
         if (buff[i] == '(')
            return true;
      }
      return false;
   }

   bool isCloseParenthesis(string buff, int lineNum) {
      for (int i = 0; i < buff.length(); i++) {
         if (buff[i] == ')')
            return true;
      }
      return false;
   }

   bool isBracket(string buff, int lineNum) {
      bool first = false;
      int stringBegin, stringEnd, i = 0;

      for (i = 0; i < buff.length(); i++) {

         if (buff[i] == '{') {
            stringBegin = i;
            break;
         }
      }
      for (int j = i + 1; j < buff.length(); j++) {

         if (buff[j] == '}') {
            stringBegin = j;
            return true;

         }
      }
      return false;
   }

   bool isOpenBracket(string buff, int lineNum) {
      for (int i = 0; i < buff.length(); i++) {
         if (buff[i] == '{')
            return true;
      }
      return false;
   }

   bool isCloseBracket(string buff, int lineNum) {
      for (int i = 0; i < buff.length(); i++) {
         if (buff[i] == '}')
            return true;
      }
      return false;
   }
   bool isIdentifier(string buff, int lineNum) {
      if (buff[0] >= 'a' && buff[0] <= 'z' || (buff[0] >= 'A' && buff[0] <= 'Z')) {
         for (int i = 0; i < buff.length(); i++) {
            if (isOperator(buff, lineNum)) {
               return false;
            }

            if (buff[i] == '#' || buff[i] == '@' || buff[i] == '!' || buff[i] == '^' || buff[i] == '&' || buff[i] == '$') {
               return false;
            }
         }

         return true;
      }
      return false;
   }

   void Tokenization(string file) {
      ifstream sourceCode(file);
      ofstream tokensFile("Output.txt");
      string line;
      string buff;
      if (!sourceCode) {
         cout << "Error in Input\n";
      }
      int lineNum = 1;
      int id = 0;

      do {
         stringstream s(line);

         while (s >> buff) {
            if (buff[0] == '"') {
               string temp;
               while (buff[buff.size() - 1] != '"') {
                  s >> temp;
                  buff = buff + ' ' + temp;
               }

            }
            if (isKeyword(buff, lineNum)) {

               id++;
               if(buff == "globlPrnt"){
               cout << "main function detected: " << buff << endl;
               tokensFile << "token_id_" << id << " " << "" << buff << "" << " main function" << endl;
               }
                if(buff == "in"){
               cout << "module detected: " << buff << endl;
               tokensFile << "token_id_" << id << " " << "" << buff << "" << " module" << endl;
               }
                if(buff == "out"){
               cout << "exit gate detected: " << buff << endl;
               tokensFile << "token_id_" << id << " " << "" << buff << "" << " exit gate" << endl;
               }
                if(buff == "Yes"){
               cout << "bool value detected: " << buff << endl;
               tokensFile << "token_id_" << id << " " << "" << buff << "" << " bool value" << endl;
               }
                if(buff == "No"){
               cout << "bool value detected: " << buff << endl;
               tokensFile << "token_id_" << id << " " << "" << buff << "" << " bool value" << endl;
               }
                if(buff == "charStr"){
               cout << "charStr detected: " << buff << endl;
               tokensFile << "token_id_" << id << " " << "" << buff << "" << " charStr" << endl;
               }
                if(buff == "console"){
               cout << "output detected: " << buff << endl;
               tokensFile << "token_id_" << id << " " << "" << buff << "" << " output" << endl;
               }
                if(buff == "store"){
               cout << "input detected: " << buff << endl;
               tokensFile << "token_id_" << id << " " << "" << buff << "" << " input" << endl;
               }
                if(buff == "check"){
               cout << "condition detected: " << buff << endl;
               tokensFile << "token_id_" << id << " " << "" << buff << "" << " condition" << endl;
               }
                if(buff == "ifNot"){
               cout << "condition detected: " << buff << endl;
               tokensFile << "token_id_" << id << " " << "" << buff << "" << " condition" << endl;
               }
                if(buff == "checkAgain"){
               cout << "condition detected: " << buff << endl;
               tokensFile << "token_id_" << id << " " << "" << buff << "" << " condition" << endl;
               }
                if(buff == "untilSatisfied"){
               cout << "loop detected: " << buff << endl;
               tokensFile << "token_id_" << id << " " << "" << buff << "" << " loop" << endl;
               }
               if(buff == "isValid"){
               cout << "bool datatype detected: " << buff << endl;
               tokensFile << "token_id_" << id << " " << "" << buff << "" << " booldatatype" << endl;
               }
        

            } else if (isHeaderFile(buff, lineNum)) {
               id++;
               cout << "header file detected: " << buff << endl;
               tokensFile << "token_id_" << id << " " << "" << buff << "" << " keyword" << endl;

            } else if (isNum(buff, lineNum)) {
               id++;
               cout << "number detected: " << buff << endl;
               tokensFile << "token_id_" << id << " " << buff << " number" << endl;
            } else if (isOperator(buff, lineNum)) {
               id++;
               if(buff == "+" | buff == "-" | buff == "/" | buff == "*" | buff == "%"){
               cout << "arithmetic operator detected: " << buff << endl;
               tokensFile << "token_id_" << id << " " << buff << " arithmetic operator" << endl;
               }
               if(buff == "==" || buff == "<" || buff == ">" || buff == "=<" || buff == "=>" || buff == "!="){
               cout << "relational operator detected: " << buff << endl;
               tokensFile << "token_id_" << id << " " << buff << " relational operator" << endl;
               }
               if(buff == "++" || buff == "--" ){
               cout << "unary operator detected: " << buff << endl;
               tokensFile << "token_id_" << id << " " << buff << " unary operator" << endl;
               }
               if(buff == "="){
               cout << "assignment operator detected: " << buff << endl;
               tokensFile << "token_id_" << id << " " << buff << " assignment operator" << endl;
               }
            

            } else if (isParenthesis(buff, lineNum)) {
               id++;
               cout << "opening and closing parenthesis are detected: " << buff << endl;
               tokensFile << "token_id_" << id << " " << buff << " are opening & closing parenthesis" << endl;
            } else if (isOpenParenthesis(buff, lineNum)) {
               id++;
               cout << "opening parenthesis detected: " << buff << endl;
               tokensFile << "token_id_" << id << " " << buff << " opening parenthesis" << endl;
            } else if (isCloseParenthesis(buff, lineNum)) {
               id++;
               cout << "closing parenthesis detected: " << buff << endl;
               tokensFile << "token_id_" << id << " " << buff << " closing parenthesis" << endl;
            } else if (isBracket(buff, lineNum)) {
               id++;
               cout << "opening and closing brackets are detected: " << buff << endl;
               tokensFile << "token_id_" << id << " " << buff << " opening and closing brackets" << endl;
            } else if (isOpenBracket(buff, lineNum)) {
               id++;
               cout << "opening bracket detected: " << buff << endl;
               tokensFile << "token_id_" << id << " " << buff << " opening bracket" << endl;
            } else if (isCloseBracket(buff, lineNum)) {
               id++;
               cout << "closing bracket detected: " << buff << endl;
               tokensFile << "token_id_" << id << " " << buff << " closing bracket" << endl;
            } else if (isIdentifier(buff, lineNum)) {
               id++;
               cout << "identifier detected: " << buff << endl;
               tokensFile << "token_id_" << id << " " << buff << " identifier" << endl;
            } else if (isTerminator(buff, lineNum)) {
               id++;
               cout << "terminator detected: " << buff << endl;
               tokensFile << "token_id_" << id << " " << buff << " terminator" << endl;

            } else if (isComment(buff, lineNum)) {
               cout << buff << " comment detected" << endl;

            } else if (isCharStr(buff, lineNum)) {
               id++;
               cout << "charStr detected: " << buff << endl;
               tokensFile << "token_id_" << id << " " << buff << " charStr" << endl;

            } else {

               cout << "Invalid syntax at line : " << lineNum << " " << buff << " Is not defined" << endl;
               tokensFile << "Invalid syntax at line : " << lineNum << " " << buff << " Is not defined" << endl;
               flag = 1;
            }

            lineNum++;
         }

      } while (getline(sourceCode, line));

      // Closing the file
      tokensFile.close();
   }

};
