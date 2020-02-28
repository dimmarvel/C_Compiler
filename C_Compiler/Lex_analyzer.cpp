#pragma once
#include "Lex_analyzer.h"
#define DEBUG

static uint keyword_index;						/*
							Текущий индекс парсинга.*/
static string input_code;						/*
							Здесь хранится код на языке С.*/
static uint stopped_index;						/*
							Хранит значение символа на котором остановился парсер.*/
static vector <token_lexeme> token_lexeme_vec;	/*
							Хранит набор спаршеных токен-лексем*/



void set_keyword_index(uint index)
{
	keyword_index = index;
}
uint get_keyword_index()
{
	return keyword_index;
}
void set_input_stream(string input_cod)
{
	input_code = input_cod;
	stopped_index = 0;
	keyword_index = 0;
}
bool isKeyword(string word) {

	for (int i = 0; i < keywords_lexeme.size(); i++)
		if (keywords_lexeme[i] == word)
			return true;
	return false;
}
token_lexeme get_next_token()				
{
	token_lexeme temp_token_lexeme = {"undefind", UNDEFIND};
	KeywordsLexeme token;
	KeywordsLexeme ch_token;
	keyword_index = stopped_index;

	while (keyword_index <= input_code.size()) {
		if (input_code[keyword_index] != '\n' && input_code[keyword_index] != ' ') {
			
			token += input_code[keyword_index];
			ch_token = input_code[keyword_index];
			
			if (isKeyword(ch_token)) {
				++keyword_index;
				string temp_token = ch_token + input_code[keyword_index];
				
				if (isKeyword(temp_token)) {
					stopped_index = ++keyword_index;
					temp_token_lexeme.value = temp_token;
					string temp_IDENTIFIER = token;
					temp_IDENTIFIER.erase(temp_IDENTIFIER.size()-1, 1);
					cout << "IDENTIFIER (" + temp_IDENTIFIER + ")"<< endl;
					return temp_token_lexeme;
				}
				
				stopped_index = keyword_index;
				temp_token_lexeme.value = ch_token;
				return temp_token_lexeme;
			}
			else if (isKeyword(token)) {
				stopped_index = ++keyword_index;
				temp_token_lexeme.value = token;
				return temp_token_lexeme;
			}
		}
		else {
#ifdef DEBUG
			if (token != "" && token != " ") {
				cout << "UNDEFINE - token(" << ch_token << ")" << endl;
				cout << "UNDEFINE - token(" << token << ")" << endl;
			}
#endif
			token = "";
		}
		keyword_index++;
	}
	stopped_index = keyword_index;
	temp_token_lexeme.value = token;
	cout << "ERROR (" << temp_token_lexeme.value << ")\n";
	return temp_token_lexeme;
}
TOKENS token_definition(){

	TOKENS some = UNDEFIND;
	return some;
}
template<> string TOKEN_definition(token_lexeme tk) {
	switch (tk.lexeme) {
	case OPEN_BRACE:
		tk.token_string = "OPEN_BRACE";
	case CLOSE_BRACE:
		tk.token_string = "CLOSE_BRACE";
	case OPEN_PARENTHESIS:
		tk.token_string = "OPEN_PARENTHESIS";
	case CLOSE_PAREN:
		tk.token_string = "CLOSE_PAREN";
	case SEMICOLON:
		tk.token_string = "SEMICOLON";
	case INT_KEYWORD:
		tk.token_string = "INT_KEYWORD";
	case RETURN_KEYWORD:
		tk.token_string = "RETURN_KEYWORD";
	case IDENTIFIER:
		tk.token_string = "IDENTIFIER";
	case INTEGER_LITERAL:
		tk.token_string = "INTEGER_LITERAL";
	case STRING_LITERAL:
		tk.token_string = "STRING_LITERAL";
	case END_OF_FILE:

	default:
		cout << "Not found lexeme." << endl;
		return "UNDEFIND";
	}
}