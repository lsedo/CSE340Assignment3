#include <stdio.h>
#include <stdlib.h>

#include "assignmentStatement.h"
#include "compiler.h"
#include "gotoStatement.h"
#include "ifStatement.h"
#include "printStatement.h"
#include "statementNode.h"
#include "token.h"
#include "tokenList.h"
#include "tokenType.h"
#include "programFile.h"
#include "Syntax.h"

#include <iostream>

#define PROGRAM_FILE_NAME	"c:\\CS Classes\\ASU - Teacher\\CSE 340\\Project 3\\Sample Program.txt"	// File with the program

// Executes the program.
void ExecuteProgram(StatementNode *program) {
	AssignmentStatement* curAssignment = NULL;	// Current assignment

	while (program != NULL) {
		switch (program->GetType()) {
			case STATEMENT_ASSIGN:	// Assignment
				curAssignment = (AssignmentStatement*)program;	// Current assignment

				curAssignment->GetLeftHandSide()->SetValue(curAssignment->GetRightHandSideValue());
				program = curAssignment->GetNextStatement();
				break;

			case STATEMENT_GOTO:	// Goto - do nothing, as only the next 
				program = ((GotoStatement*)program)->GetNextStatement();
				break;

			case STATEMENT_IF:	// If
				program = ((IfStatement*)program)->GetNextStatement();
				break;

			case STATEMENT_NONE:	// No operation
				program = program->GetNextStatement();
				break;

			case STATEMENT_PRINT:	// Print
				printf("%d\n", ((PrintStatement*)program)->GetID()->GetValue());
				program = program->GetNextStatement();
				break;
		}
//		program = program->GetNextStatement();
	}
}

// Runs the main program.
int main(int argc, char *argv[]) {
	StatementNode *program;	// Program

	ProgramFile prog;	// Current program
	TokenList *tokenList;	// List of tokens

	tokenList = prog.LoadFile((char*) "testing/sample2.txt");
	std::cout << checkSyntax(tokenList) << "\n";



//	program = parseGenerateIntermediateRepresentation(argv[1]);
//	program = parseGenerateIntermediateRepresentation((char*)PROGRAM_FILE_NAME);
//	ExecuteProgram(program);
	return 0;
}

StatementNode* parseGenerateIntermediateRepresentation(char *fileName)
{
	return NULL;
}