#include <iostream>
#include <list>

using namespace std;

class Hash{
private:
    int Bucket{0};
    list<int> *table{nullptr};

public:
    Hash(int V);
    void insertItem(int x);
    void deleteItem(int key);
    void displayHash();
    int hashFunction(int x) {
        return (x % Bucket);
    }

};

Hash::Hash(int b){
    this->Bucket = b;
    table = new list<int>[Bucket];
}


void Hash::insertItem(int key){
    int index = hashFunction(key);
    table[index].push_back(key);
}

void Hash::deleteItem(int key){
    int index = hashFunction(key);
    list<int>::iterator i;
    for(i = table[index].begin(); i!=table[index].end(); i++){
        if(*i == key)
            break;
    }

    if(i!= table[index].end())
        table[index].erase(i);
}

void Hash::displayHash(){
    for(int i = 0; i< Bucket; i++)
    {
        cout << i;
        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;

    }
}

int main()
{
    int a[] = {15, 11, 27, 8, 12};
    int n = sizeof(a)/sizeof(a[0]);

    // insert the keys into the hash table
    Hash h(7);   // 7 is count of buckets in
    // hash table
    for (int i = 0; i < n; i++)
        h.insertItem(a[i]);

    // delete 12 from hash table
    h.deleteItem(12);

    // display the Hash table
    h.displayHash();
    cout << "Hello World!" << endl;
    return 0;
}
