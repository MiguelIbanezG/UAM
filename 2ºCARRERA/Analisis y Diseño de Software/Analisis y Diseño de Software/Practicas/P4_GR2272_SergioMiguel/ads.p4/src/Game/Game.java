package Game;

import java.io.InputStreamReader;
import java.util.Map;

import Board.*;
import Tokens.*;

import java.io.BufferedReader;
import java.io.IOException;

public class Game {

    private int turns;
    private int size;
    private int wallTokens;
    private Player play1;
    private Player play2;
    private IBoard boardGame;
    Map;
    /**
     * 
     *
     * Este método inicializa el juego
     * 
     * @authors Sergio Hidalgo sergio.hidalgo@estudiante.uam.es
     *          Miguel Ibáñez miguel.ibannezg@estudiante.uam.es
     * 
     * @param turns      turnos de juego
     * @param size       tamaño
     * @param wallTokens numero de tokens de tipo muralla
     */
    public Game(int turns, int size, int wallTokens) throws InvalidGame {
        /*
         * Se hace try porque al añadir tokens dentro del tablero puede saltar una
         * excepción (aunque no se espera ninugna al estar vacío)
         */
        try {
            if (turns < 0 || size < 5 || wallTokens < 0 || (wallTokens) >= ((size) - (wallTokens + 1))) {

                throw new InvalidGame(
                        "Invalid board. Number of rows and columns must be 5. Number of wall tokens must not exceed "
                                + ((size) - (wallTokens + 1) - 1));

            } else {
                this.turns = turns;
                this.size = size;
                this.wallTokens = wallTokens;

                this.play1 = new Player();
                this.play2 = new Player();

                this.boardGame = new BoardGame(size, play1, play2);

                for (int i = 0; i < wallTokens; i++) {

                    this.addWallToken();

                }
            }

        } catch (InvalidGame e) {
            System.out.println(e);
        } catch (ForbiddenToken e) {
            System.out.println(e);
        } catch (NullPointerException e) {
            System.out.println(e);
        }
    }

