/* wordfreq.cpp
*** Data Structures - 9 A.M. ***
Program Name: Recursive Frequency List
Programmer Name: Anthony Duran
Date Submitted: 12/12/21
Purpose: Count and sort words in a file using a BST
Date Updated: N/A
Purpose for Update: N/A
Global Variable List: {avoid these}
Data Structure: Binary Tree
*/

#include <iostream>
#include "fileWords.h"
#include "bst_tree.h"
#include "frequency.h"

using namespace DS;

int main(int argc, const char* argv[]) {

    if (argc==2) {
        //Create object that opens file
        fileWords inputfile(argv[1]);

        //If true, call frequency's increment
        bool unique;
        //Our BST made to be of type frequency, which also needs a type. It's type string.
        bst_tree<frequency<std::string>> Hero;

        //While the file still has words waiting to be read
        while (inputfile.hasWords()) {
            // Create frequency obj & account for its instantiation. Use false for string comparison, then create alphabetical list.
            frequency<std::string> a(inputfile.getNextWord(), false);
            a.increment();
// alternative: return the node (actually, the reference), then increment afterward
            unique = Hero.insert(a); // Insert the object

            if(!unique){
                a = Hero.matchFound();
                a.increment();
            }
//
//            Hero.insert(a);

            // TODO: create second BST w/ type's member variable set to true for numerical comparison, then create frequency list

            /** Note to self -> Already confirmed: Output the .txt file to standard out */
        }
        std::cout << "WORD FREQUENCY - Alphabetical\n[" << Hero.toString() << "]" << std::endl;
    } else {
        //Command line arguments not configured, give error
        std::cerr << "Usage: " << argv[0] << " name_of_input_file" << std::endl;
    }

    return 0;
}

/** EXAMPLE OF OUTPUT

./freqproject ds.txt

WORD FREQUENCY - Alphabetical
[(a,2), (about,1), (all,1), (and,2), (arrays,2), (assignment,1), (at,1), (awake,1), (binary,3), (can,1), (class,1), (computer,1), (current,1), (data,1), (deques,1), (dynamic,1), (far,1), (favorite,1), (first,1), (for,2), (got,1), (have,1), (how,1), (however,1), (i,6), (is,1), (linked,1), (lists,1), (many,1), (mastered,1), (my,2), (need,1), (night,1), (now,2), (of,1), (on,1), (president,1), (problems,1), (queue,1), (queues,1), (run,1), (science,1), (search,3), (simple,1), (so,1), (solve,2), (stack,1), (states,1), (structures,1), (task,1), (that,1), (the,2), (things,1), (think,2), (to,4), (tree,2), (trees,1), (trying,1), (united,1), (ve,1), (was,1), (wcc,1), (with,2), (work,1), (world,1)]

WORD FREQUENCY - Lowest to Highest
[(1,world), (1,work), (1,wcc), (1,was), (1,ve), (1,united), (1,trying), (1,trees), (1,things), (1,that), (1,task), (1,structures), (1,states), (1,stack), (1,so), (1,simple), (1,science), (1,run), (1,queues), (1,queue), (1,problems), (1,president), (1,on), (1,of), (1,night), (1,need), (1,mastered), (1,many), (1,lists), (1,linked), (1,is), (1,however), (1,how), (1,have), (1,got), (1,first), (1,favorite), (1,far), (1,dynamic), (1,deques), (1,data), (1,current), (1,computer), (1,class), (1,can), (1,awake), (1,at), (1,assignment), (1,all), (1,about), (2,with), (2,tree), (2,think), (2,the), (2,solve), (2,now), (2,my), (2,for), (2,arrays), (2,and), (2,a), (3,search), (3,binary), (4,to), (6,i)]

 */