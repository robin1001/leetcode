/* Date: 2015-07-10
 * Author: robin1001
 * Comment: accepted
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <string>

class Solution {
private:
	enum TokenType { TOKEN_UNKNOWN = 0, 
		TOKEN_LEFT_PARA, TOKEN_RIGHT_PARA, 
		TOKEN_ADD, TOKEN_SUB,
		TOKEN_MUL, TOKEN_DVI,
		TOKEN_NUMBER};
	TokenType type_;
	int number_;
	int cur_;
	std::string s_;
public:
	TokenType get_token() {
		while (s_[cur_] == ' ') cur_++;	
		switch (s_[cur_]) {
			case '(': cur_++; return TOKEN_LEFT_PARA;
			case ')': cur_++; return TOKEN_RIGHT_PARA;
			case '+': cur_++; return TOKEN_ADD;
			case '-': cur_++; return TOKEN_SUB;
			case '*': cur_++; return TOKEN_MUL;
			case '/': cur_++; return TOKEN_DVI;
		}
		if (s_[cur_] >= '0' && s_[cur_] <= '9') {
			number_ = 0;
			do {
				number_ = s_[cur_] - '0' + number_ * 10;
				cur_++;
			} while (s_[cur_] >= '0' && s_[cur_] <= '9');
			return TOKEN_NUMBER;
		}
		return TOKEN_UNKNOWN;
	}

	void match(TokenType t) {
		if (type_ == t) type_ = get_token();
		else {
			printf("exptected %d but get %d\n", t, type_);
			exit(-1);
		}
	}
	
	int expr() {
		int x = term();
		while (type_ == TOKEN_ADD || type_ == TOKEN_SUB) {
			if (type_ == TOKEN_ADD) {
				match(TOKEN_ADD); 
				x += term();	
			}
			else if (type_ == TOKEN_SUB) {
				match(TOKEN_SUB); 
				x -= term();
			}
		}
		return x;
	}

	int term() {
		int x = factor();	
		while (type_ == TOKEN_MUL || type_ == TOKEN_DVI) {
			if (type_ == TOKEN_MUL) {
				match(TOKEN_MUL); 
				x *= factor();	
			}
			else if (type_ == TOKEN_DVI) {
				match(TOKEN_DVI); 
				x /= factor();
			}
		}
		return x;
	}


	int factor() {
		if (type_ == TOKEN_NUMBER) {
			match(TOKEN_NUMBER);
			return number_;
		} else {
			match(TOKEN_LEFT_PARA);
			int x = expr();
			match(TOKEN_RIGHT_PARA);
			return x;
		}
	}

	int calculate(std::string s) {
		cur_ = 0;
		s_ = s;
		type_ = get_token();
		return expr();
	}
};

int main() {
	Solution solution;
	assert(7 == solution.calculate("3+2*2"));
	assert(5 == solution.calculate("3+5 / 2 "));
	assert(8 == solution.calculate("3*(1+1) + 5 / 2 "));
	assert(1 == solution.calculate("3/2"));
}
