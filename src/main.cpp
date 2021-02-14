#include <math.h>

#include <iostream>
#include <list>
#include <stack>
#include <string>

#include "arithmetic.h"
#include "arithmetic1.h"

using namespace std;

int main() {
    string s;
    // cin>>s;
    s = "9+(3-1*3)*3+(1+10)/2";
    cout<<s<<endl;
    std::list<string> result= conv(s);
    cout<<calcu(result)<<endl;    
    return 0;
}