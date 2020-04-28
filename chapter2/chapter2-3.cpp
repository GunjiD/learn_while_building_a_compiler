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
		if(tmp == '+' || tmp == '*'){ 
			if(!opr.empty() && opr_rank(tmp) >= opr_rank(opr.top())){ 
					opr.push(tmp);
				} else {
					while(!opr.empty() && opr_rank(opr.top()) >= opr_rank(tmp)){
						cout << opr.top();
						opr.pop();
					}
					opr.push(tmp);
			}
		} else { 
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
			return 2;
	}
	return 0;
}
