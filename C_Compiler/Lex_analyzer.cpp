/*
uint get_keyword_index(); - получить индекс текущего токена
void set_keyword_index(uint index); - изменить индекс текущего токена
void set_input_stream(char* input); - установить начальные значения
KeywordsLexeme get_next_token(); - получить следующий токен
*/
#pragma once
#include "Lex_analyzer.h"
static uint keyword_index;
static string input_code;
static uint stopped_index;

void set_keyword_index(uint index) { keyword_index = index; }
uint get_keyword_index() { return keyword_index; }

void set_input_stream(string input_cod) 
{
	input_code = input_cod;
	stopped_index = 0;
	keyword_index = 0;
}

KeywordsLexeme get_next_token() 
{
	return "Hey all worked";
}