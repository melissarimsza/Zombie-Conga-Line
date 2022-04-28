output: rimsza_assn6.o rimsza_zombie.o
	g++ rimsza_assn6.o rimsza_zombie.o -o rimsza_assn6

rimsza_assn6.o: rimsza_assn6.cpp rimsza_linkedList.h rimsza_node.h
	g++ -c rimsza_assn6.cpp

rimsza_zombie.o: rimsza_zombie.cpp
	g++ -c rimsza_zombie.cpp

clean:
	rm *.o output