class HitCounter {
public:
    HitCounter()
        : cnt_{0}
    {}
    
    void hit(int timestamp) {
        while(!hits_.empty() && timestamp - hits_.front().first >= 300) {
            cnt_ -= hits_.front().second;
            hits_.pop();
        }
            
        ++cnt_;
        if(!hits_.empty() && timestamp == hits_.back().first) ++(hits_.back().second);
        else hits_.push({timestamp, 1});
    }
    
    int getHits(int timestamp) {
        while(!hits_.empty() && timestamp - hits_.front().first >= 300) {
            cnt_ -= hits_.front().second;
            hits_.pop();
        }
        return cnt_;
    }
private:
    queue<pair<int, int>> hits_;
    int cnt_;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
