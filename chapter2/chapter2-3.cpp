#include <iostream>
#include <stack>
#include <string>

using namespace std;

void trans_polish_notation(string);
int opr_rank(char);
	
int main(){

	string s;

	cin >> s;

	trans_polish_notation(s);
	
	return 0;
}

void trans_polish_notation(string str){
	stack<char> opr;
	
	for(int i = 0; i < str.size(); ++i){
		char tmp = str[i];
		if(tmp == '+' || tmp == '-' || tmp == '*'){
			while(!opr.empty() && opr_rank(opr.top()) > opr_rank(tmp)){
					cout << opr.top();
					opr.pop();
			}
			opr.push(tmp);
		} else {
			// 演算数のときはそのまま出力
			cout << tmp;
		}
	}

	while(!opr.empty()){
		cout << opr.top();
		opr.pop();
	}

}

// おおきいと優先度が高い
int opr_rank(char str){
	switch(str){
		case '+':
			return 1;
		case '-':
			return 1;
		case '*':
			return 3;
	}
	return 0;
}
