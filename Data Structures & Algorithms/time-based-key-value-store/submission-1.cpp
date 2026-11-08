class TimeMap {
public:
    map<pair<string,int>, string> store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[{key, timestamp}] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = store.lower_bound({key, timestamp});
        //auto k = {key, timestamp};
        if(it != store.begin() && (it == store.end() || it->first.first != key || it->first.second > timestamp)) {
            it--;
            //return "";
        }
        if(it == store.end() || it->first.first != key || it->first.second > timestamp) {
            return "";
        }
        return it->second;
    }
};
