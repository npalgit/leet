// Problem 134

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        /*
        1. Mind Draining Problem at first
        2. But, very very easy at the end
        3. Look for solution at the end.
        4. Solved in MATHS section.
        
        */
        
        
        
        int backlog = 0;
        int start = 0;
        int accumulated_extra_fuel = 0;
        
        int current_extra_fuel;
        
        for (int i = 0; i < gas.size(); ++i)
        {
            current_extra_fuel = gas[i] - cost[i];// extra fuel that I can have from this trip
            
            accumulated_extra_fuel = accumulated_extra_fuel + current_extra_fuel;// all the extra fuel if I had started from position
            // indicated by START till my current position
            
            if (accumulated_extra_fuel < 0)
            {
                backlog  = backlog + accumulated_extra_fuel;// backlog indicates deficieny in fuel from 0th position to position indicated before the START position
                
                accumulated_extra_fuel = 0;
                
                
                start = i + 1;
            }
        }
        
        if (accumulated_extra_fuel + backlog >= 0)
        {
            return start;
        }
        else
        {
            return -1;
        }
        
        
        
        
    }
};