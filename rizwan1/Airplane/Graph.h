#pragma once

#include "List.h"//Header File of Linked List

//Built in Header files
#include<iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include<iomanip>
#include"Vector.h"
using namespace std;

struct Temp {
	int data;
	Vector<string> x;
};

//Class of FLights from one to another city
class Flights_Graph
{
public:
	int size, capacity;
	//Size and Capacity of Number of Cities
	int* smallestWeight;
	Temp* smallest;
	List* cities;
	//An adjacent list of cities
	//and graph will connect each city to the correspoding city of arrival
	//ISB to NYK
	//Seoul to Tokyo
	//etc

public:
	Flights_Graph()
	{
		//A default constructor
		size = 0;
		capacity = 0;
		//start = NULL;
		//end = NULL;
		cities = new List[0];
	}
	Flights_Graph(int capacity_)//capacity defined by user
	{
		//capacity defined by user
		//An overloaded constructor
		size = 0;
		capacity = capacity_;
		//start = NULL;
		//end = NULL;
		smallestWeight = new int[capacity_];
		smallest = new Temp[capacity_];
		cities = new List[capacity_];
	}

	Node* Create_vertex_(string*& data_) {
	
		// A function that will receive an array with the data of a file 
		// and the add it to a node
		//that will be returned to the ADD_FLights_ function to be linked 
		//with adjacent list
		Node* to_ret = new Node;
		
		int index = 0;
		string temporary = "";

		to_ret->city_name = data_[1];//name of city where flight will reach
		to_ret->date.push_back(data_[2]);//date of flight
		while (data_[2][index] != '/')
		{
			temporary += data_[2][index];
			index++;
		}
		to_ret->day.push_back(stoi(temporary));
		index = 0;
		temporary = "";

		to_ret->dep_time.push_back(data_[3]);//departure time
		
		string dep_time="al", arr_time="al";
		int i = 0;
		while (data_[3][i] != ':') {
			dep_time[i] = data_[3][i];
			i++;
		}
		dep_time[i] = '\0';
		i = 0;
		while (data_[4][i] != ':') {
			arr_time[i] = data_[4][i];
			i++;
		}
		arr_time[i] = '\0';
		int dep_time1 = stoi(dep_time);
		int arr_time1 = stoi(arr_time);
		to_ret->arrtime.push_back(arr_time1);
		to_ret->deptime.push_back(dep_time1);

		int differ = arr_time1 - dep_time1;
		if (differ < 0) {
			differ = differ + 24;
		}
		to_ret->time_duration.push_back(differ);
		to_ret->arr_time.push_back(data_[4]);//arrival time
		int cost = stoi(data_[5]);
		to_ret->cost_.push_back(cost);//cost of the traveling
		to_ret->flight_name.push_back(data_[6]);//name of the flight service
		return to_ret;
	}

