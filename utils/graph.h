#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#define MAX_SIZE 10000

int string_array_size(string *data);
void split(vector<string> &input_token, string data);

class node{
public:
	string data;
	node *next;
	vector<string>pre;
	vector<string>post;
	node(string input_data);
};

class graph{
public:
	node *head;
	graph();
    int compare_data(string data);
	void add(string data);
	void pre(string data, string pre);
	void post(string data, string post);
	void test();
	void show();
};