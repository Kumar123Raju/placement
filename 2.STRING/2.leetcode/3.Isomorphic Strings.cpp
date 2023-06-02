// very important question for....may be ask in interview;

// https://leetcode.com/problems/isomorphic-strings/description/
 bool isIsomorphic(string s, string t) {
      
        if(s.size()!=t.size()) return false;
        unordered_map<char,char> um;
        unordered_map<char,int> mapped;

        for(int i=0; i<s.size(); i++){
            if(um.find(s[i])==um.end() && mapped.find(t[i])==mapped.end()){
                um[s[i]]=t[i];
                mapped[t[i]]++;
            }
        }
        for(int i=0; i<s.size(); i++){
            s[i]=um[s[i]];
        }
        if(s==t) return true;
        else return false;
        
           
        
    }
