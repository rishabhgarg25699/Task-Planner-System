#include<iostream>
#include<map>
using namespace std;

class Task{
  private: 
    string title, creater, assignee, status, type, dueData, impact, bug_severity;
    int point;
  public:
    void assignValue(string title,string creater,string assignee,string status,string type,string dueData,string impact,string bug_severity, int point)
    {
      this->title = title;
      this->creater = creater;
      this->assignee = assignee;
      this->status = status;
      this->type = type;
      this->dueData = dueData;
      this->impact = impact;
      this->bug_severity = bug_severity;
      this->point = point;
    }
    void printTask()
    {
      cout << "Title => " << this->title << endl;
      cout << "Creater => " << this->creater << endl;
      cout << "assignee => " << this->assignee << endl;
      cout << "status => " << this->status << endl;
      cout << "type => " << this->type << endl;
      cout << "dueData => " << this->dueData << endl;
      cout << "impact => " << this->impact << endl;
      cout << "bug_severity => " << this->bug_severity << endl;
      cout << endl;
    }
};

map<int, Task> allTask;
map<int, int> sprint;
int uniqueId = 0;

void createSprint()
{
  cout << "Enter sprint name" << endl;
  int newsprint;
  cin >> newsprint;
  cout << "Enter unique IDs for entering the task in the sprint" << endl;
  int id;
  cin >> id;
  if(sprint[id] != 0)
    cout << "Error -> Unique ID has a already in a sprint";
  else{
    cout << "Enter Succesfull";
    sprint[id] = newsprint;
  }
    
}

void creatingTask()
{
  cout << "Enter Details of The tesk" << endl;
  cout << "------------------------------" << endl;
  string title, creater, assignee, status, type, DueDate, impact, bug_severity;
  cout << "Enter title of task" << endl;
  cin >> title;
  cout << "Enter creater of task" << endl;
  cin >> creater;
  cout << "Enter assignee of task" << endl;
  cin >> assignee;
  cout << "Enter status of task" << endl;
  cin >> status;
  cout << "Enter type of task" << endl;
  cin >> type;
  cout << "Enter DueDate of task" << endl;
  cin >> DueDate;
  cout << "Enter impact of task" << endl;
  cin >> impact;
  cout << "Enter bug_severity of task" << endl;
  cin >> bug_severity;
  cout << "Enter point of task" << endl;
  int point;
  cin >> point;
  uniqueId++;
  Task newTask;
  newTask.assignValue(title, creater, assignee, status, type, DueDate, impact, bug_severity, point);
  allTask[uniqueId] = newTask;
  sprint[uniqueId] = 0; // this task in at in no sprint
  cout << endl;
  cout << "New Task SuccessFull Made with id = "  << uniqueId << " " << endl;
  cout << "------------------------------" << endl;
  cout << endl;
}

void deleteTask(){
  cout << "Enter task to be deleted" << endl;
  int task;
  cin >> task;
  sprint[task] = 0;
  cout << "SuccessFull Deleted" << endl;
  cout << endl;
}

void showSprint(){
  cout << "Enter Sprint number" << endl;
  int sprintNumber;
  cin >> sprintNumber;
  int temp = 0;
  for(auto i: sprint)
  {
    if(i.second == sprintNumber)
    {
      temp = 1;
      Task temp = allTask[i.first];
      temp.printTask();
    }
  }
  if(temp == 0)
    cout << "No Sprint is there for this id" << endl;
  cout << "------------------------------" << endl;
  cout << endl;
}

void showTask(){
  cout << "Enter Id of the Task " << endl;
  int id;
  cin >> id;
  if(allTask.count(id) != 0)
  {
    Task temp = allTask[id];
    temp.printTask();
  }
  else{
    cout << "No task is there for this id" << endl;
  }
  cout << "----------------------------------- " << endl;
  cout << endl;
}

int main(){
  int n;
  while(1)
  {
    cout << "Menu For Task Planner System" << endl;
    cout << "------------------------------" << endl;
    cout << "1. Create a Task" << endl;
    cout << "2. Create Sprint" << endl;
    cout << "3. Delete task from a sprint" << endl;
    cout << "4. Show task of Particular Sprint" << endl;
    cout << "5. Show particular Task" << endl;
    cout << "Exter the Option" << endl;  
    cout << "------------------------------" << endl;
    cout << endl;
    cin >> n;
    switch(n){
      case 1: 
        creatingTask();
        break;
      case 2: 
        createSprint();
        break;
      case 3: 
        deleteTask();
        break;
      case 4: 
        showSprint();
        break;
      case 5:
        showTask();
        break; 
      default: 
        cout << "Incorrect Choise" << endl;
    }
  } 
}