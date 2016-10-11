#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Random
{
	public:
		Random(){ srand(static_cast<int>(time(0))); }
		int getRandom(int n) const { return rand() % n; }
};

class Die
{
	private: 
		int numSides;
		int value;
		static Random rand;
		Die(const Die&);
	public:
		Die(int = 6);
		Die& toss();
		int getValue();
};

Random Die::rand;
int Die::getValue() const{
	return value;
}
Die::Die(int n = 6){
	numSides = n;
}
Die& Die::toss(){
	value = rand.getRandom(numSides) + 1;
	return *this;
}
int main()
{

	Die die(6);
	for (int i = 0; i < 10; i++)
	{
		die.toss();
		cout << die.getValue() << endl;
	}
	
	return 0;
}