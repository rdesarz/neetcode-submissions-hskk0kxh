class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(!m.contains(key)) return "";

        auto& vals = m[key];

        int l=0;
        int r=vals.size();
        while(l<r)
        {
            int mid=(r+l)/2;
            if(vals[mid].second<=timestamp) l=mid+1;
            else r=mid;
        }

        if(l==0) return "";

        return vals[l-1].first;
    }
private:
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> m;
};
