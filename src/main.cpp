#include <math.h>

#include <iostream>
#include <stack>
#include <string>

#include "arithmetic.h"

using namespace std;

int main() {
    string s;
    // cin>>s;
    s = "9+(3-1)*3+10/2";
    string result = conversion(s);
    cout << result;
    return 0;
}