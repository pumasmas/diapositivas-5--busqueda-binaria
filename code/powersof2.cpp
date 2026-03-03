int pos = 0;
for (int jump = n/2; jump>=1; jump/=2){
    while(pos+jump < n && array[pos+jump] <= x){
        pos += jump;
    }
 }
if (array[pos]==x){
    // x found at index pos
 }
