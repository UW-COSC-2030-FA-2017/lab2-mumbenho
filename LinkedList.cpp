// LinkedList.cpp
// Edited by McKade Umbenhower

// tom bailey   0745  5 oct 2010
// Definition of methods for the List class.

#include "LinkedList.h"

#include <utility>


List::List()
	: first_(NULL)
{
}


List::List(const List & other)
	: first_(clone(other.first_))
{
}


List::~List()
{
	while (!empty())
	{
		removeFirst();
	}
}


const List & List::operator=(const List & other)
{
	// check for list = list
	if (&other != this)
	{
		// clear the current contents of this List
		this -> ~List();
		// and get a copy of other
		first_ = clone(other.first_);
	}

	return *this;
}


bool List::empty() const
{
	return first_ == NULL;
}


void List::insertAsFirst(double x)
{
	first_ = new Node(x, first_);
}


double List::removeFirst()
{
	double item = first_->entry_;
	Node * tempPtr = first_;
	first_ = first_->next_;
	delete tempPtr;
	return item;
}


void List::print(ostream & outfile) const
{
	outfile << "[ ";
	if (!empty())
	{
		// The first entry is printed separately because no comma
		// is needed.
		outfile << first_->entry_;
		Node * ptr = first_->next_;
		while (ptr != NULL)
		{
			outfile << ", " << ptr->entry_;
			ptr = ptr->next_;
		}
	}
	outfile << " ]";
}


// Iterative version of clone.
// This version walks down the linked structure making a
//   new Node for each double in the structure.
Node * List::clone(Node * ptr)
{
	if (ptr == NULL)
	{
		return NULL;
	}
	Node * first = new Node(ptr->entry_);
	Node * last = first;
	ptr = ptr->next_;
	while (ptr != NULL)
	{
		last->next_ = new Node(ptr->entry_);
		last = last->next_;
		ptr = ptr->next_;
	}
	return first;
}


//// Recursive version of clone.
//// This version handles two cases, a linked structure with
////   no Nodes, and a linked structure with one or more
////   Nodes.
//Node * List::clone( Node * ptr )
//{
//   if( ptr == NULL )
//   {
//      return NULL;
//   }
//   return new Node( ptr->entry_, clone( ptr->next_ ) );
//}


ostream & operator<<(ostream & outfile, const List & list)
{
	list.print(outfile);
	return outfile;
}

int List::size()
{
	Node * tmp = first_;
	int count = 0;

	if (first_ == NULL)
	{
		return count;
	}

	while (tmp->next_ != NULL)
	{
		count++;
		tmp = tmp->next_;
	}

	return count + 1;
}

double List::sum()
{
	// If there is nothing in the list, total is 0
	if (first_ == NULL)
	{
		return 0;
	}

	Node * tmp = first_;
	double total = 0;

	while (tmp->next_ != NULL)
	{
		total += tmp->entry_;
		tmp = tmp->next_;
	}

	// add the last entry to the total
	total += tmp->entry_;

	return total;
}

void List::insertAsLast(double x)
{
	if (empty())
	{
		// Make the first node the inserted node
		first_ = new Node(x, NULL);
	}
	else
	{
		Node * tmp = first_;
		while (tmp->next_ != NULL)
		{
			tmp = tmp->next_;
		}

		// After finding the last node in the list
		// set the next_ node to the new node
		tmp->next_ = new Node(x, NULL);
	}
}


