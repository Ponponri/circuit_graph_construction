#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

int main(int argc, char *argv[]){
	string input_txt, tmp_txt, pre_txt, tmp_txt0, node_txt;
	int flag = 0, flag1 = 0, flag2 = 0; //flag: Is the end of the line == "\", flag1: The line of the boolean equation, flag3: Number of model.
	ifstream myTxt(argv[1]);
	ofstream outTxt("function.out");
	graph g;
	vector<string>input_array;
	int i;
	while(getline(myTxt, input_txt)){
		vector<string>input_token;
		if(input_txt[input_txt.length()-1] == '\n'){
			input_txt[input_txt.length()-1] = '\0';
		}
		if(flag == 1){
			input_txt = pre_txt + input_txt;
		}
		split(input_token, input_txt);

		i = input_token.size();
		if(i>0){
			tmp_txt = input_token[i-1];
			if(tmp_txt[tmp_txt.length()-1] == '\\'){
				
				for(int j = input_txt.length()-1; j>=0;j--){
					if(input_txt[j] == '\\'){
						input_txt[j] = ' ';
						break;
					}
					input_txt[j] = ' ';
				}
				
				pre_txt = input_txt;
				flag = 1;
				continue;
			}
		} 
		flag = 0;
		
		if(input_token.size()>0){
			for(int i = 0;i<input_token.size();i++){
				tmp_txt = input_token[i];
			}
			if(flag1 > 0){
				if(input_txt[0] == '0' || input_txt[0] == '1' || input_txt[0] == '-'){

					vector<string>node_token;
					split(node_token,node_txt);
					tmp_txt = node_token[node_token.size()-1];
					if(flag1 == 1){
						outTxt<<tmp_txt<<" = ";
					}
					else{
						outTxt<<" + ";
					}
					tmp_txt = node_token[1];
					if(input_txt[0] == '0'){
						outTxt<<tmp_txt<<"' ";
					}
					else if(input_txt[0] == '1'){
						outTxt<<tmp_txt<<" ";
					}

					for(int i = 1; i<input_txt.length() ; i++){
						tmp_txt = node_token[i+1];
						if(input_txt[i] == '0'){
							outTxt<<tmp_txt<<"' ";
						}
						else if(input_txt[i] == '1'){
							outTxt<<tmp_txt<<" ";
						}
						else if(input_txt[i] == ' '){
							break;
						}
					}

					flag1++;
				}
				else{
					outTxt<<endl;
					flag1 = 0;
				}
			}

			tmp_txt = input_token[0];

			if(tmp_txt.compare(".model") == 0){
				outTxt<<"Node function:"<<endl;
				flag2++;
			}
			if(tmp_txt.compare(".end") == 0){
				outTxt<<"END"<<endl;
			}
			else if(tmp_txt.compare(".names") == 0){
				flag1 = 1;
				node_txt = input_txt;
				input_array.push_back(input_txt);
				for(int i = 1; i < input_token.size() ; i++){				
					tmp_txt = input_token[i];
					if(g.compare_data(tmp_txt) == 1){
						g.add(tmp_txt);
					}
				}
			}
			else if(tmp_txt.compare(".inputs") == 0 || tmp_txt.compare(".outputs") == 0){
				for(int i = 1; i < input_token.size() ; i++){				
					tmp_txt = input_token[i];
					if(g.compare_data(tmp_txt) == 1){
						g.add(tmp_txt);
					}
				}
			}
		}
	}

	for(int i = 0; i < input_array.size() ; i++){
		vector<string>input_token;

		tmp_txt = input_array[i];
		split(input_token, tmp_txt);
		tmp_txt0 = input_token[input_token.size()-1];
		for(int j = 1; j < input_token.size()-1 ; j++){				
			tmp_txt = input_token[j];
			g.pre(tmp_txt0, tmp_txt);
			g.post(tmp_txt, tmp_txt0);
		}
	}

	g.test();

	outTxt.close();
	myTxt.close();
	return 0;
}