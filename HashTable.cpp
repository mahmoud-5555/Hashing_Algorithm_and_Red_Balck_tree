#include <iostream>

using namespace std;

// HashTable class definition

/**
 * HashTableDivision - class to implement hash table using division method
 * @table: array to store the elements
 * @flag: array to store the status of the elements
 * @size: number of elements in the hash table
 * @capacity: capacity of the hash table
 */
class HashTableDivision{
    private:
    int *table;
    int *flag;

    int size;
    int capacity;

    int hashingfunction(int key){
        return key % capacity;
    }

    public:
    /**
     * HashTableDivision - constructor
     * @capacity: capacity of the hash table
     * return: HashTableDivision object
     */
    HashTableDivision(int capacity){
        this->capacity = capacity;
        table = new int[capacity];
        flag = new int[capacity];
        this->size = 0;
        for(int i = 0; i < capacity; i++){
            flag[i] = 0;
        }
        
    }

    /**
     * insertElement - insert an element into the hash table
     * @key: key to be inserted
     * return: index where the key is inserted
     *         -1 if the key is not inserted
     */
    int insertElement(int key){
       
        int index = hashingfunction(key);
        if(flag[index] == 0){
            table[index] = key;
            flag[index] = 1;
            this->size++;
            return index;
        }
        else {
            return -1;
        }
    }

    /**
     * searchElement - search an element in the hash table
     * @key: key to be searched
     * return: index where the key is found
     *        -1 if the key is not found
     */
    int searchElement(int key){
        int index = hashingfunction(key);
        if(flag[index] == 1 && table[index] == key){
            return index;
        }
        else {
            return -1;
        }
    }

    /**
     * deleteElement - delete an element from the hash table
     * @key: key to be deleted
     * return: index where the key is deleted
     *         -1 if the key is not deleted
     */
    int deleteElement(int key){
        int index = hashingfunction(key);
        if(flag[index] == 1 && table[index] == key){
            flag[index] = 0;
            this->size--;
            return index;
        }
        else {
            return -1;
        }
    }
    /**
     * ~HashTableDivision - destructor
     * delete the table and flag arrays
     * return: void
     */
    ~HashTableDivision(){
        delete[] table;
        delete[] flag;
    }

};

class HashTableMultiplication{
    private:
    int *table;
    int *flag;

    int size;
    int capacity;

    int hashingfunction(int key){
        return key * 0.6180339887;
    }

    public:
    /**
     * HashTableMultiplication - constructor
     * @capacity: capacity of the hash table
     * return: HashTableMultiplication object
     */
    HashTableMultiplication(int capacity){
        this->capacity = capacity;
        table = new int[capacity];
        flag = new int[capacity];
        for(int i = 0; i < capacity; i++){
            flag[i] = 0;
        }
        
    }

    /**
     * insertElement - insert an element into the hash table
     * @key: key to be inserted
     * return: index where the key is inserted
     *         -1 if the key is not inserted
     */
    int insertElement(int key){
       
        int index = hashingfunction(key);
        if(flag[index] == 0){
            table[index] = key;
            flag[index] = 1;
            return index;
        }
        else {
            return -1;
        }
    }
    /**
     * searchElement - search an element in the hash table
     * @key: key to be searched
     * return: index where the key is found
     */
    int searchElement(int key){
        int index = hashingfunction(key);
        if(flag[index] == 1 && table[index] == key){
            return index;
        }
        else {
            return -1;
        }
    }

    /**
     * deleteElement - delete an element from the hash table
     * @key: key to be deleted
     * return: index where the key is deleted
     *         -1 if the key is not deleted
     */
    int deleteElement(int key){
        int index = hashingfunction(key);
        if(flag[index] == 1 && table[index] == key){
            flag[index] = 0;
            this->size--;
            return index;
        }
        else {
            return -1;
        }
    }

    ~HashTableMultiplication(){
        delete[] table;
        delete[] flag;
    }

};

/**
 * HashTableMidSquareMethod - class to implement hash table using mid square method
 * @table: array to store the elements
 * @flag: array to store the status of the elements
 * @size: number of elements in the hash table
 * @capacity: capacity of the hash table
 * @hashingfunction: function to calculate the hash value
 */
class HashTableMidSquareMethod {
    private:
    int *table;
    int *flag;

    int size;
    int capacity;

    int hashingfunction(int key){
        int square = key * key;
        int temp = square;
        int count = 0;
        while(temp > 0){
            count++;
            temp /= 10;
        }
        int mid = count / 2;
        int result = 0;
        for(int i = 0; i < mid; i++){
            result = result * 10 + square % 10;
            square /= 10;
        }
        return result;
    }

