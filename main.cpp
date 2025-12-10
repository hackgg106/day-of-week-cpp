#include <iostream>
#include <limits>
#include <string>
using namespace std;
void result();
int main() {
    result();
    for (int i=0; i<1; i++) {
        cout << "Do you want another trials? type y to yes or n for no..:\n";
        cout << "The first letter is the only one which is considered!!!\n";
        char mm;cin>>mm;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (mm == 'y' || mm == 'Y') {
            result();
            i=-1;
        }
        else if (mm == 'n' || mm == 'N') {
            i=0;
        }
        else if (mm != 'y' && mm != 'Y'&& mm != 'N' && mm != 'n') {
            cout << "Enter valid letter y for yes or n for no!!\n";
            i=-1;
        }
    }
}
void result() {
    cout << "Please enter year month day(in numbers) and note that years before 1601 can not be calculated:\n";
    int x, y, year, month, day, ld, n;
    for (int i=0;i<1;i++){
        if (!(cin >> year >> month >> day)) {
            cout << "Enter valid numbers(y m d)\n";
            i--;
        }
        if(year<1601){
            cout << "Enter a year after 1600\n";
            i--;
        }
    }
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        x = 4;
        y = 29;
    }
    else {
        x = 3;
        y = 28;
    }
    int lds[12]={x,y,14,4,9,6,11,8,5,10,7,12};
    ld = lds[month-1];
    int l = year-1600;
    int t=0;
    for (int i =1; i <= l; i++) {
        if ((i % 400 == 0) || (i % 4 == 0 && i % 100 != 0)) {
            t++;
        }
    }
    n=((l+2)+(t))%7;
    int q = (day - ld) % 7;
    if(q<0) {
        q+=7;
    }
    q = (q + 7) % 7;
    string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    cout << days[(q+n)%7]  << endl << endl;
}