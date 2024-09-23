#include <iostream>
#include <array>
#include <string>
#include <iomanip>
#include <vector>
#include <stdexcept>

class CharacterDragonManager {

    public:
    CharacterDragonManager() {}

    static const size_t MAX_CHARACTER_SIZE {3};
    static const size_t MAX_DRAGON_SIZE {4};
    std::array<std::array<std::string, MAX_DRAGON_SIZE> ,MAX_CHARACTER_SIZE > CharactersArr;
    std::string character_input;
    std::string dragon_input;
    int characters_left = MAX_CHARACTER_SIZE;
    int current_character_index = 0;

    void print_array() {

        std::cout << "\nPrinting data entries...\n";

        std::cout << "Characters | Dragons\n";
        for(size_t i = 0; i < MAX_CHARACTER_SIZE; i++) {
            std::cout<<CharactersArr[i][0];
            bool firstdragon = true;
            for(size_t j = 1; j < MAX_DRAGON_SIZE; j++) {
                if(CharactersArr[i][0] != "") {
                    if(firstdragon) {
                        std::cout << " | ";
                        firstdragon = false;
                    }
                    std::cout<<CharactersArr[i][j] << " ";
                }
                if(j == 3) {
                    std::cout<<std::endl;
                }
            }
        }
    }


    int get_num_characters_left() const {
        return characters_left;
    }


    void character_entry_prompt() const {
        std::cout << "Would you like to enter a character? (y/n) \n" //Ask user if they want to enter a character
        << "You have ("<< get_num_characters_left() <<") entries left\n"; //
    }

    void collect_input(char user_response) {
        while (user_response != 'y' && user_response != 'n') {
            std::cout << "Please enter only a lowercase y or n" <<std::endl;
            std::cin >> user_response;
        }

        while(user_response == 'y' && characters_left != 0) {
                std::cout << "\nEnter the name for character #" << current_character_index + 1 << ":";
                std::cin >> character_input;
                CharactersArr[current_character_index][0] = character_input;
                characters_left--;

                size_t dragon_amount = get_dragon_amount();

                for(size_t j = 1; j <= dragon_amount; j++) {
                    std::cout << "Enter the name of the dragon #"<< j << ":";
                    std::cin >> dragon_input;
                    CharactersArr[current_character_index][j] = dragon_input;
                }

                current_character_index++;

                if(get_num_characters_left() > 0) {
                    std::cout<<"Would you like to enter another character? (y/n)\n" <<
                               "You have " << get_num_characters_left() <<  " character(s) left.\n";
                    std::cin >> user_response;
                }
        }
        if(get_num_characters_left() == 0) {
            std::cout << "\nYou have reached the maximum allowed character entries." << std::endl;
        }
        print_array();
    }
    private:
        size_t get_dragon_amount() const {
            std::cout << "How many dragons would you like to enter for the character?" << std::endl
                      << "Maximum of ("<< (MAX_DRAGON_SIZE - 1) <<") allowed per character" << std::endl;
            size_t dragon_amount;
            std::cin >> dragon_amount;

            if(dragon_amount >= MAX_DRAGON_SIZE) {
                dragon_amount = MAX_DRAGON_SIZE - 1;
                std::cout<<"Dragon maximum exceeded or Below 0, defaulting to " << dragon_amount << std::endl;
            }
            return dragon_amount;
        }
};




class VectorCharacterDragonManager {
    public:
    VectorCharacterDragonManager() {}
    std::vector<std::string> kingdoms;
    std::vector<int> army_size;
    size_t kingdom_total{7};


    static void entry_prompt() {
        std::cout << "\nNow enter the name of one of the Seven Kingdoms\n";
    }


    void add_data(const std::string& kingdom, const int army) {
        kingdoms.push_back(kingdom);
        army_size.push_back(army);
    }

    void print_vectors() const {

        std::cout << "Printing Vectors...\nKingdom | Army Size\n";
        for(size_t i = 0; i < kingdom_total; i++) {
            std::cout<<kingdoms[i]<<" ";
            bool army_barrier = true;
                if(army_barrier) {
                    std::cout<<" | ";
                army_barrier = false;
            }
            std::cout<<army_size[i] << " Soldiers" << std::endl;
        }
    }

    void begin_entries() {
        entry_prompt();
        std::string kingdom_entry;
        int army_entry;

        for(size_t i = 0; i < kingdom_total; i++) {
            std::cout << "Enter the name of kingdom #" << i+1 << ":";
            std::cin >> kingdom_entry;
            std::cout << "How many soldiers are in their army?:";
            std::cin >> army_entry;
            while(army_entry < 0) {
                std::cout << "Invalid army size provided, defaulting to 0\n";
                army_entry = 0;
            }
            add_data(kingdom_entry, army_entry);
            std::cout<<std::endl;
        }
        print_vectors();
    }
};

int main() {

    char user_response;
    CharacterDragonManager manager;
    VectorCharacterDragonManager manager_vec;

    manager.character_entry_prompt();
    std::cin >> user_response;
    manager.collect_input(user_response);

    manager_vec.begin_entries();

    return 0;
};
