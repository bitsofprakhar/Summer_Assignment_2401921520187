class Solution {
public:
    bool checkInclusion(string s1, string s2) {
           vector<int> phash(26, 0);
        vector<int> hash(26, 0);

        int window = s1.size();
        int len = s2.size();

        if (window > len) {
            return false;
        }

        int l = 0, r = 0;

        while (window > r) {
            phash[s1[r] - 'a']++;
            hash[s2[r] - 'a']++;
            r++;
        }

        r--;

        while (r < len) {

            if (phash == hash) {
                return true;
            }

            r++;

            if (r < len) {
                hash[s2[r] - 'a']++;
                hash[s2[l] - 'a']--;
                l++;
            }
        }

        return false;
        
    }
};