    public:
    /**
     * HashTableMidSquareMethod - constructor
     * @capacity: capacity of the hash table
     * return: HashTableMidSquareMethod object
     */
    HashTableMidSquareMethod(int capacity){
        this->capacity = capacity;
        table = new int[capacity];
        flag = new int[capacity];
        for(int i = 0; i < capacity; i++){
            flag[i] = 0;
        }
        
    }

    /**
     * insertElement - insert an element into the hash table
     * @key: key to be inserted
     * return: index where the key is inserted
     *         -1 if the key is not inserted
     */
    int insertElement(int key){
       
        int index = hashingfunction(key);
        if(flag[index] == 0){
            table[index] = key;
            flag[index] = 1;
            return index;
        }
        else {
            return -1;
        }
    }

    /**
     * searchElement - search an element in the hash table
     * @key: key to be searched
     * return: index where the key is found
     */
    int searchElement(int key){
        int index = hashingfunction(key);
        if(flag[index] == 1 && table[index] == key){
            return index;
        }
        else {
            return -1;
        }
    }

    /**
     * deleteElement - delete an element from the hash table
     * @key: key to be deleted
     * return: index where the key is deleted
     *         -1 if the key is not deleted
     */
    int deleteElement(int key){
        int index = hashingfunction(key);
        if(flag[index] == 1 && table[index] == key){
            flag[index] = 0;
            this->size--;
            return index;
        }
        else {
            return -1;
        }
    }
};
/**
 * HashTableFoldingMethod - class to implement hash table using folding method
 * @table: array to store the elements
 * @flag: array to store the status of the elements
 * @size: number of elements in the hash table
 * @capacity: capacity of the hash table
 * @hashingfunction: function to calculate the hash value
 * 
 */
class HashTableFoldingMethod{
    private:
    int *table;
    int *flag;

    int size;
    int capacity;

    int hashingfunction(int key){
        int sum = 0;
        while(key > 0){
            sum += key % 1000;
            key /= 1000;
        }
        return sum;
    }

    public:
    /**
     * HashTableFoldingMethod - constructor
     * @capacity: capacity of the hash table
     * return: HashTableFoldingMethod object
     */
    HashTableFoldingMethod(int capacity){
        this->capacity = capacity;
        table = new int[capacity];
        flag = new int[capacity];
        for(int i = 0; i < capacity; i++){
            flag[i] = 0;
        }
        
    }

    /**
     * insertElement - insert an element into the hash table
     * @key: key to be inserted
     * return: index where the key is inserted
     *         -1 if the key is not inserted
     */
    int insertElement(int key){
       
        int index = hashingfunction(key);
        if(flag[index] == 0){
            table[index] = key;
            flag[index] = 1;
            return index;
        }
        else {
            return -1;
        }
    }

    /**
     * searchElement - search an element in the hash table
     * @key: key to be searched
     * return: index where the key is found
     */
    int searchElement(int key){
        int index = hashingfunction(key);
        if(flag[index] == 1 && table[index] == key){
            return index;
        }
        else {
            return -1;
        }
    }

    /**
     * deleteElement - delete an element from the hash table
     * @key: key to be deleted
     * return: index where the key is deleted
     *         -1 if the key is not deleted
     */
    int deleteElement(int key){
        int index = hashingfunction(key);
        if(flag[index] == 1 && table[index] == key){
            flag[index] = 0;
            this->size--;
            return index;
        }
        else {
            return -1;
        }
    }
};


/* Colision solving methods and dynamic hash Table */

/**
 * Linkedlist - class to implement linked list
 * @head: pointer to the head of the linked list
 * 
 */
class Linkedlist {
    private :
    /**
     * Node - structure to store the data and the next pointer
     * @data: data to be stored
     * @next: pointer to the next node
     */
    struct Node {
        int data;
        Node *next;
    };
    Node *head;
    public:

    /**
     * Linkedlist - constructor
     * initialize the head pointer to NULL
     */
    Linkedlist(){
        head = NULL;
    }

