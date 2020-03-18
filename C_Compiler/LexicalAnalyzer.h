#ifndef _LEXICAL_ANALYZER_H_INCLUDE
#define _LEXICAL_ANALYZER_H_INCLUDE
#include "Definitions.h"
// коды лексем С++ 
enum C_TOKENS {

	// любое имя, кроме ключевых слов
	NAME = 257,

	// операторы
	ARROW, INCREMENT, DECREMENT, DOT_POINT, ARROW_POINT,
	LEFT_SHIFT, RIGHT_SHIFT, LESS_EQU, GREATER_EQU, EQUAL,
	NOT_EQUAL, LOGIC_AND, LOGIC_OR, MUL_ASSIGN, DIV_ASSIGN,
	PERCENT_ASSIGN, PLUS_ASSIGN, MINUS_ASSIGN,
	LEFT_SHIFT_ASSIGN, RIGHT_SHIFT_ASSIGN, AND_ASSIGN, XOR_ASSIGN,
	OR_ASSIGN, COLON_COLON, DOUBLE_SHARP, ELLIPSES,

	// ключевые слова
	KWASM, KWAUTO, KWBOOL, KWBREAK,
	KWCASE, KWCATCH, KWCHAR, KWCLASS,				// KWCATCH = 300
	KWCONST, KWCONST_CAST, KWCONTINUE, KWDEFAULT,
	KWDELETE, KWDO, KWDOUBLE, KWDYNAMIC_CAST,
	KWELSE, KWENUM, KWEXPLICIT, KWEXPORT,
	KWEXTERN, KWFALSE, KWFLOAT, KWFOR,
	KWFRIEND, KWGOTO, KWIF, KWINLINE,
	KWINT, KWLONG, KWMUTABLE, KWNAMESPACE,
	KWNEW, KWOPERATOR, KWPRIVATE, KWPROTECTED,
	KWPUBLIC, KWREGISTER, KWREINTERPRET_CAST, KWRETURN,
	KWSHORT, KWSIGNED, KWSIZEOF, KWSTATIC,
	KWSTATIC_CAST, KWSTRUCT, KWSWITCH, KWTEMPLATE,
	KWTHIS, KWTHROW, KWTRUE, KWTRY,
	KWTYPEDEF, KWTYPEID, KWTYPENAME, KWUNION,
	KWUNSIGNED, KWUSING, KWVIRTUAL, KWVOID,
	KWVOLATILE, KWWCHAR_T, KWWHILE
};

// коды лексем препроцессора
enum KPP_TOKENS {
	KPP_DEFINE = 257, KPP_ERROR, KPP_UNDEF,
	KPP_ELIF, KPP_IF, KPP_INCLUDE,
	KPP_ELSE, KPP_IFDEF, KPP_LINE,
	KPP_ENDIF, KPP_IFNDEF, KPP_PRAGMA
};


class LexicalAnalyzer {
private:
	fstream *in;
	const Position &curPos;
	CppReadFile *cppReadFile;
public:
	LexicalAnalyzer(fstream *Fptr, Position &p) :curPos(p) {
		cppReadFile = new CppReadFile(Fptr, p);
	}
};


class CppReadFile {
	fstream *in;
	Position &pos;
public:
	CppReadFile(fstream *Fin, Position &p) :in(Fin), pos(p) {}

	void operator++() {
		cout << in->get();
		pos.col++;
		pos.line++;
	}
};


class Lexem {
private:
	string buf;
	Position pos;
public:
	Lexem(const string &b, const Position &p) : buf(b), pos(p) {}
	//ТУТА
	const string GetBuf() {
		return buf;
	}

	const Position GetPos() {
		return pos;
	}

};
#endif // end  _LEXICAL_ANALYZER_H_INCLUDE