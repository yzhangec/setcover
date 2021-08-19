struct index_pair {
  int set_index;
  int element_index;
};

struct element {
  int value;
  int index_previous;
  int index_next;
};

struct dynamic_array_index_pair {
  int size;
  int capacity;

  struct index_pair *data;

  void (*add)(struct index_pair, struct dynamic_array_index_pair *);
};

struct dynamic_array_element {
  int size;
	// ???
  int capacity;

  struct element *data;

  void (*add)(struct element, struct dynamic_array_element *);
};

struct set {
  float cost;
  float efficiency;
  int number_of_elements;
  int index_of_root_element;

	// all elements of a set is stored in a dynamic array
  struct dynamic_array_element *elements;
};

struct problem {
  // number of sets in problem
  int number_of_sets;
  // number of all elements in the universe set
  int number_of_elements;
  // record the index of set with smallest cost effectiveness
  int minimum_efficiency_set_index;
	// record the current value of smallest cost effectiveness
  float minimum_efficiency;
	// pair of set index and element index, e.g. first element in second set
  struct dynamic_array_index_pair *element_value_table;
	// all input sets in problem
  struct set *sets;
};

struct solution {
  // number of sets in problem
  int number_of_sets;
  // number of sets in solution
  int number_of_sets_picked;
  // number of all elements in the universe set
  int number_of_elements;
  // an indicator array with length of number_of_sets, 1 = picked/selected
  int *mask_of_picked_sets;
  // total cost
  double cost;
};