    /**
     * insert - insert an element into the linked list
     * @data: data to be inserted
     * return: void
     */
    void insert(int data){
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        if(head == NULL){
            head = newNode;
        }
        else {
            Node *temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    /**
     * search - search an element in the linked list
     * @data: data to be searched
     * return: true if the data is found
     */
    bool search(int data){
        Node *temp = head;
        while(temp != NULL){
            if(temp->data == data){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    /**
     * remove - remove an element from the linked list
     * @data: data to be removed
     * return: true if the data is removed
     */
    bool remove(int data){
        Node *temp = head;
        Node *prev = NULL;
        while(temp != NULL){
            if(temp->data == data){
                if(prev == NULL){
                    head = temp->next;
                }
                else {
                    prev->next = temp->next;
                }
                delete temp;
                return true;
            }
            prev = temp;
            temp = temp->next;
        }
        return false;
    }

    /**
     * removeall - remove all the elements from the linked list
     * return: void
    */
    void removeall(){
        Node *temp = head;
        while(temp != NULL){
            Node *next = temp->next;
            delete temp;
            temp = next;
        }
        head = NULL;
    }

    /**
     * ~Linkedlist - destructor
     * delete the linked list
     */
    ~Linkedlist(){
        Node *temp = head;
        while(temp != NULL){
            Node *next = temp->next;
            delete temp;
            temp = next;
        }
    }
    

};
/**
 * HashTableChaning - class to implement hash table using chaining method
 * @table: array to store the elements
 * @size: number of elements in the hash table
 * @capacity: capacity of the hash table
 * @hashingfunction: function to calculate the hash value
 * 
 */
class HashTableChaining {
    private:
    Linkedlist *table;
    int size;
    int capacity;


    int hashingfunction(int key){
        return key % capacity;
    }

    public:
    /**
     * HashTableChaining - constructor
     * @capacity: capacity of the hash table
     * return: HashTableChaining object
     */
    HashTableChaining(int capacity){
        this->capacity = capacity;
        table = new Linkedlist[capacity];
        this->size = 0;

    }

    /**
     * insertElement - insert an element into the hash table
     * @key: key to be inserted
     * return void
     */

    void insertElement(int key){
        int index = hashingfunction(key);
        table[index].insert(key);
        this->size++;
        float loadfactor = (float)this->size / this->capacity;
        if (loadfactor > 0.75){
            rehash();
        }
        return;
    }
    
    /**
     * rehash - rehash the hash table to extend the capacity
     * return void
     */
    void rehash(){
        int oldcapacity = this->capacity;
        Linkedlist *oldtable = this->table;
        this->capacity = 2 * this->capacity;
        this->table = new Linkedlist[this->capacity];
        this->size = 0;
        for(int i = 0; i < oldcapacity; i++){
            oldtable[i].removeall();
        }
        delete[] oldtable;
        return;
    }

    /**
     * searchElement - search an element in the hash table
     * @key: key to be searched
     * return: index where the key is found
     *       -1 if the key is not found
     */
    int searchElement(int key){
        int index = hashingfunction(key);
        if (table[index].search(key)){
            return index;

        }
        else {
            return -1;
        }
    }

    /**
     * deleteElement - delete an element from the hash table
     * @key: key to be deleted
     * return: index where the key is deleted
     *         -1 if the key is not deleted
     */
    bool deleteElement(int key){
        int index = hashingfunction(key);
        if (table[index].remove(key)){
            this->size--;
            return index;
        }
        else {
            return -1;
        }
    }

    /**
     * ~HashTableChaining - destructor
     * delete the table array
     */
    ~HashTableChaining(){
        delete[] table;
    }
};
 /**
  * HashTableOpenAddressing - class to implement hash table using open addressing method
  * @table: array to store the elements
  * @flag: array to store the status of the elements
  * @size: number of elements in the hash table
  * @capacity: capacity of the hash table
  * @hashingfunction: function to calculate the hash value
  */
class HashTableOpenAddressing {
    private:
    int *table;
    int *flag;
    

    int size;
    int capacity;

    /**
     * hashingfunction - function to calculate the hash value
     * @key: key to be hashed
     * return: hash value
     */
    int hashingfunction(int key){
        return key % capacity;
    }

    public:
    HashTableOpenAddressing(int capacity){
        this->capacity = capacity;
        table = new int[capacity];
        flag = new int[capacity];
        for(int i = 0; i < capacity; i++){
            flag[i] = 0;
        }
        
    }

    /**
     * insertElement - insert an element into the hash table or extand the capacity and add the element
     * @key: key to be inserted
     * return: index where the key is inserted
     *        -
     */
    int insertElement(int key){
       
        int index = hashingfunction(key);
        if(flag[index] == 0){
            table[index] = key;
            flag[index] = 1;
            return index;
        }
        else {
            int i = 1;
            while(i < capacity){
                int newIndex = (index + i) % capacity;
                if(flag[newIndex] == 0){
                    table[newIndex] = key;
                    flag[newIndex] = 1;
                    return newIndex;
                }
                i++;
            }
            // extand the capacity
            int oldcapacity = this->capacity;
            int *oldtable = this->table;
            int *oldflag = this->flag;
            this->capacity = 2 * this->capacity;
            this->table = new int[this->capacity];
            this->flag = new int[this->capacity];
            for(int i = 0; i < oldcapacity; i++){
                if(oldflag[i] == 1){
                    insertElement(oldtable[i]);
                }
            }
            delete[] oldtable;
            delete[] oldflag;
            return insertElement(key);
                
        }
    }
    /**
     * searchElement - search an element in the hash table
     * @key: key to be searched
     * return: index where the key is found
     */
    int searchElement(int key){
        int index = hashingfunction(key);
        if(flag[index] == 1 && table[index] == key){
            return index;
        }
        else {
            int i = 1;
            while(i < capacity){
                int newIndex = (index + i) % capacity;
                if(flag[newIndex] == 1 && table[newIndex] == key){
                    return newIndex;
                }
                i++;
            }
            return -1;
        }
    }

    /**
     * deleteElement - delete an element from the hash table
     * @key: key to be deleted
     * return: index where the key is deleted
     */
    int deleteElement(int key){
        int index = hashingfunction(key);
        if(flag[index] == 1 && table[index] == key){
            flag[index] = 0;
            this->size--;
            return index;
        }
        else {
            int i = 1;
            while(i < capacity){
                int newIndex = (index + i) % capacity;
                if(flag[newIndex] == 1 && table[newIndex] == key){
                    flag[newIndex] = 0;
                    this->size--;
                    return newIndex;
                }
                i++;
            }
            return -1;
        }
    }
    /**
     * ~HashTableOpenAddressing - destructor
     * delete the table and flag arrays
     */
    ~HashTableOpenAddressing(){
        delete[] table;
        delete[] flag;
    }

};

/**
 * HashTableDoubleHashing - class to implement hash table using double hashing method
 * @table: array to store the elements
 * @flag: array to store the status of the elements
 * @size: number of elements in the hash table
 * @capacity: capacity of the hash table
 * @hashingfunction: function to calculate the hash value
 * @hashingfunction2: function to calculate the second hash value
 */

class HashTableDoubleHashing {
    private:
    int *table;
    int *flag;
    int size;
    int capacity;
    /**
     * hashingfunction - function to calculate the hash value
     * @key: key to be hashed
     * return: hash value
     */
    int hashingfunction(int key){
        return key % capacity;
    }
    /**
     * hashingfunction2 - function to calculate the second hash value
     * @key: key to be hashed
     * return: hash value
     */
    int hashingfunction2(int key){
        return 7 - (key % 7);
    }

    public:
    /**
     * HashTableDoubleHashing - constructor
     * @capacity: capacity of the hash table
     * return: HashTableDoubleHashing object
     */
    HashTableDoubleHashing(int capacity){
        this->capacity = capacity;
        table = new int[capacity];
        flag = new int[capacity];
        for(int i = 0; i < capacity; i++){
            flag[i] = 0;
        }
        
    }

    /**
     * insertElement - insert an element into the hash table or extand the capacity and add the element
     * @key: key to be inserted
     * return: index where the key is inserted
     */
    int insertElement(int key){
       
        int index = hashingfunction(key);
        if(flag[index] == 0){
            table[index] = key;
            flag[index] = 1;
            return index;
        }
        else {
            int i = 1;
            while(i < capacity){
                int newIndex = (index + i * hashingfunction2(key)) % capacity;
                if(flag[newIndex] == 0){
                    table[newIndex] = key;
                    flag[newIndex] = 1;
                    return newIndex;
                }
                i++;
            }
            // extand the capacity
            int oldcapacity = this->capacity;
            int *oldtable = this->table;
            int *oldflag = this->flag;
            this->capacity = 2 * this->capacity;
            this->table = new int[this->capacity];
            this->flag = new int[this->capacity];
            for(int i = 0; i < oldcapacity; i++){
                if(oldflag[i] == 1){
                    insertElement(oldtable[i]);
                }
            }
            delete[] oldtable;
            delete[] oldflag;
            return insertElement(key);
        }
    }

    /**
     * searchElement - search an element in the hash table
     * @key: key to be searched
     * return: index where the key is found
     *       -1 if the key is not found
     * 
     */
    int searchElement(int key){
        int index = hashingfunction(key);
        if(flag[index] == 1 && table[index] == key){
            return index;
        }
        else {
            int i = 1;
            while(i < capacity){
                int newIndex = (index + i * hashingfunction2(key)) % capacity;
                if(flag[newIndex] == 1 && table[newIndex] == key){
                    return newIndex;
                }
                i++;
            }
            return -1;
        }
    }
    /**
     * deleteElement - delete an element from the hash table
     * @key: key to be deleted
     * return: index where the key is deleted
     *         -1 if the key is not deleted
     */
    int deleteElement(int key){
        int index = hashingfunction(key);
        if(flag[index] == 1 && table[index] == key){
            flag[index] = 0;
            this->size--;
            return index;
        }
        else {
            int i = 1;
            while(i < capacity){
                int newIndex = (index + i * hashingfunction2(key)) % capacity;
                if(flag[newIndex] == 1 && table[newIndex] == key){
                    flag[newIndex] = 0;
                    this->size--;
                    return newIndex;
                }
                i++;
            }
            return -1;
        }
    }
    /**
     * ~HashTableDoubleHashing - destructor
     */
    ~HashTableDoubleHashing(){
        delete[] table;
    }
};




