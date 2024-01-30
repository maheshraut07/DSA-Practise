/*
object = entity = 1)state/properties
                  2)behaviour
                  
                  */
#include<iostream>
using namespace std;

class Hero{
    private:
    int health;

    public:
    char level;

    Hero(int health){
        cout<<"\nThe address of  by using this pointer : "<<this;
        this -> health = health;

    }
    
    void print(){
        cout<<level;
    }

    int getHealth(){
        return health;
    }

    int setHealth(int h){
        health = h;
        return health;
    }

    void setLevel(char ch){
        level  = ch;
    }


};

int main(){

    /* Hero h1;
    Hero ramesh;  // static memory allocation of objcet
   
    cout<<"size : "<<sizeof(h1); // size of h1 will be 1 if there is nothing in the class
    
   
    cout<<"\nHealth is :"<<ramesh.getHealth();
     ramesh.setHealth(70);
    cout<<"\nHealth is: "<<ramesh.getHealth();


    Hero *h = new Hero(); // dynamic memroy allocation of abject
    cout<<"\nHealth is : "<<(*h).getHealth();  // we used derefernec operator because h is the address

    cout<<"\nHealth is : "<< h -> getHealth(); // alternative for *h is h ->
   */

   
    Hero ramesh(10);
    ramesh.getHealth();
    cout<<"\nthe address of ramesh is :"<<&ramesh;

    Hero suresh(20);
    cout<<"\n the address is suresh is : "<<&suresh;

    return 0;
    
}

/*This keyword = stores current object address . in above case ramesh is current object because ramesh is calling class method . 
This pointer = by using this we can access current object parameter */
// this -> health = ramesh.health;




/*
if we do not define any  constructor then default constructor will be automatically created
and if we make the consructor then automatically created default constructor will be destroyed


*/


/*
COPY Constructor

Hero s (70,"c");
s.print();

Hero r(s);
r.print();   the output will be same as s.print() becuase we copied s object in the r

Hero(Hero &temp){
    cout<<"copy constructor called;"
}

Hero r(s);

*/
