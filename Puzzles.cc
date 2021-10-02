int puzzle1(){
  string correct = "little";
  string test = "";
  bool loop = FALSE;
  string prompt = "";
//This the puzz;e for figuring out the password
  cout << "Please input your password\n";
  cin >> test;
  if (test == "little"){
      cout << "That is correct";
      loop = TRUE;
      return 0;
  }
  while (loop){
    cout << "That is incorrect.\n would you like to see your secret prompt?\n";
    cin >> prompt;
    if(prompt == "no"){
      cout << "Please input your password\n";
      cin
    } else if(prompt == "yes"){
      cout << "It is your mothers maiden name, remember its not Tall\n";
      cin >> test;
    }
    if (test == "little"){
      cout << "That is correct\n";
      loop = TRUE;
      return 0;
    
  }
}
  int puzzle2(){
    \\ This is the puzzle to restore fuel to the engine
      bool loop = FALSE;
      int ans1 = 0;
      int ans2 = 0;
      int ans3 = 0;
      cout << "Here is where we put so sort of dialouge about how we need to vent reserve fuel to the engine if we want to make it to the moon\n "
      "So you need to input the passcodes for the three compartments of raw material that we need to mix together to create more fuel.\n"
      "For each passcode you will be asked a simple math riddle to make sure that you are competent enough to operate the fuel mixology.";
    cout << "The first riddle is:\n";
    while (loop){
      cout << "What number multiplied by itself and divided by one hundred is equal to four?\n";
      cin ans1;
      if (!ans1){cout << "Invalid Input, Please Try Again"; continue;}
      if (
                 
    }
    \\20*20/100=4
      \\
    
  }
