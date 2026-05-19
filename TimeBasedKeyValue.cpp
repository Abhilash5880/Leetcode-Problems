class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> TM;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) 
    {
        TM[key].push_back({timestamp, value});
        
    }
    
    string get(string key, int timestamp) 
    {
        if (TM.find(key)==TM.end())
        {
            return "";
        }
        vector<pair<int,string>>& vec = TM[key];
        int low=0;
        int high=vec.size()-1;
        string ans="";
        while(low<=high)
        {
            int mid=(low+high)/2;
            // vec[mid].first = timestamp
            // vec[mid].second = value
            if(vec[mid].first==timestamp)
            {
                return vec[mid].second;
            }
            if(vec[mid].first<timestamp)
            {
                ans=vec[mid].second;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */