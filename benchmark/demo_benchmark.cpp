#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <sstream>      // stringstream
#include <vector>
#include "data_structure.hpp"

using namespace std;
using namespace itis;

const string absolutePathToInputFile = "C:/Users/PC/CLionProjects/semester-work-AA-Trees-by-DjangoGirls/dataset/data";
const string Operations[] = {"insert", "search", "remove"};
const string Amount[] = {"100", "500", "1000", "5000", "10000", "25000", "50000", "100000", "250000", "500000",
                         "750000", "1000000", "2500000", "5000000"};
ofstream result(absolutePathToInputFile + "/result.txt");

bool testing() {
  auto Tree = AATree();
  Tree.insert(22);
  if (!(Tree.search(22))) {return false;}
  Tree.removeData(22);
  return (!(Tree.search(22)));
}

int main() {

  if (!(testing())) {
    cout << "Testing failed" << endl;
    return 0;
  }

  for (const auto& amount : Amount) {
    result << "\t" << amount << endl;
    auto Tree = AATree();
    for (const string& operation : Operations) {
      auto path = (absolutePathToInputFile + "/" + operation + "/data(" + amount + ").txt");
      result << operation << "\t";

      ifstream file(path);
      string s;
      vector<int> intValues;

      for (file >> s; !file.eof(); file >> s) {
        intValues.push_back(stoi(s));
      }

      const auto time_point_before = chrono::high_resolution_clock::now();

      for (int value : intValues) {
        if (operation == "insert") {
          Tree.insert(value);
        }
        if (operation == "search") {
          Tree.search(value);
        }
        else {
          Tree.removeData(value);
        }
      }
      const auto time_point_after = chrono::high_resolution_clock::now();

      // переводим время в наносекунды
      const auto time_diff = time_point_after - time_point_before;
      const long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();

      result << "Time elapsed (ns): " << time_elapsed_ns << endl;
    }
  }
  return 0;
}
