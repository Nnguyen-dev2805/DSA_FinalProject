// ------------------------------------------------------------------------------------
//
// User Interface
//
// ------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <windows.h> // For coloured text
#include <conio.h>   // For _getch() function
#include <functional>

#include "HashTable.h"
#include "Trie.h"
#include "Bookmark.h"

// control
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_SPACE 32
#define KEY_BACKSPACE 8
#define KEY_ESCAPE 27

// color
#define MAIN_COLOUR 11
#define SECONDARY_COLOUR 224
#define COLOUR_WHITE 15
#define COLOUR_GREY 7
#define COLOUR_YELLOW 14

// screen
#define SCREEN_MAIN 0
#define SCREEN_SEARCH 1
#define SCREEN_BOOKMARKS 2

// bookmarks object
BookMarkList b;

// Becomes true when program has to be exited
bool exit_program = false;

// Main menu item array
string itemArray_DictMain[]{"Search for a word", "Bookmarks", "Exit"};

using namespace std;

class UI
{
public:
    // tùy chọn người dùng
    int selection;

    // số lượng tùy chọn
    int max_selections;

    // lưu trữ số người dùng nhập
    int key_input;

    // lưu trữ chuỗi người dùng nhập
    string str_input;

    // biến cờ xác định khi nào dừng nhận chuỗi từ người dùng
    bool stop_taking_str_input;

    // biến trạng thái xác định màn hình hiện tại
    unsigned int screen = SCREEN_MAIN;

    // tương tác với console
    HANDLE hConsole;

    HashTable dhtObj;

    Trie autoCompleteTrieObj;

    // public:
    // constructor
    UI();

    // process menu and UI elements
    void process();

    // change text color
    void setTextColour(int color);

    void changeScreen(int id);

    // display menu from string array
    void showMenu(string *strArr);

    // returns true when input is a-z, A-Z, or BACKSPACE, SPACE or ESC
    bool validEntry(void);
};
// implement the above functions here....

UI::UI()
{
    selection = 0;
    max_selections = sizeof(itemArray_DictMain) / sizeof(*itemArray_DictMain);
    stop_taking_str_input = false;

    // lấy handle của console để làm việc với đầu ra
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    dhtObj.loadWordsFromFile();
    autoCompleteTrieObj.import_txt();
}

void UI::setTextColour(int color)
{
    SetConsoleTextAttribute(hConsole, color);
}

void UI::showMenu(string *strArr)
{
    for (int i = 0; i < max_selections; i++)
    {
        if (i == selection)
        {
            setTextColour(SECONDARY_COLOUR);
            cout << " -> " << strArr[i] << " " << endl;
        }
        else
        {
            setTextColour(COLOUR_WHITE);
            cout << "    " << strArr[i] << " " << endl;
        }
    }
}

