class Solution {
public:
    void DFS(vector<vector<char>>& board, int row, int col){
        board[row][col] = '2';

        if(row-1 >= 0 && board[row-1][col] == 'O'){
            DFS(board, row-1, col);
        }
        if(row+1 < board.size() && board[row+1][col] == 'O'){
            DFS(board, row+1, col);
        }
        if(col-1 >= 0 && board[row][col-1] == 'O'){
            DFS(board, row, col-1);
        }
        if(col+1 < board[0].size() && board[row][col+1] == 'O'){
            DFS(board, row, col+1);
        }
    }
    void solve(vector<vector<char>>& board) {
        // traversing top boundary
        for(int i = 0; i < board[0].size(); i++){
            if(board[0][i] == 'O'){
                DFS(board, 0, i);
            }
        }

        // traversing down boundary
        for(int i = 0; i < board[0].size(); i++){
            if(board[board.size()-1][i] == 'O'){
                DFS(board, board.size()-1, i);
            }
        }

        // traversing left boundary
        for(int i = 0; i < board.size(); i++){
            if(board[i][0] == 'O'){
                DFS(board, i, 0);
            }
        }

        // traversing right boundary
        for(int i = 0; i < board.size(); i++){
            if(board[i][board[0].size()-1] == 'O'){
                DFS(board, i, board[0].size()-1);
            }
        }

        // coverting the remaining '0' into 'X'
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }

        // coverting the marked elements again into 'O'
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == '2'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};