enum Color {YELLOW, BLUE, RED};


vector<int> rows {0, 0, 1, -1};
vector<int> cols {1, -1, 0, 0};


bool is_safe(vector<vector<int>> matrix, int row, int col){
    int row_size = matrix.size();
    int col_size = matrix[0].size();
    if(row >= row_size || col >= col_size || row < 0 || col < 0){
        return false;
    }
    return true;
}

/*
     0 1 2 3

  0  0 1 1 2
  1  0 1 1 2
  2  0 1 1 2
  3  2 2 2 2
  4  1 1 1 1

0 - yellow
1 - blue
2 - red
*/

void fill_same_color(int col, int row, vector<<vector<int>> &matrix, Color color){
    if(matrix[row][col] == color){
        return;
    }
    pair<int, int> start = make_pair(row, col);
    Color color_to_change = matrix[row][col]; // 2
    stack<pair<int,int>> nodes_to_visit (start); // (2,1), (0,1)
    while(!nodes_to_visit.empty()){
        cur = nodes_to_visit.top(); nodes_to_visit.pop(); // (2, 1)
        matrix[cur.first][cur.second] = color;
        for(int i = 0; i < rows.size(); i++){
            int new_row = cur.first+rows[i];
            int new_col = cur.second+cols[i];
            if(is_safe(matrix, new_row, new_col) && matrix[new_row][new_col] == color_to_change){
                pair<int, int> cell_to_visit = make_pair(new_row, new_col);
                nodes_to_visit.push(cell_to_visit);
            }
        }
    }
}
fill_same_color(1, 1, mat, color.BLUE);
