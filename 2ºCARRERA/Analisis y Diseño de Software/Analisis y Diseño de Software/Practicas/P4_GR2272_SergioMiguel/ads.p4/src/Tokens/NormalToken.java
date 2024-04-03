package Tokens;

import Game.Player;

public class NormalToken implements IToken {
    private Player play;
    private int val;

    /**
     *
     * Este método inicializa una ficha normal
     * 
     * @authors Sergio Hidalgo sergio.hidalgo@estudiante.uam.es
     *          Miguel Ibáñez miguel.ibannezg@estudiante.uam.es
     */
    public NormalToken(Player play) {
        this.play = play;
        this.val = 1;
    }

    public boolean canBeOverwritten() {
        return true;
    }

    public String toString() {
        String s = "N" + this.play.getId();
        return s;
    }

    public Player getPlay() {
        return play;
    }

    public int getVal() {
        return val;
    }
}
