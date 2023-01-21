//main
#include <iostream>
#include "utils.h"
#include "shapes.h"
using namespace std;

int main() {
	enum errorList {
		UNKNOWN_CMD,
		MISSING_ARGS,
		INVALID_ARGS,
		DIMENSION_LIMIT_REACHED,
		NEGETIVE_DIMENSION,
		UNKNOWN_COORDS
		
	};
	Eval eval;
	Exceptions error;
	color(logo(), 14);
	
	string input;
	getline(cin, input);
	
	if (eval.confirm(input, 0, "--help")) {

	}
	else {
		
	}
}