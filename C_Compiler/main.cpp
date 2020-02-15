#include "parser.h"

int main(int argc, char **argv) {
	string code = {"int main() { return 0; }"};
	C_parser(code);
	system("pause");
}