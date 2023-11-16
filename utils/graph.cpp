#include"graph.h"

using namespace std;

void split(vector<string> &input_token, string data){
	string tmp;
	stringstream ss(data);
	int i = 0;

	while(getline(ss,tmp,' ')){
		if(tmp != "")
			input_token.push_back(tmp);
	}
}

int string_array_size(string *data){
	int i =0;
	while(data[i] != "\0"){
		//cout<<i<<"\t"<<data[i]<<endl;
		i++;
	}
	return i;
}


class node{
public:
	string data;
	node *next;
	vector<string>pre;
	vector<string>post;
	node(string input_data){
		data = input_data;
		next = NULL;
	}
};

class graph{
public:
	node *head;

	graph(){
		head = new node("head");
	}

	void add(string data){
		int flag = 1;
		node *current = head;
		while(current->next != NULL){
			if(current->data.compare(data) == 0){
				flag = 0;
				break;
			}
			current = current->next;
		}
		if(flag){
			current->next = new node(data);
			
		}

	}

	int compare_data(string data){
		int flag = 1;
		node *current = head;
		while(current->next != NULL){
			if(current->data.compare(data) == 0){
				flag = 0;
				break;
			}
			current = current->next;
		}
		return flag;
	}

	void pre(string data, string pre){
		int flag = 0;
		node *current = head;
		while(current->next != NULL){
			if(current->data == data){
				flag = 1;
				break;
			}
			current = current->next;
		}
		if(flag){
			current->pre.push_back(pre);
		}
	}

	void post(string data, string post){
		int flag = 0;
		node *current = head;
		while(current->next != NULL){
			if(current->data == data){
				flag = 1;
				break;
			}
			current = current->next;
		}
		if(flag){
			current->post.push_back(post);
		}
	}

	void test(){
		string input;
		int count = 0;
		node *current;
		cout<<"Please input a node: ";
		cin>>input;
		while(input != "0"){
			current = head->next;
			while(current != NULL){
				if(current->data == input){
					cout<<"predecessor: ";
					count = 0;
					for(int i = 0; i < current->pre.size() ; i++){
						if(count != 0)
							cout<<", ";
						cout<<current->pre[i];
						count++;
					}
					count = 0;
					cout<<endl<<"successor: ";
					for(int i = 0; i < current->post.size() ; i++){
						if(count != 0)
							cout<<", ";
						cout<<current->post[i];
						count++;

					}
					
					cout<<endl;
					break;
				}
				current = current->next;
			}

			cout<<"Please input a node: ";
			cin>>input;
		}

	}

	void show(){
		node *current = head->next;
		while(current != NULL){
			cout<<"node: ";
			cout<<current->data<<endl;
			cout<<"predecessor: ";
			for(int i = 0; i < current->pre.size() ; i++)
				cout<<current->pre[i]<<" ";
			cout<<endl<<"successor: ";
			for(int i = 0; i < current->post.size() ; i++)
				cout<<current->post[i]<<" ";
			cout<<endl<<endl;

			current = current->next;
		}
		cout<<endl;
	}
};