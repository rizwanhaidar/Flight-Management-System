#pragma once

#include <iostream>
#include"Vector.h"
#include<iostream> 
#include <sstream>  // for string streams 
#include <string>  // for string 
using namespace std;

struct Node
{
	string city_name;
	Vector<string> dep_time;
	Vector<string> arr_time;
	Vector<string> date;
	Vector<string> flight_name;
	Vector<int> cost_;
	Vector<int> time_duration;
	Vector<int> day;
	Vector<int> arrtime;
	Vector<int> deptime;
	int size;
	int destination_index = -1;
	Node* next;
	string prev;

public:
	Node()
	{
		next = NULL;
		city_name = "";
	}

	string get_date(int index)
	{
		return date[index];
	}

	int min_cost() {
		int min = cost_[0];
		for (int i = 0; i < getsize(); i++) {
			if (cost_[i] < min) {
				min = cost_[i];
			}
		}
		return min;
	}
	int get_minCost_index() {
		int min = cost_[0];
		int index = 0;
		for (int i = 0; i < getsize(); i++) {
			if (cost_[i] < min) {
				min = cost_[i];
				index = i;
			}
		}
		return index;
	}
	int get_minCost_date_index(string dat) {
		int min = cost_[0];
		int index = 0;
		for (int i = 0; i < getsize(); i++) {
			if (date[i] == dat) {
				if (cost_[i] < min) {
					min = cost_[i];
					index = i;
				}
			}
		}
		return index;
	}
	int get_minCost_date_airline_index(string dat,string air) {
		int min = cost_[0];
		int index = 0;
		for (int i = 0; i < getsize(); i++) {
			if (date[i] == dat) {
				if (flight_name[i]==air) {
					if (cost_[i] < min) {
						min = cost_[i];
						index = i;
					}
				}
			}
		}
		return index;
	}
	int min_duration() {
		int min = time_duration[0];
		
		return min;
	}
	int max_cost() {
		int max = cost_[0];
		for (int i = 0; i < getsize(); i++) {
			if (cost_[i] > max) {
				max = cost_[i];
			}
		}
		return max;
	}
	int get_minDuration_date_index(string dat) {
		int min = time_duration[0];
		int index = 0;
		for (int i = 0; i < getsize(); i++) {
			if (date[i] == dat) {
				if (time_duration[i] < min) {
					min = time_duration[i];
					index = i;
				}
			}
		}
		return index;
	}
	int min_cost_requirment_air_dat(string air,string dat) {
		int min_cost = 987654321;//max_cost();
		int index=0;
		//string flight = flight_name[0];
		//string date_ = date[0];
		
		for (int i = 0; i < getsize(); i++) {
			if (date[i] == dat) {
				if (flight_name[i]==air) {
					if (cost_[i]<min_cost) {
						min_cost = cost_[i];
					}
				}
			}
		}
		return min_cost;
	}
	int min_cost_requirment_dat(string dat) {
		int min_cost = 987654321;//max_cost();
		int index = 0;
		//string flight = flight_name[0];
		//string dat = date[0];

		for (int i = 0; i < getsize(); i++) {
			if (date[i] == dat) {
				if (cost_[i] < min_cost) {
					min_cost = cost_[i];
				}
			}
		}
		return min_cost;
	}
	int min_duration_requirment_dat(string dat) {
		int min_duration = 987654321;//max_cost();
		//int index = 0;
		//string flight = flight_name[0];
		//string dat = date[0];

		for (int i = 0; i < getsize(); i++) {
			if (date[i] == dat) {
				if (time_duration[i] < min_duration) {
					min_duration = time_duration[i];
				}
			}
		}
		return min_duration;
	}
	Node* operator=(Node* input)
	{
		city_name = input->city_name;
		dep_time = input->dep_time;
		arr_time = input->arr_time;
		flight_name = input->flight_name;
		date = input->date;
		cost_ = input->cost_;
		time_duration = input->time_duration;
		return this;
	}

	string to_string(int index) {

		string to_ret;
		ostringstream str2;

		// Sending a number as a stream into output 
		// string 
		str2 << destination_index;
		// the str() coverts number into string 
		string geek1 = str2.str();
		to_ret.append(geek1);
		to_ret.append(")  -  ");
		to_ret.append(city_name);
		to_ret.append("  -  ");
		to_ret.append(date[index]);
		to_ret.append("  -  ");
		to_ret.append(dep_time[index]);
		to_ret.append("  -  ");
		to_ret.append(arr_time[index]);
		to_ret.append("  -  ");
		int time_duration1 = time_duration[index];
		//cout << time_duration1 << endl;
		ostringstream str3;
		str3 << time_duration1;
		string geek3 = str3.str();

		to_ret.append(geek3);
	//	to_ret.append(flight_name[index]);
		to_ret.append("  -  ");
		int cost = cost_[index];
		//	 cout << cost;
			 // declaring output string stream 
		ostringstream str1;

		// Sending a number as a stream into output 
		// string 
		str1 << cost;

		// the str() coverts number into string 
		string geek = str1.str();
		//string cost1 = to_string(1);
		//cout << cost;
		//cout << cost_[index];
		to_ret.append(geek);
		to_ret.append("  -  ");
		to_ret.append(flight_name[index]);
	

	
		return to_ret;

	}
public:
	int getsize() {
		return dep_time.Size();
	}
	Vector<string>  to_string() {
		Vector<string> to_ret;

		for (int i = 0; i < getsize(); i++) {

			to_ret.push_back(to_string(i));

		}
		return to_ret;
	}
};


class List
{
public:
	string origon;//from the city
	Node* head;
	Node* tail;
	int source_index = -1;
	int size = 0;
	int hotel_charges;

public:
	List():hotel_charges(0)
	{
		head = NULL;
		tail = NULL;
	}

	bool isEmpty()
	{
		if (head == NULL)
			return true;

		return false;
	}
	void get_links_printed_()
	{
		//cout << "Lets try to print link\n";
		//cout << head->next->city_name;

		int x = 8;
		Node* temp = head;
		while (temp != NULL) {
			cout << endl << "-->" << temp->city_name << endl;
			Vector<string> complete_data = temp->to_string();
			for (int i = 0; i < complete_data.Size(); i++) {
				cout << complete_data[i] << endl;
			}
			temp = temp->next;
			x++;
			if (x % 8 == 0) {
				cout << endl;
			}
		}
		temp = NULL;
		delete temp;
		cout << endl;
	}
	void insert(Node* temp)
	{
		//cout << temp->city_name << endl;
		if (isEmpty())
		{
			//cout << "Nigga is Empty\n";
			head = new Node;


			head = temp;
			tail = temp;
		}

		else
		{
			//cout << temp->to_string()<<endl;
			size++;
			temp->prev = origon;
			tail->next = temp;
			tail = temp;
			//cout << tail->to_string()<<endl;

			temp = NULL;
			delete temp;
		}
	}
};
