package gaming;
import java.util.Random;
class Game {
    final int BOARD_LENGTH = 4;

    private static class GameCell {
        int value_cell;
        boolean was_merged;

        GameCell()
        {
            value_cell = 0;
        }
        void setValue_cell(int value) {
            value_cell = value;
        }

        void setWas_merged(boolean was_merged) {
            this.was_merged = was_merged;
        }

        boolean getWas_merged() {
            return was_merged;
        }

        int getValue_cell() {
            return value_cell;
        }
    }

    int points;

    GameCell[][] board = new GameCell[BOARD_LENGTH][BOARD_LENGTH];

    public void startGame() {
        for (int i = 0; i < BOARD_LENGTH; i++) {
            for (int j = 0; j < BOARD_LENGTH; j++) {
                board[i][j] = new GameCell();
            }
        }

        int[] coordinates = getFreeCell();
        board[coordinates[0]][coordinates[1]].setValue_cell(2);
    }


    int[] getFreeCell() //
    {
        Random random = new Random();

        while (true) {
            int randomRow = random.nextInt(BOARD_LENGTH);
            int randomCol = random.nextInt(BOARD_LENGTH);

            if (board[randomRow][randomCol].getValue_cell() == 0) {
                return new int[]{randomRow, randomCol};
            }
        }
    }
    boolean checkWin()
    {
        for(int i = 0; i < BOARD_LENGTH; i++)
        {
            for(int j = 0; j < BOARD_LENGTH; j++)
            {
                if(board[i][j].getValue_cell() == 2048)
                {
                    return true;
                }
            }
        }

        return false;
    }

    boolean checkLoss() {
        for (int i = 0; i < BOARD_LENGTH; i++) {
            for (int j = 0; j < BOARD_LENGTH; j++) {
                if (board[i][j].getValue_cell() == 0) {
                    return false;
                }
            }
        }
        return true;
    }

    void resetWasMerged()
    {
        for(int i = 0; i < BOARD_LENGTH; i++)
        {
            for(int j = 0; j < BOARD_LENGTH; j++)
            {
                board[i][j].setWas_merged(false);
            }
        }
    }
    void goRight()
    {
        for(int count = 0; count < BOARD_LENGTH; count++) {
            for (int j = 0; j < BOARD_LENGTH - 1; j++) {
                for (int i = 0; i < BOARD_LENGTH; i++) {
                    if (board[i][j + 1].getValue_cell() == 0) {
                        board[i][j + 1].setValue_cell(board[i][j].getValue_cell());
                        board[i][j].setValue_cell(0);
                    } else if (board[i][j].getValue_cell() == board[i][j + 1].getValue_cell() && !board[i][j].getWas_merged()){
                        board[i][j + 1].setValue_cell((board[i][j].getValue_cell() + board[i][j + 1].getValue_cell()));
                        board[i][j].setValue_cell(0);
                        setPoints(getPoints() + board[i][j + 1].getValue_cell());
                        board[i][j + 1].setWas_merged(true);
                    }

                }
            }
        }
        resetWasMerged();
    }
    void goLeft()
    {
        for(int count = 0; count < BOARD_LENGTH; count++) {
            for (int j = BOARD_LENGTH - 1; j > 0; j--) {
                for (int i = 0; i < BOARD_LENGTH; i++) {
                    if (board[i][j - 1].getValue_cell() == 0) {
                        board[i][j - 1].setValue_cell(board[i][j].getValue_cell());
                        board[i][j].setValue_cell(0);
                    } else if (board[i][j].getValue_cell() == board[i][j - 1].getValue_cell() && !board[i][j].getWas_merged()) {
                        board[i][j - 1].setValue_cell((board[i][j].getValue_cell() + board[i][j - 1].getValue_cell()));
                        board[i][j].setValue_cell(0);
                        setPoints(getPoints() + board[i][j - 1].getValue_cell());
                        board[i][j - 1].setWas_merged(true);
                    }

                }
            }
        }
        resetWasMerged();
    }
    void goDown()
    {
        for(int count = 0; count < BOARD_LENGTH; count++) {
            for (int i = 0; i < BOARD_LENGTH - 1; i++) {
                for (int j = 0; j < BOARD_LENGTH; j++) {
                    if (board[i + 1][j].getValue_cell() == 0) {
                        board[i + 1][j].setValue_cell(board[i][j].getValue_cell());
                        board[i][j].setValue_cell(0);
                    } else if (board[i][j].getValue_cell() == board[i + 1][j].getValue_cell() && !board[i][j].getWas_merged()) {
                        board[i + 1][j].setValue_cell((board[i][j].getValue_cell() + board[i + 1][j].getValue_cell()));
                        board[i][j].setValue_cell(0);
                        setPoints(getPoints() + board[i + 1][j].getValue_cell());
                        board[i + 1][j].setWas_merged(true);
                    }

                }
            }
        }
        resetWasMerged();
    }
    void goUp()
    {
        for(int count = 0; count < BOARD_LENGTH; count++) {
            for (int i = BOARD_LENGTH - 1; i > 0; i--) {
                for (int j = 0; j < BOARD_LENGTH; j++) {
                    if (board[i - 1][j].getValue_cell() == 0) {
                        board[i - 1][j].setValue_cell(board[i][j].getValue_cell());
                        board[i][j].setValue_cell(0);
                    } else if (board[i][j].getValue_cell() == board[i - 1][j].getValue_cell() && !board[i][j].getWas_merged()) {
                        board[i - 1][j].setValue_cell((board[i][j].getValue_cell() + board[i - 1][j].getValue_cell()));
                        board[i][j].setValue_cell(0);
                        setPoints(getPoints() + board[i + 1][j].getValue_cell());
                        board[i - 1][j].setWas_merged(true);
                    }

                }
            }
        }
        resetWasMerged();
    }

