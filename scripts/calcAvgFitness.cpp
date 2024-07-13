#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  ifstream file("in/" + string(argv[1]) + ".txt");
    
    if (!file.is_open()) {
      cerr << "Failed to open the file." << endl;
      return 1;
    }

    vector<vector<double>> bestFit;
    vector<vector<double>> avgFit;
    vector<double> testBest;
    vector<double> testAvg;
    
    string line;
    while (getline(file, line)) {
      istringstream ss(line);
      string token;

      getline(ss, token, ';');
      if (token == "Generation")
        continue;
      else if (token == "#") {
        bestFit.push_back(testBest);
        avgFit.push_back(testAvg);
        testBest.clear();
        testAvg.clear();
        continue;
      }
      getline(ss, token, ';');
      double bestFitness = stod(token);
      testBest.push_back(bestFitness);
      getline(ss, token, ';');
      double avgFitness = stod(token);
      testAvg.push_back(avgFitness);
    }
    file.close();
    cout << "Best Fitness" << endl;
    for (unsigned int i = 0; i < bestFit[0].size(); i++) {
      double temp = 0;
      for (unsigned int j = 0; j < bestFit.size(); j++) {
        temp += bestFit[j][i];
      }
      cout << temp / 5 << endl;
    }
    cout << endl;
    cout << "Average Fitness" << endl;
    for (unsigned int i = 0; i < avgFit[0].size(); i++) {
      double temp = 0;
      for (unsigned int j = 0; j < avgFit.size(); j++) {
        temp += avgFit[j][i];
      }
      cout << temp / 5 << endl;
    }

  return 0;
}