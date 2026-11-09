/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    map<int, int> pos;
    int bs(int l, int h, MountainArray m) {
        while(l < h) {
            int mid = l + (h-l)/2;
            int val = pos.contains(mid) ? pos[mid] : m.get(mid);
            int prev = -1e8;
            int next = 1e8;
            if(mid-1 >= 0) {
                if(pos.contains(mid-1)) {
                    prev = pos[mid-1];
                } else {
                    prev = m.get(mid-1);
                }
            }
            if(mid+1 >= 0) {
                if(pos.contains(mid+1)) {
                    next = pos[mid+1];
                } else {
                    next = m.get(mid+1);
                }
            }
            if(!pos.contains(mid)) {
                pos[mid] = val;
            }
            if(prev < val && val < next) {
                l = mid+1;
            } else {
                h = mid;
            }
        }
        return h;
    }
    int bsMod(int l, int h, int target, MountainArray m) {
        while(l < h) {
            int mid = l + (h-l)/2;
            int val = pos.contains(mid) ? pos[mid] : m.get(mid);
            if(!pos.contains(mid)) {
                pos[mid] = val;
            }
            if(val == target) {
                return mid;
            } else if(val < target) {
                l = mid+1;
            } else {
                h = mid-1;
            }
        }
        return l;
    }
    int bsModRev(int l, int h, int target, MountainArray m) {
        while(l < h) {
            int mid = l + (h-l)/2;
            int val = pos.contains(mid) ? pos[mid] : m.get(mid);
            if(!pos.contains(mid)) {
                pos[mid] = val;
            }
            if(val == target) {
                return mid;
            } else if(val > target) {
                l = mid+1;
            } else {
                h = mid-1;
            }
        }
        return l;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int p = bs(0, mountainArr.length()-1, mountainArr);
        cout<<p<<" ";
        int op1 = bsMod(0, p, target, mountainArr);
        //cout<<op1<<" "<<pos[op1]<<endl;
        if(mountainArr.get(op1) == target) {
            return op1;
        }
        int op2 = bsModRev(p+1, mountainArr.length()-1, target, mountainArr);
        //cout<<op2;
        if(mountainArr.get(op2) == target) {
            return op2;
        }
        return -1;
    }
};