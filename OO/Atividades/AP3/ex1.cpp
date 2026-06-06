#include <iostream>
#include <string>
using namespace std;

int main() {

    string s1 = "As time by ...";
    string s2 = "goes";

    int pos_by = s1.find("by");

    s1.insert(pos_by, s2 + " ");
    cout << s1 << endl;

    pos_by = s1.find("by");

    s1.erase(pos_by + 2);
    cout << s1 << endl;

    int pos_time = s1.find("time");

    s1.replace(pos_time, 4, "Bill");
    cout << s1 << endl;

    return 0;
}