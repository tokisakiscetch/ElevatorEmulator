#include <iostream>
#include <chrono>
#include <thread>

std::chrono::seconds sleeptime(2);

class Elevator
{
private:
	int stage;
public:
	Elevator() : stage(0) { std::cout << "-You entered the elevator-\nNow stage is " << stage << std::endl; }
	Elevator(int stage) : stage(stage) { std::cout << "-You entered the elevator-\nNow stage is " << stage << std::endl; }
	~Elevator() { std::cout << "-You left the elevator-\n"; }

	int setStage(int floor)
	{
		if (floor == stage) {
			std::cout << "You are already on this stage.\n";
			return stage;
		}
		std::cout << "Moving from stage " << stage << " to stage " << floor << std::endl;
		std::cout << "The elevator is moving...\n";
		std::this_thread::sleep_for(sleeptime);
		stage = floor;
		std::cout << "You have arrived at stage " << stage << ".\n";
		return stage;
	}

	int elevator_panel()
	{
		int choice;
		std::cout << "The elevator panel appears in front of you...\n" << std::endl;
		std::cout << "Your actions?\n1)Move to stage\n2)Log out" << std::endl;
		std::cout << "Your choice -> ";
		std::cin >> choice;
		if (choice == 2)
		{
			return 1;
		}
		while (choice == 1)
		{ 
			int floor;
			std::cout << "Choice stage(from 1 to 10) -> ";
			std::cin >> floor;
			while (floor < 1 || floor > 10)
			{
				std::cerr << "Wrong choice. Choice again.\n";
				std::cin >> floor;
			}
			setStage(floor);
			std::cout << "Your actions?\n1)Move to stage\n2)Log out" << std::endl;
			std::cout << "Your choice -> ";
			std::cin >> choice;
		}
	}
};

int main()
{
	Elevator lift;
	lift.elevator_panel();
}