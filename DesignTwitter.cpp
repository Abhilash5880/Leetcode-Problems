class Twitter {
    int time;
    unordered_map<int, unordered_set<int>> followMap; //(followee, follower)
    unordered_map<int, vector<pair<int, int>>> tweetMap; //(userID, (time++, twwetID))

public:
    Twitter(): time(0) {}
    
    
    void postTweet(int userId, int tweetId) 
    {
        tweetMap[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) 
    {
        vector<pair<int, int>> feed = tweetMap[userId];
        for (int followeeID : followMap[userId])
        {
            feed.insert(feed.end(), tweetMap[followeeID]. begin(), tweetMap[followeeID]. end());
        }
        sort(feed.begin(), feed.end(), [](auto &a, auto &b) {
            return a.first > b.first;});
        vector<int> res;
        for (int i = 0; i < min(10, (int)feed.size()); ++i) {
            res.push_back(feed[i].second);}
        return res;
    }
    
    void follow(int followerId, int followeeId) 
    {
        if (followerId != followeeId) {
            followMap[followerId].insert(followeeId);
        }
        
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
        
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */