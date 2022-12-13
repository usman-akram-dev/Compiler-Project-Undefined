%{
	#include <cstdio>
	#include <cstdlib>
	#include <iostream>
	#include <bits/stdc++.h>

	using namespace std;
	//Declare stuff from Flex that Bison needs to know about
	int yylex();
	extern FILE *yyin;
	extern int lineno;
	void yyerror(const char *s);
	 int token_id=0 ;
	std::ofstream tokensFile("Output.txt");
	
%}
 
%token MAIN LOOP NUM OPERATOR_A OPERATOR_R OPERATOR_U OPERATOR_E IDENTIFIER BOOL INPUT OUTPUT STRING IF ELSE ELSEIF IMPORT RETURN YES NO TERMINATOR ERROR COMMENT OPEN_BR OPEN_PR CLOSE_BR CLOSE_PR HEADER_FILE BOOL_YES BOOL_NO OTHER SEMICOLON  

%type <keyword> MAIN
%type <keyword> LOOP
%type <keyword> BOOL
%type <keyword> INPUT
%type <keyword> OUTPUT
%type <keyword> IF
%type <keyword> ELSE
%type <keyword> ELSEIF
%type <keyword> IMPORT
%type <keyword> RETURN
%type <keyword> YES
%type <keyword> NO
%type <datatype> NUM
%type <op> OPERATOR_A
%type <op> OPERATOR_R
%type <op> OPERATOR_U
%type <op> OPERATOR_E
%type <identifier> IDENTIFIER
%type <charStr> STRING
%type <terminator> TERMINATOR
%type <other> OTHER
%type <error> ERROR
%type <comment> COMMENT
%type <openBr> OPEN_BR
%type <openPr> OPEN_PR
%type <closeBr> CLOSE_BR
%type <closePr> CLOSE_PR
%type <headerFile> HEADER_FILE
%type <boolYes> BOOL_YES
%type <boolNo> BOOL_NO 


%union {
	int datatype;
	char *op;
	char *keyword;
	char *identifier;
	char *charStr;
	char *terminator;
	char *error;
	char *other;
	char *comment;
	char *openBr;
	char *openPr;
	char *closeBr;
	char *closePr;
	char *headerFile;
	char *boolYes;
	char *boolNo;
}
	
