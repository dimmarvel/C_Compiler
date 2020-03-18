#ifndef _APPLICATION_H_
#define _APPLICATION_H_		

#include "Definitions.h"
#include "Limits.h"
#include "Application.h"
#include "LexicalAnalyzer.h"
#include "Parser.h"

// выход с ошибками
#define ERROR_EXIT_CODE		-1
// нормальное завершение приожени€
#define SUCCESS_EXIT_CODE	0


extern theAPP;

struct Position {
	unsigned line, col;
	Position(unsigned l = 0, unsigned c = 0) :line(0), col(0) {}
};

// класс объ€влен в LexicalAnalyzer.h
class LexicalAnalyzer; 

class TranslationUnit {
private:
	string path;
	bool isCompile;
	fstream *FILEptr;
	Parser *parser;
	Position currentPos;
	LexicalAnalyzer *lexicalAnalyzer;
public:
	TranslationUnit(string ptr);
	~TranslationUnit();
	Position GetPosition() const { return currentPos; }
};


class App {
private:
	TranslationUnit* translationUnit;
public:
	void Make();
};

int main() {
	system("pause");
}





#endif // _APPLICATION_H_
