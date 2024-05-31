package gaming;
import java.util.Scanner;

public class ConsoleUserInterface {
    public void startGame() {
        while (true) {
            System.out.print("Let's start our game\n");
            Game game = new Game();
            game.startGame();
            printBoard(game.getBoard());
            char answer;

            while (true) {
                System.out.print("Pick a direction (u, d, l, r) or q: ");
                Scanner sc = new Scanner(System.in);
                answer = sc.next().charAt(0);

                if (answer == 'q') {
                    break;
                }

                int result = 0;
                try {
                    result = game.processMove(answer);
                } catch (IllegalArgumentException e) {
                    System.out.println("Invalid move");
                    continue;
                }

                printBoard(game.getBoard());

                if (result == 1) {
                    System.out.println("You won!");
                    System.out.println("You have " + game.getPoints() + " points");
                    System.out.println("Do you want to continue? (y/n)");
                    answer = sc.next().charAt(0);
                    break;
                } else if (result == 2) {
                    System.out.println("You lost haha!");
                    System.out.println("You have " + game.getPoints() + " points");
                    System.out.println("Do you want to continue? (y/n)");

                    do{
                        answer = sc.next().charAt(0);
                    }while(answer != 'y' && answer != 'n');

                    break;
                } else {
                    System.out.println("You have " + game.getPoints() + " points");
                }
            }
            if(answer == 'n' || answer == 'q')
            {
                break;
            }
            else if(answer == 'y')
            {
                System.out.println();
                continue;
            } else
            {
                System.out.println("Invalid input");
                break;
            }
        }



    }
    void printBoard(int[][] board) {
        int boardSize = board.length;

        System.out.print("+-");
        for (int i = 0; i < boardSize; i++) {
            System.out.print("----");
        }
        System.out.println("+");

        for (int i = 0; i < boardSize; i++) {
            System.out.print("| ");
            for (int j = 0; j < boardSize; j++) {
                System.out.printf("%-4s", board[i][j]);
            }
            System.out.println("|");
        }

        System.out.print("+-");
        for (int i = 0; i < boardSize; i++) {
            System.out.print("----");
        }
        System.out.println("+");
        System.out.println();
    }


}

