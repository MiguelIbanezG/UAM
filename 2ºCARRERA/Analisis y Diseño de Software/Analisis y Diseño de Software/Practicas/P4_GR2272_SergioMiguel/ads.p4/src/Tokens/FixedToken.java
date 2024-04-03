package Tokens;

import Game.Player;

public class FixedToken implements IToken {
    private Player play;
    private int val;

    /**
     *
     * Este método inicializa una ficha fija
     * 
     * @authors Sergio Hidalgo sergio.hidalgo@estudiante.uam.es
     *          Miguel Ibáñez miguel.ibannezg@estudiante.uam.es
     */
    public FixedToken(Player play) {
        this.play = play;
        this.val = 1;
    }

    public boolean canBeOverwritten() {
        return false;
    }

    public String toString() {
        String s = "F" + this.play.getId();
        return s;
    }

    public Player getPlay() {
        return play;
    }

    public int getVal() {
        return val;
    }
}
