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
"abruptly", 
"absurd", 
"abyss", 
"affix", 
"askew", 
"avenue", 
"awkward", 
"axiom", 
"azure", 
"bagpipes", 
"bandwagon",
"banjo", 
"bayou", 
"beekeeper", 
"bikini", 
"blitz", 
"blizzard", 
"boggle", 
"bookworm", 
"boxcar", 
"boxful", 
"buckaroo", 
"buffalo", 
"buffoon", 
"buxom", 
"buzzard", 
"buzzing", 
"buzzwords", 
"caliph", 
"cobweb", 
"cockiness", 
"croquet", 
"crypt", 
"curacao", 
"cycle", 
"daiquiri", 
"dirndl", 
"disavow", 
"dizzying", 
"duplex", 
"dwarves", 
"embezzle", 
"equip", 
"espionage", 
"euouae", 
"exodus", 
"faking", 
"fishhook", 
"fixable", 
"fjord", 
"flapjack", 
"flopping", 
"fluffiness", 
"flyby", 
"foxglove", 
"frazzled", 
"frizzled", 
"fuchsia", 
"funny", 
"gabby", 
"galaxy", 
"galvanize", 
"gazebo", 
"giaour", 
"gizmo", 
"glowworm", 
"glyph", 
"gnarly", 
"gnostic", 
"gossip", 
"grogginess", 
"haiku", 
"haphazard", 
"hyphen", 
"iatrogenic", 
"icebox", 
"injury", 
"ivory", 
"ivy", 
"jackpot", 
"jaundice", 
"jawbreaker", 
"jaywalk", 
"jazziest", 
"jazzy", 
"jelly", 
"jigsaw", 
"jinx", 
"jiujitsu", 
"jockey", 
"jogging", 
"joking", 
"jovial", 
"joyful", 
"juicy", 
"jukebox", 
"jumbo", 
"kayak", 
"kazoo", 
"keyhole", 
"khaki", 
"kilobyte", 
"kiosk", 
"kitsch", 
"kiwifruit", 
"klutz", 
"knapsack", 
"larynx", 
"lengths", 
"lucky", 
"luxury", 
"lymph", 
"marquis", 
"matrix", 
"megahertz", 
"microwave", 
"mnemonic", 
"mystify", 
"naphtha", 
"nightclub", 
"nowadays", 
"numbskull", 
"nymph", 
"onyx", 
"ovary", 
"oxidize", 
"oxygen", 
"pajama", 
"peekaboo", 
"phlegm", 
"pixel", 
"pizazz", 
"pneumonia", 
"polka", 
"pshaw", 
"psyche", 
"puppy", 
"puzzling", 
"quartz", 
"queue", 
"quips", 
"quixotic", 
"quiz", 
"quizzes", 
"quorum", 
"razzmatazz", 
"rhubarb", 
"rhythm", 
"rickshaw", 
"schnapps", 
"scratch", 
"shiv", 
"snazzy", 
"sphinx", 
"spritz", 
"squawk", 
"staff", 
"strength", 
"strengths", 
"stretch", 
"stronghold", 
"stymied", 
"subway", 
"swivel", 
"syndrome", 
"thriftless", 
"thumbscrew", 
"topaz", 
"transcript", 
"transgress", 
"transplant", 
"triphthong", 
"twelfth", 
"twelfths", 
"unknown", 
"unworthy", 
"unzip", 
"uptown", 
"vaporize", 
"vixen", 
"vodka", 
"voodoo", 
"vortex", 
"voyeurism", 
"walkway", 
"waltz", 
"wave", 
"wavy", 
"waxy", 
"wellspring", 
"wheezy", 
"whiskey", 
"whizzing", 
"whomever", 
"wimpy", 
"witchcraft", 
"wizard", 
"woozy", 
"wristwatch", 
"wyvern", 
"xylophone", 
"yachtsman", 
"yippee", 
"yoked", 
"youthful", 
"yummy", 
"zephyr", 
"zigzag", 
"zigzagging", 
"zilch", 
"zipper", 
"zodiac", 
"zombie"
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
    string chosen_word = word_list[rand() % 213];
    bool end_of_game{0};
    int lives{6};
    //cout << "The solution is " << chosen_word << endl;
    vector<string> display;
    int length = chosen_word.length();

    for (int i=0;i<length; ++i) {
        display.push_back("_");
    }
        
    cout << "Welcome to the hangman." << endl;    
        
    while (end_of_game == 0) {
        char guess;
        cout << "Guess a letter: \n" << endl;
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
            cout << guess << " is not in the word." << endl;
            if (lives == 0) {
                end_of_game = 1;
                cout << "You lose." << endl;
                cout << "The word you were looking for is: " << chosen_word << endl;
            }
        }
        
        print(display);
        
        string underscore = "_";
        vector<string>::iterator it = find(display.begin(), display.end(), underscore);
        if (it == display.end()) {
            end_of_game = 1;
            cout << "Congratulations, you win." << endl;
        }
        
        display_stages(lives);
        
    }
       
    
        
        
        
        
        
        
        
       /* if (display.find(guess)){
            cout << "You have already guessed " + guess << endl;
        }*/
        
        

        
    
    
    

    
    return 0;
}
