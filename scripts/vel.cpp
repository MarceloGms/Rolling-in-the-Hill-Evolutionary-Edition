#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  ifstream file("vel/" + string(argv[1]) + ".txt");
    
    if (!file.is_open()) {
      cerr << "Failed to open the file." << endl;
      return 1;
    }

    vector<vector<double>> bestTime;
    vector<double> testTime;
    
    string line;
    while (getline(file, line)) {
      istringstream ss(line);
      string token;

      getline(ss, token, ';');
      if (token == "Generation")
        continue;
      else if (token == "#") {
        bestTime.push_back(testTime);
        testTime.clear();
        continue;
      }
      for (int i = 0; i < 6; i++)
       getline(ss, token, ';');
      getline(ss, token, ';');
      double ellapsedTime = stod(token);
      testTime.push_back(ellapsedTime);
    }
    file.close();
    cout << "Ellapsed Time" << endl;
    for (unsigned int i = 0; i < bestTime[0].size(); i++) {
      double temp = 0;
      for (unsigned int j = 0; j < bestTime.size(); j++) {
        temp += bestTime[j][i];
      }
      cout << temp / 8 << endl;
    }

  return 0;
}