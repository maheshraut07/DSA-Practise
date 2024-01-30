/*
Hashmap in cpp 
we are using hashmap because its time complexity of inserting , deleting and updating the elements in the hashmap is only of o(1)

map = time complexity o(logn)
there are unique entries along the map entry

unordered_map = time complexity o(1)*/

#include<iostream>
#include<map>
#include<unordered_map>

using namespace std;

int main(){
    unordered_map <string, int> m;

    //inserting the values in the map
    pair <string,int> p  = make_pair ("mahesh", 1);
    m.insert(p);

    // method 2

    pair <string, int> q ("Vivek" ,2 );
    m.insert(q);

    //method 3

    m["sumit"] = 3;


    //finding the elements in the map
    cout << m["mahesh"] << endl;
    cout << m.at("mahesh") << endl;

    /*cout << m.at("sam") << endl;  // will occur error
    cout << m["sam"] << endl;     // will make new entry ans will insert 0 in that entry  */

    cout << m["sam"] << endl;     // will make new entry ans will insert 0 in that entry
    cout << m.at("sam") << endl;  // no error will occur

    // finding the size of the map 
    cout << "The size of the map is : " << m.size();

    //applying the count function on the map

    cout << "\nis mahesh is present in the map or not :" <<  m.count("mahesh") << endl;  //as mahesh is present in the map it will print the '1'
    cout << "is gaurav is present in the map or not:"  << m.count("gaurav") << endl; // as gaurav is not present in the map so it will print '0'

    // removing the eleement from the map

    m.erase("sam"); // sam will be removed from the map


    // printing the element in the map
    //method 1
    for(auto i : m){
        cout << i.first << " : " << i.second << endl;
    }

    //method 2
    cout << endl;

    unordered_map <string,int> :: iterator it = m.begin();

    while(it != m.end()){
        cout << it -> first << " : " << it -> second << endl;
        it++;
    }


} 

/*
add an element = o(1)
remove the element  = o(1)
delete the element = o(1) */