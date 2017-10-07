#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <string>
#include <fstream>

int main(){
	srand(time(NULL));
	std::string base(".txt");
	int ind = 0;
	while(1){
		int n = (rand() % 22) + 5;
		int f = (rand() % 8) + 2;
		int counter = 0;
		std::ofstream outfile(std::to_string(ind++)+base);
		std::vector<char> v;
		outfile << n << std::endl;
		outfile << f << std::endl;
		outfile << 214748 << std::endl;
		for(int j = 0;j < n*n; j++){
			v.push_back('0'+ (rand() % f));
		}

		std::random_shuffle(v.begin(), v.end());

		for(int j=0;j<n*n;j++){
			if(counter++ == n){
				outfile << std::endl;
				counter = 1;
			}
			outfile << v.back();
			v.pop_back();
		}
	}

}