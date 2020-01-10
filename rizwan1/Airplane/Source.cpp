#include <iostream>
using namespace std;
#include <iomanip>
#include"List.h"
#include"Vector.h"
#include"Graph.h"
string Origin, Destination, Date_of_travel_, Transit_location,
min_Tranist_duration_, max_Transit_duration, Airline_of_choice,
Destination1;

void menu() {

	
	cout << "\t\t\t\t" << "-------------------------------------------------------\n";
	cout << "\t\t\t\t" << "|                 Welcome to RSA Airline              |\n";
	cout << "\t\t\t\t" << "-------------------------------------------------------\n";
	cout << "\t\t\t\t" << "|    Please Choose one of the Given Options           |\n";
	cout << "\t\t\t\t" << "-------------------------------------------------------\n";
	cout << "\t\t\t\t" << "|       1)Book a flight as                            |\n";
	cout << "\t\t\t\t" << "|            A certain airline                        |\n";
	cout << "\t\t\t\t" << "|            Going to a certain Place                 |\n";
	cout << "\t\t\t\t" << "|            On a specific date                       |\n";
	cout << "\t\t\t\t" << "|            With minimal travel cost                 |\n";
	cout << "\t\t\t\t" << "-------------------------------------------------------\n";
	cout << "\t\t\t\t" << "|       2)Book a flight as                            |\n";
	cout << "\t\t\t\t" << "|            Going to a certain Place                 |\n";
	cout << "\t\t\t\t" << "|            On a specific date                       |\n";
	cout << "\t\t\t\t" << "|            With minimal travel time                 |\n";
	cout << "\t\t\t\t" << "-------------------------------------------------------\n";
	cout << "\t\t\t\t" << "|       3)Book a flight as                            |\n";
	cout << "\t\t\t\t" << "|            A connecting flight                      |\n";
	cout << "\t\t\t\t" << "|            Going to a certain Place                 |\n";
	cout << "\t\t\t\t" << "|            On a specific date                       |\n";
	cout << "\t\t\t\t" << "|            with a transit stay                      |\n";
	cout << "\t\t\t\t" << "-------------------------------------------------------\n";
	cout << "\t\t\t\t" << "|       4)Book a flight as                            |\n";
	cout << "\t\t\t\t" << "|            A connecting flight                      |\n";
	cout << "\t\t\t\t" << "|            Going to a certain Place                 |\n";
	cout << "\t\t\t\t" << "|            On a specific date                       |\n";
	cout << "\t\t\t\t" << "|            with a transit stay                      |\n";
	cout << "\t\t\t\t" << "|            And minimal travel time                  |\n";
	cout << "\t\t\t\t" << "-------------------------------------------------------\n";
	cout << "\t\t\t\t" << "|       5)Book a flight as                            |\n";
	cout << "\t\t\t\t" << "|            A non-connecting (direct) flight         |\n";
	cout << "\t\t\t\t" << "|            Going to a certain Place                 |\n";
	cout << "\t\t\t\t" << "|            On a specific date                       |\n";
	cout << "\t\t\t\t" << "-------------------------------------------------------\n";
	cout << "\t\t\t\t" << "|       6)Plan a two cities trip                      |\n";
	cout << "\t\t\t\t" << "|            A non-connecting (direct) flight         |\n";
	cout << "\t\t\t\t" << "|            Going to a certain Place                 |\n";
	cout << "\t\t\t\t" << "|            On a specific date                       |\n";
	cout << "\t\t\t\t" << "|            then to another Place                    |\n";
	cout << "\t\t\t\t" << "|            & Returning on Back to ist City          |\n";
	cout << "\t\t\t\t" << "-------------------------------------------------------\n";
}
void Scenario_one() {
	cout << "\nEnter Origin:";
	cin >> Origin;
	cout << "\nEnter Destination:";
	cin >> Destination;
	cout << "\nEnter Date of Travel:";
	cout << "\nIn Format Day/Month/Year:";
	cin >> Date_of_travel_;
	cout << "\nAirLine of Choice:";
	cin >> Airline_of_choice;
}
void Scenario_two() {
	cout << "\nEnter Origin:";
	cin >> Origin;
	cout << "\nEnter Destination:";
	cin >> Destination;
	cout << "\nEnter Date of Travel:";
	cout << "\nIn Format Day/Month/Year:";
	cin >> Date_of_travel_;
}
void Scenario_three() {
	cout << "\nEnter Origin:";
	cin >> Origin;
	cout << "\nEnter Destination:";
	cin >> Destination;
	cout << "\nEnter Date of Travel:";
	cout << "\nIn Format Day/Month/Year:";
	cin >> Date_of_travel_;
	cout << "\nEnter Transit Loocation:";
	cin >> Transit_location;
}
void Scenario_four() {
	cout << "\nEnter Origin:";
	cin >> Origin;
	cout << "\nEnter Destination:";
	cin >> Destination;
	cout << "\nEnter Date of Travel:";
	cout << "\nIn Format Day/Month/Year:";
	cin >> Date_of_travel_;
	cout << "\nEnter Transit Loocation:";
	cin >> Transit_location;
	cout << "\nEnter Min Transit Duration:";
	cin >> min_Tranist_duration_;
	cout << "\nEnter Max Transit Duration:";
	cin >> max_Transit_duration;
}
void Scenario_five() {

	cout << "\nEnter Origin:";
	cin >> Origin;
	cout << "\nEnter Destination:";
	cin >> Destination;
	cout << "\nEnter Date of Travel:";
	cout << "\nIn Format Day/Month/Year:";
	cin >> Date_of_travel_;

}
void Scenario_six() {
	cout << "\nEnter Origin:";
	cin >> Origin;
	cout << "\nEnter Destination 1:";
	cin >> Destination;
	cout << "\nEnter Destination 2:";
	cin >> Destination1;
	cout << "\nEnter Date of Travel:";
	cout << "\nIn Format Day/Month/Year:";
	cin >> Date_of_travel_;
}
/*
void connected_ticket(Vector<string> city, Vector<string> dep_times, Vector<string> arr_times, int t_cost,bool stay,int transit_Duration) {
	//will be implemented here
}*/
void direct_ticket(string direct) {
	
	//will be implemented here
}
void flights_available(int size) {
	cout << "\t\t\t\t" << "-------------------------------------------------------\n";
	cout << "\t\t\t\t" << "|       Total Flights from " << Origin << " to " << Destination << " :" << size << "    |\n";
	cout << "\t\t\t\t" << "-------------------------------------------------------\n";
	//cout << "                 Ori      Desti               D-o-T    Arr-Time      Travel-D    C-Of-Travel      Airline\n";
	cout << "\t\t" << "------------------------------------------------------------------------------------------\n";
	cout << "\t\t|   " << "Orig       |    Desti   |    D-O-T    | Dep_Time|  Ar_T   | T_D |   Cost   | Airline |\n";
	cout << "\t\t" << "------------------------------------------------------------------------------------------\n";
}
int get_city_start(string temp) {
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] >=65 && temp[i] <=90 ) {
			return i;
		}
	}
}
string utility(string data) {
	string data_ = "";
	string x = "a";
	int start = get_city_start(data);
	for (int i = start; data[i] != ' '; i++) {
		 x[0]= data[i];
		 x[1] = '/0';

		 data_.append(x);
	}
	//cout << data_<<endl;
	return data_;
}
Vector<string> divide_and_conquer(Vector<string> temp) {
	Vector<string> to_be_retruned;
	for (int i = 0; i < temp.Size(); i++) {
		
		to_be_retruned.push_back(utility(temp[i]));
	}
	return to_be_retruned;
}

