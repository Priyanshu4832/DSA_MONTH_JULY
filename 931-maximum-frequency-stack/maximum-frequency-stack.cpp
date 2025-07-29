class FreqStack {
    int time;
    priority_queue<pair<int,pair<int,int>>> pq;
    unordered_map<int,int> freq_cnt;
public:
    FreqStack() {
        time = 0;
    }
    
    void push(int val) {
        freq_cnt[val]++;
        int new_freq = freq_cnt[val];
        pq.push({new_freq,{time,val}});
        time++;
    }
    
    int pop() {
        
        auto it = pq.top();
        pq.pop();

        freq_cnt[it.second.second]--;
        return it.second.second;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */