class ExamTracker {
public:

    vector<long long> scores;
    vector<int> times;
    ExamTracker() {
        scores.resize(0);
        times.resize(0);
    }
    
    void record(int time, int score) {
        times.push_back(time);
        if(scores.size()==0) scores.push_back(score);
        else scores.push_back(scores.back()+score);

    }
    
    long long totalScore(int startTime, int endTime) {
        
        if(endTime<times[0]) return 0;
        auto start = lower_bound(times.begin(), times.end(), startTime);
        int startIdx = start-times.begin();

        long long startscore = (startIdx==0) ? 0 : scores[startIdx-1];
 

        auto end = upper_bound(times.begin(), times.end(), endTime);
        int endIdx=end-times.begin()-1;
        long long endscore = scores[endIdx];

        

        return endscore-startscore;

        
       
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */