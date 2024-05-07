#include <iostream>
#include <string>


std::string encrypt(std::string s, char tabelle[2][26]){

	int n = s.length();
	std::string code = s;

	for(int i=0; i<n; i++){
		for(int j=0; j<26; j++){
			if(s[i] == tabelle[0][j]){
				code[i] = tabelle[1][j];
			}
		}
	}

	return code;

	}

std::string decrypt(std::string s, char tabelle[2][26]){

	int n = s.length();
		std::string code = s;

		for(int i=0; i<n; i++){
			for(int j=0; j<26; j++){
				if(s[i] == tabelle[1][j]){
					code[i] = tabelle[0][j];
				}
			}
		}

		return code;
}

int main() {
	char lookup[2][26] = {
			{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'},
			{'N', 'F', 'A', 'W', 'Y', 'B', 'P', 'K', 'H', 'G', 'R', 'Q', 'V', 'I', 'T', 'Z', 'J', 'U', 'D', 'X', 'C', 'S', 'E', 'M', 'L', 'O'}
	};

	std::string wort;

	std::cout<<"Geben Sie ein Wort ein: "<<std::endl;
	std::cin>>wort;

	std::string code1 = encrypt(wort, lookup);
	std::string code2 = decrypt(code1, lookup);

	std::cout<<"Das verschlüsselte Wort ist :"<<code1<<std::endl;
	std::cout<<"Das Wort wieder entschlüsselt lautet: "<<code2<<std::endl;

	return 0;
}
