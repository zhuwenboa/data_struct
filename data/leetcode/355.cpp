#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<unordered_map>
using namespace std;

//设计推特：我采用的哈希表＋链表的方法
//找出所关注用户和自己的top_ten news 我用的优先队列的方法

struct User_twitter
{
    User_twitter(int id, int t) : tw_id(id), times(t) {}
    int tw_id;
    int times;
};

struct compare 
{
    bool operator () (const pair<list<User_twitter>::iterator, list<User_twitter>::iterator>& a, 
                      const pair<list<User_twitter>::iterator, list<User_twitter>::iterator>& b)
    {
        return a.first->times < b.first->times;
    }
};

class Twitter 
{
public:
    /** Initialize your data structure here. */
    Twitter() : timefd(0)
    {}
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) 
    {
        user_tw[userId].push_front({tweetId, ++timefd});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) 
    {
        int count = 0;
        //结果
        vector<int> res;
        //用优先队列来获取10条最近的推文
        priority_queue< pair<list<User_twitter>::iterator,list<User_twitter>::iterator>, 
                            vector< pair<list<User_twitter>::iterator,list<User_twitter>::iterator> >, 
                            compare > top_tenNews;
        //保存该用户和其关注用户的推文集
        vector<list<User_twitter>> news;
        news.push_back(user_tw[userId]);
        //该用户关注的所有id,将其所对应的推文集加入到vector中
        list<int> Id = Users[userId];
        for(auto a = Id.begin(); a != Id.end(); ++a)
        {
            news.push_back(user_tw[*a]);
        }

        for(auto a = news.begin(); a != news.end(); ++a)
        {   
            top_tenNews.push({a->begin(), a->end()});
        }
        while(count < 10 && !top_tenNews.empty())
        {
            auto t = top_tenNews.top();
            top_tenNews.pop();
            if(t.first == t.second)
                continue;
            res.push_back(t.first->tw_id);
            list<User_twitter>::iterator iter = ++t.first;
            if(iter != t.second)
            {
                top_tenNews.push({iter, t.second});
            }
            ++count;
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) 
    {
        //考虑自我关注的情况
        if(followerId == followeeId)
            return;
        //已经关注过的情况
        if(find(Users[followerId].begin(), Users[followerId].end(), followeeId) != Users[followerId].end())
            return;
        Users[followerId].push_back(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) 
    {
        auto iter = find(Users[followerId].begin(), Users[followerId].end(), followeeId);
        if(iter == Users[followerId].end())
        {
        }
        else
        {
            Users[followerId].erase(iter);   
        }
    }
private:  
    unordered_map<int, list<int>> Users;
    unordered_map<int, list<User_twitter>> user_tw;
    int timefd;
};

int main()
{
    Twitter twitter;
    std::vector<int> res;
    twitter.postTweet(1, 1);
    res = twitter.getNewsFeed(1);
    for(auto a : res)
        std::cout << a << "\n";
    twitter.follow(2, 1);
    //twitter.postTweet(2, 6);
    res = twitter.getNewsFeed(2);
    for(auto a : res)
        std::cout << a << "\n";
    
    twitter.unfollow(2, 1);
    res = twitter.getNewsFeed(2);
    for(auto a : res)
        std::cout << a << "\n";

}