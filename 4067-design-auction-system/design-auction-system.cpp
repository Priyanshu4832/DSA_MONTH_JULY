class AuctionSystem {
public:
    unordered_map<int,unordered_map<int,int>> mpp;
    // <item id , <user id , amt >>
    unordered_map<int,set<pair<int,int>>> highBid;
    // item id , set of< amt , user id >

    AuctionSystem() {
        
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        
        if (mpp[itemId].count(userId)) {
            updateBid(userId, itemId, bidAmount);
        } else {
            mpp[itemId][userId] = bidAmount;
            highBid[itemId].insert({bidAmount, userId});
        }
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        
        int oldAmount = mpp[itemId][userId];

        highBid[itemId].erase({oldAmount, userId});
        mpp[itemId][userId] = newAmount;
        
        highBid[itemId].insert({newAmount, userId});
    }
    
    void removeBid(int userId, int itemId) {
        int amount = mpp[itemId][userId];
        
        mpp[itemId].erase(userId);
        highBid[itemId].erase({amount, userId});
    }
    
    int getHighestBidder(int itemId) {
        if (highBid.find(itemId) == highBid.end() || highBid[itemId].empty()) {
            return -1;
        }
        pair<int, int> highest = *highBid[itemId].rbegin();
        
        return highest.second; 
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */