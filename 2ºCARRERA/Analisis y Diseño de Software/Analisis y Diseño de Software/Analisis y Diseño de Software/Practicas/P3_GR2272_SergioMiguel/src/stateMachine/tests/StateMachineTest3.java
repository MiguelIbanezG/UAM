package stateMachine.tests;

import java.util.List;
import stateMachine.*;

public class StateMachineTest3 {
	public static void main(String[] args) {
		StateMachine musicSystem = StateMachineTest2.createMusicSystem();
		musicSystem.setInitial("off");	
		
		musicSystem.simulate(List.of("power", "mode", "mode", "power"));
		musicSystem.simulate(List.of("power", "foo"));
	}
}
