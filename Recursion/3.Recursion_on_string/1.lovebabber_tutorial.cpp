//reverse the string
// subsequence of the string (very important question:****try to revise more and more .)
// additon of string (ex: str1= "1234"; str2="234"; output: "1468") 
// hits: call all given function accoding to function requirement 

#include<bits/stdc++.h>
using namespace std;
// reverse a string -------------------------------
void reverseString1(string& str,int i,int j){
	  if(i>=j) return;
	  swap(str[i],str[j]);
	  reverseString1(str,i+1,j-1);
}
void reverseString2(string &str,int index,string &ans){
	if(index==str.size()) return ;
	reverseString2(str,index+1,ans);
	ans.push_back(str[index]);

}
// --------------End of reverse of string--------------
// --------------subsequence of a String---------------
void subsequnce_of_String(string str,int i,string ans){
	if(i==str.size()) {
		cout<<ans<<endl;
		return ;
	}
	// include
	subsequnce_of_String(str,i+1,ans+str[i]);


	// exclude
	subsequnce_of_String(str,i+1,ans);

}

// -------------------End of subsequence---------------
//--------------------Addition of two string -------------
void addtionOfString(string str1,string str2,int i,int j,int carry,string& ans){
	// base case
	if(i<0 && j<0 && carry==0) return ;
	
	int first=0;
	int second=0;
	if(i>=0)
	first=str1[i]-'0';
        if(j>=0)
	second=str2[j]-'0';
	
	int sum=first+second+carry;
	int last_digit=sum%10;
	carry=sum/10;
	
	ans.push_back(last_digit + '0');
	addtionOfString(str1,str2,i-1,j-1,carry,ans);
	
}
 
// -------------------end of addtion of two string--------



int main(){
	// string str="Raju";
	string a="123";
	string b="2347";
	
	// reverseString1(str,0,str.size());
	// cout<<str<<endl;
	string ans="";
	// reverseString2(str,0,ans);
	// cout<<ans<<endl;

	// subsequnce
	// subsequnce_of_String(str,0,ans);

    // addtion of two string
    addtionOfString(a,b,a.length()-1,b.length()-1,0,ans);
	   reverse(ans.begin(),ans.end());
	   cout<<ans<<endl;
	   

	return 0;

}
