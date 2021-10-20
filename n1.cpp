#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>

int main(){
	
	std::vector<std::string> words;
	std::string line;
	std::getline(std::cin, line);
	
	std::istringstream str(line);
	std::string word;
	while(str >> word)	words.push_back(word);
	
	bool isPos = 1;
	float avr = 0;
	
	for(int i = 0; i < words.size();i++){
		int gr = std::stoi(words[i]);
		avr += gr;
		if(gr == 1) {
			isPos = 0;
			break;
		}
	}
	
	if(isPos)	{
	    std::cout << "Uspeh je pozitiven, in je: "; printf("%g\n", avr/words.size()); 
	    
	} else std::cout << "Uspeh je negativen.\n";
}
