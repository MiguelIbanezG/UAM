package Board;

import Tokens.*;
public class Cell implements ICell {

    private int row;
    private int col;
    private IToken tok;

    /**
     * Se inicializan las celdas
     * 
     * @authors Sergio Hidalgo sergio.hidalgo@estudiante.uam.es
     *          Miguel Ibáñez miguel.ibannezg@estudiante.uam.es
     * 
     * @param row
     * @param column
     * @param f
     */
    public Cell(int row, int column, IToken f) {
        this.row = row;
        this.col = column;
        this.tok = f;
    }

    public int getRow() {
        return this.row;
    }

    public int getColumn() {
        return this.col;
    }

    public void setToken(IToken f) {
        this.tok = f;
    }

    public IToken getToken() {

        return this.tok;
    }


    /* Comprueba si son vecinas dos celdas */
    public boolean isNeighbor(ICell c) {
        /* Se restan de las filas*/
        if (c.getRow() - this.getRow() == 1 || this.getRow() - c.getRow() == 1 || this.getRow() - c.getRow() == 0) {
            /*y se hace igual con las columnas */
            if (c.getColumn() - this.getColumn() == 1 || this.getColumn() - c.getColumn() == 1
                    || this.getColumn() - c.getColumn() == 0) {
                return true;
            }
        }
        return false;
    }

}
