#include <stdio.h>

// Hold a string
class Item {
public:
  const char * str;
  Item(const char *as = "") 
  { 
    str = as;
  }
};

struct List {
private:

// ListNode represents each 
// node of the list
  class ListNode {
  private:
    Item item; // data in the list
    ListNode *next;	
  public:
    ListNode(Item a) 
    { 
      item = a; 
      next=NULL; // automatically serves as a list tail
    }
    ListNode* getNext() 
    { 
      return next; 
    }
    void setNext(ListNode *n) 
    { 
      next = n; 
    }
    Item getItem() 
    { 
      return item; 
    }
  };

  // add head and tail pointer
  ListNode *head;
  ListNode *tail;

public:
  List();
  void push_back(Item a);    
  bool remove(Item &a);    
  bool empty();
  void length();
};

List::List()
{
  // start with an empty list
  head = NULL;
  tail = NULL;
}

void List::push_back(Item a)
{
  ListNode *node = new ListNode(a);
  if (head == NULL)
    {
      // list is empty
      head = node;
      tail = node;
    }
  else 
    {
      tail->setNext(node);
      tail = node;
    }
}
// A destructor
bool List::remove(Item &copy) 
{
  if (!empty()) // if list is not empty
    {
      copy = head->getItem(); // return copy
      ListNode *tmp = head->getNext();
      delete head; // delete the node
      head = tmp;  // update the head
      if (tmp==NULL) // removed last element 
	tail = NULL;
      return true;
    }
  return false; // nothing in list
}

bool List::empty()
{
  return head==NULL;
}
void List::length()
{
  int length(node *head)
  {
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;

    }
    return len;
  }
}


int main()
{
  List l;

  l.push_back(Item("milk"));
  l.push_back(Item("eggs"));
  l.push_back(Item("bread"));
  l.push_back(Item("potato chips"));
  l.push_back(Item("toothpaste"));


  while(!l.empty())
    {
      Item copy;
      l.remove(copy);

      printf("Next thing removed: %s\n",copy.str);
    }

  return 0;
}
