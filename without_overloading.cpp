#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class fileRA{
private:
  string fname;
  fstream myFile;
public:  
  fileRA(const string &filename){
    fname=filename;
    myFile.open(fname,ios::in|ios::out);
  }
  void write_at(int pos, char ch){
    myFile.seekp(pos);
    myFile.put(ch);
  }
  char read_at(int pos){
    myFile.seekg(pos);
    return myFile.get();
  }
  int get_size(){
    myFile.seekg(0, ios::end);
    return myFile.tellg();
  }
};
int main(){
  fileRA fobj("f.txt");
  fobj.write_at(4,'A');
  for(unsigned int i=0;i<fobj.get_size();i++){
    cout << fobj.read_at(i);
  }
  char c = fobj.read_at(4);
  cout << "Char is = " << c << std::endl;
}