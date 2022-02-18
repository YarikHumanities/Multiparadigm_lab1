#include <iostream>
#include <string>
#include<vector>
using namespace std;
//FIRST TASK
string text = "     White tigers live mostly in India Wild   lions live mostly in Africa live africa live live live live live live live live live live live live live live live live live live live";

int main() {
	int splitted_size = 0;
	string* splitted_array = new string[splitted_size];
	string* new_splitted_array;
	int init_counter = 0;
	int counter_for_mem = 0;
	string NumberAsString;
init_label:
		/*splitted_array[init_counter] = "";
		init_counter+=1;
		if (init_counter < splitted_size) {
			goto init_label;
		}*/

	int start = 0, end = 0;
	//while (end < text.size()) {
cycle_start:
		start = end;
		first_while:
		/*while (start < text.size() && text[start] == ' ')
		{
			++start;
		}*/
		if (start < text.size() && text[start] == ' ') {
			++start;
			goto first_while;
		}
		end = start;

		second_while:
		/*while (end < text.size() && text[end] != ' ')
		{
			++end;
		}*/
		if (end < text.size() && text[end] != ' ') {
			++end;
			goto second_while;
		}
		string our_part="";

		init_counter = start;

	substring_label:
		//int init_counter_2 = 0;
		if (text[init_counter]>=65 && text[init_counter]<=90) {
			text[init_counter] += 32;
		}
		our_part += text[init_counter];
		++init_counter;
		if (init_counter < end) {
			goto substring_label;
		}
	
		if (our_part.size() < 3) {
			goto continue_if_small;
		}
		init_counter = 0;
	fill_splited_array_label:
		/*string**/ new_splitted_array = new string[splitted_size+1];
		counter_for_mem = 0;

	vector_adding_label:
		if (splitted_size == 0) {
			goto array_adding_continue;
		}
			
			new_splitted_array[counter_for_mem] = splitted_array[counter_for_mem];
			
			
			counter_for_mem++;
			if (counter_for_mem < splitted_size) {
				goto vector_adding_label;
			}
	
		

		array_adding_continue:
		new_splitted_array[splitted_size] = our_part;
		splitted_size++;
		delete[] splitted_array;
		splitted_array = new_splitted_array;
	

		continue_if_small:
		if (end < text.size()) {
			goto cycle_start;
		}


		counter_for_mem = 0;
		print_array:		
	
			cout <<"'"<< splitted_array[counter_for_mem] <<"'"<< " ";
		
		++counter_for_mem;
		if (counter_for_mem < splitted_size) {
			goto print_array;
		}

		
		cout << endl;


		//start to work with matrix
	
		bool first_matrix_insert = true;
		int rows = 1;
		int cols = 2;
		string** matrix = new string* [rows];
		string** new_matrix;
		init_counter = 0;
		matrix_allocation:
			matrix[init_counter] = new string[cols];
			++init_counter;
			if (init_counter < rows) {
				goto matrix_allocation;
			}

		init_counter = 0;
		int counter_inner = 0;
		int quant = 0;
		int our_i;
		int adding_to_matrix_counter;
		cout_cases_label_outter:
		
			string current_word = splitted_array[init_counter];
			bool word_already_in = false;
	
		
			int counter_for_matrix_check = 0;
			matrix_repeat_check:
				if (matrix[counter_for_matrix_check][0] == current_word) {
					word_already_in = true;
					goto continue_from_here;
				}
				++counter_for_matrix_check;
				if (counter_for_matrix_check < rows) {
					
					goto matrix_repeat_check;
				}
			
				continue_from_here:
			if (current_word.size()==1 || word_already_in) {
				++init_counter;
				if (init_counter < splitted_size) {
					goto cout_cases_label_outter;
				}
				goto continue_work_label;
			}

			quant = 0;

			our_i = 0;

			adding_to_matrix_counter = 0;
		add_to_matrix_label:
			
			if (first_matrix_insert) {
				//matrix[0][0] = current_word;
				--rows;
				//matrix[0][1] = '1';                     //TODO: first case should made somehow (now it's uncorrect hardcode not to break all) 
				first_matrix_insert = false;              //DONE
				//goto first_case;
			}

			new_matrix = new string * [rows+1];

			counter_for_mem = 0;
			new_matrix_init:
		
				new_matrix[counter_for_mem] = matrix[counter_for_mem];
			
			counter_for_mem++;
			if (counter_for_mem < rows) {
				goto new_matrix_init;
			}
			new_matrix[rows] = new string[cols];
			new_matrix[rows][0] = current_word;
			


			continue_after_adding_to_matrix_label:
			//cout << "Word " << init_counter << ": " << current_word<<" = ";
	
			cout_cases_label_inner:
			
				if (current_word == splitted_array[counter_inner]) {
					++quant;
				}
			
				++counter_inner;
				if (counter_inner < splitted_size) {
					goto cout_cases_label_inner;
				}
			
				
				NumberAsString = "\0";
				
				string_to_num_label:
				
					if (quant) {
						NumberAsString = char(quant % 10 + '0') + NumberAsString, quant /= 10;
						goto string_to_num_label;
					}
				



				//new_matrix[rows][1] = to_string(quant);
				new_matrix[rows][1] = NumberAsString;
					++rows;
					delete[] matrix;
					matrix = new_matrix;
				
		//first_case:
		++init_counter;
		if (init_counter < splitted_size) {
			counter_inner = 0;
			goto cout_cases_label_outter;
		}
		


		continue_work_label:
		


		int string_to_int_1 = 0;
		int string_to_int_2 = 0;
		bool swapped;
		init_counter = 0;
		sort_first_loop:
		
			swapped = false;
			counter_for_mem = 0;
			sort_second_loop:
			
			resume_sort_error:
				if (matrix[counter_for_mem + 1][0] == "") {
					goto continue_sort_when_empty;
				}
				if (matrix[counter_for_mem][0] == "" || matrix[counter_for_mem][0] == "a") {
					++counter_for_mem;
					goto resume_sort_error;
				}

				for (int i = 0; i < matrix[counter_for_mem][1].size(); i++) {
					string_to_int_1 += (matrix[counter_for_mem][1][i] - 48) * pow(10, (matrix[counter_for_mem][1].size() - i - 1));
				}
				for (int i = 0; i < matrix[counter_for_mem + 1][1].size(); i++) {
					string_to_int_2 += (matrix[counter_for_mem + 1][1][i] - 48) * pow(10, (matrix[counter_for_mem + 1][1].size() - i - 1));
				}

					if (stoi(matrix[counter_for_mem][1]) < stoi(matrix[counter_for_mem + 1][1])) {
						//cout << "Swapping" << endl;
						string* temp = matrix[counter_for_mem];
						matrix[counter_for_mem] = matrix[counter_for_mem + 1];
						matrix[counter_for_mem + 1] = temp;
						swapped = true;
					}
			
			counter_for_mem++;
			if (counter_for_mem< rows - init_counter - 1) {
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
	

}
