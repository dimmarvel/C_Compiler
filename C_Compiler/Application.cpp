#include"Application.h"

App theAPP;

TranslationUnit::TranslationUnit(string ptr) {
	path = ptr;
	FILEptr->open(ptr);
	lexicalAnalyzer = new LexicalAnalyzer(FILEptr, currentPos);
	parser = new Parser(*lexicalAnalyzer);
}

void App::Make(){
	translationUnit = new TranslationUnit("some.txt");
}




int main() {


	system("pause");
}