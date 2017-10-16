// Problem 49

using namespace std;

typedef vector<string> Vector;
typedef vector<Vector> Matrix;

typedef map<string, int> HashMap;

#include<algorithm>
class Solution {
public:

    string strSort(string& s) {
        int count[26] = {0}, n = s.length();
        for (int i = 0; i < n; i++)
            count[s[i] - 'a']++;
        int p = 0;
        string t(n, 'a');
        for (int j = 0; j < 26; j++)
            for (int i = 0; i < count[j]; i++)
                t[p++] += j;
        return t;
    } 
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        
        /*
        1. The trick is just to sort the string before building a hashMap.
        2. Without initial sorting, very complex problem.
        3. Corner Cases:
            a. If the given vector is of zero length
            b. If the given vector has a null string
        
        
        
        */
        Matrix table;
        Vector myVect;
        
        string current = "";
        
        HashMap myMap;
        
        // Corner Case 3a.
        if(strs.size() == 0) {
            table.push_back(myVect);
            return table;
        
            
        }
        
        int index = -1;
        
        for(int i = 0; i < strs.size(); i++){
            
            current = strs[i];
            
            // Corner Case 3b.
            //if(current.empty() != 1)sort(current.begin(), current.end());
            
            if(current.empty() != 1) current = strSort(current);
            
            //cout << "current = " << current << endl;
            
            if(myMap.find(current) == myMap.end()){
                
                myVect.clear();
                myMap[current] = table.size();
                
                myVect.push_back(strs[i]);
                
                table.push_back(myVect);
            }
            
            else{
                
                index = myMap[current];
                table[index].push_back(strs[i]);
            }
            
            
        }        
        
        return table;
    }
};