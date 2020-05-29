#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    bitset<10> a(n);
    cout<<a<<endl;       //Print binary of n instead of using loop

    int cnt=a.count();   // number of set bits(1) in bitset 
    cout<<cnt<<endl;

    if (a.any())         // any function will return true if any bits is set 
        cout << "set has bit set.\n";
    
    if (a.none())         // none function will return true if no bits is set 
        cout << "set has no bit set.\n";

    cout<<a.set()<<endl;   //Set all bits 

    cout<<a.set(5,0)<<endl;  // Set or unset the specified position

    cout<<a.reset()<<endl;   // Unset all the bits

    cout<<a.flip()<<endl;   //Flip  1 <-> 0
}
