class Solution {
public:
    int bsMod(int low1, int high1, vector<int> & nums1, vector<int> & nums2, int median) {
        int n = nums1.size();
        int m = nums2.size();
        while(low1 <= high1) {
            int mid1 = low1 + (high1-low1)/2;
            int pos = bs(0, m-1, nums1[mid1], false, nums2);
            int pos2 = bs(0, m-1, nums1[mid1], true, nums2);
            cout<<mid1<<" "<<pos<<endl;
            bool bool1 = nums1[mid1] >= nums2[pos];
            bool bool2 = nums1[mid1] >= nums2[pos2];
            if((mid1 + pos + 1 == median && bool1) || (mid1 + pos2 + 1 == median && bool2)) {
                return nums1[mid1];
            } else if(bool1 && bool2 && mid1 + pos + 1 <= median && median <= mid1 + pos2 + 1) {
                return nums1[mid1];
            } else if(mid1 + pos + 1 < median) {
                low1 = mid1+1;
            } else {
                high1 = mid1-1;
            }
        }
        return -1e7;
    }
    int bs(int l, int h, int val, bool comp, vector<int> & nums) {
        while(l < h) {
            int mid = l + (h-l+1)/2;
            if(comp) {
                if(nums[mid] <= val) {
                    l = mid;
                } else {
                    h = mid-1; 
                }
            } else {
                if(nums[mid] < val) {
                    l = mid;
                } else {
                    h = mid-1; 
                }
            }
        }
        return l;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n == 0) {
            return (nums2[(m-1)/2] + nums2[m/2])/2.0;
        }
        if(m == 0) {
            return (nums1[(n-1)/2] + nums1[n/2])/2.0;
        }
        if((n+m)%2) {
            if(nums1[n-1] <= nums2[0]) {
                if((n+m)/2 < n)
                    return nums1[(n+m)/2]; 
                else 
                    return nums2[(n+m)/2-n];
            }
            if(nums2[m-1] <= nums1[0]) {
                if((n+m)/2 < m)
                    return nums2[(n+m)/2];
                else 
                    return nums1[(n+m)/2-m];
            }
            int op1 = bsMod(0, n-1, nums1, nums2, (n+m)/2);
            cout<<"Value: "<<op1<<" ";
            if(op1 == -1e7) {
                op1 = bsMod(0, m-1, nums2, nums1, (n+m)/2);
            }
            cout<<op1<<endl;
            return op1;
        } else {
            if(nums1[n-1] <= nums2[0]) {
                int part1 = (n+m/2 < n) ? nums1[(n+m)/2] : nums2[(n+m)/2 - n];
                int part2 = ((n+m-1)/2 < n) ? nums1[(n+m-1)/2] : nums2[(n+m-1)/2 - n];
                return (part1 + part2)/2.0;
            }
            if(nums2[m-1] <= nums1[0]) {
                int part1 = (n+m/2 < m) ? nums2[(n+m)/2] : nums1[(n+m)/2 - m];
                int part2 = ((n+m-1)/2 < m) ? nums2[(n+m-1)/2] : nums1[(n+m-1)/2 - m];
                return (part1 + part2)/2.0;
            }
            int part1 = bsMod(0, n-1, nums1, nums2, (n+m)/2);
            int part2 = bsMod(0, n-1, nums1, nums2, (n+m-1)/2);
            cout<<"Value: "<<part1<<" "<<part2<<endl;
            if(part1 == -1e7 || part2 == -1e7) {
                part1 = part1 == -1e7 ? bsMod(0, m-1, nums2, nums1, (n+m)/2) : part1;
                //part1 = part1 == -1 ? bsMod(0, n-1, true, nums1, nums2, (n+m)/2) : part1;
                part2 = part2 == -1e7 ? bsMod(0, m-1, nums2, nums1, (n+m-1)/2) : part2;
                //part2 = part2 == -1 ? bsMod(0, n-1, true, nums1, nums2, (n+m-1)/2) : part2;
            }
            cout<<part1<<" "<<part2<<endl;
            return (part1+part2)/2.0;
        }
    }
};
