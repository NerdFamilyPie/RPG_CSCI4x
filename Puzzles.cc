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
      cout << "That is correct";
      loop = TRUE;
      return 0;
    
  }
}
  int puzzle2(){
    \\ This is the puzzle to restore fuel to the engine
      cout << "Here is where we put so sort of dialouge about how we need to vent reserve fuel to the engine if we want to make it to the moon\n";
    
    
  }
