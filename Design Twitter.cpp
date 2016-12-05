bool cmp (pair<int, int> &p1, pair<int, int> &p2)
{return p1.second > p2.second;}

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        globalAge++;
        usertweets[userId].emplace_back(make_pair(tweetId, globalAge));
        if (usertweets[userId].size() > 10)
            usertweets[userId].pop_front();
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> tweets;
        if (usertweets.count(userId))
            tweets.insert(tweets.end(), usertweets[userId].begin(), usertweets[userId].end());
        // Get other users' posts
        if (following.count(userId)) {
            for (auto i : following[userId]) {
                if (i == userId) continue;
                if (usertweets.count(i)) 
                    tweets.insert(tweets.end(), usertweets[i].begin(), usertweets[i].end());
            }
        }
        sort(tweets.begin(), tweets.end(), cmp);
        vector<int> res;
        for (auto i : tweets) {
            if (res.size() >= 10) break;
            res.emplace_back(i.first);
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (following.count(followerId) && following[followerId].count(followeeId))
            following[followerId].erase(followeeId);
    }
private:
    unsigned globalAge = 0;
    unordered_map<int, list<pair<int, int>>> usertweets; // uid->tweets<id, age>
    unordered_map<int, unordered_set<int>> following; // uid->uidset
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */