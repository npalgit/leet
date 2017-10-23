// Problem 158


// Forward declaration of the read4 API.
int read4(char *buf);

using namespace std;

typedef queue<int> Queue;
class Solution {
    
private:
    
    Queue leftOver;
    
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        
        int len = 0;
        //if(n == 0) return len;
        
        // Pushing LeftOver Characters in the Buffer from last Read Call, if any
        while(leftOver.size()) {
            
            buf[len] = leftOver.front();
            len++;
            leftOver.pop();
            
            
            // Ensures if n is reached before finished reading from the Queue
            if(len == n) return len;
            
        }
        
        int result = 0;
        while(len < n){
            
            result = read4(buf + len);
            
            len = len + result;
            
            // If result is less than 4, that means File Ended abruptly even before reaching n
            if(result < 4) break;
            
        }
        
        // Push the unwanted characters into the queue as buffer has already advanced
        // This is done to ensure the correctness of the next Read Call
        for(int i = n; i < len; i++) {
            
            leftOver.push(buf[i]);
        }
        
        // If extra bytes were read, they would have been pushed into the Queue
        // But, return only the minimum of both
        int finalReadBytes = min(len, n);
        
        
        // Finally Place a end of character at the buffer to signify EOF
        buf[finalReadBytes] = '\0';
        
        return finalReadBytes;
        
        
        
        
        
    }
};