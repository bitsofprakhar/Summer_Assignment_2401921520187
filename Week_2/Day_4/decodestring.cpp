class Solution {
public:
    string decodeString(string s) {
        stack<int> numstack;
        stack<string> strstack;

        int currnum=0;
        string currstr="";

        for (int i =0 ; i<s.size(); i++){
            if(isdigit(s[i])){
                currnum= currnum*10 + (s[i]-'0');   
            }

            else if(s[i]=='['){
                numstack.push(currnum);
                strstack.push(currstr);
                 currnum=0;
                 currstr="";
            }
            
            else if(s[i]==']'){
                int num =numstack.top();
                numstack.pop();

                string prevstr=strstack.top();
                strstack.pop();

                string temp = "";

                for(int j = 0; j < num; j++) {
                    temp += currstr;
                }

                currstr= prevstr + temp;   
            }
            else {

                currstr += s[i];
            }
        }
        return currstr;

    }
};