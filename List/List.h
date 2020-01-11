#ifndef LIST_H
#define LIST_H


class List
{
private:
    int m_count;
    int *m_items;
public:
    List();
    ~List();
    void Insert(int index, int val);
    int Get(int index);
    int Search(int val);
    void Remove(int index);
    int Count();
};

#endif // LIST_H