%%
undefined:
 MAIN undefined {
  cout << "main function detected: " << $1 << endl;
  token_id++;
  tokensFile <<"token_id_" << token_id << " " << $1 << " main function" << endl;
  }
  |
 LOOP undefined {
  cout << "loop detected: " << $1 << endl;
  token_id++;
  tokensFile <<"token_id_" << token_id << " " << $1 << " loop" << endl;
  }
  |
 BOOL undefined {
  cout << "bool datatype detected: " << $1 << endl;
  token_id++;
  tokensFile <<"token_id_" << token_id << " " << $1 << " bool datatype" << endl;
  }
  |
 INPUT undefined {
  cout << "input detected: " << $1 << endl;
  token_id++;
  tokensFile <<"token_id_" << token_id << " " << $1 << " input" << endl;
  }
  |
 OUTPUT undefined{
  cout << "output detected: " << $1 << endl;
  token_id++;
  tokensFile <<"token_id_" << token_id << " " << $1 << " output" << endl;
  }
  |
 IF undefined{
  cout << "condition detected: " << $1 << endl;
  token_id++;
  tokensFile <<"token_id_" << token_id << " " << $1 << " condition" << endl;
  } 
  |
 ELSE undefined{
  cout << "condition detected: " << $1 << endl;
  token_id++;
  tokensFile <<"token_id_" << token_id << " " << $1 << " condition" << endl;
  }
  |
 ELSEIF undefined{
  cout << "nested condition detected: " << $1 << endl;
  token_id++;
  tokensFile <<"token_id_" << token_id << " " << $1 << " nested condition" << endl;
  } 
  |
 IMPORT undefined{
  cout << "module detected: " << $1 << endl;
  token_id++;
  tokensFile <<"token_id_" << token_id << " " << $1 << " module" << endl;
  }
  |
 RETURN undefined {
  cout << "exit gate detected: " << $1 << endl;
  token_id++;
  tokensFile <<"token_id_" << token_id << " " << $1 << " exit gate" << endl;
  }
  |
 YES undefined{
  cout << "bool value detected: " << $1 << endl;
  token_id++;
  tokensFile <<"token_id_" << token_id << " " << $1 << " bool value" << endl;
  }
  |
 NO undefined{
  cout << "bool value detected: " << $1 << endl;
  token_id++;
  tokensFile <<"token_id_" << token_id << " " << $1 << " bool value" << endl;
  }
  |
 NUM undefined {
  cout << "number detected: " << $1 << endl;
  token_id++;
  tokensFile <<"token_id_" << token_id << " " << $1 << " number" << endl;
  }
  
 | STRING undefined {
  cout << "charStr detected: " << $1 << endl;
  token_id++;
  tokensFile << "token_id_" << token_id << " " << $1 << " charStr" << endl;
  }

  | OPERATOR_A undefined {
  cout << "arithmetic operator detected: " << $1 << endl;
  token_id++;
  tokensFile << "token_id_" << token_id << " " << $1 << " arithmetic operator" << endl;
  }

  | OPERATOR_R undefined {
  cout << "relational operator detected: " << $1 << endl;
  token_id++;
  tokensFile << "token_id_" << token_id << " " << $1 << " relational operator" << endl;
  }

  | OPERATOR_U undefined {
  cout << "unary operator detected: " << $1 << endl;
  token_id++;
  tokensFile << "token_id_" << token_id << " " << $1 << " unary operator" << endl;
  }
  | OPERATOR_E undefined {
  cout << "assignment operator detected: " << $1 << endl;
  token_id++;
  tokensFile << "token_id_" << token_id << " " << $1 << " assignment operator" << endl;
  }

  | IDENTIFIER undefined {
  cout << "identifier detected: " << $1 << endl;
  token_id++;
  tokensFile << "token_id_" << token_id << " " << $1 << " identifier" << endl;
  }

   | TERMINATOR undefined {
  cout << "terminator detected: " << $1 << endl;
  token_id++;
  tokensFile << "token_id_" << token_id << " " << $1 << " terminator" << endl;
  }

   | COMMENT undefined {
  cout << "comment detected: " << $1 << endl;
  token_id++;
  tokensFile << "token_id_" << token_id << " " << $1 << " comment" << endl;
   }
   
   | OPEN_BR undefined {
  cout << "open bracket detected: " << $1 << endl;
  token_id++;
  tokensFile << "token_id_" << token_id << " " << $1 << " open bracket" << endl;
  }

   | OPEN_PR undefined { 
  cout << "open parenthesis detected: " << $1 << endl;
  token_id++;
  tokensFile << "token_id_" << token_id << " " << $1 << " open parenthesis" << endl;
  }
   | CLOSE_BR undefined {
  cout << "close bracket detected: " << $1 << endl;
  token_id++;
  tokensFile << "token_id_" << token_id << " " << $1 << " close bracket" << endl;
  }

   | CLOSE_PR undefined {
  cout << "close parenthesis detected: " << $1 << endl;
  token_id++;
  tokensFile << "token_id_" << token_id << " " << $1 << " close parenthesis" << endl;
  }
   | HEADER_FILE undefined{
  cout << "header file detected: " << $1 << endl;
  token_id++;
  tokensFile << "token_id_" << token_id << " " << $1 << " keyword" << endl;
  }
   | OTHER undefined{
	  cout << "Lexical Error : token not defined: " << $1 << endl;
    tokensFile << "Lexical Error : token not defined: " << $1 << endl;
  }
  |
  MAIN {
  cout << "main function detected: " << $1 << endl;
  token_id++;
  tokensFile <<"token_id_" << token_id << " " << $1 << " main function" << endl;
  }
  |
  LOOP {
  cout << "loop detected: " << $1 << endl;
  token_id++;
  tokensFile <<"token_id_" << token_id << " " << $1 << " loop" << endl;
  }
  |
  BOOL {
  cout << "bool datatype detected: " << $1 << endl;
  token_id++;
  tokensFile <<"token_id_" << token_id << " " << $1 << " bool datatype" << endl;
  }
  |
  INPUT {
  cout << "input detected: " << $1 << endl;
  token_id++;
  tokensFile <<"token_id_" << token_id << " " << $1 << " input" << endl;
  }
  |
 OUTPUT {
  cout << "output detected: " << $1 << endl;
  token_id++;
  tokensFile <<"token_id_" << token_id << " " << $1 << " output" << endl;
  }
  |
 IF {
  cout << "condition detected: " << $1 << endl;
  token_id++;
  tokensFile <<"token_id_" << token_id << " " << $1 << " condition" << endl;
  } 
  |
 ELSE {
  cout << "condition detected: " << $1 << endl;
  token_id++;
  tokensFile <<"token_id_" << token_id << " " << $1 << " condition" << endl;
  }
  |
 ELSEIF {
  cout << "nested condition detected: " << $1 << endl;
  token_id++;
  tokensFile <<"token_id_" << token_id << " " << $1 << " nested condition" << endl;
  } 
  |
 IMPORT {
  cout << "module detected: " << $1 << endl;
  token_id++;
  tokensFile <<"token_id_" << token_id << " " << $1 << " module" << endl;
  }
  |
 RETURN {
  cout << "exit gate detected: " << $1 << endl;
  token_id++;
  tokensFile <<"token_id_" << token_id << " " << $1 << " exit gate" << endl;
  }
  | YES {
  cout << "bool value detected: " << $1 << endl;
  token_id++;
  tokensFile <<"token_id_" << token_id << " " << $1 << " bool value" << endl;
  }
  | NO  {
  cout << "bool value detected: " << $1 << endl;
  token_id++;
  tokensFile <<"token_id_" << token_id << " " << $1 << " bool value" << endl;
  }

  | NUM {
  cout << "number detected: " << $1 << endl;
  token_id++;
  tokensFile << "token_id_" << token_id << " " << $1 << " number" << endl;
  }

 | STRING {
  cout << "charStr detected: " << $1 << endl;
  token_id++;
  tokensFile << "token_id_" << token_id << " " << $1 << " charStr" << endl;
  }

 | OPERATOR_A {
  cout << "arithmetic operator detected: " << $1 << endl;
  token_id++;
  tokensFile << "token_id_" << token_id << " " << $1 << " arithmetic operator" << endl;
  }

 | OPERATOR_R {
  cout << "relational operator detected: " << $1 << endl;
  token_id++;
  tokensFile << "token_id_" << token_id << " " << $1 << " relational operator" << endl;
  }

 | OPERATOR_U {
  cout << "unary operator detected: " << $1 << endl;
  token_id++;
  tokensFile << "token_id_" << token_id << " " << $1 << " unary operator" << endl;
  }
 | OPERATOR_E {
  cout << "assignment operator detected: " << $1 << endl;
  token_id++;
  tokensFile << "token_id_" << token_id << " " << $1 << " assignment operator" << endl;
  }

 | IDENTIFIER {
  cout << "identifier detected: " << $1 << endl;
  token_id++;
  tokensFile << "token_id_" << token_id << " " << $1 << " identifier" << endl;
  }
    
 | TERMINATOR {
  cout << "terminator detected: " << $1 << endl;
  token_id++;
  tokensFile << "token_id_" << token_id << " " << $1 << " terminator" << endl;
  }

 | COMMENT  {
  cout << "comment detected: " << $1 << endl;
  token_id++;
  tokensFile << "token_id_" << token_id << " " << $1 << " comment" << endl;
  }
  
 | OPEN_BR {
  cout << "open bracket detected: " << $1 << endl;
  token_id++;
  tokensFile << "token_id_" << token_id << " " << $1 << " open bracket" << endl;
  }
  
  | OPEN_PR {
  cout << "open parenthesis detected: " << $1 << endl;
  token_id++;
  tokensFile << "token_id_" << token_id << " " << $1 << " open parenthesis" << endl;
  }
  
 | CLOSE_BR {
  cout << "close bracket detected: " << $1 << endl;
  token_id++;
  tokensFile << "token_id_" << token_id << " " << $1 << " close bracket" << endl;
  }

  | CLOSE_PR {
  cout << "close parenthesis detected: " << $1 << endl;
  token_id++;
  tokensFile << "token_id_" << token_id << " " << $1 << " close parenthesis" << endl;
  }
  

 | HEADER_FILE {
  cout << "header file detected: " << $1 << endl;
  token_id++;
  tokensFile << "token_id_" << token_id << " " << $1 << " keyword" << endl;
  } 
  
  | OTHER {
	  cout << "Lexical Error : token not defined: " << $1 << endl;
    tokensFile << "Lexical Error : token not defined: " << $1 << endl;
  }
  
;
%%
	
int main(int, char**){
		FILE *myfile = fopen("input.un","r");
		
		if (!myfile){
			cout << "I can't open a file" << endl;
			return -1;
		}
		yyin = myfile;
		if(yyparse()==0){
			cout << "Parsing Successful !" << endl;
		}
    {tokensFile.close();}
}
void yyerror(const char *s){
		cout << "Parsing Failed ! found " << s << " at line " << lineno <<endl;
    tokensFile << "Parsing Failed ! found " << s << " at line " << lineno <<endl;
		exit(-1);
}
