class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        data_[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = data_[key].upper_bound(timestamp);
        return it == data_[key].begin() ? "" : prev(it)->second;
    }
private:
    unordered_map<string, map<int, string>> data_;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
