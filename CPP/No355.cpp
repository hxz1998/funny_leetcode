/**
 * Created by Xiaozhong on 2020/8/31.
 * Copyright (c) 2020/8/31 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "list"
#include "unordered_map"
#include "unordered_set"
#include "iostream"

using namespace std;

class Twitter {
private:
    /**
     * 建立两个映射表，一个简单列表
     * follow_mapper : 用来建立用户之间的连接，可以查询某一个用户 u 的用户列表里是否存在 i
     * post_to_user_mapper : 用来建立文章到用户的连接，可以查询某一个文章的发出者 u
     * posts : 文章列表，从后添加
     */
    unordered_map<int, unordered_set<int>> follow_mapper;
    unordered_map<int, int> post_to_user_mapper;
    list<int> posts;
public:
    /** Initialize your data structure here. */
    Twitter() {
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        post_to_user_mapper[tweetId] = userId;
        posts.push_back(tweetId);
        follow_mapper[userId].insert(userId);
    }

    /**
     * Retrieve the 10 most recent tweet ids in the user's news feed.
     * Each item in the news feed must be posted by users who the user followed or by the user herself.
     * Tweets must be ordered from most recent to least recent.
     */
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        // 从后往前找，看看有哪条的创建者 i 在 u 的关注者列表里
        for (auto iter = posts.rbegin(); iter != posts.rend(); iter++) {
            // 如果 follow_mapper[userId] 的关注列表里有 post_to_user_mapper[*iter] ，那么就把这个文章放到返回值中
            if (follow_mapper[userId].count(post_to_user_mapper[*iter])) {
                ans.push_back(*iter);
                if (ans.size() >= 10) return ans; // 如果大小已经到了 10，那么就直接返回吧
            }
        }
        return ans;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        follow_mapper[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;   // 过滤无效请求
        follow_mapper[followerId].erase(followeeId);
    }
};

int main() {
    Twitter twitter;
    twitter.postTweet(1, 5);
    vector<int> ans = twitter.getNewsFeed(1);
    for (int i : ans) cout << i << " ";
}