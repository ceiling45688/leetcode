/*
Question: Jump to The Flag
Find the minimum number of times Bob must jump up the wall to get the flag.
A climber is trying to reach a flag that is some height above the ground. 
In the attempt to reach the flag, the climber can make any number of jumps up the rock wall where the flag is mounted.
Movements can only be made up the wall, and the climber must end at exactly the height of the flag.
------
There are 2 types of jumps:
	A jump of height 1.
	A jump of height bigJump.
Determine the minimum number of jumps it will take the climber to reach the flag's exact height.
--------------------------------------------------------------------------------
Example:
flagHeight = 8
bigJump = 3

The climber starts at height 0, takes two jumps of height bigJump and two of height 1 to reach exactly 8 units in 4 jumps.
--------------------------------
Function Description:
Complete the function jumps in the editor below.
jumps has the following parameter(s):

int flagHeight:an integer, the flag height

int  bigJump: an integer, the height of the second type of jump

Returns:
int: an integer, the minimum number of jumps necessary
-----------------------------------
Constraints
	1 ≤ bigJump, flagHeight ≤ 109
 DO NOT REMOVE THIS LINE-->
Input Format for Custom Testing

Input from stdin will be processed as follows and passed to the function.

The first line contains an integer flagHeight.

The second line contains an integer bigJump.

Sample Case 0
Sample Input
STDIN     Function
-----     -----
3      →  flagHeight = 3
1      →  bigJump = 1

Sample Output
3
Explanation
The climber can only jump 1 unit or bigJump units. With bigJump = 1, the climber can only make 1-unit jumps. It will take 3 jumps to reach the flag.
*/

/*
Complete the jumps function below.
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int jumps(int flagHeight, int bigJump)
{
    return flagHeight/bigJump + flagHeight%bigJump;
}
int main(){
    int flagHeight;
    // cin>>flagHeight;
    int bigJump;
    // cin>>bigJump;
    cout<<jumps(8, 3)<<endl;
    return 0;
}
