class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set<string> st;
        st.insert(startGene);
        for(auto it : bank) st.insert(it);
        
        queue<pair<int,string>> pq;
        //step,word

        pq.push({0,startGene});
        st.erase(startGene);

        while(!pq.empty()){

            auto temp = pq.front();
            int step=temp.first;
            string gene = temp.second;
            pq.pop();
           

            if(gene==endGene) return step;

            for(int i=0 ; i<gene.size() ; i++){

                string w = gene;
                char g[4]={'A','C','G','T'};
                for(int j=0 ; j<4 ; j++){
                    w[i]=g[j];
                    if(st.find(w)!=st.end()){
                        pq.push({step+1,w});
                        st.erase(gene);
                    }
                }
            }
        }
        return -1;
    }
};