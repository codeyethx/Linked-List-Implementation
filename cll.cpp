
/**
* Circularly linked list that models a simple stone-moving game
* @file cll.cpp
* @author Gift Chidera U.
* @date March 30, 2022
*/

#include <iostream>
#include <cstring>

struct Node
{
   int data;
   struct Node* next;
   struct Node* back;
};

class LinkedList
{
private:
   Node* head;
   Node* tail;
public:
   LinkedList()
   {
      head = NULL;
      tail = NULL;
   }
/**
* Function that inserts node into code, and links the node; thus, creating
* circularily linked list.
* @param new_key is the value passed by user.
*/
   void add(int new_key)
   {
      Node *NewNode = new Node();
      NewNode->data = new_key;
      if (head == NULL)
      {
         head = tail = NewNode;
         head->back = head;
         head->next = head;
      }
      else
      {
         tail->next = NewNode;
         NewNode->back = tail;
         NewNode->next = head;
         tail = NewNode;
      }
   }

/**
* Helper function that places node in appropiate index of gaame.
* @param place is the index to which the user passes in
*/
   void place_node(int place)
   {
      Node* current = head;
      int count, index = 0;
      for (int index = 0; index < place; ++index)
      current = current->next;
      {
        current->data += 1;
      }
   }

/**
* Helper function that traverses through the list in a clockwise direction
* @param number is the index to which the traversal starts at
*/
   void clockwise(const int number)
   {
      int temp = 0;
      Node * traverse = head;
      for (int index = 0; index < number; index++)
      {
         traverse = traverse->next;
      }
      temp = traverse->data;
      traverse->data = 0;
      for (int index = 0; index < temp; index++)
      {
         traverse = traverse->next;
         if (index == temp - 1 && traverse->data == 0)
         {
            traverse->data = 0;
         }
         else
         {
            traverse->data = traverse->data + 1;
         }
      }
   }
/**
Helper function that traverses through the list in an anti-clockwise direction
* @param number is the index to which the traversal starts at
*/
   void anticlockwise(int const number)
   {
      int temp = 0;
      Node * traverse = head;
      for (int index = 0; index < number; index++)
      {
       traverse = traverse->next;
      }
      temp = traverse->data;
      traverse->data = 0;
      for (int index = 0; index < temp; index++)
      {
       traverse = traverse->back;
       if (index == temp - 1 && traverse->data == 0)
       {
          traverse->data = 0;
       }
       else
       {
         traverse->data = traverse->data + 1;
       }
      }
   }

/**
* Function that displays the list
* Code was extracted and modified from "Day-15 linked lists classes" of class.
* CITE: TA helped me understand that "do..while" loop helps execute the body of the loop
* at least once without evaluating its teminating condition.
*/
   void print() const
   {
      Node* current = head;
      if (head != nullptr)
      {
      do
      {
        std::cout << current->data;
        current = current->next;
        if (current != head)
        {
           std::cout << " ";
        }
      }
      while (current != head);
      }
      std::cout << std::endl;
   }
};

// Controls execution of program
int main()
{
   LinkedList link_one;
   std::string play;
   int nodes;
   std::cin >> play;
   std::cin >> nodes;
   for (int index = 0; index < nodes; index++)
   {
      link_one.add(1);
   }
   int moves;
   std::cin >> play;
   std::cin >> moves;
   for (int index = 0; index < moves; index++)
   {
    int times;
    std::cin >> play;
    std::cin >> times;
    if (play == "place")
    {
      link_one.place_node(times);
    }
    else if ((play == "clock"))
    {
      link_one.clockwise(times);
    }
    else if ((play == "anti"))
    {
      link_one.anticlockwise(times);
    }
   }
   link_one.print();
}
