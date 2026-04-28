//To check if number is even or odd;

#include <bits/stdc++.h>
using namespace std;
int main(){
    int x;
    cin>>x;
    if(x&1==1)cout<<"ODD";          //faster than x%2
    else cout<<"even";
}

//To check if a numeber is power of 2 

#include <bits/stdc++.h>
using namespace std;
int main(){
    int x;          //not valid for x==0
    cin>>x;
    if(x>0 && (x & (x-1) )== 0)cout<<"Yes power of 2";          
    else{
        cout<<"No not power of 2";
    }
}


//Multiply by 2^k (x<<k) and divide by 2^k  (x>>k)

//to get rightmost bit of any number do  x&1  if it comes 0 then rightmost bit is 0 otherwise 1 

// if we want to remove rightmost bit (rightshift) ->   x>>=1;

//Number of set bits -> number of 1's in binary representation.
  to set a bit in least significant position agar 0th bit set krni h to 1 ke saath OR lelo 
  agar 1st bit krni h to 1 ko ekbaar left shift krke OR lelo
agar nth bit set krni h to n times leftshit krke OR

for example . 01001100 isme 0th bit set krni h so 1 ke saath or
agar 1st bit to 1 ko left shift krke 00000010 ke saath or
x = x | (1 << bit)


//Unset a bit       //Codestorywithmik leetcode 2429.

to unset wahi left shift kro 1 ko then uska not lelo aur fir and lelo
x = x & (~(1<<bit));

//Check if a bit is set

    x & (1<<bit) == 0 then unset otherwise set