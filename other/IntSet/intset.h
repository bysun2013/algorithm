#ifndef INTSET_H_INCLUDED
#define INTSET_H_INCLUDED
/**
* Sets are typically implemented as binary search trees.
*/
class IntSet
{
private:
    struct node{
        int value;
        struct node *left, *right;
    };
    struct node *root;
    void free_nodes(struct node *root);
    void traverse();
public:
	IntSet(void);
	virtual ~IntSet(void);
	void insert(int x);
	bool IsEqual(const IntSet & s);
	IntSet & union2(const IntSet & s1, const IntSet & s2);
	IntSet & incorporate2(const IntSet & s1, const IntSet & s2);

	void print(void);
};

#endif // INTSET_H_INCLUDED
