class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> ans;
        vector<int> phash(26,0);
        vector<int> hash(26,0);

        int window = p.size();
        int len = s.size();
        if(window>len){
            return {};
        }

        int l=0,r=0;
        while(window>r){
            phash[p[r]-'a']++;
            hash[s[r]-'a']++;
            r++;
        }

        r--;

        while(r<len){
            if(phash==hash){
                ans.push_back(l);
            }
            r++;
            if(r<len){
                hash[s[r]-'a']++;
                hash[s[l]-'a']--;
                l++;
            }
        }

        return ans;

    }
};