void UI::process()
{
    while (!exit_program)
    {
        switch (screen)
        {
        case SCREEN_MAIN:

            setTextColour(COLOUR_WHITE);
            cout << endl;
            cout << "    DATA STRUCTURES AND ALGORITHMS END-OF-SEMESTER PROJECT" << endl
                 << endl;

            setTextColour(MAIN_COLOUR);
            cout << " + ------------------------------------------------------------------- +" << endl;
            cout << "    DICTIONARY ENGLISH - VIETNAMESE WITH AUTOCOMPLETE AND AUTOCORRECT             " << endl;
            cout << " + ------------------------------------------------------------------- +" << endl
                 << endl;

            showMenu(itemArray_DictMain);

            setTextColour(COLOUR_GREY);
            cout << endl
                 << " Use UP and DOWN arrow keys to navigate." << endl;
            cout << " Press SPACE to select." << endl;

            // controls input key command
            // get a character without pressing ENTER
            switch (key_input = _getch())
            {
            case KEY_UP:
                --selection;
                break;
            case KEY_DOWN:
                ++selection;
                break;
            case KEY_SPACE:
                if (selection == 0)
                    changeScreen(SCREEN_SEARCH);
                if (selection == 1)
                    changeScreen(SCREEN_BOOKMARKS);
                if (selection == 2)
                {
                    setTextColour(COLOUR_WHITE);
                    char confirm;
                    bool validInput = false;

                    do
                    {
                        cout << endl
                             << "Are you sure you want to exit? (Y/N): ";

                        confirm = _getch();

                        if (confirm == 'Y' || confirm == 'y')
                        {
                            system("cls");
                            setTextColour(MAIN_COLOUR);
                            cout << " + ------------------------------------------------------------------- +" << endl;
                            cout << "               Thank you for using our Dictionary!" << endl;
                            cout << " + ------------------------------------------------------------------- +" << endl;
                            system("pause");
                            exit_program = true;
                            validInput = true;
                        }
                        else if (confirm == 'N' || confirm == 'n')
                        {
                            selection = 0;
                            validInput = true;
                        }
                        else
                        {
                            setTextColour(COLOUR_YELLOW);
                            cout << "\nInvalid input! Please enter 'Y' for Yes or 'N' for No." << endl
                                 << endl;
                        }
                    } while (!validInput);
                }
                break;
            }

            // controls selection counter
            if (selection > max_selections - 1)
                selection = 0;
            if (selection < 0)
                selection = max_selections - 1;
            break;
        case SCREEN_SEARCH:
            setTextColour(MAIN_COLOUR);
            cout << " + ------------------------------------------------------------------- +" << endl;
            cout << "    DICTIONARY ENGLISH - VIETNAMESE WITH AUTOCOMPLETE AND AUTOCORRECT             " << endl;
            cout << " + ------------------------------------------------------------------- +" << endl
                 << endl;

            setTextColour(COLOUR_GREY);
            cout << " Press SPACE to enter." << endl;
            cout << " Press ESC to go back." << endl
                 << endl
                 << endl;

            // take string input
            setTextColour(COLOUR_YELLOW);
            cout << "Enter word to search: ";
            setTextColour(COLOUR_WHITE);
            cout << " ";
            cout << str_input;

            // run autocomplete / autocorrect as long as string input is provided
            if (str_input != "")
            {
                cout << endl
                     << endl;
                autoCompleteTrieObj.get_prefix(str_input);
            }

            // take keyboard input
            if (!stop_taking_str_input)
            {
                key_input = _getch();

                if (key_input == KEY_SPACE)
                {
                    // kiểm tra chuỗi có ký tự nào khác khoảng trắng không
                    if (str_input.find_first_not_of(' ') == string::npos)
                    {
                        setTextColour(COLOUR_YELLOW);
                        cout << endl
                             << "\nPlease enter a valid word to search!" << endl;
                        setTextColour(COLOUR_WHITE);
                        system("pause");
                    }
                    else
                    {
                        stop_taking_str_input = true;
                    }
                }

                // remove character when BACKSPACE is pressed
                else if (str_input != "" && key_input == KEY_BACKSPACE)
                    str_input.pop_back();

                // 13 is Enter
                // add character to string input
                else if (key_input != NULL && key_input != 13 && key_input != KEY_BACKSPACE && validEntry())
                    str_input.push_back(key_input);

                // ESC
                if (key_input == KEY_ESCAPE)
                    changeScreen(SCREEN_MAIN);
            }

            // one word is entered
            if (stop_taking_str_input)
            {
                for (char &c : str_input)
                {
                    c = tolower(c);
                }
                string res = dhtObj.getDefinition(str_input);

                if (res == " Word doesn't exist!")
                {
                    cout << " ";
                    setTextColour(SECONDARY_COLOUR);
                    cout << str_input;
                    setTextColour(COLOUR_WHITE);
                    cout << " " << res;
                }
                else
                {
                    cout << endl
                         << endl
                         << " ";
                    setTextColour(SECONDARY_COLOUR);

                    cout << str_input;
                    setTextColour(COLOUR_WHITE);
                    cout << " " << res;
                }

                cout << endl
                     << endl;
                setTextColour(COLOUR_GREY);
                cout << endl
                     << " Press SPACE to search again." << endl;
                cout << endl
                     << " Press B to bookmark word." << endl;
                key_input = _getch();
                if (key_input == KEY_SPACE)
                {
                    str_input = ""; // reset string input
                    stop_taking_str_input = false;
                }
                else if (key_input == KEY_ESCAPE)
                    changeScreen(SCREEN_MAIN); // go back to main menu
                // b or B
                else if (key_input == 66 || key_input == 98)
                {
                    if (b.contains(str_input) && res != " Word doesn't exist!")
                    {
                        setTextColour(COLOUR_YELLOW);
                        cout << "\nWord \"" << str_input << "\" already exists in bookmarks." << endl;
                    }
                    else if (!b.contains(str_input) && res != " Word doesn't exist!")
                    {
                        string bookmark_entry = str_input + ": " + res;
                        b.insert(bookmark_entry); // add to bookmarks
                        setTextColour(MAIN_COLOUR);
                        cout << "\nWord \"" << str_input << "\" added to bookmarks successfully!" << endl;
                    }
                    else
                    {
                        setTextColour(COLOUR_YELLOW);
                        cout << "\nWord \"" << str_input << "\" has no meaning and cannot be added to the bookmark." << endl;
                    }
                    setTextColour(COLOUR_WHITE);
                    system("pause");
                }
            }
            break;
        case SCREEN_BOOKMARKS:
            setTextColour(MAIN_COLOUR);
            cout << " + ------------------------------------------------------------------- +" << endl;
            cout << "    DICTIONARY ENGLISH - VIETNAMESE WITH AUTOCOMPLETE AND AUTOCORRECT             " << endl;
            cout << " + ------------------------------------------------------------------- +" << endl
                 << endl;

            setTextColour(SECONDARY_COLOUR);
            cout << " Bookmarks " << endl
                 << endl;

            setTextColour(COLOUR_WHITE);

            // show bookmarks
            b.display();

            setTextColour(COLOUR_GREY);
            cout << endl
                 << " Press ESC to go back." << endl;

            key_input = _getch();
            if (key_input == KEY_ESCAPE)
                changeScreen(SCREEN_MAIN);

            break;
        }
        key_input = 0;
        system("cls");
    }
}

void UI::changeScreen(int id)
{
    switch (id)
    {
    case SCREEN_MAIN:
        max_selections = sizeof(itemArray_DictMain) / sizeof(*itemArray_DictMain);
        selection = 0;
        screen = SCREEN_MAIN;
        break;
    case SCREEN_SEARCH:
        screen = SCREEN_SEARCH;
        break;
    case SCREEN_BOOKMARKS:
        screen = SCREEN_BOOKMARKS;
        break;
    }
}

bool UI::validEntry()
{
    if (key_input >= (int)'a' && key_input <= (int)'z' || key_input >= (int)'A' && key_input <= (int)'Z' || key_input == KEY_BACKSPACE || key_input == KEY_SPACE || key_input == KEY_ESCAPE)
        return true;
    return false;
}