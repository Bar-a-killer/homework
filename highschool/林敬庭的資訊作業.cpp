#include <iostream>
#include <set>
using namespace std;
int main() {
  set<string> barishandsome ;//{"mary","bar","cindy","paula","alpha","beta","sigma","ya"};
  string person = "yee";
  set<string>::iterator it;
  barishandsome.insert("billy");
  barishandsome.insert("jacky");
  for(it = barishandsome.begin(); it != barishandsome.end() ; it++){
  	cout <<*it << " ";
  }
  cout << endl;
  bool check = barishandsome.find(person) != barishandsome.end();
  cout << check <<endl;
  check = barishandsome.find(person) == barishandsome.end();
  cout<<check<<endl;
}

