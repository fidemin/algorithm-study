#include <iostream>
#include <stack>

using namespace std;

bool bracketMatched(const string& formula) {
	const string opening("({["), closing(")}]");
	stack<char> openStack;

	for (int i = 0; i < formula.size(); i++) {
		if (opening.find(formula[i]) != string::npos) {
			openStack.push(formula[i]);
		} else {
			if (openStack.empty()) {
				return false;
			}

			if (opening.find(openStack.top()) != closing.find(formula[i])) {
				return false;
			}
			openStack.pop();
		}
	}

	return openStack.empty();
}

int main() {
	string f1 = "()()";
	assert(true == bracketMatched(f1));

	string f2 = "({[}])";
	assert(false == bracketMatched(f2));

	string f3 = "({}[(){}])";
	assert(true == bracketMatched(f3));

	string f4 = "({}))";
	assert(false == bracketMatched(f4));

	string f5 = "(({})";
	assert(false == bracketMatched(f5));
}
