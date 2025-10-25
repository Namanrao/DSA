class Solution {
public int ap(int monday) {
    int n = 7;
    int d = 1;
    int sum = n * (2 * monday + (n - 1) * d) / 2;
    return sum;
}

    public int totalMoney(int n) {
        // taking out the weeks 
    int weeks = n/7;
    int days = n %7;

    int total_sum = 0 ;
    int monday = 0; 
    while(weeks-->0){
        monday++;
        total_sum = total_sum + ap(monday);
    }
    monday++;
    while(days>0){
        total_sum += days*(2*monday + (days-1)*1)/2;
        break;
    }
    return total_sum;
    }
}