#pragma once
#include "parser.h"
void C_parser(string input_code)
{
	set_input_stream(input_code);
	token_lexeme tk;
	tk = get_next_token();
	cout << tk.value << ", " << tk.lexeme << endl;
	tk = get_next_token();
	cout << tk.value << ", " << tk.lexeme << endl;
	tk = get_next_token();
	cout << tk.value << ", " << tk.lexeme << endl;
	tk = get_next_token();
	cout << tk.value << ", " << tk.lexeme << endl;
	tk = get_next_token();
	cout << tk.value << ", " << tk.lexeme << endl;
	tk = get_next_token();
	cout << tk.value << ", " << tk.lexeme << endl;
	tk = get_next_token();
	cout << tk.value << ", " << tk.lexeme << endl;
	tk = get_next_token();
	cout << tk.value << ", " << tk.lexeme << endl;
	tk = get_next_token();
	cout << tk.value << ", " << tk.lexeme << endl;
	tk = get_next_token();
	cout << tk.value << ", " << tk.lexeme << endl;
	tk = get_next_token();
	cout << tk.value << ", " << tk.lexeme << endl;
	tk = get_next_token();
	cout << tk.value << ", " << tk.lexeme << endl;
}