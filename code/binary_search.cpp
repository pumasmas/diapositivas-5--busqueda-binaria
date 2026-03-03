int l = 0, r = n-1;
while (l <= r) {
    int m = (l+r) / 2;
    if (array[m] == x) {
        return m;
    } else if (array[m] < x) {
        l = m + 1;
    } else {
        r = m - 1;
    }
 }
return -1;
