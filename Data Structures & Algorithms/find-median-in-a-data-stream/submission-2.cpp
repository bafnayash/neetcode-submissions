class MedianFinder {
public:
    vector<int> v;
    int bs(int low, int high, int ele, vector<int> &v) {
        while(low < high) {
            int mid = low + (high-low)/2;
            if(v[mid] >= ele) {
                high = mid;
            } else {
                low = mid+1;
            }
        }
        return high;
    }
    MedianFinder() {
        v.clear();
    }
    
    void addNum(int num) {
        int n = v.size();
        int pos = bs(0, n-1, num, v);
        if(n == 0 || (n == 1 && v[0] <= num)) {
            v.push_back(num);
            return;
        } else if(n == 1) {
            pos = 0;
        }
        if(pos == n-1 && v[pos] <= num) {
            v.push_back(num);
        } else {
            v.insert(v.begin() + pos, num);
        } 
    }
    
    double findMedian() {
        int n = v.size();
        double ans = 0;
        if(n%2 == 0) {
            ans = (v[n/2] + v[n/2-1])/2.0;
        } else {
            ans = v[n/2];
        }
        return ans;
    }
};
