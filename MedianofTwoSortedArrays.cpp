class Solution {
public:
    double findMedian(vector<int>& a, vector<int>& b) {
        double result;
        vector<int> med;

        for (int i = 0; i < a.size(); i++) {
            med.push_back(a[i]);
        }
        for (int i = 0; i < b.size(); i++) {
            med.push_back(b[i]);
        }

        sort(med.begin(), med.end());
        int number = med.size() - 1;
        if (number % 2 == 0) {
            result = med[number / 2.0];
        }
        else {
            result = (med[number / 2] + med[number / 2 + 1]) / 2.0;
        }
        return result;
    }
};
