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

  {
    std::vector<int> dist(v1.size());
    std::transform(v1.begin(), v1.end(), v2.begin(), dist.begin(), [](int const x, int const y){
      return std::abs(x - y);
    });
    std::cout << std::accumulate(dist.begin(), dist.end(), 0) << "\n";
  }

  {
    std::vector<int> sim(v1.size());
    std::transform(v1.begin(), v1.end(), sim.begin(), [&v2](int const x){
      return std::count(v2.begin(), v2.end(), x) * x;
    });
    std::cout << std::accumulate(sim.begin(), sim.end(), 0) << std::endl;
  }
  
  return 0;
}
