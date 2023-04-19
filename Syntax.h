#ifndef SYNTAX_H
#define SYNTAX_H

#include "tokenList.h"
#include <vector>

extern std::vector<int> evalPoints;

int checkSyntax(TokenList* tkList);

int program(TokenList* tkList);
int variables(TokenList* tkList);
int idList(TokenList* tkList);
int body(TokenList* tkList);
int statementList(TokenList* tkList);
int statement(TokenList* tkList);
int assignStatement(TokenList* tkList);
int ifStatement(TokenList* tkList);
int printStatement(TokenList* tkList);
int switchStatement(TokenList* tkList);
int whileStatement(TokenList* tkList);
int expression(TokenList* tkList);
int conditional(TokenList* tkList);
int primary(TokenList* tkList);
int op(TokenList* tkList);
int relationalOperator(TokenList* tkList);
int caseList(TokenList* tkList);
int case(TokenList* tkList);
int defaultCase(TokenList* tkList);


#endif