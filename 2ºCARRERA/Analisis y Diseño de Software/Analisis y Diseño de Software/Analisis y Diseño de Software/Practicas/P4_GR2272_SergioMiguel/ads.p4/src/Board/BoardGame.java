package Board;

import Game.*;
import Tokens.*;
import java.util.*;


public class BoardGame implements IBoard {
    private Player play1;
    private Player play2;
    private int rows;
    private int cols;
    private List<ICell> cells;

    /**
     * Se inicializa el tablero
     * 
     * @authors Sergio Hidalgo sergio.hidalgo@estudiante.uam.es
     *          Miguel Ibáñez miguel.ibannezg@estudiante.uam.es
     * 
     * 
     * @param tam   tamaño
     * @param play1 jugador 1
     * @param play2 jugador 2
     */

    public BoardGame(int tam, Player play1, Player play2) {
        this.play1 = play1;
        this.play2 = play2;
        this.rows = tam;
        this.cols = tam;
        this.cells = new ArrayList<ICell>();

        /* todas las celdas inicializadas con un token a null */
        for (int i = 0; i < this.rows; i++) {
            for (int j = 0; j < this.cols; j++) {

                this.cells.add(new Cell(i, j, null));

            }

        }

        /* try catch para el add token */
        try {

            /* Se añaden los tokens y las posiciones de estos a los jugadores */
            this.addToken(0, 0, new NormalToken(play1));
            this.play1.setLastcellrow(0);
            this.play1.setLastcellcol(0);

            /* El otro token es simétrico */
            ICell tp2 = this.getSymmetric(this.getCell(0, 0));
            this.addToken(tp2.getRow(), tp2.getColumn(), new NormalToken(play2));

            this.play2.setLastcellrow(tp2.getRow());
            this.play2.setLastcellcol(tp2.getColumn());

            /* Se añaden de manera random los potenciadores (pero simétricos) */

            int rowt = (int) (Math.random() * (this.rows - 1));
            int colt = (int) (Math.random() * (this.cols - 1));

            while (this.getCell(rowt, colt).getToken() != null) {
                rowt = (int) (Math.random() * (this.rows - 1));
                colt = (int) (Math.random() * (this.cols - 1));
            }
            this.addToken(rowt, colt, new EnhancerToken());
            ICell en2 = this.getSymmetric(this.getCell(rowt, colt));
            this.addToken(en2.getRow(), en2.getColumn(), new EnhancerToken());

        } catch (ForbiddenToken e) {
            System.out.println(e);
        }

    }

    public int getRows() {
        return this.rows;
    }

    public int getColumns() {
        return this.cols;
    }

    public String toString() {
        String s = "";

        for (int i = 0; i < this.rows; i++) {
            for (int j = 0; j < this.cols; j++) {

                if (this.getCell(i, j).getToken() == null) {
                    s = s + "--  ";

                } else {

                    s = s + this.getCell(i, j).getToken() + "  ";
                }

            }

            s = s + "\n";
        }

        return s;
    }

