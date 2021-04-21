#include <iostream>

#include "data_structure.hpp"
#include <fstream>
#include "vector"
#include <chrono>

using namespace std;
using namespace itis;

int main()
{
  auto Tree = AATree();
  const string absolutePathToInputFile = "C:/Users/PC/CLionProjects/semester-work-AA-Trees-by-DjangoGirls/dataset/data";
  string path = (absolutePathToInputFile + "/search/data(100).txt");
  ifstream file(path);
  string s;
  vector<int> intValues;
  for (file >> s; !file.eof(); file >> s) {
    intValues.push_back(stoi(s));
  }
  for (int value : intValues) {
    Tree.insert(value);
  }
  const auto time_point_before = chrono::steady_clock::now();
  for (int value : intValues) {
    Tree.search(value);
  }
  const auto time_point_after = chrono::steady_clock::now();
  // переводим время в наносекунды
  const auto time_diff = time_point_after - time_point_before;

  const long long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();
  cout << "Time elapsed (ns): " << time_elapsed_ns << endl;
  return 0;
}