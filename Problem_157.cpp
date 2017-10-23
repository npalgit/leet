// Problem 157


// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        
        if(n == 0) return 0;
        
        int len = 0;
        int readBytes = 0;
        
        int result;
        while(len < n) {
            
            result = read4(buf + len);
            len = len + result;
            if(result < 4) break;
            
            
        }
        
        
        readBytes = min(len, n);
        
        return readBytes;
        
        
    }
};