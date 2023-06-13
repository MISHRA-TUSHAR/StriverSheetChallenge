vector<int> stringMatch(string &str, string &pat) {
     int n=pat.
     vector<int>ans
     int index=0;
     while (str.find(pat) < str.length()) {
       index = str.find(pat);
       ans.push_back(index);
       str[index] = '0';
     }
     return ans;
}
