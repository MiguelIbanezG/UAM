package Testers;

import Game.*;

public class GameMainFromFile {
	
	public static void main(String args[]) {

		Game g = GameLoader.load(args[0]);
		if (g != null) 
			g.play();

	}

}
