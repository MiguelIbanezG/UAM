javac_: 
	javac Testers/*.java 

test1: javac_
	java Testers.TokensAndPlayersTest >> ../txt/TokensAndPlayersTest.txt

test2: javac_
	java Testers.CellAndBoardTest >> ../txt/CellAndBoardTest.txt

test3: javac_
	java Testers.GameMain >> ../txt/GameMain.txt

test4: javac_
	java Testers.GameMainFromFile load.txt >> ../txt/GameMainFromFile.txt

doc:
	javadoc -d ../doc/Game Game/*.java | javadoc -d ../doc/Board Board/*.java | javadoc -d ../doc/Tokens Tokens/*.java
