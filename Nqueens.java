public class Nqueens {
    // Define the number of N needs to be places on the board
    public int N = 5;

    // \Print the board
    public void printBoard(int[][] board) {
        int n = board.length;
        int m = board[0].length;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
    }

    // Check if the curr ceil/block is safe to place the queen
    public boolean isSafe(int[][] board, int row, int col) {
        // check in the row
        int i = 0;
        int j = 0;

        for (i = 0; i < col; i++) {
            if (board[row][i] == 1) {
                return false;
            }
        }

        // check in the upper diagonal on the left side
        for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1) {
                return false;
            }
        }

        // check in the upper diagonal on the right side
        for (i = row, j = col; i > 0 && j < N; i--, j++) {
            if (board[i][j] == 1) {
                return false;
            }
        }

        // check in the lower diagonal on the right side
        for (i = row, j = col; i < N && j < N; i++, j++) {
            if (board[i][j] == 1) {
                return false;
            }
        }
        // check the lower diagonal on the left side
        for (i = row, j = col; j >= 0 && i < N; i++, j--) {
            if (board[i][j] == 1) {
                return false;
            }
        }
        return true;
    }

    // write the function that handles the condition to solve the problem
    public boolean solevNQueens(int[][] board, int col) {
        if (col >= N) {
            return true;
        }

        for (int i = 0; i < N; i++) {
            if (isSafe(board, i, col)) {
                board[i][col] = 1;

                if (solevNQueens(board, col + 1) == true) {
                    return true;
                }

                // if we did not get any possible solution from the given ceil we will unmark it

                board[i][col] = 0;
            }
        }
        return false;
    }

    public void solveQueen() {
        // int[][] board = {
        // { 0, 0, 0, 0 },
        // { 0, 0, 0, 0 },
        // { 0, 0, 0, 0 },
        // { 0, 0, 0, 0 }
        // };

        int[][] board = {
                { 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0 }
        };

        if (N > board.length || solevNQueens(board, 0) == false) {
            System.out.println("No possible solution");
            return;
        }

        // if the solution exists then simply print the path
        printBoard(board);
        return;
    }

    public static void main(String[] args) {
        Nqueens Queen = new Nqueens();
        Queen.solveQueen();
    }
}