	void Add_Flights_(string filename)
	{
		// A function that will create the graph and 
		// will link one city with all other flight
		// of different citites and may be same at different times
		string data; //A temporary variable
		int cost = 0;
		int x = 0;
		//source_indexing=0;
		fstream file;
		string* data_array_ = new string[7]; //Array for data reading
		int find_pos = -1;
		int k = 0;
		file.open(filename, ios::in);
		if (file) {
			for (int i = 0; !file.eof(); i++) {
				bool put = true;
				file >> data;
				if (i == 1) {
					for (int j = 0; j < size; j++) {
						if (data == cities[j].origon) {
							put = false;
							break;
						}
					}
					if (put) {
						cities[k].origon = data;
						size++;
						cities[k].source_index = k;
						k++;
					}
				}//shabih
				//int t1 = 0;
				//int t2=0;
				//if (i==3) { //departual time
				//		string t = data;
				//		string p = "";
				//		p += t[0];
				//		if (t[1]!=':') {
				//			p += t[1];
				//		}
				//		cout << p << " ";
				//		//t1 = stoi(p);
				//}
				//if (i==4) {	//arrival time
				//	string t = data;
				//	string p = "";
				//	p += t[0];
				//	if (t[1] != ':') {
				//		p += t[1];
				//	}
				//	cout << p << "\n";
				//	//t2 = stoi(p);
				//}
				else if (i == 7) {
					i = 0;
				}
				//cout << t1<<" "<<t2<<"\n";
				//int dif = t2 - t1;
				//cout << dif<<" ";
			}
		}
		file.close();

		file.open(filename, ios::in);
		//*****************File Reading**********************
		//try and throw in case if file is not opened
		
		if (file)
		{
			while (!file.eof())
			{
				for (int i = 0; i < 7; i++)
				{
					file >> data;
					data_array_[i] = data;
					//pushing all data to an array
				}

				find_pos = -1;
				// a handler to check if city exists before or not

				Node* temp = Create_vertex_(data_array_);
				//will be received by a pointer that holds data of
				//a flight

				for (int i = 0; i < size; i++)
				{
					//traversal to check if city has departure city already
					//exists in the graph

					if (data_array_[0] == cities[i].origon)
					{
						//break the loop if you find the city in list
						//else continue

						find_pos = i;
						break;
					}
				}

				if (find_pos == -1)
				{

					//if departure city does not exists in the list then add new city
					//and flight from this city to other cities
					//	cout << "New Entry\n";
					//	cout << size<<"   " << temp->to_string() << endl;
					cities[size].origon = data_array_[0];

					//temp->size++;
					cities[size].insert(temp);
					size++;
					cout << "\nmain nae chly ga\n";
				}
				else



				{
					//	cout << "Old Entry\n";
					//	cout << find_pos<<"   " << temp->to_string() << endl;
					//cities[find_pos].origon = data_array_[0];
					//if city already exists in the list so just add a new flight to
					//it
					Node* temp_ox = cities[find_pos].head;
					while (temp_ox != NULL) {
						if (temp_ox->city_name == data_array_[1]) {
							break;
						}
						temp_ox = temp_ox->next;
					}
					if (temp_ox == NULL) 
					{
						cities[find_pos].insert(temp);
					}
					else 
					{
						temp_ox->arr_time.push_back(temp->arr_time[0]);
						temp_ox->cost_.push_back(temp->cost_[0]);
						temp_ox->date.push_back(temp->date[0]);
						temp_ox->dep_time.push_back(temp->dep_time[0]);
						temp_ox->flight_name.push_back(temp->flight_name[0]);
						temp_ox->time_duration.push_back(temp->time_duration[0]);
						temp_ox->size++;
					}
				}

				//reading each line and then saving it into a string array
				x++;
			}
		
		}
		file.close();
		apply_indexes();

		int stay_price;
		file.open("HotelCharges_perday.txt", ios::in);
		if (file)
		{
			while (!file.eof())
			{
				file >> data;
				file >> stay_price;
				//cout << cities[get_index(data)].origon << " " << stay_price << endl;
				cities[get_index(data)].hotel_charges = stay_price;
			}
		}

		file.close();
	}
	int get_index(string city) {
		for (int i = 0; i <= capacity; i++) {
			if (city == cities[i].origon) {
				return i;
			}
		}
		return -1;
	}
	void apply_indexes() {
		for (int i = 0; i < size; i++) {
			Node* temp = cities[i].head;
			cities[i].source_index = get_index(cities[i].origon);
			while (temp != NULL) {
				temp->destination_index = get_index(temp->city_name);
				if (temp->destination_index == -1) {
					
				}
				temp = temp->next;
			}
		}
	}

	void Print_Adj_List_()
	{
		for (int i = 0; i < size; i++)
		{
			//a function that will print the graph in a manner that 
			// every Node of Adj List is linked to all the citites of 
			//different flights

			cout << cities[i].origon << "  ";
			cities[i].get_links_printed_();
			cout << endl;
		}
	}

	Vector<string> direct_Flights_1(string origin_, string destination_, string d_o_t)
	{
		//A function that takes different strings
		//to implement scenario 5
		//and returns an array of strings 

		int index = 0;
		string temporary = "";

		while (d_o_t[index] != '/')
		{
			temporary += d_o_t[index];
			index++;
		}
		index = stoi(temporary);

		int origin_index = -1;// a handler to find the values
		Vector<string> to_ret;

		for (int i = 0; i < size; i++)
		{
			//an iteration to find at what index the source actually exists
			if (origin_ == cities[i].origon)
			{
				//if find then return make the handlerequals to the
				//index and break the loop
				origin_index = i;
				break;
			}
		}

		if (origin_index != -1)
		{
			Node* temp = cities[origin_index].head;
			while (temp != NULL)
			{
				if (temp->city_name == destination_)
				{
					break;
				}
				temp = temp->next;
			}
			if (temp != NULL) {
				for (int i = 0; i < temp->getsize(); i++) {
					if (temp->day[i] >= index) {
						to_ret.push_back(temp->to_string(i));
					}
				}
			}
			else {
				cout << "\nNo Flight towards " << destination_ << endl;
				exit(-1);
			}
		}
		else
		{
			cout << "\nOrigin was not found\n";
			exit(-1);
		}
		return to_ret;
	}