int main() {
	Flights_Graph temp(20);
	temp.Add_Flights_("Flights.txt");
	temp.shortestPath("Islamabad");
	temp.printShortestDistance("Islamabad","HongKong");
	//Vector<string> toPrint = temp.scenario3("Newyork", "Tokyo", "Islamabad");
	//toPrint.print();
	//temp.Print_Adj_List_();
	//temp.shortestPath("Newyork");
	//temp.shortestPath_wrt_dat("Newyork","1/12/2019");
	//temp.shortestPath_wrt_date_airline("Newyork", "1/12/2019","ANA");
	
	/*Vector<string>returned=temp.printShortestDistance("Newyork","Paris");
	Vector<string> x = divide_and_conquer(returned);
	for (int i = 0; i < x.Size()-1; i++) {
		temp.printShortestDistance("Newyork", x[i]);
		cout << endl;
	}*/

	//temp.sho
	string Origin, Destination, Date_of_travel_, Airline_of_choice, Transit_location, Destination1;
	int min_Tranist_duration_;
label:
	//system("CLS");
	menu();
	cout << "\t\t\t\t" << "|          Please Enter a Number of Your Choice       |\n";
	int initiali_choice = -1;
	cin >> initiali_choice;
	if (initiali_choice > 6 || initiali_choice < 1) {
		goto label;
	}
	else {
		if (initiali_choice == 1) {
			cout << "\nEnter Origin:";
			cin >> Origin;
			cout << "\nEnter Destination:";
			cin >> Destination;
			cout << "\nEnter Date of Travel:";
			cout << "\nIn Format Day/Month/Year:";
			cin >> Date_of_travel_;
			cout << "\nAirLine of Choice:";
			cin >> Airline_of_choice;

			temp.shortestPath_wrt_date_airline(Origin, Date_of_travel_, Airline_of_choice);
			Vector<string>returned = temp.printShortestDistance(Origin, Destination);
			Vector<string> x = divide_and_conquer(returned);
			for (int i = 0; i < x.Size() - 1; i++) {
				temp.printShortestDistance(Origin, x[i]);
				cout << endl;
			}
			//Scenario_one();
			system("pause");
			//Uses 
			//Origin, 
			//Destination, 
			//Date_of_travel_, 
			//Airline_of_choice			
		}
		else if (initiali_choice == 2) {
			cout << "\nEnter Origin:";
			cin >> Origin;
			cout << "\nEnter Destination:";
			cin >> Destination;
			cout << "\nEnter Date of Travel:";
			cout << "\nIn Format Day/Month/Year:";
			cin >> Date_of_travel_;
			

			temp.shortest_Duration_wrt_dat(Origin, Date_of_travel_);
			Vector<string>returned = temp.printShortestDistance(Origin, Destination);
			Vector<string> x = divide_and_conquer(returned);
			for (int i = 0; i < x.Size() - 1; i++) {
				temp.printShortestDistance(Origin, x[i]);
				cout << endl;
			}
			system("pause");
			//Scenario_two();
			//system("CLS");
			//Uses
			//Origin,
		//	Destination,
		//	Date_of_travel_,
		}
		else if (initiali_choice == 3) {
			
			cout << "\nEnter Origin:";
			cin >> Origin;
			cout << "\nEnter Destination:";
			cin >> Destination;
			cout << "\nEnter Date of Travel:";
			cout << "\nIn Format Day/Month/Year:";
			cin >> Date_of_travel_;
			cout << "\nEnter Transit Location:";
			cin >> Transit_location;

			Vector<string> toPrint = temp.scenario3(Origin, Destination, Transit_location);
			toPrint.print();
			system("pause");
			//Scenario_three();
			//system("CLS");
			//Uses
			//Origin,
			//Destination,
			//Date_of_travel_,
			//Transit Location	
		}
		else if (initiali_choice == 4) {
			cout << "\nEnter Origin:";
			cin >> Origin;
			cout << "\nEnter Destination:";
			cin >> Destination;
			cout << "\nEnter Date of Travel:";
			cout << "\nIn Format Day/Month/Year:";
			cin >> Date_of_travel_;
			cout << "\nEnter Transit Loocation:";
			cin >> Transit_location;
			cout << "\nEnter Transit Duration:";
			cin >> min_Tranist_duration_;
			//cout << "\nEnter Max Transit Duration:";
			//cin >> max_Transit_duration;
			
			Vector<string> toPrint = temp.scenario4(Origin, Destination, Transit_location, min_Tranist_duration_);
			toPrint.print();
			system("pause");

			//Scenario_four();
			//system("CLS");
			//Uses
			//Origin,
			//Destination,
			//Date_of_travel_,
			//Transit Location
			//min_transit_duration
			//max_transit_duration
		}
		else if (initiali_choice == 5) {
			//Scenario_five();
			system("CLS");
			cout << "\nEnter Origin:";
			cin >> Origin;
			cout << "\nEnter Destination:";
			cin >> Destination;
			cout << "\nEnter Date of Travel:";
			cout << "\nIn Format Day/Month/Year:";
			cin >> Date_of_travel_;
			//Uses
			//Origin,
			//Destination,
			//Date_of_travel_,
			int choice=-1;
			//Origin = "Islamabad";
			//Destination = "Newyork";
			//Date_of_travel_ = "1/12/2019";
			Vector<string> x=temp.direct_Flights_(Origin, Destination, Date_of_travel_);
			flights_available(x.Size());
			for (int i = 0; i < x.Size(); i++) {
				cout <<"\t\t"<< i+1 << ") "<<Origin<<"  ---> ";
				for (int j = 7; x[i][j] != '\0'; j++) {
					cout << x[i][j];
				}
				cout << endl;
			}
			cout << "\nPlease Choose a Flight\n";
			cin >> choice;
			if (choice > 0 && choice <= x.Size()) {
				direct_ticket(x[choice]);
			}
			system("pause");
		}
		else if (initiali_choice == 6) {
		cout << "\nEnter Origin:";
		cin >> Origin;
		cout << "\nEnter Destination 1:";
		cin >> Destination;
		cout << "\nEnter Destination 2:";
		cin >> Destination1;
		cout << "\nEnter Date of Travel:";
		cout << "\nIn Format Day/Month/Year:";
		cin >> Date_of_travel_;
		//Scenario_six();
			system("pause");
			//Uses
			//Origin,
			//Destination,
			//Destination1,
			//Date_of_travel_,
			
		}
	}
	//getchar();
	return 0;
}