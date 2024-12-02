#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using inds = std::pair<std::vector<int>&, std::vector<int>&>;

void parse_file(std::string const filename, inds file_inds){

  std::ifstream file(filename);
  int ind1, ind2;
  while(file >> ind1 >> ind2){
    file_inds.first.push_back(ind1);
    file_inds.second.push_back(ind2);
  }  
}

int main(){

  std::ifstream file("puzzle1_data.dat");
  std::vector<int> v1, v2;

  {
    inds ind_vectors(v1, v2);
    parse_file("puzzle1_data.dat", ind_vectors);
  }

  std::sort(v1.begin(), v1.end());
  std::sort(v2.begin(), v2.end());

  // Distance
  std::cout << std::transform_reduce(v1.begin(), v1.end(), v2.begin(), 0, std::plus<>(),
			             [](int const x, int const y){			  
                                       return std::abs(x-y);}) << std::endl;

  // Similarity
  std::cout << std::transform_reduce(v1.begin(), v1.end(), 0, std::plus<>(),
				     [&v2](int const x){
				       return std::count(v2.begin(), v2.end(), x) * x;
				     }) << std::endl;
  
  return 0;
}
