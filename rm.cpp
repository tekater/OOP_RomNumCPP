#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <direct.h>

using namespace std;

class comdel {
    string text;
    int counter;
public:
    comdel(string utext) {
        text = utext;
    }
    comdel():comdel("Aboba//ladno\nok") {}
    void del(int first = 0) {
        int second;
        string copy;
        if (text.find("\n", 0) != -1) {
            second = text.find("\n", 0);
        }
        else {
            second = text.find("\0", 0);
        }

        if (text.find("//",0) != -1) {
            first = text.find("//",0);
        }
        else {
            first = text.find("/*",0);
            second = text.find("*/", 0) + 2;
        }

        
        
        
        copy = text.substr(0, first);
        copy += text.substr(second,text.size());
        text = copy;
        if (text.find("//", first + 1) != -1 || text.find("/*",first +1) != -1) {
            del(first);
        }
        else {
            return;
        }
    }
    void print() {
        cout << text << endl;
    }
};




class RomNum {
    int numbers;
    string roman;
public:
    RomNum(int num) {
        numbers = num;
    }
    
    string translate()
    {
        string ans;
        string M[] = { "","M","MM","MMM" };
        string C[] = { "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM" };
        string X[] = { "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" };
        string I[] = { "","I","II","III","IV","V","VI","VII","VIII","IX" };
        ans = M[numbers / 1000] + C[(numbers % 1000) / 100] + X[(numbers % 100) / 10] + I[(numbers % 10)];
        return ans;
    }
    

};

int main()
{
    setlocale(0, "");
    srand(time(nullptr));

    comdel c{"Ahaha//mda\nladno/*dadada*/ da"};
    c.del();
    c.print();

    RomNum rm{ 961 };
    cout << rm.translate();
}