	Vector<string> direct_Flights_(string origin_, string destination_, string d_o_t_)
	{
		//A function that takes different strings
		//to implement scenario 5
		//and returns an array of strings 

		int origin_index = -1;// a handler to find the values
		Vector<string> to_ret;

		for (int i = 0; i < size; i++)
		{
			//an iteration to find at what index the source actually exists
			if (origin_ == cities[i].origon)
			{
				//if find then return make the handlerequals to the
				//index and break the loop
				origin_index = i;
				break;
			}
		}

		if (origin_index != -1)
		{
			Node* temp = cities[origin_index].head;
			while (temp != NULL)
			{
				if (temp->city_name == destination_)
				{
					break;
				}
				temp = temp->next;
			}
			if (temp != NULL) {
				for (int i = 0; i < temp->getsize(); i++) {
					if (temp->date[i] == d_o_t_) {
						to_ret.push_back(temp->to_string(i));
					}
				}
			}
			else {
				cout << "\nNo Flight towards " << destination_ << endl;
				exit(-1);
			}
		}
		else
		{
			cout << "\nOrigin was not found\n";
			exit(-1);
		}
		return to_ret;
	}
	int** get_cost_weight() {
		int** weights = new int* [size];
		for (int i = 0; i < size; i++) {
			weights[i] = new int[size];
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (i==j) {
					weights[i][j]=0;
				}
				else {
					weights[i][j] = INT32_MAX;
				}
			}
		}
		for (int i = 0; i < size; i++) {
			Node* ptr = cities[i].head;
			while (ptr != NULL) {
				weights[i][ptr->destination_index] = ptr->min_cost();
				ptr = ptr->next;
			}
		}
		//Node* ptr = cities[0].head->next;
		//cout<<"oooooooooopsssssss"<<ptr->min_cost_requirment_air_dat("Emirates","1/12/2019")<<"\n \n \n \n";
		return weights;
	}
	int** get_cost_weight_wrt_date_and_Airline(string dat,string air) {	//date and airline
		int** weights = new int* [size];
		for (int i = 0; i < size; i++) {
			weights[i] = new int[size];
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (i == j) {
					weights[i][j] = 0;
				}
				else {
					weights[i][j] = INT32_MAX;
				}
			}
		}
		for (int i = 0; i < size; i++) {
			Node* ptr = cities[i].head;
			while (ptr != NULL) {
				weights[i][ptr->destination_index] = ptr->min_cost_requirment_air_dat(air,dat);
				ptr = ptr->next;
			}
		}
		return weights;
	}

	int** get_cost_weight_wrt_date(string dat) {		//2d matrix for minimum cost with date given
		int** weights = new int* [size];
		for (int i = 0; i < size; i++) {
			weights[i] = new int[size];
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (i == j) {
					weights[i][j] = 0;
				}
				else {
					weights[i][j] = INT32_MAX;
				}
			}
		}
		for (int i = 0; i < size; i++) {
			Node* ptr = cities[i].head;
			while (ptr != NULL) {
				weights[i][ptr->destination_index] = ptr->min_cost_requirment_dat(dat);
				ptr = ptr->next;
			}
		}
		return weights;
	}
	Vector<string> scenario4(string src, string des, string transit_loc, int trans_time)
	{
		int transint;
		int desint;

		Vector<string> toReturn;
		Vector<string> tempVec;
		Node* tempNode = cities[get_index(src)].head;
		Node* tempNode1 = cities[get_index(transit_loc)].head;
		while (tempNode != NULL)
		{
			if (tempNode->city_name == transit_loc)
				break;
			tempNode = tempNode->next;
		}

		while (tempNode1 != NULL)
		{
			if (tempNode1->city_name == des)
				break;
			tempNode1 = tempNode1->next;
		}

		int index = 0, flag = 0;;
		if (tempNode != NULL)
		{
			tempVec = direct_Flights_(transit_loc, des, tempNode->get_date(index));
			while (index < tempNode->date.Size())
			{
				transint = tempNode->deptime[index];
				for (int i = 0; i < tempNode1->size; i++)
				{
					desint = tempNode1->arrtime[i];
					if (tempNode1->day[i] >= tempNode->day[index] && desint - transint == trans_time)
					{
						flag = 1;
						break;
					}
				}

				if (tempVec.Size() > 0 && flag == 1)
				{
					toReturn.push_back(tempNode->to_string(index));
					for (int i = 0; i < tempVec.Size(); i++)
					{
						toReturn.push_back(tempVec[i]);
					}
				}
				index++;
				flag = 0;
			}
		}

		else
		{
			cout << "Transit location not found!" << endl;
		}
		return toReturn;
	}

	Vector<int> findArrTime(string src, string des, string date)
	{
		Vector<int> toReturn;
		Node* temp = cities[get_index(src)].head;
		while (temp->city_name != des)
		{
			temp = temp->next;
		}
		for (int i = 0; i < temp->date.Size(); i++)
		{
			if (temp->date[i] == date)
			{
				toReturn.push_back(temp->arrtime[i]);
			}
		}

		return toReturn;
	}

	//----------scenario 3-----------
	Vector<string> scenario3(string src, string dest, string transit_loc)
	{
		Vector<string> toReturn;
		Vector<string> tempVec;
		Node* tempNode = cities[get_index(src)].head;
		while (tempNode != NULL)
		{
			if (tempNode->city_name == transit_loc)
				break;
			tempNode = tempNode->next;
		}

		int index = 0;
		if (tempNode != NULL)
		{
			while (index < tempNode->date.Size())
			{
				tempVec = direct_Flights_(transit_loc, dest, tempNode->get_date(index));

				if (tempVec.Size() > 0)
				{
					toReturn.push_back(tempNode->to_string(index));
					for (int i = 0; i < tempVec.Size(); i++)
					{
						toReturn.push_back(tempVec[i]);
					}
				}
				index++;
			}
		}

		else
		{
			cout << "Transit location not found!" << endl;
		}

		return toReturn;
	}
	void shortestPath_requirments(string src,string date__) {
		int vertex = get_index(src);
		//cout << endl << endl << endl << vertex;
		/*int** weigh = get_cost_weight_wrt_date("4/12/2019");
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << weigh[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "\n \n \n";*/

		int** weights = get_cost_weight_wrt_date(date__);
		/*for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << weights[i][j] << "\t";
			}
			cout << endl;
		}*/
		for (int j = 0; j < size; j++) {
			smallest[j].data = weights[vertex][j];
		}
		bool* weightFound;
		weightFound = new bool[size];
		for (int j = 0; j < size; j++) {
			weightFound[j] = false;
		}
		weightFound[vertex] = true;
		smallest[vertex].data = 0;
		for (int i = 0; i < size - 1; i++) {
			double minWeight = DBL_MAX;
			int v;
			for (int j = 0; j < size; j++) {
				if (!weightFound[j]) {
					if (smallest[j].data < minWeight)
					{
						v = j;
						minWeight = smallest[v].data;
					}
				}
			}
			weightFound[v] = true;
			for (int j = 0; j < size; j++)
				if (!weightFound[j])
					if (minWeight + weights[v][j] < smallest[j].data) {
						smallest[j].data = minWeight + weights[v][j];
						//cout << get_city(v) << "\t" << get_city(j) << endl;
					}

		} //end for}
	}
	struct temp1 {
		Vector<string> temp;
		int data1;
	};
	struct temp2 {
		double data;
		string path;
	};
	temp1** get_cost_weight_Node() {
		temp1** weights = new temp1* [size];
		for (int i = 0; i < size; i++) {
			weights[i] = new temp1[size];
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (i == j) {
					weights[i][j].data1 = 0;
				}
				else {
					weights[i][j].data1 = INT32_MAX;
				}
			}
		}
		for (int i = 0; i < size; i++) {
			Node* ptr = cities[i].head;
			while (ptr != NULL) {
				weights[i][ptr->destination_index].data1 = ptr->min_cost();
				weights[i][ptr->destination_index].temp.push_back(ptr->to_string(ptr->get_minCost_index()));
				ptr = ptr->next;
			}
		}
		//Node* ptr = cities[0].head->next;
		//cout<<"oooooooooopsssssss"<<ptr->min_cost_requirment_air_dat("Emirates","1/12/2019")<<"\n \n \n \n";
		return weights;
	}
	temp1** get_duration_Node_date(string date__) {
		temp1** weights = new temp1 * [size];
		for (int i = 0; i < size; i++) {
			weights[i] = new temp1[size];
		}
		/*
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (i == j) {
					weights[i][j].data1 = 0;
				}
				else {
					weights[i][j].data1 = INT32_MAX;
				}
			}
		}
		*/
		for (int i = 0; i < size; i++) {
			Node* ptr = cities[i].head;
			while (ptr != NULL) {
				weights[i][ptr->destination_index].data1 = ptr->min_duration_requirment_dat(date__);
				//cout << weights[i][ptr->destination_index].data1<<" ";
				weights[i][ptr->destination_index].temp.push_back(ptr->to_string(ptr->get_minDuration_date_index(date__)));
				//cout << ptr->to_string(ptr->get_minCost_index())<<"\n";
				ptr = ptr->next;
			}
			//cout << "\n";
		}/*
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << weights[i][j].data1 << " ";
			}
			cout << "\n";
		}*/
		//Node* ptr = cities[0].head->next;
		//cout<<"oooooooooopsssssss"<<ptr->min_cost_requirment_air_dat("Emirates","1/12/2019")<<"\n \n \n \n";
		return weights;
	}
	temp1** get_weight_Node_date(string date__) {
		temp1** weights = new temp1 * [size];
		for (int i = 0; i < size; i++) {
			weights[i] = new temp1[size];
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (i == j) {
					weights[i][j].data1 = 0;
				}
				else {
					weights[i][j].data1 = INT32_MAX;
				}
			}
		}
		for (int i = 0; i < size; i++) {
			Node* ptr = cities[i].head;
			while (ptr != NULL) {
				weights[i][ptr->destination_index].data1 = ptr->min_cost_requirment_dat(date__);
				//cout << weights[i][ptr->destination_index].data1<<" ";
				weights[i][ptr->destination_index].temp.push_back(ptr->to_string(ptr->get_minCost_date_index(date__)));
				cout << ptr->to_string(ptr->get_minCost_index())<<"\n";
				ptr = ptr->next;
			}
			//cout << "\n";
		}
		/*for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << weights[i][j].data1 << " ";
			}
			cout << "\n";
		}*/
		//Node* ptr = cities[0].head->next;
		//cout<<"oooooooooopsssssss"<<ptr->min_cost_requirment_air_dat("Emirates","1/12/2019")<<"\n \n \n \n";
		return weights;
	}
	//----
	temp1** get_weight_Node_date_airline(string date__,string air) {
		temp1** weights = new temp1 * [size];
		for (int i = 0; i < size; i++) {
			weights[i] = new temp1[size];
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (i == j) {
					weights[i][j].data1 = 0;
				}
				else {
					weights[i][j].data1 = INT32_MAX;
				}
			}
		}

		for (int i = 0; i < size; i++) {
			Node* ptr = cities[i].head;
			while (ptr != NULL) {
				weights[i][ptr->destination_index].data1 = ptr->min_cost_requirment_air_dat(air,date__);
				//cout << weights[i][ptr->destination_index].data1<<" ";
				weights[i][ptr->destination_index].temp.push_back(ptr->to_string(ptr->get_minCost_date_airline_index(date__,air)));
				//cout << ptr->to_string(ptr->get_minCost_index())<<"\n";
				ptr = ptr->next;
			}
			//cout << "\n";
		}
		//Node* ptr = cities[0].head->next;
		//cout<<"oooooooooopsssssss"<<ptr->min_cost_requirment_air_dat("Emirates","1/12/2019")<<"\n \n \n \n";
		return weights;
	}

	//------
	void shortest_Duration_wrt_dat(string src, string dat__) {
		int vertex = get_index(src);

		temp1** weights = get_duration_Node_date(dat__);// get_weight_Node_date(dat__);
		/*for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << weights[i][j] << "\t";
			}
			cout << endl;
		}*/
		for (int j = 0; j < size; j++) {
			smallest[j].data = weights[vertex][j].data1;
			if (weights[vertex][j].temp.Size() >= 0) {
				for (int i = 0; i < weights[vertex][j].temp.Size(); i++) {
					smallest[j].x.push_back(weights[vertex][j].temp[i]);
				}
			}
		}
		bool* weightFound;
		weightFound = new bool[size];
		for (int j = 0; j < size; j++) {
			weightFound[j] = false;
		}
		weightFound[vertex] = true;
		smallest[vertex].data = 0;

		for (int i = 0; i < size - 1; i++) {
			//double minWeight = DBL_MAX;
			temp2 minWeight;
			minWeight.data = DBL_MAX;
			minWeight.path = "dsfsddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd";
			int v;
			for (int j = 0; j < size; j++) {
				if (!weightFound[j]) {
					if (smallest[j].data < minWeight.data)
					{
						v = j;
						minWeight.data = smallest[v].data;
						if (smallest[v].x.Size() >= 0) {
							//	cout << "aa bail mjy mar\n";
							//	cout << smallest[v].x[0] << endl;
							for (int i = 0; i < smallest[v].x.Size(); i++)
								minWeight.path = smallest[v].x[i];
						}
						//minWeight.path = smallest[v].x[0];
					}
				}
			}
			weightFound[v] = true;
			for (int j = 0; j < size; j++)
				if (!weightFound[j])
					if (minWeight.data + weights[v][j].data1 < smallest[j].data) {
						smallest[j].data = minWeight.data + weights[v][j].data1;
						smallest[j].x.push_back(minWeight.path);
						for (int i = 0; i < weights[v][j].temp.Size(); i++) {
							smallest[j].x.push_back(weights[v][j].temp[i]);
						}
						//cout << get_city(v) << "\t" << get_city(j)<<endl;
					}

		} //end for}
	}

	
	///////////////////////shortest path wrt date
	void shortestPath_wrt_dat(string src,string dat__) {
		int vertex = get_index(src);

		temp1** weights = get_weight_Node_date(dat__);// get_weight_Node_date(dat__);
		/*for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << weights[i][j] << "\t";
			}
			cout << endl;
		}*/
		for (int j = 0; j < size; j++) {
			smallest[j].data = weights[vertex][j].data1;
			if (weights[vertex][j].temp.Size() >= 0) {
				for (int i = 0; i < weights[vertex][j].temp.Size(); i++) {
					smallest[j].x.push_back(weights[vertex][j].temp[i]);
				}
			}
		}
		bool* weightFound;
		weightFound = new bool[size];
		for (int j = 0; j < size; j++) {
			weightFound[j] = false;
		}
		weightFound[vertex] = true;
		smallest[vertex].data = 0;

		for (int i = 0; i < size - 1; i++) {
			//double minWeight = DBL_MAX;
			temp2 minWeight;
			minWeight.data = DBL_MAX;
			minWeight.path = "dsfsddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd";
			int v;
			for (int j = 0; j < size; j++) {
				if (!weightFound[j]) {
					if (smallest[j].data < minWeight.data)
					{
						v = j;
						minWeight.data = smallest[v].data;
						if (smallest[v].x.Size() >= 0) {
							//	cout << "aa bail mjy mar\n";
							//	cout << smallest[v].x[0] << endl;
							for (int i = 0; i < smallest[v].x.Size(); i++)
								minWeight.path = smallest[v].x[i];
						}
						//minWeight.path = smallest[v].x[0];
					}
				}
			}
			weightFound[v] = true;
			for (int j = 0; j < size; j++)
				if (!weightFound[j])
					if (minWeight.data + weights[v][j].data1 < smallest[j].data) {
						smallest[j].data = minWeight.data + weights[v][j].data1;
						smallest[j].x.push_back(minWeight.path);
						for (int i = 0; i < weights[v][j].temp.Size(); i++) {
							smallest[j].x.push_back(weights[v][j].temp[i]);
						}
						//cout << get_city(v) << "\t" << get_city(j)<<endl;
					}

		} //end for}
	}

	///////////////////////-----------------------
	///for scenario 1
	void shortestPath_wrt_date_airline(string src, string dat__,string air) {
		int vertex = get_index(src);

		temp1** weights = get_weight_Node_date_airline(dat__,air);// get_weight_Node_date(dat__);
		/*for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << weights[i][j] << "\t";
			}
			cout << endl;
		}*/
		for (int j = 0; j < size; j++) {
			smallest[j].data = weights[vertex][j].data1;
			if (weights[vertex][j].temp.Size() >= 0) {
				for (int i = 0; i < weights[vertex][j].temp.Size(); i++) {
					smallest[j].x.push_back(weights[vertex][j].temp[i]);
				}
			}
		}
		bool* weightFound;
		weightFound = new bool[size];
		for (int j = 0; j < size; j++) {
			weightFound[j] = false;
		}
		weightFound[vertex] = true;
		smallest[vertex].data = 0;

		for (int i = 0; i < size - 1; i++) {
			//double minWeight = DBL_MAX;
			temp2 minWeight;
			minWeight.data = DBL_MAX;
			minWeight.path = "dsfsddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd";
			int v;
			for (int j = 0; j < size; j++) {
				if (!weightFound[j]) {
					if (smallest[j].data < minWeight.data)
					{
						v = j;
						minWeight.data = smallest[v].data;
						if (smallest[v].x.Size() >= 0) {
							//	cout << "aa bail mjy mar\n";
							//	cout << smallest[v].x[0] << endl;
							for (int i = 0; i < smallest[v].x.Size(); i++)
								minWeight.path = smallest[v].x[i];
						}
						//minWeight.path = smallest[v].x[0];
					}
				}
			}
			weightFound[v] = true;
			for (int j = 0; j < size; j++)
				if (!weightFound[j])
					if (minWeight.data + weights[v][j].data1 < smallest[j].data) {
						smallest[j].data = minWeight.data + weights[v][j].data1;
						smallest[j].x.push_back(minWeight.path);
						for (int i = 0; i < weights[v][j].temp.Size(); i++) {
							smallest[j].x.push_back(weights[v][j].temp[i]);
						}
						//cout << get_city(v) << "\t" << get_city(j)<<endl;
					}

		} //end for}
	}

	
	//---------
	void shortestPath(string src) {
		int vertex = get_index(src);
		
		temp1** weights = get_cost_weight_Node();
		/*for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << weights[i][j] << "\t";
			}
			cout << endl;
		}*/
		for (int j = 0; j < size; j++) {
			smallest[j].data = weights[vertex][j].data1;
			if (weights[vertex][j].temp.Size() >= 0) {
				for (int i = 0; i < weights[vertex][j].temp.Size(); i++) {
					smallest[j].x.push_back(weights[vertex][j].temp[i]); 
				}
			}
		}
		bool* weightFound;
		weightFound = new bool[size];
		for (int j = 0; j < size; j++) {
			weightFound[j] = false;
		}
		weightFound[vertex] = true;
		smallest[vertex].data = 0;
		
		for (int i = 0; i < size - 1; i++){
			//double minWeight = DBL_MAX;
			temp2 minWeight;
			minWeight.data = DBL_MAX;
			minWeight.path = "dsfsddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd";
			int v;
			for (int j = 0; j < size; j++) {
				if (!weightFound[j]) {
					if (smallest[j].data < minWeight.data)
					{
						v = j;
						minWeight.data = smallest[v].data;
						if (smallest[v].x.Size() >= 0) {
						//	cout << "aa bail mjy mar\n";
						//	cout << smallest[v].x[0] << endl;
							for(int i=0;i<smallest[v].x.Size();i++)
							minWeight.path = smallest[v].x[i];
							cout << minWeight.path << endl;
						}
							//minWeight.path = smallest[v].x[0];
					}
				}
			}
			weightFound[v] = true;
			for (int j = 0; j < size; j++)
				if (!weightFound[j])
					if (minWeight.data + weights[v][j].data1 < smallest[j].data) {
						smallest[j].data = minWeight.data + weights[v][j].data1;
						smallest[j].x.push_back(minWeight.path);
						for (int i = 0; i < weights[v][j].temp.Size();i++) {
							smallest[j].x.push_back(weights[v][j].temp[i]);
						}
					
						//cout << get_city(v) << "\t" << get_city(j)<<endl;
					}

			} //end for}
	}
	string get_city(int index) {
		return cities[index].origon;
	}
	Vector<string> printShortestDistance(string src,string destination) {
		int vertex = get_index(src);
		int desti_index = get_index(destination);
		cout << "Source Vertex: " << vertex << endl; cout << "Shortest Distance from Source to each Vertex." << endl; cout << "Vertex Shortest_Distance" << endl;
		//for (int j = 0; j < size; j++){
			cout << setw(4) << get_city(desti_index) << setw(12) << smallest[desti_index].data << endl;
			for (int i = 0; i < smallest[desti_index].x.Size(); i++) {
				cout<<smallest[desti_index].x[i]<<endl;
			}
			return smallest[desti_index].x;
	}
		//cout << endl;
	//} //end printShortestDistance

};