    /**
     * Esta función gestiona la lógica de las fichas potenciadoras y los tokens
     * 
     * @param row    fila
     * @param column columna
     * @param f      token
     */
    public void addToken(int row, int column, IToken f) throws ForbiddenToken {
        if (this.checkCells() == 0) {
            return;
        }
        /* try catch porque es recursiva */
        try {
            /*
             * Se comprueba si es nula y si puede ser sobrescrito el token que hay en esa
             * posición
             */

            if (this.cells.get(this.cols * (row) + column).getToken() == null
                    || this.cells.get(this.cols * (row) + column).getToken().canBeOverwritten() == true) {
                /* Si no es nulo, se comprueba si es potenciadora */
                if (this.cells.get(this.cols * (row) + column).getToken() != null
                        && this.cells.get(this.cols * (row) + column).getToken().toString().equals("EN")) {
                    /* Si lo es se genera un número aleatorio para determinar su comportamiento */
                    int dice = (int) (Math.random() * (3) + 1);

                    if (dice == 1) {
                        /* Si es 1 se sustituiran todas las columnas */
                        this.cells.get(this.cols * (row) + column).setToken(f);
                        for (int i = 0; i < this.rows; i++) {

                            /* Si es nula se añade sin mas y se le suma 1 punto al jugador */
                            if (this.cells.get(this.cols * (i) + column).getToken() == null) {

                                this.addToken(i, column, f);
                                /* Al ser obligatoriamente normal no hay peligro de hacer casting */
                                NormalToken n = (NormalToken) f;
                                n.getPlay().setPoints(n.getPlay().getPoints() + 1);
                            } else {
                                /* Si no es nula se comprueba si se puede sobre escribir */
                                if (this.cells.get(this.cols * (i) + column).getToken().canBeOverwritten()) {
                                    /* Si es del mismo jugador no se hace nada */
                                    if (this.cells.get(this.cols * (i) + column).getToken().toString().charAt(1) == f
                                            .toString().charAt(1)) {

                                    } else {
                                        /* Si no lo es, se añade */
                                        this.addToken(i, column, f);
                                        NormalToken n = (NormalToken) f;
                                        n.getPlay().setPoints(n.getPlay().getPoints() + 1);
                                    }
                                }
                            }

                        }

                        /* Si no quedan espacios se vuelve */
                        if (this.checkCells() == 0) {
                            return;
                        }
                        /* Sino se añade una potenciadora */

                        int rowt = (int) (Math.random() * (this.rows - 1));
                        int colt = (int) (Math.random() * (this.cols - 1));

                        while (this.getCell(rowt, colt).getToken() != null) {
                            rowt = (int) (Math.random() * (this.rows - 1));
                            colt = (int) (Math.random() * (this.cols - 1));
                        }
                        this.addToken(rowt, colt, new EnhancerToken());

                        return;
                    }

                    /* Esta parte funciona de manera similar a la anterior */
                    if (dice == 2) {
                        this.cells.get(this.cols * (row) + column).setToken(f);
                        for (int i = 0; i < this.rows; i++) {
                            if (this.cells.get(this.cols * (row) + i).getToken() == null) {

                                this.addToken(row, i, f);
                                NormalToken n = (NormalToken) f;
                                n.getPlay().setPoints(n.getPlay().getPoints() + 1);
                            } else {
                                if (this.cells.get(this.cols * (row) + i).getToken().canBeOverwritten()) {

                                    if (this.cells.get(this.cols * (row) + i).getToken().toString().charAt(1) == f
                                            .toString().charAt(1)) {

                                    } else {
                                        this.addToken(row, i, f);

                                        NormalToken n = (NormalToken) f;
                                        n.getPlay().setPoints(n.getPlay().getPoints() + 1);

                                    }
                                }
                            }

                        }

                        if (this.checkCells() == 0) {
                            return;
                        }

                        int rowt = (int) (Math.random() * (this.rows - 1));
                        int colt = (int) (Math.random() * (this.cols - 1));

                        while (this.getCell(rowt, colt).getToken() != null) {
                            rowt = (int) (Math.random() * (this.rows - 1));
                            colt = (int) (Math.random() * (this.cols - 1));
                        }
                        this.addToken(rowt, colt, new EnhancerToken());

                        return;
                    }

                    if (dice == 3) {

                        /*
                         * La diferencia principal de esta parte radica en el uso de la funcion
                         * getNeighbors()
                         */
                        List<ICell> neighbors = getNeighbors(row, column);
                        this.cells.get(this.cols * (row) + column).setToken(f);

                        /*
                         * Se recorren los vecinos y se van añadiendo siguiendo la misma lógica de
                         * nulos/no nulos y
                         * si están o no en propiedad del jugador
                         */
                        for (ICell iCell : neighbors) {

                            if (iCell.getToken() == null) {

                                this.addToken(iCell.getRow(), iCell.getColumn(), f);
                                NormalToken n = (NormalToken) f;
                                n.getPlay().setPoints(n.getPlay().getPoints() + 1);

                            } else {
                                if (iCell.getToken().canBeOverwritten()) {

                                    if (iCell.getToken().toString().charAt(1) == f
                                            .toString().charAt(1)) {

                                    } else {
                                        this.addToken(iCell.getRow(), iCell.getColumn(), f);
                                        NormalToken n = (NormalToken) f;
                                        n.getPlay().setPoints(n.getPlay().getPoints() + 1);
                                    }
                                }
                            }

                        }

                        if (this.checkCells() == 0) {
                            return;
                        }

                        int rowt = (int) (Math.random() * (this.rows - 1));
                        int colt = (int) (Math.random() * (this.cols - 1));

                        while (this.getCell(rowt, colt).getToken() != null) {
                            rowt = (int) (Math.random() * (this.rows - 1));
                            colt = (int) (Math.random() * (this.cols - 1));
                        }
                        this.addToken(rowt, colt, new EnhancerToken());

                        return;
                    }

                }
                this.cells.get(this.cols * (row) + column).setToken(f);

            } else {
                throw new ForbiddenToken("the token " + this.cells.get(this.cols * (row) + column).getToken()
                        + " can not be placed in position " + row + "," + column
                        + " because: the cell contains a token that cannot be overwritten");
            }
        } catch (ForbiddenToken e) {
            System.out.println(e);
        }

    }