    int biggestNumberOnBoard()
    {
        int max = 0;

        for(int i = 0; i < BOARD_LENGTH; i++)
        {
            for(int j = 0; j < BOARD_LENGTH; j++)
            {
                if(board[i][j].getValue_cell() > max)
                {
                    max = board[i][j].getValue_cell();
                }
            }
        }

        return max;
    }

    int getRandomNumber(int[] options) {
        Random random = new Random();
        int randomIndex = random.nextInt(options.length);
        return options[randomIndex];
    }
    void generateNewCell()
    {
        int[] coordinates = getFreeCell();

        int max = biggestNumberOnBoard();
        if(max == 8 || max > 8)
        {
            int randomNumber = getRandomNumber(new int[]{2, 4, 8});
            board[coordinates[0]][coordinates[1]].setValue_cell(randomNumber);
        } else if (max == 4){
            int randomNumber = getRandomNumber(new int[]{2, 4});
            board[coordinates[0]][coordinates[1]].setValue_cell(randomNumber);
        } else {
            board[coordinates[0]][coordinates[1]].setValue_cell(2);
        }
    }
    int processMove(char move) {
        if (move != 'u' && move != 'd' && move != 'r' && move != 'l') {
            throw new IllegalArgumentException("Invalid move");
        }

        switch (move)
        {
            case 'u':
            {
                goUp();
                break;
            }
            case 'd':
            {
                goDown();
                break;
            }
            case 'r':
            {
                goRight();
                break;
            }
            case 'l':
            {
                goLeft();
                break;
            }
        }

        if(checkLoss())
        {
            return 2;
        }

        if(checkWin())
        {
            return 1;
        }

        generateNewCell();

        return 0;
    }

    int getPoints()
    {
        return points;
    }

    void setPoints(int points)
    {
        this.points = points;
    }

    int[][] getBoard()
    {
        int[][] int_board = new int[BOARD_LENGTH][BOARD_LENGTH];

        for(int i = 0; i < BOARD_LENGTH; i++)
        {
            for(int j = 0; j < BOARD_LENGTH; j++)
            {
                int_board[i][j] = this.board[i][j].getValue_cell();
            }
        }

        return int_board;
    }
}
