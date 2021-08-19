#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "functions.h"

/* reads problem description from source data struct and fills `problem' data
 * type accordingly */
void read_problem_description(struct problem *specific_problem){

	int number_of_sets = 6, number_of_elements = 9;
  
  specific_problem->number_of_sets = number_of_sets;
  specific_problem->number_of_elements = number_of_elements;

	// initialize with largest float (normal) number
	specific_problem->minimum_efficiency = (float) 0x7f7fffff;

	// allocate and initialize set array
	specific_problem->sets = (struct set*)calloc(number_of_sets, sizeof(struct set));
	for (int i = 0; i < number_of_sets; ++i) {
		specific_problem->sets[i].index_of_root_element = 0;
		specific_problem->sets[i].elements = (struct dynamic_array_element*)malloc(sizeof(struct dynamic_array_element));
		initialize_element(specific_problem->sets[i].elements);
	}

	// allocate and initialize element-value-table
  specific_problem->element_value_table = (struct dynamic_array_index_pair*)calloc(number_of_elements, sizeof(struct dynamic_array_index_pair));
	for (int i = 0; i < number_of_elements; ++i)
		initialize(&(specific_problem->element_value_table[i]));

}