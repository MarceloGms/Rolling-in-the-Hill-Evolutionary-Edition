#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  ifstream file("en/" + string(argv[1]) + ".txt");
    
    if (!file.is_open()) {
      cerr << "Failed to open the file." << endl;
      return 1;
    }

    vector<vector<double>> bestFit;
    vector<vector<double>> avgFit;
    vector<vector<double>> forces;
    vector<vector<double>> distance;
    vector<double> testBest;
    vector<double> testAvg;
    vector<double> testForces;
    vector<double> testDist;
    
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
        forces.push_back(testForces);
        distance.push_back(testDist);
        testBest.clear();
        testAvg.clear();
        testForces.clear();
        testDist.clear();
        continue;
      }
      getline(ss, token, ';');
      double bestFitness = stod(token);
      testBest.push_back(bestFitness);
      getline(ss, token, ';');
      double avgFitness = stod(token);
      testAvg.push_back(avgFitness);
      for (int i = 0; i < 3; i++)
        getline(ss, token, ';');
      getline(ss, token, ';');
      double dist = stod(token);
      testDist.push_back(dist);

      for (int i = 0; i < 3; i++)
        getline(ss, token, ';');
      getline(ss, token, '\n');
      double sumForces = stod(token);
      testForces.push_back(sumForces);
      
    }
    file.close();
    cout << "Best Fitness" << endl;
    for (unsigned int i = 0; i < bestFit[0].size(); i++) {
      double temp = 0;
      for (unsigned int j = 0; j < bestFit.size(); j++) {
        temp += bestFit[j][i];
      }
      cout << temp / 8 << endl;
    }
    cout << endl;
    cout << "Average Fitness" << endl;
    for (unsigned int i = 0; i < avgFit[0].size(); i++) {
      double temp = 0;
      for (unsigned int j = 0; j < avgFit.size(); j++) {
        temp += avgFit[j][i];
      }
      cout << temp / 8 << endl;
    }
    cout << endl;
    cout << "Distance" << endl;
    for (unsigned int i = 0; i < distance[0].size(); i++) {
      double temp = 0;
      for (unsigned int j = 0; j < distance.size(); j++) {
        temp += distance[j][i];
      }
      cout << temp / 8 << endl;
    }
    cout << endl;
    cout << "SumForces" << endl;
    for (unsigned int i = 0; i < forces[0].size(); i++) {
      double temp = 0;
      for (unsigned int j = 0; j < forces.size(); j++) {
        temp += forces[j][i];
      }
      cout << temp / 8 << endl;
    }

  return 0;
}