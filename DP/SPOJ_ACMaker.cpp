//https://www.spoj.com/problems/ACMAKER/

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <sstream>
#include <cstring>
#include <cctype>
#define fo(i,a,b)   for (int i = a; i < b; i++) 
      
using namespace std;
#include<bits/stdc++.h>
int count_subseq(string a,string b,int st,int bb){
 //   cout<<st<<bb<<endl;
    int dp[151][151];
    memset(dp,0,sizeof dp);
    string c=' '+a;  //c *geeks
    int aa=c.length(); // aa=6
    int bl=bb-st;     // 5 bb- *(st)abcde(st+bb-st)
    fo(i,0,aa)
     dp[i][0]=1;
    fo(i,1,aa){
     fo(j,1,bl+1){
      dp[i][j]+=dp[i-1][j];
      if(c[i]==tolower(b[st+j])){
       dp[i][j]+=dp[i-1][j-1];                   
      }
     }
   }
   return dp[aa-1][bl];
   
}
int main() {
    for (;;) {
        int n; cin >> n; if (n == 0) return 0;
        set<string> insignificant;
        for (int i = 0; i < n; i++) {
            string s; cin >> s; insignificant.insert(s);
        }
        for (;;) {
            string acro1,acro; cin >> acro1;
            cin.ignore();
            acro=' '+acro1;
/*            fo(k,0,acro1.length()-1){
             acro1[k]=acro1[k+1];
            }*/
           // acro1[acro1.length()-1]='\0';
            string phrase; getline(cin, phrase);
            if (phrase == "CASE") break;
            istringstream iss(phrase);
            vector<string> words;
            words.push_back("abcd");
            for (;;) {
                string word; iss >> word;
                if (word == "") break;
                if (insignificant.find(word) == insignificant.end()) {
                    words.push_back(word);
                }
            }
            // dp[i][j] is the number of ways to use the first i words and the
            // first j letters of the acronym
            
            int dp[151][151];
            memset(dp, 0, sizeof(dp));
            dp[0][0]=1;
            for (int i = 1; i < words.size(); i++) {
                for (int j = 1; j < acro.length(); j++) {
                    int sum=0;
                    for(int k=i-1; k <=  j-1 ; k++){ 
                     sum+=dp[i-1][k]*count_subseq(words[i],acro,k,j);//actually k+1 to j but passing k to make it 1 -indexed
                    }
                    dp[i][j]=sum;
                 }
            }   
            
            if (dp[words.size()-1][acro.length()-1] == 0) {
                cout << acro1 << " is not a valid abbreviation" << endl;
            } else {
                
                cout <<acro1 <<" can be formed in "
                     << dp[words.size()-1][acro.length()-1] << " ways" << endl;
 
            }
        }
    }
} 
