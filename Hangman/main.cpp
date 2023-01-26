#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include <algorithm>


using namespace std;

// word list

string word_list[] = {
"serdar", 
"itsmybirthday", 
"serdaremre"
};

void print(vector<string>display) {
    for(size_t i=0; i < display.size(); i++)
        cout << display.at(i) << ' ';
            cout << endl;
}

void display_stages(int lives) {
    if (lives == 0) {
        cout<<"  +---+ \n";
        cout<<"  |   | \n";
        cout<<"  O   | \n";
        cout<<" /|\\  | \n";
        cout<<" / \\  | \n";
        cout<<"      | \n";
        cout<<" ========= \n";  
    }
    else if (lives == 1){
        cout<<"  +---+ \n";
        cout<<"  |   | \n";
        cout<<"  O   | \n";
        cout<<" /|\\  | \n";
        cout<<" /    | \n";
        cout<<"      | \n";
        cout<<" ========= \n";
        
    }
    else if (lives == 2){
        cout<<"  +---+ \n";
        cout<<"  |   | \n";
        cout<<"  O   | \n";
        cout<<" /|\\  | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<" ========= \n";       
    }
    else if (lives == 3){
        cout<<"  +---+ \n";
        cout<<"  |   | \n";
        cout<<"  O   | \n";
        cout<<" /|   | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<" ========= \n";       
    }
    else if (lives == 4){
        cout<<"  +---+ \n";
        cout<<"  |   | \n";
        cout<<"  O   | \n";
        cout<<"  |   | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<" ========= \n";       
    }
    else if (lives == 5){
        cout<<"  +---+ \n";
        cout<<"  |   | \n";
        cout<<"  O   | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<" ========= \n";        
    }
    else if (lives == 6){
        cout<<"  +---+ \n";
        cout<<"  |   | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<" ========= \n";        
    }
}



int main(){
    srand(time(NULL));
    string chosen_word = word_list[rand() % 3];
    bool end_of_game{0};
    int lives{6};
    //cout << "The solution is " << chosen_word << endl;
    vector<string> display;
    int length = chosen_word.length();

    for (int i=0;i<length; ++i) {
        display.push_back("_");
    }
        
    cout << "Adam asmaca oyununa hosgeldiniz." << endl;    
        
    while (end_of_game == 0) {
        char guess;
        cout << "Bir harf yazin lutfen: \n" << endl;
        cin >> guess;
        guess = tolower(guess);
        
        //clearing the screen to not being have to scroll down on each guess
        system("cls");
        
        for (int i=0;i<length; ++i) {
            char letter;
            letter = chosen_word[i];
            if (letter == guess){
                display[i] = letter;
            }
        }
        
        if (chosen_word.find(guess) == string::npos) {
            lives -= 1;
            cout << guess << " kelimenin icinde yok." << endl;
            if (lives == 0) {
                end_of_game = 1;
                cout << "Kaybettin." << endl;
                cout << "Aradigin kelime: " << chosen_word << endl;
            }
        }
        
        print(display);
        
        string underscore = "_";
        vector<string>::iterator it = find(display.begin(), display.end(), underscore);
        if (it == display.end()) {
            end_of_game = 1;
            cout << "Tebrikler kazandin." << endl;
        }
        
        display_stages(lives);
        
    }
       
    
        
        
        
        
        
        
        
       /* if (display.find(guess)){
            cout << "You have already guessed " + guess << endl;
        }*/
        
        

        
    
    
    

    
    return 0;
}