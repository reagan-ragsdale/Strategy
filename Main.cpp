#include <iostream>
#include <string>

using namespace std;

class Strategy {
    public:
      virtual int doOperation(int num1, int num2) = 0;
};

class OperationAdd:public Strategy {
    public:
      int doOperation(int num1, int num2) {
        return num1 + num2;
      }
};

class OperationSubstract:public Strategy {

    public:
      int doOperation(int num1, int num2) {
        return num1 - num2;
      }
};

class OperationMultiply:public Strategy {

   public:
      int doOperation(int num1, int num2) {
        return num1 * num2;
      }
};

class OperationDivide:public Strategy {

    public:
      int doOperation(int num1, int num2) {
        return num1 / num2;
      }
};



class Context {
  private:
    Strategy *strategy;

  public:
    Context(Strategy *new_strategy){
      strategy = new_strategy;
    }
   
    void changeStrategy(Strategy *new_strategy){
      strategy = new_strategy;
    }

    int executeStrategy(int num1, int num2){
      return strategy->doOperation(num1, num2);
   }
};

int main() {
  bool c = true;
  while(c == true){
  cout << "Calculator: Enter one at a time.\n";
  int num1, num2;
  string op;
  cin >> num1;
  cin >> op;
  cin >> num2;
  
  OperationAdd add_strategy;
  Context context(&add_strategy);
  if(op == "+"){
    context.changeStrategy(&add_strategy);
    cout << context.executeStrategy(num1, num2);
  }
  else if(op == "-"){
    OperationSubstract subtract_strategy;
    context.changeStrategy(&subtract_strategy);
    cout << context.executeStrategy(num1, num2);
  }
  else if(op == "*"){
    OperationMultiply multiply_strategy;
    context.changeStrategy(&multiply_strategy);
    cout << context.executeStrategy(num1, num2);
  }
  else if(op == "/"){
    OperationDivide divide_strategy;
    context.changeStrategy(&divide_strategy);
    cout << context.executeStrategy(num1, num2);
  }
  else{
    cout << "I'm not smart enough to do that.";
    }
    
    
    cout << "\nWould you like to continue? yes/no\n";
    string a;
    cin >> a;
    if(a == "yes"){
      c = true;
    }
    else if(a == "no"){
    cout << "Goodbye";
    c = false;
    
    }
    else{
      cout << "You're speaking gibberish. Let's continue anyways.";
      c = true;
    }
  }
} 