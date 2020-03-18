#ifndef _LEXICAL_ANALYZER_CPP_INCLUDE
#define _LEXICAL_ANALYZER_CPP_INCLUDE
#include "Definitions.h"
#include "LexicalAnalyzer.h"

// структура которая обеспечивает поиск кода лексемы
// по ее имени 
struct keywords
{
	// имя ключевого слова
	const char *name;
	// код ключевого слова
	int code;
}
kpp_words[] = {
	{ "define", KPP_DEFINE },
	{ "error",  KPP_ERROR  },
	{ "undef",  KPP_UNDEF  },
	{ "elif",   KPP_ELIF   },
	{ "if",		KPP_IF     },
	{ "include",KPP_INCLUDE},
	{ "else",   KPP_ELSE   },
	{ "ifdef",  KPP_IFDEF  },
	{ "line",   KPP_LINE   },
	{ "endif",  KPP_ENDIF  },
	{ "ifndef", KPP_IFNDEF },
	{ "pragma", KPP_PRAGMA }
},

c_words[] = {
	{ "auto", KWAUTO }, { "break", KWBREAK },
	{ "case", KWCASE }, { "char",  KWCHAR },
	{ "const", KWCONST }, { "continue", KWCONTINUE },
	{ "default", KWDEFAULT }, { "do", KWDO },
	{ "double", KWDOUBLE }, { "else", KWELSE },
	{ "enum", KWENUM },	{ "extern", KWEXTERN },
	{ "float", KWFLOAT }, { "for", KWFOR },
	{ "goto", KWGOTO }, { "if", KWIF },
	{ "int", KWINT }, { "long", KWLONG },
	{ "register", KWREGISTER }, { "return", KWRETURN },
	{ "short", KWSHORT }, { "signed", KWSIGNED },
	{ "sizeof", KWSIZEOF },  { "static", KWSTATIC },
	{ "struct", KWSTRUCT }, { "switch", KWSWITCH },
	{ "typedef", KWTYPEDEF }, { "union", KWUNION },
	{ "unsigned", KWUNSIGNED }, { "void", KWVOID },
	{ "volatile", KWVOLATILE }, { "while", KWWHILE }
};


#endif // end  _LEXICAL_ANALYZER_CPP_INCLUDE