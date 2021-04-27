
#include <iostream>
#include <string>
//#include <sstream>
#include <math.h>
#include <set>
#include <vector>
//#include <cmath>

using namespace std;

int factorial(int n);
void get_permutations(set<string>& perm, string number,int begin, int length);
void split(vector<string> &fangs, string number);
string checkvampire(const vector<string>& fangs, string number);



int main()
{

    int vamp = 0;
    int n = 1;   // n will be the number of digits the number in question has
    int k = 0;   //k will be the number of permutations possible
    set<string> perm; //a set that will hold all the permutations as STRINGS!
    vector<string> fangs; //a vector that will hold all the fangs (meaning, the split up numbers!) This can not be a set, because some fang might be used twice!

    while (vamp < 100) { 
        cout << "\nEnter Number greater than 99: ";
            cin >> vamp;
      }

    //here, we determine how many digits vamp has. This could be done more elegantly, but the idea is to practise apply creative thinking
    //An integer with n digits will always be >10^(n-1) and <(10^n). We can use this to find the number of digits of vamp

    for (; vamp > pow(10, n); n++) ;  //this loop doesn't really need a body, because it finds n automatically
    
    k = factorial(n);


    cout << "\n\n"<< k << " possible permutations found. \n";
    
    //Now, for the permutations to happen, we turn the int into a string
    string vampstring = to_string(vamp);

    get_permutations(perm, vampstring,0,n);

    
  /*  cout << "all permutations\n";
    for (auto it = perm.begin(); it != perm.end(); it++) {
        cout << *it << endl;

    }*/



    //We now call a function that will just generate the fangs and store them in a vector via reference
    //the function has to be called for every single permutation
    for(auto it =perm.begin();it!=perm.end();it++) {
    split(fangs, *it);
    }




    cout << "\nList of possible fangs \n\n";
    for (auto it = fangs.begin(); it < (fangs.end()-1); it+=2) cout <<"("<< *it << " "<<*(it+1)<<"), ";


    //finally, we can check for the vampire-property

    string Answer = checkvampire(fangs, vampstring);

    cout << "\n\n" << Answer << "\n\n";

}



int factorial(int n) {
    
    int a = 1;
    
        for (int i = n; i > 0; i--) {
            a *= i;

    }

        return a;
}


//this function takes a string and its length and returns a permuted string
//this is done recursively, iteratively to get all permutations of the given string
void get_permutations(set<string> &perm, string number, int begin, int end) {

        if (begin != end)
        {
            // Permutations made
            for (int i = begin; i < end; i++)
            {

                // Swapping done
                char tmp = number[begin]; 
                number[begin]=number[i];
                number[i] = tmp;

                // Recursion called
                get_permutations(perm, number, begin + 1, end);

                //backtrack
                tmp = number[begin];
                number[begin] = number[i];
                number[i] = tmp;

            }

            
         }

       //store permutations in vector:
        perm.insert(number);
    }


//splits the string into two halves. Easy for even-numbered strings, trickier for odd-numbered ones, because they can be split in two different ways
void split(vector<string> &fangs, string number) {
    string lefthalf = "";
    string righthalf = "";
    if (size(number) % 2 == 0) {
        for (int i = 0; i < size(number) / 2; i++)  lefthalf += number[i];
       
        for (int j = size(number)/2; j < size(number); j++) righthalf += number[j];

        fangs.push_back(lefthalf);
        fangs.push_back(righthalf);
    }



    else { //if we have a string of odd-numbered length, we get two pair sof fangs
           //notice that size(number) is an integer (half the length) and will be rounded down automatically. 
           //say the string has a length of 5, which means it has indexes 0 to 4. (size(number)/2) will then be 2, so if used as an index, point beyond the middle
 
        
        //for the shorter left fang:
        for (int i = 0; i < size(number) / 2; i++)  lefthalf += number[i];

        for (int j = size(number) / 2; j < size(number); j++) righthalf += number[j];
       
        fangs.push_back(lefthalf);
        fangs.push_back(righthalf);
    
    
        //reset the two strings to reuse them without complications

        string lefthalf = "";
        string righthalf = "";

        //for the longer left fang
        for (int i = 0; i < (size(number) / 2+1); i++)  lefthalf += number[i];

        for (int j = (size(number) / 2 +1); j < size(number); j++) righthalf += number[j];

        fangs.push_back(lefthalf);
        fangs.push_back(righthalf);


      }




}





string checkvampire(const vector<string>& fangs, string number) {
    bool isvampire = false;

    //first, convert the strings into int!



    vector<int> intfangs;

  for(auto it=fangs.begin();it!=fangs.end();it++){ 
      
      intfangs.push_back(stoi(*it));
  }

  int intnumber = stoi(number);
  //Not, we have the fangs as integer. The rest is easy
  //We multiply the neighbors with each other and then iterate forward in steps of 2


  
  cout << "\n\n";
    for (auto it = intfangs.begin(); it < (intfangs.end() - 1); it+=2) {
        if (*it * *(it + 1) == intnumber) {                         //The syntax is tricky here: The * in the middle means multiplication, and has nothing to do with pointers per se!
            cout << "\n Factorial decomposition found:   " << *it << " x " << *(it + 1) << " = " << intnumber;
            isvampire = true;
        }
    }

    if (isvampire && size(number) % 2 == 0) return "This number is a true vampire";
    else if (isvampire) return "This number is a pseudo-vampire";
    else return "This number is not a vampire";
}
