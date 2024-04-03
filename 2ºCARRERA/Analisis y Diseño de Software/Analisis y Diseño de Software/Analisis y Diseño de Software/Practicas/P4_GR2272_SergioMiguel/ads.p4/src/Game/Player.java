package Game;

public class Player {

    private static int n_players;

    private double points;
    private int id;
    private int lastcellrow;
    private int lastcellcol;

    /**
     *
     * Este método inicializa un jugador
     * 
     * @authors Sergio Hidalgo sergio.hidalgo@estudiante.uam.es
     *          Miguel Ibáñez miguel.ibannezg@estudiante.uam.es
     */
    public Player() {
        n_players++;
        this.id = n_players;
        this.points = 1.0;
        this.lastcellrow = 0;
        this.lastcellcol = 0;
    }

    public int getId() {
        return this.id;
    }

    public double getPoints() {
        return this.points;
    }

    public int getLastcellrow() {
        return this.lastcellrow;
    }

    public int getLastcellcol() {
        return this.lastcellcol;
    }

    public void setPoints(double points) {
        this.points = points;
    }

    public void setLastcellrow(int lastcellrow) {
        this.lastcellrow = lastcellrow;
    }

    public void setLastcellcol(int lastcellcol) {
        this.lastcellcol = lastcellcol;
    }

    @Override
    public String toString() {
        return (this.id + ": points " + this.points + " last cell: " + this.lastcellrow + "," + this.lastcellcol);
    }
}
