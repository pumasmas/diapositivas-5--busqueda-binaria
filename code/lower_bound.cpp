int lower_bound(int array[], int n, int x) {
    int l = 0, r = n - 1;
    int ans = -1; 
    while (l <= r) {
        int m = l + (r-l) / 2;
        if (array[m] >= x) {
            ans = m;      
            r = m - 1;  
        } else {
            l = m + 1;
        }
    }
    return ans;
}