    /*
     * Esta función comprueba las distintas combinaciones posibles de vecinos
     */
    public List<ICell> getNeighbors(int row, int column) {
        List<ICell> neighbors = new ArrayList<ICell>();

        /* Las 4 esquinas */
        if (row == 0 && column == 0) {
            neighbors.add(this.getCell(row, column + 1));
            neighbors.add(this.getCell(row + 1, column + 1));
            neighbors.add(this.getCell(row + 1, column));
            return neighbors;
        }

        if (row == this.rows - 1 && column == this.cols - 1) {
            neighbors.add(this.getCell(row, column - 1));
            neighbors.add(this.getCell(row - 1, column - 1));
            neighbors.add(this.getCell(row - 1, column));
            return neighbors;
        }

        if (row == 0 && column == this.cols - 1) {
            neighbors.add(this.getCell(row, column - 1));
            neighbors.add(this.getCell(row + 1, column - 1));
            neighbors.add(this.getCell(row + 1, column));
            return neighbors;
        }

        if (row == this.rows - 1 && column == 0) {
            neighbors.add(this.getCell(row, column + 1));
            neighbors.add(this.getCell(row - 1, column + 1));
            neighbors.add(this.getCell(row - 1, column));
            return neighbors;
        }

        /* Las 4 posibles partes intermedias */
        if (row == 0) {
            neighbors.add(this.getCell(row, column - 1));
            neighbors.add(this.getCell(row + 1, column - 1));
            neighbors.add(this.getCell(row + 1, column));
            neighbors.add(this.getCell(row + 1, column + 1));
            neighbors.add(this.getCell(row, column + 1));

            return neighbors;
        }

        if (column == 0) {
            neighbors.add(this.getCell(row, column + 1));
            neighbors.add(this.getCell(row - 1, column + 1));
            neighbors.add(this.getCell(row - 1, column));
            neighbors.add(this.getCell(row + 1, column + 1));
            neighbors.add(this.getCell(row + 1, column));
            return neighbors;
        }

        if (row == this.rows - 1) {
            neighbors.add(this.getCell(row, column + 1));
            neighbors.add(this.getCell(row - 1, column + 1));
            neighbors.add(this.getCell(row - 1, column));
            neighbors.add(this.getCell(row - 1, column - 1));
            neighbors.add(this.getCell(row, column - 1));
            return neighbors;
        }

        if (column == this.cols - 1) {
            neighbors.add(this.getCell(row, column - 1));
            neighbors.add(this.getCell(row + 1, column - 1));
            neighbors.add(this.getCell(row + 1, column));
            neighbors.add(this.getCell(row - 1, column - 1));
            neighbors.add(this.getCell(row - 1, column));
            return neighbors;
        }

        /* las partes centricas */
        neighbors.add(this.getCell(row, column + 1));
        neighbors.add(this.getCell(row + 1, column));
        neighbors.add(this.getCell(row + 1, column + 1));
        neighbors.add(this.getCell(row - 1, column));
        neighbors.add(this.getCell(row, column - 1));
        neighbors.add(this.getCell(row - 1, column - 1));
        neighbors.add(this.getCell(row + 1, column - 1));
        neighbors.add(this.getCell(row - 1, column + 1));

        return neighbors;
    }

    /**
     * En esta función se crea una casilla simetrica
     */
    public ICell getSymmetric(ICell c) {

        int row = c.getRow();
        int col = c.getColumn();

        row = this.rows - row - 1;

        col = this.cols - col - 1;

        return new Cell(row, col, c.getToken());
    }

    public ICell getCell(int row, int column) {

        return this.cells.get(this.cols * (row) + column);
    }

    /**
     * Función idéntica a la de Game
     * 
     * @return
     */
    private int checkCells() {
        int c = 0;
        for (int i = 0; i < this.getRows(); i++) {
            for (int j = 0; j < this.getColumns(); j++) {

                if (this.getCell(i, j).getToken() == null) {
                    c++;
                }

            }
        }

        return c;
    }
}