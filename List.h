#include "utility.h"

const int max_list = 1000;

template <class List_entry>
class List {
public:
//  methods of the List ADT
   List();
   int size() const;
   bool full() const;
   bool empty() const;
   void clear();
   void traverse(void (*visit)(List_entry &));
   Error_code retrieve(int position, List_entry &x) const;
   Error_code replace(int position, const List_entry &x);
   Error_code remove(int position, List_entry &x);
   Error_code insert(int position, const List_entry &x);
   void print() const;

protected:
//  data members for a contiguous list implementation
   int count;
   List_entry entry[max_list];
};

template <class List_entry>
List<List_entry>::List()
{
  count=0;
}

template <class List_entry>
int List<List_entry>::size() const
/*
Post: The function returns the number of entries in the List.
*/
{
   return count;
}

template <class List_entry>
bool List<List_entry>::full() const
{
  return count==max_list;
}

template <class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &x)
/*
Post: If the List is not full and 0 <= position <= n,
      where n is the number of entries in the List, the function succeeds:
      Any entry formerly at position and all later entries have their
      position numbers increased by 1 and x is inserted at position of the List.      Else: The function fails with a diagnostic error code.
*/
{
   if (full())
      return overflow;

   if (position < 0 || position > count)
      return range_error;

   for (int i = count - 1; i >= position; i--)
      entry[i + 1] = entry[i];

   entry[position] = x;
   count++;
   return success;
}

template <class List_entry>
Error_code  List<List_entry>::retrieve(int position, List_entry &x) const
{
   if (position < 0 || position >= count)
      return range_error;

   x = entry[position];
   return success;
}
