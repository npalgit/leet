// Problem 405


using namespace std;

typedef bitset<32> BitSet;
typedef unordered_map<string, string> HashMap;

class Solution {

private:
    HashMap myMap;
    
public:
    
    Solution() {
        
        myMap["0000"] = "0";
        myMap["0001"] = "1";
        myMap["0010"] = "2";
        myMap["0011"] = "3";        
        myMap["0100"] = "4";
        myMap["0101"] = "5";
        myMap["0110"] = "6";
        myMap["0111"] = "7";
        
        myMap["1000"] = "8";
        myMap["1001"] = "9";
        myMap["1010"] = "a";
        myMap["1011"] = "b";        
        myMap["1100"] = "c";
        myMap["1101"] = "d";
        myMap["1110"] = "e";
        myMap["1111"] = "f";
        
        
    }
    
    string hexFromBin(string bin){
        
        string temp;
        string hex;
        
        while(bin.size()){
            
            temp = bin.substr(0,4);
            hex = hex + myMap[temp];
            bin.erase(0,4);
            
            
            
        }
        
        return hex;
        
        
    }
    string toHex(int num) {
        
        string hex = "";
        
        if(num == 0) {
            hex = hex + to_string(0);
            return hex;
        }
        
        
        BitSet binary(num);
        string bin = binary.to_string();
        
        hex = hexFromBin(bin);
        
        
        // Removing Starting Zeros
        while(hex.size() && hex[0] == '0'){
            
            hex.erase(0,1);
        }
        
        return hex;
    }
};