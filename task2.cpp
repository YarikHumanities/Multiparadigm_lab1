#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//SECOND TASK
int QUANT_LIMIT = 5;
string str_FILE = "Pride_And.txt";
int main() {
	int splitted_size = 0;
	int init_counter = 0;
	int counter_for_mem = 0;
	int additional_counter = 0;
	bool already_in_matrix;
	int start_for_num = 0, end_for_num = 0;
	bool already_in_pages = false;
	bool already_in_nums = false;
	int quant_of_times = 0;
	string temp_str = "";
	int temp_page;
	string NumberAsString;
	//string* splitted_array = new string[splitted_size];
	
	string forbidden_word;
	string* forbidden = new string[splitted_size];
	string* new_forbidden;
	int row_to_delete;
	std::ifstream inFile;
	inFile.open(str_FILE);
	int quant = 0;
	int page = 1;


	bool first_matrix_insert = true;
	int rows = 1;
	int cols = 2;
	string** matrix = new string * [rows];
	string** new_matrix;
	init_counter = 0;
matrix_allocation:
	matrix[init_counter] = new string[cols];
	++init_counter;
	if (init_counter < rows) {
		goto matrix_allocation;
	}

	if (!inFile.is_open()) {
		std::cout << "Cannot open the file" << std::endl;
	}
	else
	{
		std::cout << "File opened" << std::endl;

		string str;
	end_of_file:
		if (!inFile.eof()) {
		
				str = "";
				getline(inFile, str);
				if (str.size() > 0)
				{
					quant++;
					if (quant % 45 == 0) {
						//cout <<endl<< "Current page: " << page << endl;
						page++;
					}

					int start = 0, end = 0;

				cycle_start:
					start = end;

				first_while:
					if (start < str.size() && (str[start] == ' ' || str[start] == '.' || str[start] == ',' || str[start] == '"' || str[start] == '!' || str[start] == '?' || str[start] == ';')) {
						++start;
						goto first_while;
					}
					
					end = start;

				second_while:
					if (end < str.size() && (str[end] != ' ' && str[end] != '.' && str[end] != ',' && str[end] != '"' && str[end] != '!' && str[end] != '?' && str[end] != ';')) {
						++end;
						goto second_while;
					}
					

					string our_part = "";
					init_counter = start;
				substring_label:
					if (str[init_counter] >= 65 && str[init_counter] <= 90) {
						str[init_counter] = str[init_counter] + 32;
					}
					our_part += str[init_counter];
					++init_counter;
					if (init_counter < end) {
						goto substring_label;
					}
					if (our_part.size() <= 3) {
						goto continue_for_small;
					}

					already_in_matrix = false;
					additional_counter = 0;
					search_for_repeat:
					
					init_counter = 0;
					check_if_forbidden:
						
							if (forbidden[init_counter] == our_part) {
								goto continue_for_small;
							}
						
						init_counter++;
						if (init_counter < splitted_size) {
							goto check_if_forbidden;
						}
						if (matrix[additional_counter][0] == our_part) {
							already_in_matrix = true;
							
							start_for_num = 0;
							end_for_num = 0;
							//cout << "String before cut fot num: " << matrix[i][1] << endl;
						cycle_start_for_num:
							start_for_num = end_for_num;

						first_while_for_num:
							if (start_for_num < matrix[additional_counter][1].size() && matrix[additional_counter][1][start_for_num] == ' ') {
								++start_for_num;
							}
						
							end_for_num = start_for_num;

						second_while_for_num:
							if (end_for_num < matrix[additional_counter][1].size() && matrix[additional_counter][1][end_for_num] != ' ') {
								++end_for_num;
							}
							

							string our_num = "";


							init_counter = start_for_num;

						label_for_subs_num:
							our_num += matrix[additional_counter][1][init_counter];        //substr word - our num
							++init_counter;
							if (init_counter < end_for_num) {
								goto label_for_subs_num;
							}
							
							quant_of_times++;
							
							if (end_for_num < matrix[additional_counter][1].size()) {
								goto cycle_start_for_num;
							}
							
							if (quant_of_times >= QUANT_LIMIT || (quant_of_times + 1) >= QUANT_LIMIT) {        //TODO: delete matrix[i][0-1]
								forbidden_word = our_part;
								row_to_delete = additional_counter;
								delete[] matrix[row_to_delete];
								string** tmp = new string * [rows - 1];
								int tmpI = 0;
								for (int i = 0; i < rows; ++i)
									if (i != row_to_delete)
										tmp[tmpI++] = matrix[i];

								delete[] matrix;
								matrix = tmp;
								rows = rows - 1;



								init_counter = 0;
								//fill_splited_array_label:
								string* new_forbidden = new string[splitted_size + 1];
								
							rellocate_forbidden:
								if (splitted_size != 0) {

									new_forbidden[init_counter] = forbidden[init_counter];
									//}
									init_counter++;
									if (init_counter < splitted_size) {
										goto rellocate_forbidden;
									}
								}
								
								//array_adding_continue:
								new_forbidden[splitted_size] = forbidden_word;
								splitted_size++;
								delete[] forbidden;
								forbidden = new_forbidden;
							}
							
							NumberAsString = "\0";
							temp_page = page;
						string_to_num_label:
							
							if (temp_page) {
								NumberAsString = char(temp_page % 10 + '0') + NumberAsString, temp_page /= 10;
								goto string_to_num_label;
							}

							//matrix[additional_counter][1] += " " + to_string(page);
							matrix[additional_counter][1] += " " + NumberAsString;

							
							quant_of_times = 0;
							goto continue_for_small;

						}
				
					additional_counter++;
					if (additional_counter < rows) {
						goto search_for_repeat;
					}


					if (first_matrix_insert) {
						--rows;
						first_matrix_insert = false;
					}

					new_matrix = new string * [rows + 1];

					counter_for_mem = 0;
				new_matrix_init:

					new_matrix[counter_for_mem] = matrix[counter_for_mem];
					counter_for_mem++;
					if (counter_for_mem < rows) {
						goto new_matrix_init;
					}
					new_matrix[rows] = new string[cols];
					new_matrix[rows][0] = our_part;

					NumberAsString = "\0";
					temp_page = page;
				string_to_num_label_2:

					if (temp_page) {
						NumberAsString = char(temp_page % 10 + '0') + NumberAsString, temp_page /= 10;
						goto string_to_num_label_2;
					}

					//new_matrix[rows][1] = to_string(page);
					new_matrix[rows][1] = NumberAsString;
					++rows;
					delete[] matrix;
					matrix = new_matrix;
					
				continue_for_small:
					if (end < str.size()) {
						goto cycle_start;
					}
				}
			
				goto end_of_file;
		}
	}

	bool swapped;
	init_counter = 0;
sort_first_loop:

	swapped = false;
	counter_for_mem = 0;
sort_second_loop:

	if (matrix[counter_for_mem][0] > matrix[counter_for_mem + 1][0]) {
		//cout << "Swapping" << endl;
		string* temp = matrix[counter_for_mem];
		matrix[counter_for_mem] = matrix[counter_for_mem + 1];
		matrix[counter_for_mem + 1] = temp;
		swapped = true;
	}

	counter_for_mem++;
	if (counter_for_mem < rows - init_counter - 1) {
		goto sort_second_loop;
	}
continue_sort_when_empty:
	if (!swapped) {
		//break;
		goto exit_sort;
	}

	init_counter++;
	if (init_counter < rows - 1) {
		goto sort_first_loop;
	}



exit_sort:
	cout << "Sorted Matrix" << endl;

	init_counter = 0;
outter_print_matrix:
	
	counter_for_mem = 0;
inner_print_matrix:
	
	cout << "'" << matrix[init_counter][counter_for_mem] << "'" << " ";              //just for tests

	counter_for_mem++;
	if (counter_for_mem < cols) {
		goto inner_print_matrix;
	}
	cout << endl;

	init_counter++;
	if (init_counter < rows) {
		goto outter_print_matrix;
	}



	cout << "End now sorted matrix in final way of printing" << endl;
	int start_print = 0, end_print = 0;
	string our_print_part = "";
	string previous_num = "";
	counter_for_mem = 0;
	final_printing:
	//for (int i = 0; i < rows; i++)
	//{
		start_print = 0, end_print = 0;
		cout << "Word: " << matrix[counter_for_mem][0] << " - ";
		previous_num = "";
		bool its_first_page = true;

		cycle_start_print:
		start_print = end_print;

	first_fin_print_while:
		if (start_print < matrix[counter_for_mem][1].size() && matrix[counter_for_mem][1][start_print] == ' ') {
			++start_print;
			goto first_fin_print_while;
		}
		end_print = start_print;

	second_fin_print_while:
		if (end_print < matrix[counter_for_mem][1].size() && matrix[counter_for_mem][1][end_print] != ' ') {
			++end_print;
			goto second_fin_print_while;
		}

		our_print_part = "";
		init_counter = start_print;
	substring_label_for_print:
		
		our_print_part += matrix[counter_for_mem][1][init_counter];
		++init_counter;
		if (init_counter < end_print) {
			goto substring_label_for_print;
		}

		//cout << our_print_part << ", ";
		if (its_first_page) {
			its_first_page = false;
			previous_num = our_print_part;
			cout << our_print_part /*<<"(previous: "<<previous_num<<")"*/ << ", ";
		}
		else {
			if (previous_num != our_print_part) {
				cout << our_print_part /*<< "(previous: " << previous_num << ")"*/ << ", ";
				previous_num = our_print_part;
			}
		
		}

		


		if (end_print < matrix[counter_for_mem][1].size()) {
			goto cycle_start_print;
		}
		

		cout << endl;
	//}
		counter_for_mem++;
	if (counter_for_mem < rows) {
		goto final_printing;
	}
}