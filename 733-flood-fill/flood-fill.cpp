class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int starting_row, int starting_column, int new_color) {
        //implement breath first seach in this.
        int n= image.size();
        int m = image[0].size();

        queue<pair<int,int>> q;
        int starting_color = image[starting_row][starting_column];
        int delta_row[] = {0 , -1 , 0 ,1};
        int delta_column []= {-1, 0 , 1, 0};
        
        if(starting_color == new_color){
            return image;
        }

        if(starting_color != new_color){
            image[starting_row][starting_column] = new_color;
            q.push({starting_row , starting_column});
            while(!q.empty()){
                pair<int ,int> p = q.front();
                q.pop();

                for(int d = 0 ; d<4 ;d++){
                    int neighbour_row = p.first + delta_row[d];
                    int negihbour_column = p.second +delta_column[d];

                    if(neighbour_row<n &&neighbour_row>=0 &&negihbour_column<m &&negihbour_column>=0 && image[neighbour_row][negihbour_column]==starting_color){
                        image[neighbour_row][negihbour_column] = new_color;
                        q.push({neighbour_row,negihbour_column});
                    }
                }
            }
        }
    return image;
    }
};