#include "priority_queue_v2.h"
  
#include <iostream>
#include <functional>

using namespace std;



int main()
{ 

  int i;
  priority_queue<int> q1;
  greater<int> menor;
  vector<int> aux;
  
  priority_queue<int> q2 ; 

  priority_queue<int> q3 ; 


  for (i=1;i<10;i++) 
    q1.push(i);

  for (i=20;i>11;i--)
    q1.push(i);

  while (!q1.empty())
    {
      cout << q1.top() << " ";
      q1.pop();
    }
  cout << endl;
 
  while (!q2.empty()) {
      cout << q2.top() << " ";
      q2.pop();
  } 
  cout << endl;

  for (i=1;i<10;i++) 
    q2.push(i);

q2.push(50);

  for (i=20;i>11;i--)
    q2.push(i);

  while (!q2.empty()) {
      cout << q2.top() << " ";
      q2.pop();
  } 
  cout << endl;

  for (i=1;i<10;i++) 
    q3.push(i);


  return 0;

  }
