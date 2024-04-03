javac_: 
	javac stateMachine/tests/StateMachineTest*.java | make tests

tests: test1 test2 test3 test4 test5


test1: 
	java stateMachine.tests.StateMachineTest1 >> ../txt/test1.txt
	
test2: 
	java stateMachine.tests.StateMachineTest2 >> ../txt/test2.txt

test3: 
	java stateMachine.tests.StateMachineTest3 >> ../txt/test3.txt

test4: 
	java stateMachine.tests.StateMachineTest4 >> ../txt/test4.txt

test5: 
	java stateMachine.tests.StateMachineTest5 >> ../txt/test5.txt

doc:
	javadoc -d ../doc stateMachine/*.java

clean:
	rm -r */*.class | rm -r */*/*.class
