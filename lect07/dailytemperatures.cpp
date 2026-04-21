class Solution {
public:
   vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> s;
        for (int i = n - 1 ; i >= 0 ; i--){ // Runs n times
            while(!s.empty() && temperatures[i] >= temperatures[s.top()]){ //Total O(n+ n) =O(n) 
                s.pop();  // Total = O(n) 
            } 
            // No. of times the check in the while is done is 1 + no. of pop operation
            // How mant pop operations can happen over the entir run of the algorithm.. overall i
            // A value is never popped more than its pushed
            // Every value (index) is pushed exactly once, there are n values in the input. Therefore total pops is no more than n
            // Overall the code below is O(n), O(1) per iteration
            if(!s.empty()){
                result[i] = s.top() - i;
            }
            s.push(i);
        } // total = O(n) worst case 
 
        return result;  
    }
    vector<int> dailyTemperatures_v0(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        for (int i = n - 1 ; i >= 0 ; i--){ // Runs n times
            for(int j = i + 1; j < n; j++){ // At most n times
                if(temperatures[j] > temperatures[i]){ // Because of possible early termination
                    result[i] = j - i;     // think of best case and worst case inputs and 
                                           // Big -O for each of those
                    break;      // Best case: monotinacally increasing sequence of temperatures
                                // Ex: 75 , 76, 78, 80, 81 --> BigO  T(n) = O(n)
                                // Worst case: non-increasing sequence
                                // Ex: 75, 75 , 75, 75, 60, 60, 60, Big O T(n) = O(n^2)
                }
            }
        } 
        return result;  
    }

};