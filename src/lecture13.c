#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct tree_node {
  int key;
  struct tree_node *leftp, *rightp;
};

typedef struct tree_node tree_node;

tree_node *make_tree(int key, tree_node *left, tree_node *right);
void assert_allocation_success(void *alloc_pointer);
tree_node *insert_in_binary_search_tree(tree_node *tree_ptr, int e);
void print_tree(tree_node *tree_ptr);
void print_tree_helper(tree_node *tree_ptr, int level);
int tree_height(tree_node *tree_ptr);
int is_binary_search_tree(tree_node *tree_ptr);
//
int exercise12_7_and_12_8() {

  tree_node *tree4 = NULL;
  tree4 = insert_in_binary_search_tree(tree4, 6);
  tree4 = insert_in_binary_search_tree(tree4, 2);
  tree4 = insert_in_binary_search_tree(tree4, 1);
  tree4 = insert_in_binary_search_tree(tree4, 4);
  tree4 = insert_in_binary_search_tree(tree4, 3);
  tree4 = insert_in_binary_search_tree(tree4, 5);
  tree4 = insert_in_binary_search_tree(tree4, 7);
  tree4 = insert_in_binary_search_tree(tree4, 9);
  tree4 = insert_in_binary_search_tree(tree4, 8);

  // Invalid because the left child is greater than its parent
  tree_node *invalid_tree =
      make_tree(10, make_tree(15, NULL, NULL), // 15 > 10 - WRONG!
                make_tree(20, NULL, NULL));

  printf("tree4:\n");
  print_tree(tree4);
  // The exercise12_7:
  printf("Height of tree4: %d\n", tree_height(tree4));
  // Test the is_binary_search_tree function
  printf("\nIs tree4 a valid BST? %s\n",
         is_binary_search_tree(/*invalid_tree*/ tree4) ? "Yes" : "No");
  exit(EXIT_FAILURE);
}

tree_node *make_tree(int key, tree_node *left, tree_node *right) {
  tree_node *the_tree = malloc(sizeof(tree_node));
  assert_allocation_success(the_tree);
  the_tree->key = key;
  the_tree->leftp = left;
  the_tree->rightp = right;
  return the_tree;
}

void assert_allocation_success(void *alloc_pointer) {
  if (alloc_pointer == NULL) {
    printf("Allocation problems. Your program stops.");
    exit(EXIT_FAILURE);
  }
}

/* Insert the element e i the binary search tree, designated by tree_ptr.
   Drop the insertion if e is already in the tree.
   Return the tree  in terms of a pointer to its root node. */
tree_node *insert_in_binary_search_tree(tree_node *tree_ptr, int e) {
  if (tree_ptr == NULL) {
    /* Make a small tree rooted with e and empty subtrees */
    /* This branch is never reached via recursion */
    tree_node *the_tree = make_tree(e, NULL, NULL);
    return the_tree;
  } else if (e == tree_ptr->key) {
    /* Do nothing */
    return tree_ptr;
  } else if (e < tree_ptr->key && tree_ptr->leftp == NULL) {
    tree_node *the_tree = make_tree(e, NULL, NULL);
    tree_ptr->leftp = the_tree;
    return tree_ptr;
  } else if (e < tree_ptr->key) {
    insert_in_binary_search_tree(tree_ptr->leftp, e);
    return tree_ptr;
  } else if (e > tree_ptr->key && tree_ptr->rightp == NULL) {
    tree_node *the_tree = make_tree(e, NULL, NULL);
    tree_ptr->rightp = the_tree;
    return tree_ptr;
  } else { /* e > tree_ptr->key) */
    insert_in_binary_search_tree(tree_ptr->rightp, e);
    return tree_ptr;
  }
}

// void print_tree(tree_node *tree_ptr) { print_tree_helper(tree_ptr, 0); }

/* print the tree designated by tree_ptr as horizotally, as an indented text, on
   standard output. Empty subtrees are printed as "." if tree_ptr is passsed as
   NULL
void print_tree_helper(tree_node *tree_ptr, int level) {
  int i;

  /* print indented root
  for (i = 0; i < level; ++i)
    printf("   ");
  if (tree_ptr == NULL)
    printf(".\n"); /* Missing part
  else
    printf("%d\n", tree_ptr->key);

  if (tree_ptr != NULL) {
    /* print branches
    if (tree_ptr->leftp == NULL && tree_ptr->rightp == NULL) {
      /* print nothing
    } else if (tree_ptr->leftp != NULL && tree_ptr->rightp == NULL) {
      print_tree_helper(tree_ptr->leftp, level + 1);
      print_tree_helper(NULL, level + 1);
    } else if (tree_ptr->leftp == NULL && tree_ptr->rightp != NULL) {
      print_tree_helper(NULL, level + 1);
      print_tree_helper(tree_ptr->rightp, level + 1);
    } else {
      print_tree_helper(tree_ptr->leftp, level + 1);
      print_tree_helper(tree_ptr->rightp, level + 1);
    }
  }
}
*/

/* Helper function to print n spaces */
void print_spaces(int n) {
  for (int i = 0; i < n; i++)
    printf(" ");
}

/* Print the binary tree in a traditional tree format with branches
   Example:
       6
      / \
     2   7
    / \   \
   1   4   9
*/
void print_tree(tree_node *tree_ptr) { // BRACE 1: function opens
  if (tree_ptr == NULL) {
    printf("Empty tree\n");
    return;
  }

  // Calculate tree height and maximum width needed for display
  int h = tree_height(tree_ptr);
  int max_width = (1 << h) - 1; // 2^h - 1 gives max nodes at bottom level

  // Allocate a 2D array to store pointers to nodes at each level
  // levels[i] will contain all nodes (or NULLs) at level i
  tree_node ***levels = malloc(sizeof(tree_node **) * h);

  // Array to store the number of positions at each level
  // Level 0 has 1 node, level 1 has 2, level 2 has 4, etc.  (2^i)
  int *level_sizes = malloc(sizeof(int) * h);

  // Initialize each level's array
  for (int i = 0; i < h; i++) { // BRACE 2: first for loop opens
    level_sizes[i] = 1 << i;    // 2^i nodes at level i
    levels[i] = calloc(level_sizes[i],
                       sizeof(tree_node *)); // calloc initializes to NULL
  } // BRACE 2 closes

  // Place the root node at level 0, position 0
  levels[0][0] = tree_ptr;

  // Fill remaining levels by traversing from parents to children
  // For each node at position j in level i:
  //   - its left child goes to position 2*j in level i+1
  //   - its right child goes to position 2*j+1 in level i+1
  for (int i = 0; i < h - 1; i++) {            // BRACE 3: second for loop opens
    for (int j = 0; j < level_sizes[i]; j++) { // BRACE 4: nested for loop opens
      if (levels[i][j] != NULL) {
        levels[i + 1][2 * j] = levels[i][j]->leftp;
        levels[i + 1][2 * j + 1] = levels[i][j]->rightp;
      }
    } // BRACE 4 closes
  } // BRACE 3 closes

  // Print each level with appropriate spacing
  for (int i = 0; i < h; i++) { // BRACE 5: main printing for loop opens
    // Calculate spacing:    deeper levels have nodes closer together
    int spacing = max_width / level_sizes[i]; // Space allocated per node
    int leading = spacing / 2; // Initial indentation to center the level

    // Print leading spaces to center this level
    print_spaces(leading);

    // Print all nodes (or spaces for NULL) at this level
    for (int j = 0; j < level_sizes[i];
         j++) { // BRACE 6: node printing for loop opens
      if (levels[i][j] != NULL) {
        printf("%d", levels[i][j]->key);
      } else {
        printf(" "); // Print space for missing nodes
      }

      // Print spacing between nodes (except after the last node)
      if (j < level_sizes[i] - 1) {
        print_spaces(spacing - 1);
      }
    } // BRACE 6 closes
    printf("\n");

    // Print branch lines connecting to next level (/ and \)
    // Skip this for the last level (leaves have no children)
    if (i < h - 1) { // BRACE 7: if statement opens
      // Indent slightly less than the nodes to position branches
      print_spaces(leading - 1);

      // For each node position, print its left and right branches
      for (int j = 0; j < level_sizes[i];
           j++) { // BRACE 8: branch printing for loop opens
        // Print left branch (/) if left child exists
        if (levels[i][j] != NULL && levels[i][j]->leftp != NULL) {
          printf("/");
        } else {
          printf(" ");
        }

        // Space between / and \
        print_spaces(1);

        // Print right branch (\) if right child exists
        if (levels[i][j] != NULL && levels[i][j]->rightp != NULL) {
          printf("\\");
        } else {
          printf(" ");
        }

        // Print spacing before next node's branches
        if (j < level_sizes[i] - 1) {
          print_spaces(spacing - 3); // -3 accounts for the /, space, and \

        }
      }
      printf("\n");
    }
  }

  // Free all allocated memory
  for (int i = 0; i < h; i++) {
    free(levels[i]);
  }
  free(levels);
  free(level_sizes);
}

int int_max(int a, int b) { return a > b ? a : b; }

/* Opgave */
int tree_height(tree_node *tree_ptr) {
  if (tree_ptr == NULL) {
    return 0;
  }

  int left_height = tree_height(tree_ptr->leftp);
  int right_height = tree_height(tree_ptr->rightp);

  return (left_height > right_height ? left_height : right_height) + 1;
}

/* Opgaven */
int is_binary_search_tree(tree_node *tree_ptr) {
  // Empty tree is a valid BST
  if (tree_ptr == NULL) {
    return 1;
  }

  // Check left subtree:  all keys must be < current key
  if (tree_ptr->leftp != NULL && tree_ptr->leftp->key >= tree_ptr->key) {
    return 0;
  }

  // Check right subtree: all keys must be > current key
  if (tree_ptr->rightp != NULL && tree_ptr->rightp->key <= tree_ptr->key) {
    return 0;
  }

  // Recursively check both subtrees
  return is_binary_search_tree(tree_ptr->leftp) &&
         is_binary_search_tree(tree_ptr->rightp);
}

// <============== circular lists ==============>
struct point {
  int x;
  int y;
};
typedef struct point point;

struct list_node {
  void *data;
  struct list_node *next;
};
typedef struct list_node list_node;

void print_point(point *p);
void print_circular_point_list(list_node *cl);
list_node *insert_head(list_node *cl, void *el);
list_node *insert_tail(list_node *cl, void *el);
list_node *delete_head(list_node *cl);
list_node *delete_tail(list_node *cl);
int length_of_circular_list(list_node *cl);
list_node *find_previous_node(list_node *cl);

int exercise12_6() {
  point p1 = {1, 2}, p2 = {3, 4}, p3 = {5, 6}, p4 = {7, 8};

  list_node *circular_list = NULL;
  printf("Length of circular list: %d\n",
         length_of_circular_list(circular_list));

  return EXIT_SUCCESS;
}

void print_point(point *p) { printf("(%1d, %1d)\n", p->x, p->y); }

void print_circular_point_list(list_node *cl) {
  list_node *cur, *prev;

  if (cl != NULL) {
    cur = cl->next;
    do {
      prev = cur;
      print_point(cur->data);
      cur = cur->next;
    } while (prev != cl);
  }
}

/* An exercise */
int length_of_circular_list(list_node *cl) { return 0; }

// int exercise12_6() {}
