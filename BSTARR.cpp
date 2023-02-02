#include <iostream>
using namespace std;
class BST{
    private:
    int i=0,k=0;
    int sizes = 13;
    int arr[13];
    public:
    BST(){
        for(int i=0; i<sizes; i++){ // Assigning the every index of array 0
            arr[i] = 0;
        }
    }
    // Insert
    void left(int r , int data){ // Left Child Formula :- 2r+1
        if(((2*r)+1)<sizes){ // Left Child Formula value is smaller then size of an array
            arr[((2*r)+1)] = data;
        }
    }
    void right(int r , int data){ // Right Child Formula :- 2r+2
        if(((2*r)+2)<sizes){ // Right Child Formula value is smaller then size of an array
            arr[((2*r)+2)] = data;
        }
    }
    int parent(int r , int data){ // Parent Function
        int index = (r-1)/2; // Parent Formula :- r-1/2
        if(index != 0){ // if index is not equal to 0
            if(arr[index] > data){ // if array index is greater then the data
                left(index , data);
            }
            else if(arr[index] < data){ // if array index is smaller then the data
                right(index , data);
            }
        }
        else{
            arr[r] = data;
        }
    }
    void insert(int data){ // wrap insert function
        insert(i , data);
        i++;
    }
    void insert(int j,int data){ // insert function
        if(arr[0] == 0){ // check the arr[0] is zero then insert data
            arr[0] = data;
        }
        else{
            if(arr[0]>data){ // arr[0] is greater the data move to the parent
                parent(j , data);   
            }
            else if(arr[0]<data){ // arr[0] is smaller the data move to the parent
                parent(j ,data);
            }
        }
    }
    //Delete
    void del(int r , int data , int k){
        if(arr[(2*r)+1] != 0 && arr[(2*r)+1]<sizes){ // check the Left child is not zero and smaller then size
            arr[k] = arr[(2*r)+1]; //Assiging the delete node to the right from the left node
            arr[(2*r)+1] = 0; // replaced node will set zero
        }
        else{
            arr[k] = arr[(2*k)+2]; //Assiging the delete node to the right node
            arr[(2*k)+2] = 0; // replaced node will set zero
        }
    }
    int delparent(int r , int data){ // Parent Function
        if(arr[(2*r)+2] != 0 && arr[(2*r)+2]<sizes){ // check the Right child is not zero and smaller then size
            del((2*r)+2 , data,r); 
        }
        else{
            arr[r] = 0;
        }
    }
    void Delete(int data){ //wrap function of the delete
        Delete(k , data);
    }
    void Delete(int k ,int data){
        if(k == sizes){
            return;
        }
        else{
            if(arr[k] == data){
                delparent(k , data);
            }
            k++;
            Delete(k,data);
        }
    }
    // Display
    void display(){ // Warp Display Function
        int i = 0;
        displays(i,sizes);
    }
    void displays(int i,int sz){ // Display Function with Recursion Method
        if( i == sizes){
            return;
        }else{
            cout<<i<<" : "<<arr[i]<<endl;
            i++;
            displays(i , sz);
        }
    }
};
int main(){
    BST obj;
    obj.insert(50);
    obj.insert(17);
    obj.insert(72);
    obj.insert(12);
    obj.insert(23);
    obj.insert(54);
    obj.insert(76);
    obj.insert(9);
    obj.insert(14);
    obj.insert(19);
    obj.insert(67);
    obj.display();
    cout<<" - - - DELETE - - - "<<endl;
    obj.Delete(67);
    obj.display();
    return 0;
}