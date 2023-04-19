#include <stdio.h>
#include <vector>
#include "Syntax.h"
#include "token.h"
#include "tokenList.h"
#include "tokenType.h"

#define SUCCESS 1
#define FAIL	0

int a = 1;
std::vector<int> evalPoints;

int checkSyntax(TokenList* tkList)
{
    return program(tkList);
}

int program(TokenList* tkList)
{
	if(variables(tkList))
	{
		if(body(tkList))
		{
			return SUCCESS;
		}
	}
	return FAIL;
}

int variables(TokenList* tkList)
{
	if(idList(tkList))
	{
		if(tkList->GetToken(a)->GetType() == SEMICOLON)
		{
			a++;
			return SUCCESS;
		}
	}
}

int idList(TokenList* tkList)
{
	if(tkList->GetToken(a)->GetType() == ID)
	{
		a++;
		while(tkList->GetToken(a)->GetType() == COMMA)
		{
			a++;
			if(tkList->GetToken(a)->GetType() == ID)
			{
				a++;
			}
			else
			{
				return FAIL;
			}
		}

		return SUCCESS;
	}
	return FAIL;
}
		

int body(TokenList* tkList)
{
	if(tkList->GetToken(a)->GetType() == LeftBRACE)
	{
		a++;
		if(statementList(tkList))
		{
			if(tkList->GetToken(a)->GetType() == RightBRACE)
			{
				a++;
				return SUCCESS;
			}
		}
	}
	return FAIL;
}

int idList(TokenList* tkList)
{
	if(tkList->GetToken(a)->GetType() == ID)
	{
		a++;
		while(tkList->GetToken(a)->GetType() == COMMA)
		{
			a++;
			if(tkList->GetToken(a)->GetType() == ID)
			{
				a++;
			}
			else
			{
				return FAIL;
			}
		}

		return SUCCESS;
	}
	return FAIL;
}

int statementList(TokenList* tkList)
{
	if(statement(tkList))
	{
		while(statement(tkList))
		{

		}
		return SUCCESS;
	}
	return FAIL;
}

int statement(TokenList* tkList)
{
	if(whileStatement(tkList) 
	|| assignStatement(tkList) 
	|| switchStatement(tkList)
	|| printStatement(tkList))
	{
		return SUCCESS;
	}
	return FAIL;
}

int whileStatement(TokenList* tkList)
{
	if(tkList->GetToken(a)->GetType() == WHILE)
	{
		a++;
		if(conditional(tkList))
		{
			if(body(tkList))
			{
				return SUCCESS;
			}
		}
	}
	return FAIL;
}

int assignStatement(TokenList* tkList)
{
	if(tkList->GetToken(a)->GetType() == ID)
	{
		a++;
		if(tkList->GetToken(a)->GetType() == EQUAL)
		{
			a++;
			if(primary(tkList) || expression(tkList)
			{
				if(tkList->GetToken(a)->GetType() == SEMICOLON)
				{
					a++;
					return SUCCESS;
				}
			}
		}
	}
	return FAIL;
}

int ifStatement(TokenList* tkList)
{
	if(tkList->GetToken(a)->GetType() == IF)
	{
		a++;
		if(conditional(tkList))
		{
			if(body(tkList))
			{
				return SUCCESS;
			}
		}
	}
	return FAIL;
}

int printStatement(TokenList* tkList)
{
	if(tkList->GetToken(a)->GetType() == PRINT)
	{
		a++;
		if(tkList->GetToken(a)->GetType() == ID)
		{
			a++;
			if(tkList->GetToken(a)->GetType() == SEMICOLON)
			{
				a++;
				return SUCCESS;
			}
		}
	}
	return FAIL;
}

int switchStatement(TokenList* tkList)
{
	if(tkList->GetToken(a)->GetType() == SWITCH)
	{
		a++;
		if(tkList->GetToken(a)->GetType() == ID)
		{
			a++;
			if(tkList->GetToken(a)->GetType() == LeftBRACE)
			{
				a++;
				if(caseList(tkList))
				{
					if(defaultCase(tkList))
					{
						if(tkList->GetToken(a)->GetType() == RightBRACE)
						{
							a++;
							return SUCCESS;
						}
					}
					else
					{
						if(tkList->GetToken(a)->GetType() == RightBRACE)
						{
							a++;
							return SUCCESS;
						}
					}
				}
			}
		}
	}
	return FAIL;
}

int expression(TokenList* tkList)
{
	if(primary(tkList))
	{
		if(op(tkList))
		{
			if(primary(tkList))
			{
				return SUCCESS;
			}
		}
	}
	return FAIL;
}

int conditional(TokenList* tkList)
{
	if(primary(tkList)
	{
		if(relationalOperator(tkList))
		{
			if(primary(tkList))
			{
				return SUCCESS;
			}
		}
	}
	return FAIL;
}

int primary(TokenList* tkList)
{
	if(tkList->GetToken(a)->GetType() == ID 
	|| tkList->GetToken(a)->GetType() == NUM)
	{
		a++;
		return SUCCESS;
	}
	return FAIL;
}

int op(TokenList* tkList)
{
	if(tkList->GetToken(a)->GetType() == PLUS 
	|| tkList->GetToken(a)->GetType() == MINUS
	|| tkList->GetToken(a)->GetType() == MULT
	|| tkList->GetToken(a)->GetType() == DIV)
	{
		a++;
		return SUCCESS;
	}
	return FAIL;
}

int relationalOperator(TokenList* tkList)
{
	if(tkList->GetToken(a)->GetType() == NotEQUAL
	|| tkList->GetToken(a)->GetType() == GREATER
	|| tkList->GetToken(a)->GetType() == LESS)
	{
		a++;
		return SUCCESS;
	}
	return FAIL;
}

int caseList(TokenList* tkList)
{
	if(case(tkList))
	{
		while(case(tkList))
		{
		
		}
		return SUCCESS;
	}
	return FAIL;
}

int case(TokenList* tkList)
{
	if(tkList->GetToken(a)->GetType() == CASE)
	{
		a++;
		if(tkList->GetToken(a)->GetType() == NUM)
		{
			a++;
			if(tkList->GetToken(a)->GetType() == COLON)
			{
				a++;
				if(body(tkList))
				{
					return SUCCESS;
				}
			}
		}
	}
	return FAIL;
}

int defaultCase(TokenList* tkList)
{
	if(tkList->GetToken(a)->GetType() == DEFAULT)
	{
		a++;
		if(tkList->GetToken(a)->GetType() == COLON)
		{
			a++;
			if(body(tkList))
			{
				return SUCCESS;
			}
		}
	}
	return FAIL;
}