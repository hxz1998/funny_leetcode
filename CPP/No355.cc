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
     * ��������ӳ���һ�����б�
     * follow_mapper : ���������û�֮������ӣ����Բ�ѯĳһ���û� u ���û��б����Ƿ���� i
     * post_to_user_mapper : �����������µ��û������ӣ����Բ�ѯĳһ�����µķ����� u
     * posts : �����б��Ӻ����
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
        // �Ӻ���ǰ�ң������������Ĵ����� i �� u �Ĺ�ע���б���
        for (auto iter = posts.rbegin(); iter != posts.rend(); iter++) {
            // ��� follow_mapper[userId] �Ĺ�ע�б����� post_to_user_mapper[*iter] ����ô�Ͱ�������·ŵ�����ֵ��
            if (follow_mapper[userId].count(post_to_user_mapper[*iter])) {
                ans.push_back(*iter);
                if (ans.size() >= 10) return ans; // �����С�Ѿ����� 10����ô��ֱ�ӷ��ذ�
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
        if (followerId == followeeId) return;   // ������Ч����
        follow_mapper[followerId].erase(followeeId);
    }
};

int main() {
    Twitter twitter;
    twitter.postTweet(1, 5);
    vector<int> ans = twitter.getNewsFeed(1);
    for (int i : ans) cout << i << " ";
}