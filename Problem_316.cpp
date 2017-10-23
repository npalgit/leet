// Problem 316


using namespace std;


typedef unordered_map<char, int> HashMap;
typedef vector<int> Vector;



class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        
        HashMap myMap;
        
        
        
		for (char x : s) {
			myMap[x]++;
		}
		
		Vector visited(256, false);		
		string result;
		
		for (int i = 0; i < s.size(); i++) {
			
			char currentChar = s[i];
			
			// Reducing the Character count from the Frequency Map
			myMap[currentChar]--;
			
			
			// The character has been visited. Therefore, no point visiting it again
			if (visited[currentChar]) {
				continue;
			}
			
			
			char backChar = result[result.size()-1];
			
			//cout << "Current Char = " << currentChar << endl;
			//cout << "Back Char = " << backChar << endl;
			
			// This Loop will continuously remove the back character
			
			/*
			
			3 conditions to be satisfied for removal of the back character from the result string:
			
			1. Current Char is lesser than the Back Character
			2. Back Character is removed if we are sure that we will encounter it again later in the string
			3. Result string is not empty
			
			
			*/
			
			
			while (result.size() && (currentChar < backChar) && (myMap[backChar] > 0)) { 
                

				visited[backChar] = false;
				result = result.erase(result.size()-1, 1);
				
				backChar = result[result.size()-1];
				
			}
			
			
			// Add the current Char to the result string
			result = result + currentChar;
			
			//cout << "Final String = " << result << endl;
			//cout << endl;
			
			
			// Marking that Current Character has been visited
			visited[currentChar] = true;
		
		    
		}

		return result;
        
    }
};