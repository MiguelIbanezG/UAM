package Tokens;

import Game.Player;

public class MultiplierToken implements IToken {
    private Player play;
    private int val;

    /**
     *
     * Este método inicializa una ficha multiplicadora
     * 
     * @authors Sergio Hidalgo sergio.hidalgo@estudiante.uam.es
     *          Miguel Ibáñez miguel.ibannezg@estudiante.uam.es
     */
    public MultiplierToken(Player play) {
        this.play = play;
        this.val = 3;
    }

    public boolean canBeOverwritten() {
        return true;
    }

    public String toString() {
        String s = "M" + this.play.getId();
        return s;
    }

    public Player getPlay() {
        return play;
    }

    public int getVal() {
        return val;
    }
}
