#include<iostream>
#include<fstream>
using namespace std;

class TravellingSalesMan{
public:
    int const MAX = 999;
    int cities;
    int completed_visit;
    int distan[10][10];
    int DP[100][10];

int  TSP(int subset,int start){
  if(subset==completed_visit){      // checking whether all the cities are visited or not

    return distan[start][0];
  }
  if(DP[subset][start]!=-1){
     return DP[subset][start];
  }

  int answer = MAX;

  for(int city=0;city<cities;city++){
    if((subset&(1<<city))==0){
      int newAnswer = distan[start][city] + TSP( subset|(1<<city),city);
      answer = min(answer, newAnswer);
    }

  }
  return DP[subset][start] = answer;

}

};

int main()
{
    TravellingSalesMan s1;

    ifstream num_cities;
    num_cities.open("no_cities.txt");
    num_cities >>s1.cities;


    s1.completed_visit = (1<<s1.cities)-1;

    ifstream distance;
    distance.open("matrixinput.txt");

    for(int i=0; i<s1.cities; i++){
        for(int j=0; j<s1.cities; j++){
            distance >> s1.distan[i][j];
        }
    }

        for(int i=0;i<(1<<s1.cities);i++){
        for(int j=0;j<s1.cities;j++){
            s1.DP[i][j] = -1;
        }
    }

    int Distance_traveled = s1.TSP(1, 0);

    fstream result;
    result.open("output.txt", ios::out);
    result<<"Total number of cities: "<<s1.cities<<endl<<endl;
    result<<"Distance Matrix: "<<endl;
         for(int i=0; i<s1.cities; i++){
        for(int j=0; j<s1.cities; j++){
            result<<s1.distan[i][j]<<" ";

        }
        result<<endl;
   }
    result<<endl<<"Minimum Distance Traveled by you is "<<Distance_traveled;

return 0;

}
