javac_: 
	javac Testers/*.java  

test1: javac_
	java Testers.SorterMain >> ../txt/SorterMain.txt

test2: javac_
	java Testers.TemplateMain >> ../txt/TemplateMain.txt

test3: javac_
	java Testers.IteratedTemplateMain >> ../txt/IteratedTemplateMain.txt

test4: javac_
	java Testers.StrategyMain >> ../txt/StrategyMain.txt

doc:
	javadoc -d ../doc/Entity Entity/*.java | javadoc -d ../doc/SortedList SortedList/*.java | javadoc -d ../doc/Strategy Strategy/*.java |  javadoc -d ../doc/Template Template/*.java 

clean:
	rm Testers/*.class | rm Entity/*.class | rm SortedList/*.class | rm Template/*.class | rm Strategy/*.class 