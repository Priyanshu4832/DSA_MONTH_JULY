class Router {
public:
    int memoryLimit = 0 ;
    int lastTimeStamp = -1;
    unordered_set<long long> currentBatchSeen;

    deque<vector<int>> dq;
    vector<pair<int,vector<int>>> destPackets;

    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
        destPackets.resize(2e5  + 1);
    }

    long long pack(int source, int destination) {
        return ((long long)source << 32) | destination;
    }
    bool addPacket(int source, int destination, int timestamp) {
        //check duplicate
        if(timestamp != lastTimeStamp){
            currentBatchSeen.clear();
            lastTimeStamp = timestamp;
        }

        long long key = pack(source,destination);
        if(currentBatchSeen.find(key)!=currentBatchSeen.end()){
            return false;
        }
      
       
        //check memory overflow
        if(dq.size()>=memoryLimit){
            
            destPackets[dq.back()[1]].first +=1;
            auto& removedPacket = dq.back();
            
            if(removedPacket[2] == timestamp) {
                long long removedKey = pack(removedPacket[0], removedPacket[1]);
                currentBatchSeen.erase(removedKey);
            }
            dq.pop_back();
            
        }
        //insert
        dq.push_front({source,destination,timestamp});
        currentBatchSeen.insert(key);
        destPackets[destination].second.push_back(timestamp);
      
        return true;
    }
    
    vector<int> forwardPacket() {
        if(dq.empty()) return {};
        auto packet = dq.back();
        //forDuplicate.erase(dq.back());
        destPackets[dq.back()[1]].first+=1;

        dq.pop_back();
        if(packet[2] == lastTimeStamp) {
            long long key = pack(packet[0], packet[1]);
            currentBatchSeen.erase(key);
        }
        return packet ;
    }
    

   
    int getCount(int destination, int startTime, int endTime) {
        
        auto low = lower_bound(destPackets[destination].second.begin() + destPackets[destination].first , destPackets[destination].second.end() , startTime );
        auto high = upper_bound(destPackets[destination].second.begin() + destPackets[destination].first , destPackets[destination].second.end() , endTime );

        return high-low;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */