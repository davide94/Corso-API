
void inorder_tree_walker(node *x) {
	
	if (x != NULL) {
		inorder_tree_walker(x->left);
		printf("%i\n", x->key);
		inorder_tree_walker(x->right);
	}
}

uint32_t tree_height(node *x, uint32_t h) {
	
	if (x == NULL)
		return h-1;

	uint32_t l = tree_height(x->left, h+1);
	uint32_t r = tree_height(x->right, h+1);

	if (l < r)
		return r;
	return l;
}

node *tree_search(node *x, uint32_t key) {

	if (x == NULL || x->key == key)
		return x;

	if (key < x->key)
		return tree_search(x->left, key);

	return tree_search(x->right, key);
}

node *iterative_tree_search(node *x, uint32_t key) {

	while (x != NULL && x->key != key) {
		if (key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	return x;
}

node *tree_maximum(node *x) {
	
	if (x->right == NULL)
		return x;
	return tree_maximum(x->right);
}

node *iterative_tree_maximum(node *x) {
	
	while (x->right != NULL) {
		x = x->right;
	}
	return x;
}

node *tree_minimum(node *x) {
	
	if (x->left == NULL)
		return x;
	return tree_minimum(x->left);

}

node *iterative_tree_minimum(node *x) {
	
	while (x->left != NULL) {
		x = x->left;
	}
	return x;
}

node *tree_successor(node *x) {
	if (x->right != NULL)
		return tree_minimum(x->right);
	
	node *y = x->p;

	while (y != NULL && x == y->right) {
		x = y;
		y = y->p;
	}
	return x;
}

node *tree_predecessor(node *x) {
	
	if (x->left != NULL)
		return tree_maximum(x->left);
	
	node *y = x->p;

	while (y != NULL && x == y->left) {
		x = y;
		y = y->p;
	}
	return x;
}

void tree_insert(node *x, uint32_t v) {
	//printf("--%i---\n", v);
	node *y = NULL;
	
	while (x != NULL) {	
		y = x;
		//printf("%i\n", x->key);
		if (v < x->key)
			x = x->left;
		else 
			x = x->right;
	}

	node *new = malloc(sizeof(node));
	new->key = v;
	new->p = y;
	new->left = NULL;
	new->right = NULL;

	if (new->key < y->key)
		y->left = new;
	else
		y->right = new;
	//printf("------\n");

}









