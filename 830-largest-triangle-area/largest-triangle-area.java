class Solution {

    public double solve(double x1, double y1 , double x2 ,double y2 , double x3 , double y3){
        double a  = Math.hypot(x1-x2, y1-y2);
        double b  = Math.hypot(x2-x3, y2-y3);
        double c  = Math.hypot(x1-x3, y1-y3);
        double s = (a + b + c)/2.0;
        double result = s*(s-a)*(s-b)*(s-c);
        
        if(result<0){
            result = 0 ;
        }
        double f =  Math.sqrt(result);
        return f;
    }

    public double largestTriangleArea(int[][] points) {
        int n = points.length;
        double result =0 ;
        for(int i = 0 ;i <n ;i++){
            for(int j = i+1 ;j<n ;j++){
                for(int k = j+1 ; k<n ; k++){

                    double x1 = points[i][0];
                    double y1 = points[i][1];

                    double x2 = points[j][0];
                    double y2 = points[j][1];

                    double x3 = points[k][0];
                    double y3 = points[k][1];

                    double temp = solve(x1,y1,x2,y2,x3,y3);
                    result = Math.max(temp , result);
                }
            }
        }
        return result;
    }
}