#include <iostream>
#include <fstream>
using namespace std;

class LabelGenerator{
protected:
    string str;
    int num;
public:
    LabelGenerator(string s=" ", int n=0,string s2=" "){
        str=s;num=n;
    }
    int nextLabel(){
        cout<<str;
        return num++;
    }
};
class  FileLabelGenerator : public LabelGenerator{
private:
    string str2;
public:
    FileLabelGenerator(string s1,int n,string s2){
        str=s1;num=n;str2=s2;
    }
    string nextLabel(){
        cout<<str<<num<<" ";
        ifstream file;
        file.open(str2);
        int currentline=0;
        string line;
        if(file.is_open()) {
            while (!file.eof()) {
                currentline++;
                getline(file, line);
                if (currentline == num)break;
            }
            num++;
            return line;
        }else
            cout<<"File open error! ";
    }
};
int main() {
    LabelGenerator figureNumbers("Figure ", 1);
    LabelGenerator pointNumbers("P", 0);
    cout << "Figure numbers: ";
    for (int i = 0; i < 3; i++) {
        cout << figureNumbers.nextLabel() << ",";
    }
    cout <<"\b \b"<< endl << "Point numbers: ";
    for (int i = 0; i < 5; i++) {
        cout << pointNumbers.nextLabel() << ",";
    }
    cout << "\b \b"<<endl << "More figures: ";
    for (int i = 0; i < 3; i++) {
        cout << figureNumbers.nextLabel() << ",";
    }
    cout << "\b \b"<<endl;
    FileLabelGenerator figureLabels ("Figure ", 1, "test");
    cout << "Figure labels: \n";
    for (int i = 0; i < 3; i++) {
        cout << figureLabels.nextLabel() << endl;
    }
    return 0;

}