    /**
     * 
     * En este método tiene lugar la lógica principal del juego
     * 
     */
    public void play() {

        int i = 0;
        int tokencont = this.size * this.size - 4;
        int rowp = 0;
        int colp = 0;
        while (i < this.turns && (tokencont > 0)) {
            /*
             * Se hace try por el mismo motivo que antes, pero además se capturan las
             * excepciones de cadena y de
             * entrada/salid
             */
            try {
                BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
                System.out.println("Starting turn " + (i + 1));

                /* Para el cambio de murallas (cada 2 turnos, es decir, cada turno par) */
                if ((i + 1) % 2 == 0) {
                    for (int j = 0; j < this.boardGame.getRows(); j++) {
                        for (int j2 = 0; j2 < this.boardGame.getColumns(); j2++) {
                            if (this.boardGame.getCell(j, j2).getToken() != null) {
                                /* Se buscan las murallas y se eliminan */
                                if (this.boardGame.getCell(j, j2).getToken().toString().equals("WA")) {
                                    this.boardGame.getCell(j, j2).setToken(null);
                                }
                            }
                        }
                    }
                    for (int j = 0; j < this.wallTokens; j++) {
                        /* Se añade el número de murallas */
                        this.addWallToken();
                    }
                }

                System.out.println(this.boardGame);

                System.out.println(this.play1);
                System.out.println(this.play2);

                /* se comprueban las casillas */
                tokencont = checkCells();
                if (tokencont == 0) {
                    System.out.println("Game end");
                    break;
                }

                /* boolean para saber cuando se ha introducido correctamente el valor */
                boolean token = false;
                String coordinates = "";

                while (token == false) {

                    try {

                        System.out.println("Turn " + (i + 1));
                        System.out.println("Player 1 enter the coordinates of the new token:");

                        coordinates = br.readLine();

                        if (coordinates.equals("END")) {
                            System.out.println("Game end");
                            return;
                        }
                        rowp = Character.getNumericValue(coordinates.charAt(0));
                        colp = Character.getNumericValue(coordinates.charAt(2));

                        /*
                         * Si alguno de los valores introducidos por el usuario no es 1 número o
                         * carácter válido se lanza una excepción
                         */

                        if (rowp < 0 || colp < 0 || rowp >= this.boardGame.getRows()
                                || colp >= this.boardGame.getColumns()) {
                            throw new NumberFormatException();
                        }

                        /*
                         * Se comprueba si son vecinos y el resultado se guarda en la variable de la
                         * condición del bucle
                         */
                        token = this.boardGame.getCell(this.play1.getLastcellrow(),
                                this.play1.getLastcellcol()).isNeighbor(this.boardGame.getCell(rowp, colp));

                        /* Si no es así se lanza la excepción y se reinicia el bucle */
                        if (token == false) {
                            throw new ForbiddenToken("You can place the token only near your last token");
                        }
                    } catch (ForbiddenToken e) {
                        System.out.println(e);
                    } catch (IOException e) {
                        System.out.println("Error reading the values");
                    } catch (IndexOutOfBoundsException e) {
                        System.out.println("Incorrect command");
                    }

                }

                IToken tp1 = null;
                int n1 = (int) (Math.random() * (10) + 1);
                /* Aquí se determina la ficha del jugador */

                if (n1 <= 7) {
                    tp1 = new NormalToken(play1);
                    this.play1.setPoints(this.play1.getPoints() + 1);

                }
                if (n1 > 7 && n1 < 9) {
                    tp1 = new MultiplierToken(play1);
                    this.play1.setPoints(this.play1.getPoints() + 3);
                }
                if (n1 == 10) {
                    tp1 = new FixedToken(play1);
                    this.play1.setPoints(this.play1.getPoints() + 1);
                }

                /* si la casilla es tipo potenciadora se pasa una normal */
                if (this.boardGame.getCell(rowp, colp).getToken() != null) {
                    if (this.boardGame.getCell(rowp, colp).getToken().toString().equals("EN")) {
                        this.boardGame.addToken(rowp, colp, new NormalToken(play1));
                    } else {
                        this.boardGame.addToken(rowp, colp, tp1);
                    }
                } else {
                    this.boardGame.addToken(rowp, colp, tp1);
                }

                this.play1.setLastcellrow(rowp);
                this.play1.setLastcellcol(colp);

                System.out.println(this.boardGame);

                System.out.println(this.play1);
                System.out.println(this.play2);

                /* El resto es idéntico pero para el jugador 2 */
                tokencont = checkCells();
                if (tokencont == 0) {
                    System.out.println("Game end");
                    break;
                }

                token = false;

                while (token == false) {

                    try {
                        System.out.println("Turn " + (i + 1));
                        System.out.println("Player 2 enter the coordinates of the new token:");

                        coordinates = br.readLine();

                        if (coordinates.equals("END")) {
                            System.out.println("Game end");
                            return;
                        }
                        rowp = Character.getNumericValue(coordinates.charAt(0));
                        colp = Character.getNumericValue(coordinates.charAt(2));

                        if (rowp < 0 || colp < 0 || rowp >= this.boardGame.getRows()
                                || colp >= this.boardGame.getColumns()) {
                            throw new NumberFormatException();
                        }

                        token = this.boardGame.getCell(this.play2.getLastcellrow(),
                                this.play2.getLastcellcol()).isNeighbor(this.boardGame.getCell(rowp, colp));

                        if (token == false) {
                            throw new ForbiddenToken("You can place the token only near your last token");
                        }
                    } catch (ForbiddenToken e) {
                        System.out.println(e);
                    } catch (IOException e) {
                        System.out.println("Error reading the values");
                    } catch (IndexOutOfBoundsException e) {
                        System.out.println("Incorrect command");
                    }

                }

                IToken tp2 = null;
                n1 = (int) (Math.random() * (10) + 1);

                if (n1 <= 7) {
                    tp2 = new NormalToken(play2);
                    this.play2.setPoints(this.play2.getPoints() + 1);

                }
                if (n1 > 7 && n1 < 9) {
                    tp2 = new MultiplierToken(play2);
                    this.play2.setPoints(this.play2.getPoints() + 3);
                }
                if (n1 == 10) {
                    tp2 = new FixedToken(play2);
                    this.play2.setPoints(this.play2.getPoints() + 1);
                }

                if (this.boardGame.getCell(rowp, colp).getToken() != null) {
                    if (this.boardGame.getCell(rowp, colp).getToken().toString().equals("EN")) {
                        this.boardGame.addToken(rowp, colp, new NormalToken(play2));
                    } else {
                        this.boardGame.addToken(rowp, colp, tp2);
                    }
                } else {
                    this.boardGame.addToken(rowp, colp, tp2);
                }

                this.play2.setLastcellrow(rowp);
                this.play2.setLastcellcol(colp);

                System.out.println(this.boardGame);

                System.out.println(this.play1);
                System.out.println(this.play2);

                i++;
                tokencont = checkCells();

            } catch (ForbiddenToken e) {
                System.out.println(e);
            } catch (IndexOutOfBoundsException e) {
                System.out.println("Incorrect command");
            }
        }

        if (this.play1.getPoints() > this.play2.getPoints()) {
            System.out.println("The winer is player " + this.play1);
        } else {
            System.out.println("The winer is player " + this.play2);
        }
    }

    /**
     * 
     * En este método se añaden 1 token de tipo muro
     * 
     */
    private void addWallToken() throws ForbiddenToken {
        /* Se comprueba si hay espacio */
        if (this.checkCells() == 0) {
            return;
        }
        int rowt = (int) (Math.random() * (this.size - 1));
        int colt = (int) (Math.random() * (this.size - 1));
        while (this.boardGame.getCell(rowt, colt).getToken() != null) {
            rowt = (int) (Math.random() * (this.size - 1));
            colt = (int) (Math.random() * (this.size - 1));
        }
        this.boardGame.addToken(rowt, colt, new WallToken());
        /* se añade y se crea la simétrica */
        ICell wa = this.boardGame.getSymmetric(this.boardGame.getCell(rowt, colt));

        this.boardGame.addToken(wa.getRow(), wa.getColumn(), new WallToken());
    }

    /**
     * 
     * En este método se comprueba el número de casillas vacías
     * 
     */
    private int checkCells() {
        int c = 0;
        for (int i = 0; i < this.boardGame.getRows(); i++) {
            for (int j = 0; j < this.boardGame.getColumns(); j++) {

                if (this.boardGame.getCell(i, j).getToken() == null) {
                    c++;
                }

            }
        }

        return c;
    }
}
