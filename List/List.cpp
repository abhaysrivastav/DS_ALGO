#include "List.h"

List::List():m_count{0}
{

}

List::~List(){
    delete []m_items;
    m_items = nullptr;
}

void List::Insert(int index, int val){

    // Check is out of bound
    if(index < 0 || index >m_count)
        return;

    // Copy the current array
    int *oldArray = m_items;

    //increase the array length
    m_count++;

    //Initialize the new array
    m_items = new int[m_count];

    // Fill the new array with inserted data
    for(int i = 0, j=0; i< m_count; i++ ){

        if(index == j){
            m_items[i] = val;
        }else{
            m_items[i] = oldArray[j];
            ++j;
        }
    }
    delete[] oldArray;

}

int List::Get(int index){

    if(index < 0 || index > m_count)
        return -1;

    return m_items[index];

}

int List::Search(int val){

    for(int i=0; i< m_count;++i)
    {
        if(m_items[i] == val){
            return i;
        }
    }
    return -1;
}
void List::Remove(int index){

    if(index < 0 || index > m_count)
        return;

    // Copy the current array
    int *oldArray = m_items;

    // Decrease the array length
    m_count--;

    //Initialize the new array
    m_items = new int[m_count];

    // Fill the new array

    for(int i = 0, j =0; i < m_count; ++i)
    {
        if(index == j){
            ++j;
        }
        m_items[i] = oldArray[j];
    }
    delete []oldArray;

}


int List::Count()
{
    return m_count;
}


